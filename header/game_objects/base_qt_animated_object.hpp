#ifndef GAME_BASE_QT_ANIMATED_OBJECT_HPP
#define GAME_BASE_QT_ANIMATED_OBJECT_HPP

// project libraries
#include "base_object.hpp"

// this class is responsible for the abstract animation that will drive our bullets
// goal is to have a signal released after the animation
// this signal will then trigger a delete on this object!

// qt libraries
#include <QAbstractAnimation>//this is the base for all anmations -- can not instantiate directly
#include <QParallelAnimationGroup>//this is the animation group to hold all property animations to be executed simultaneously
#include <QPropertyAnimation>//base class for all animations

namespace game {

	class Base_qt_animated_object : public Base_object {//inheriting from qwidget in base_object

		Q_OBJECT
		
		public:
			Base_qt_animated_object(Game_state * game_state);
			~Base_qt_animated_object();
			
		public slots://this will be 
			virtual void animation_end() = 0;//this is the animation callback method

		protected:
			QParallelAnimationGroup * animation_group;//this is the animation group element
			std::vector<QPropertyAnimation *>animation_container;//this holds the references to the actual animations so they don't go out of scope
	};
}


#endif