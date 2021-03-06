/*
 * =====================================================================================
 *
 *       Filename:  OctorokLoader.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 02:29:58
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "OctorokFactory.hpp"
#include "OctorokLoader.hpp"

void OctorokLoader::load(tinyxml2::XMLElement *octorokElement, gk::Scene &scene) {
	u16 tileX = octorokElement->IntAttribute("tileX");
	u16 tileY = octorokElement->IntAttribute("tileY");

	scene.addObject(OctorokFactory::create(tileX * 16, tileY * 16));
}

