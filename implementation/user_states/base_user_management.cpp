#include "user_states/base_user_management.hpp"

using namespace std;

Base_user_management::Base_user_management(Game_state * game_state) : Base_user_state(game_state) {

	this->checkboxes = vector<QCheckBox *>();//checkboxes
	this->form_elements = vector<QLineEdit *>(3);

}

Base_user_management::~Base_user_management() {

	for (int i = 0, z = this->form_elements.size(); i < z; i++) {
		
		delete this->form_elements[i];
		// this->form_elements[i].disconnect();

	}


	for (int i = 0, z = this->checkboxes.size(); i < z; i++)
		delete this->checkboxes[i];


}