/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 22:01:37
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef PLAYERFACTORY_HPP_
#define PLAYERFACTORY_HPP_

#include "SceneObject.hpp"

class PlayerFactory {
	public:
		static SceneObject create(float x, float y);
};

#endif // PLAYERFACTORY_HPP_