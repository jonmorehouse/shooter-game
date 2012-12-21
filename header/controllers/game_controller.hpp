#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include "base_controller.hpp"

// game namespace projects
// #include "game_controllers/enemy_controller.hpp"
#include "game_controllers/rock_controller.hpp"
#include "game_controllers/character_controller.hpp"
#include "game_objects/timer.hpp"

class Game_controller : public Base_controller {

	Q_OBJECT
	
	public:
		Game_controller(Game_state * game_state);
		~Game_controller();

	// slots:
		// responsible for catching losing life elements
		// responsible for resetting all elements


	private:
		// game::Enemy_controller * enemy_controller;//
		game::Rock_controller * rock_controller;//
		game::Character_controller * character_controller;//
		game::Timer * timer;//master timer -- this is an extended class which uses timers
};


#endif