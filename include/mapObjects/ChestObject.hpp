/*
 * =====================================================================================
 *
 *       Filename:  ChestObject.hpp
 *
 *    Description:  
 *
 *        Created:  06/10/2014 20:24:41
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHESTOBJECT_HPP_
#define CHESTOBJECT_HPP_

#include "MapObject.hpp"
#include "RupeeCollectable.hpp"

class ChestObject : public MapObject {
	public:
		ChestObject(float x, float y) : MapObject(x, y, 16, 16),
		                                m_collectable(x, y, 30) {}
		
		void onEvent(u8 event);
		
		void reset(Map &map) override;
		
	private:
		bool m_opened = false;
		
		RupeeCollectable m_collectable;
};

#endif // CHESTOBJECT_HPP_