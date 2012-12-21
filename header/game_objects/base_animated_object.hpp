#ifndef GAME_BASE_ANIMATED_OBJECT_HPP
#define GAME_BASE_ANIMATED_OBJECT_HPP

// project include
#include "base_object.hpp"

// c++ libraries
#include "list_templates/list_templates"

namespace game {

	class Base_animated_object : public Base_object {

		Q_OBJECT

		public:

			Base_animated_object(Game_state * game_state);
			~Base_animated_object();

		protected slots://animation only functions
			virtual void animation_update();//this is responsible for setting the current image globally!

		protected:

			int animation_counter;//this is the animation counter for the image switching
			Linked_list<QImage> * images;//want this to be used by all elements




	};
}
#endif