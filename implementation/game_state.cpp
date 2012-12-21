#include "game_state.hpp"

#include <iostream>
Game_state::Game_state(QGraphicsScene * scene, User_api * user_api, QApplication * application, int height, int width) : scene(scene), user_api(user_api), application(application), width(width),  height(height) {

	this->logged_in = false;
	this->timer = NULL;
	this->update_interval = 500;//default setting

	this->level = 1;
	this->timer = new game::Timer(this->update_interval);//instantiate a new timer 
}

Game_state::~Game_state() {



}


/************ PUBLIC GETTER FUNCTIONS ***********/
QGraphicsScene * Game_state::get_scene() const {

	return this->scene;
}

QString Game_state::get_application() const {

	return this->current_application;
}

QApplication * Game_state::get_window() const {



}

User_api * Game_state::get_user_api() const {

	return this->user_api;
}

int Game_state::get_height() const {

	return this->height;

}

int Game_state::get_width() const {

	return this->width;
}

bool Game_state::is_logged_in() const {

	return this->logged_in;
}

User * Game_state::get_user() const {

	return this->user;//returns the user pointer
}

game::Timer * Game_state::get_timer() const {

	return this->timer;//returns the timer

}

unsigned int Game_state::get_update_interval() const {

	return this->update_interval;
}

unsigned int Game_state::get_level() const {

	return this->level;

}

unsigned int Game_state::get_score() const {

	return this->score;
}

unsigned int Game_state::get_lives() const {

	return this->lives;

}

/******** GAME STATE SETTER FUNCTIONS *******/
void Game_state::set_timer(game::Timer * timer) {

	this->timer = timer;

}

void Game_state::set_timer_interval(int interval) {

	this->update_interval = interval;
	this->timer->setInterval(this->update_interval);
} 


void Game_state::set_application(QString application) {

	this->current_application = application;

}

void Game_state::set_user(User * user) {

	this->logged_in = true;
	this->user = user;

}


