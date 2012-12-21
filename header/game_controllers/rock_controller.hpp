#ifndef GAME_ROCK_CONTROLLER
#define GAME_ROCK_CONTROLLER

// project includes
#include "game_base_controller.hpp"
#include "game_objects/rock.hpp"
#include <iostream>

namespace game {

	class Rock_controller : public Game_base_controller {

		Q_OBJECT

		public://constructors / destructors
			Rock_controller(Game_state * game_state);
			~Rock_controller();

		protected://functions
			void destroy_rocks();//destroys random rocks at random times
			void create_rock(unsigned int id);//create an individual rock and link it!

		public slots://slot functions -- but also accessible from this base
			void create_rocks();//this is responsible for creating all rocks -- calls the create_rock element
			void destroy_random_rock();//destroy random rock
			void destroy_rock(unsigned int id);//destroy a particular rock -- protection against overlaying elements
			void reset();//resets all the elements -- responsible for deleting all rocks!

		private://
			std::vector<Rock *>rocks;//

			static const int min_rocks = 5,
				max_rocks = 15;//

	};

}

#endif