/*
 * =====================================================================================
 *
 *       Filename:  EasyBehaviour.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 21:21:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EASYBEHAVIOUR_HPP_
#define EASYBEHAVIOUR_HPP_

#include <functional>

#include "Behaviour.hpp"

class EasyBehaviour : public Behaviour {
	using Action = std::function<void(gk::SceneObject&)>;

	public:
		enum class FunctionType {
			Action,
			Reset
		};

		EasyBehaviour(Action action, Action reset) : m_action(action), m_reset(reset) {}
		EasyBehaviour(Action action, FunctionType type = FunctionType::Action) {
			if(type == FunctionType::Action) {
				m_action = action;
			} else {
				m_reset = action;
			}
		}

		void reset(gk::SceneObject &object) override {
			if(m_reset) m_reset(object);
		}

		void update(gk::SceneObject &object) override {
			if(m_action) m_action(object);
		}

	private:
		Action m_action;

		Action m_reset;
};

#endif // EASYBEHAVIOUR_HPP_
