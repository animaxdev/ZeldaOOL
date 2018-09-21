/*
 * =====================================================================================
 *
 *       Filename:  OctorokLoader.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 02:29:58
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "OctorokFactory.hpp"
#include "OctorokLoader.hpp"

void OctorokLoader::load(XMLElement *octorokElement, SceneObjectList &objectList) {
	u16 tileX = octorokElement->IntAttribute("tileX");
	u16 tileY = octorokElement->IntAttribute("tileY");

	objectList.addObject(OctorokFactory::create(tileX * 16, tileY * 16));
}

