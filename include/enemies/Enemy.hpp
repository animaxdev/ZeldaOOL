/*
 * =====================================================================================
 *
 *       Filename:  Enemy.hpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 21:38:31
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Battler.hpp"

class Enemy : public Battler {
	public:
		Enemy() = default;
		Enemy(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		void load(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		virtual void reset(Map &) override;
		
		virtual void draw();
		
		void mapBordersCollisions();
		
		void checkDeath();
		
		u8 strength() const { return m_strength; }
		
		bool isDead() const { return m_dead; }
		
	protected:
		bool m_dead = false;
		
	private:
		Sprite m_destroyAnimation{"animations-monsterDestroy", 32, 32};
		
		u8 m_strength = 1;
};

#endif // ENEMY_HPP_