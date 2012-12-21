#include "user_states/base_user_display.hpp"

using namespace std;

Base_user_display::Base_user_display(Game_state * game_state) : Base_user_state(game_state) {


	this->elements = vector<QLineEdit *>();

}

Base_user_display::~Base_user_display() {

	// will be responsible for deleting the qline elements later
	for (int i = 0, z = this->elements.size(); i < z; i++) {

		delete this->elements[i];//deletes the qlineedit elements
	}
	
}

void Base_user_display::create_body() {

	for (int i = 0, z = this->elements.size(); i < z; i++)
		this->elements[i]->setReadOnly(true);//makes each element read only!

}