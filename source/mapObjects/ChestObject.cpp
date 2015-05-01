/*
 * =====================================================================================
 *
 *       Filename:  ChestObject.cpp
 *
 *    Description:  
 *
 *        Created:  06/10/2014 20:24:58
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "AudioPlayer.hpp"
#include "ChestObject.hpp"
#include "ChestOpenedState.hpp"
#include "Map.hpp"
#include "RupeeCollectable.hpp"

void ChestObject::onEvent(u8 event) {
	if(event == Map::EventType::ChestOpened) {
		AudioPlayer::playEffect("chest");
		
		m_opened = true;
		
		reset(*Map::currentMap);
		
		// FIXME: TO REMOVE LATER
		ApplicationStateStack::getInstance().push<ChestOpenedState>(ApplicationStateStack::getInstance().top(), m_x, m_y, m_collectable);
	}
}

void ChestObject::reset(Map &map) {
	if(m_opened) {
		map.setTile(m_x / 16, m_y / 16, 240);
	}
}
