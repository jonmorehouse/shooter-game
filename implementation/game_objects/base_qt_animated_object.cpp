#include "game_objects/base_qt_animated_object.hpp"

using namespace std;

namespace game {


	Base_qt_animated_object::Base_qt_animated_object(Game_state * game_state) : Base_object(game_state) {

		// create the containers for these elements
		this->animation_group = new QParallelAnimationGroup;//new animation group to hold all the concurrent animations
		this->animation_container = vector<QPropertyAnimation *>();//create the animation container
		

	}

	Base_qt_animated_object::~Base_qt_animated_object() {
		

	}
}