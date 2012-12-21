#include "game_controllers/game_base_controller.hpp"

using namespace std;//
// using namespace game;//game namespace for easier work

namespace game {
	
	Game_base_controller::Game_base_controller(Game_state * game_state) : QGraphicsView(game_state->get_scene()), scene(game_state->get_scene()), game_state(game_state) {

		// initialize timer here
		this->timer_interval = 1000;
		this->timer = new QTimer(this);//connect the qtimer to this element!
    	timer->start(this->timer_interval);
		// now initialize the elements list
		// this->elements = new Linked_list<Game_object *>();//create a new linked list to hold game objects

	}

	Game_base_controller::~Game_base_controller() {

		// need to delink each element
		// loop through all elements and 
		this->timer->disconnect();
		delete this->timer;

	}

	void Game_base_controller::keyPressEvent(QKeyEvent * event) {

		emit keyPress(event);//emits a local signal

	}

}//end namespace
