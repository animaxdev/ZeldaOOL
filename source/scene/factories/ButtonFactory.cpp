/*
 * =====================================================================================
 *
 *       Filename:  ButtonFactory.cpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 01:50:40
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ButtonFactory.hpp"
#include "Scene.hpp"

#include "ButtonComponent.hpp"
#include "CollisionComponent.hpp"
#include "HitboxesComponent.hpp"
#include "PositionComponent.hpp"

void buttonAction(SceneObject &button, SceneObject &object, CollisionInformations &collisionInformations);

SceneObject ButtonFactory::create(u16 tileX, u16 tileY) {
	SceneObject object;
	object.set<ButtonComponent>();
	object.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);
	
	auto &hitboxesComponent = object.set<HitboxesComponent>();
	hitboxesComponent.addHitbox(IntRect(4, 4, 8, 8));
	
	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addAction(&buttonAction);
	
	return object;
}

void buttonAction(SceneObject &button, SceneObject &object, CollisionInformations &collisionInformations) {
	auto &positionComponent = button.get<PositionComponent>();
	auto &buttonComponent = button.get<ButtonComponent>();
	
	if(Scene::isPlayer(object)) {
		if(!collisionInformations.empty()) {
			buttonComponent.pressedAction(positionComponent.x / 16,
			                              positionComponent.y / 16);
		} else {
			buttonComponent.releasedAction(positionComponent.x / 16,
			                               positionComponent.y / 16);
		}
	}
}
