/*
 * =====================================================================================
 *
 *       Filename:  EffectView.hpp
 *
 *    Description:
 *
 *        Created:  16/09/2018 23:56:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EFFECTVIEW_HPP_
#define EFFECTVIEW_HPP_

#include "AbstractView.hpp"

class EffectView : public AbstractView {
	public:
		void draw(const SceneObject &object, RenderTarget &target, RenderStates states) override;
};

#endif // EFFECTVIEW_HPP_
