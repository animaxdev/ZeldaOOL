/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimation.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 20:40:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SPRITEANIMATION_HPP_
#define SPRITEANIMATION_HPP_

#include <vector>

#include "Timer.hpp"

struct SpriteAnimation {
	SpriteAnimation(u16 _delay) :
		delay(_delay), isPlaying(false) {}
	
	u16 delay;
	bool isPlaying;
	Timer timer;
	std::vector<u16> frames;
};

#endif // SPRITEANIMATION_HPP_