/*
 * =====================================================================================
 *
 *       Filename:  Sprite.hpp
 *
 *    Description:
 *
 *        Created:  17/01/2018 19:48:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "Image.hpp"
#include "SpriteAnimation.hpp"

class Sprite : public Image {
	public:
		Sprite() = default;
		Sprite(const std::string &textureName, u16 frameWidth, u16 frameHeight, bool isAnimated = false);

		void load(const std::string &textureName, u16 frameWidth, u16 frameHeight, bool isAnimated = false);

		void updateAnimations();

		void setCurrentFrame(u16 currentFrame);
		void setCurrentFrame(u16 animID, u16 frameID);
		void setCurrentAnimation(u16 currentAnimation);

		void addAnimation(const SpriteAnimation &animation) { m_animations.emplace_back(animation); }

		u16 currentFrame() const { return m_currentFrame; }

		u16 frameWidth() const { return m_frameWidth; }
		u16 frameHeight() const { return m_frameHeight; }

		bool hasAnimations() const { return m_animations.size() != 0; }
		u16 currentAnimationID() const { return m_currentAnimation; }
		const SpriteAnimation &currentAnimation() const { return m_animations[m_currentAnimation]; }

		// FIXME: To remove (used in GrassFactory)
		SpriteAnimation &currentAnimation() { return m_animations.at(m_currentAnimation); }
		SpriteAnimation &getAnimation(u16 i) { return m_animations.at(i); }

		bool isAnimated() const { return m_isAnimated; }
		void setAnimated(bool isAnimated) { m_isAnimated = isAnimated; }

		const std::vector<SpriteAnimation> &animations() const { return m_animations; }
		void setAnimations(const std::vector<SpriteAnimation> &animations) { m_animations = animations; }

		static bool pause;

	private:
		std::vector<SpriteAnimation> m_animations;

		u16 m_currentFrame = 0;
		u16 m_currentAnimation = 0;
		u16 m_previousAnimation = 0;

		u16 m_frameWidth = 0;
		u16 m_frameHeight = 0;

		bool m_isAnimated = false;
};

#endif // SPRITE_HPP_
