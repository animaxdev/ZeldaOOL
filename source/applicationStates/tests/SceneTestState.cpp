/*
 * =====================================================================================
 *
 *       Filename:  SceneTestState.cpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 12:43:41
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "Map.hpp"
#include "OctorokFactory.hpp"
#include "PlayerFactory.hpp"
#include "SceneTestState.hpp"

SceneTestState::SceneTestState() {
	Map::currentMap = &Map::getMap(0, 0, 0);
	
	m_scene.addObject(PlayerFactory::create(75, 50));
}

void SceneTestState::update() {
	Map::currentMap->update();
	
	m_scene.update();
	
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		m_scene.addObject(OctorokFactory::create(100, 80));
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void SceneTestState::draw() {
	m_font.drawString(4, -2, "A: Spawn an Octorok");
	
	Map::currentMap->draw();
	
	View::bind(&Map::currentMap->view());
	
	m_scene.draw();
	
	View::bind(nullptr);
}
