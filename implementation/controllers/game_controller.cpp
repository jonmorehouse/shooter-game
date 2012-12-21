#include "controllers/game_controller.hpp"

using namespace std;


Game_controller::Game_controller(Game_state * game_state) : Base_controller(game_state) {

	// instantiate different controllers
	this->character_controller = new game::Character_controller(game_state);
	connect(this, SIGNAL(keyPress(QKeyEvent *)), this->character_controller, SLOT(keyPressEvent(QKeyEvent * )));

	this->rock_controller = new game::Rock_controller(game_state);
		

}

Game_controller::~Game_controller() {

	if (this->character_controller) delete this->character_controller;

	if (this->rock_controller) delete this->rock_controller;


}

