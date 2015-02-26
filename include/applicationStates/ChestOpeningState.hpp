/*
 * =====================================================================================
 *
 *       Filename:  ChestOpeningState.hpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 15:43:52
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHESTOPENINGSTATE_HPP_
#define CHESTOPENINGSTATE_HPP_

#include "ApplicationState.hpp"
#include "SceneObject.hpp"

class ChestOpeningState : public ApplicationState {
	public:
		ChestOpeningState(SceneObject &chest, ApplicationState *parent);
		
		void update() override;
		
		void draw() override;
		
		enum class State {
			Opening,
			Opened,
			Finished
		};
		
	private:
		State m_state = State::Opening;
		
		SceneObject *m_item = nullptr;
};

#endif // CHESTOPENINGSTATE_HPP_
