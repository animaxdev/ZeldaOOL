/*
 * =====================================================================================
 *
 *       Filename:  PlayerMapCollision.hpp
 *
 *    Description:
 *
 *        Created:  25/09/2018 16:43:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERMAPCOLLISION_HPP_
#define PLAYERMAPCOLLISION_HPP_

#include <gk/scene/SceneObject.hpp>

class PlayerMapCollision {
	public:
		static void update(gk::SceneObject &player);
};

#endif // PLAYERMAPCOLLISION_HPP_
