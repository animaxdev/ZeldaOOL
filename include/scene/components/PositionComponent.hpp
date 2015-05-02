/*
 * =====================================================================================
 *
 *       Filename:  PositionComponent.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:22:51
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_

#include "Direction.hpp"
#include "Rect.hpp"

class PositionComponent {
	public:
		PositionComponent(float _x, float _y, u16 _width, u16 _height)
			: x(_x), y(_y), width(_width), height(_height), hitbox(0, 0, width, height) {}
		
		void move(float dx, float dy) { x += dx; y += dy; }
		
		float x = 0;
		float y = 0;
		
		u16 width = 0;
		u16 height = 0;
		
		IntRect hitbox;
		
		Direction direction = Direction::None;
};

#endif // POSITIONCOMPONENT_HPP_