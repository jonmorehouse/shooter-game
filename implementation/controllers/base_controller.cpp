#include "controllers/base_controller.hpp"

using namespace std;

Base_controller::Base_controller(Game_state * game_state, QWidget * parent) : game_state(game_state), QGraphicsView(game_state->get_scene(), parent), scene(game_state->get_scene()) {


}

Base_controller::~Base_controller() {

	// responsible for cleaning out the application and removing unwanted / unnecessary things



}

void Base_controller::keyPressEvent(QKeyEvent * event) {

	emit keyPress(event);//emits a key press to buttom elements

}



