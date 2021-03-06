/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:
 *
 *        Created:  30/04/2015 19:45:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <algorithm>

#include <gk/resource/ResourceHandler.hpp>

#include "CollisionHelper.hpp"
#include "Config.hpp"
#include "Map.hpp"
#include "MapLoader.hpp"
#include "PositionComponent.hpp"
#include "TilesInfos.hpp"
#include "World.hpp"

#include "BattleController.hpp"
#include "BehaviourController.hpp"
#include "LifetimeController.hpp"
#include "MovementController.hpp"

#include "EffectView.hpp"
#include "HitboxView.hpp"
#include "SpriteView.hpp"

Map::Map(u16 area, u16 x, u16 y, u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data) : m_tileset(tileset) {
	m_area = area;
	m_x = x;
	m_y = y;

	m_width = width;
	m_height = height;

	m_baseData = data;
	m_data = m_baseData;

	setPosition(0, 16);

	m_animator.init(*this);
	m_renderer.init(this, m_width, m_height);

	updateTiles();

	// FIXME: Move this to MapState
	if (!m_scene.isActive()) {
		m_scene.setCollisionHelper<CollisionHelper>();
		m_scene.addController<MovementController>();
		m_scene.addController<BattleController>();
		m_scene.addController<BehaviourController>();
		m_scene.addController<LifetimeController>();
		m_scene.addView<SpriteView>();
		m_scene.addView<EffectView>();
		// m_scene.addView<HitboxView>();
	}

}

void Map::reset() {
	m_data = m_baseData;

	m_scene.reset();
}

void Map::update() {
	m_animator.animateTiles(*this);

	m_scene.update();

	auto &positionComponent = World::getInstance().player().get<PositionComponent>();

	int x = SCREEN_WIDTH / 2 - positionComponent.x + 8;
	int y = SCREEN_HEIGHT / 2 - positionComponent.y + 8;
	setPosition(std::clamp<int>(x, SCREEN_WIDTH - m_width * 16, 0), std::clamp<int>(y, SCREEN_HEIGHT - m_height * 16, 16));
}

void Map::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.transform *= getTransform();

	target.draw(m_renderer, states);

	target.draw(m_scene, states);
}

void Map::updateTiles() {
	for(u16 tileY = 0 ; tileY < m_height ; tileY++) {
		for(u16 tileX = 0 ; tileX < m_width ; tileX++) {
			u16 tileID = getTile(tileX, tileY);

			m_renderer.updateTile(tileX, tileY, tileID, *this);
		}
	}
}

u16 Map::getTile(u16 tileX, u16 tileY) {
	if(tileX + tileY * m_width < m_width * m_height) {
		return m_data[tileX + tileY * m_width];
	} else {
		return 0;
	}
}

void Map::setTile(u16 tileX, u16 tileY, u16 id, bool write, bool persistent) {
	if(write && tileX + tileY * m_width < m_width * m_height) {
		m_data[tileX + tileY * m_width] = id;

		if (persistent) m_baseData[tileX + tileY * m_width] = id;
	}

	m_renderer.updateTile(tileX, tileY, id, *this);
}

bool Map::passable(float x, float y) {
	s16 tile = m_tileset.info()[getTile(x / m_tileset.tileWidth(),
	                                    y / m_tileset.tileHeight())];

	return TilesInfos::infos[tile][(s16(x) & 0xF) / (m_tileset.tileWidth()  / 2)
	                             + (s16(y) & 0xF) / (m_tileset.tileHeight() / 2) * 2] != TilesInfos::SubTileType::NonPassable;
}

bool Map::onDoor(float x, float y) {
	s16 tile = m_tileset.info()[getTile(x / m_tileset.tileWidth(),
	                                    y / m_tileset.tileHeight())];

	return TilesInfos::infos[tile][(s16(x) & 0xF) / (m_tileset.tileWidth()  / 2)
	                             + (s16(y) & 0xF) / (m_tileset.tileHeight() / 2) * 2] == TilesInfos::SubTileType::ChangeMap;
}

bool Map::isTile(float x, float y, u16 tile) {
	return m_tileset.info()[getTile(x / m_tileset.tileWidth(),
	                                y / m_tileset.tileHeight())] == tile;
}

