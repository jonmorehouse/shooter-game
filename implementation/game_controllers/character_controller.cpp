#include "game_controllers/character_controller.hpp"

using namespace std;

/*
	We need to connect character as a proxy widget because
	



*/

namespace game {

	Character_controller::Character_controller(Game_state * game_state) : Game_base_controller(game_state) {

		this->character = NULL;
		this->reset();//will use the game level to update the current element
		
 	
	}

	Character_controller::~Character_controller() {
		

	}

/************ PUBLIC SLOTS ***********/

	void Character_controller::reset() {

		// 1.) create character and link 
		// 2.) create bullet container -- set maxes etc
		if (this->character) {

			this->character->disconnect();
			this->character->deleteLater();
		}
		
		int level = this->game_state->get_level(),//cache level of game currently
			max = (level < 4) ? (8) : (level * 3);
		
		// bullet vector size
		this->bullets = vector<Bullet *>(utilities::random_integer(10, max), NULL);//we should signal this later
		
		// character elements
		this->character = new Character(this->game_state);//create a new character -- will set the character in the correct position as well
		
		// add widget to the scene and then initialize
		this->scene->addWidget(this->character);

		// connections
		connect(this, SIGNAL(keyPress(QKeyEvent *)), this->character, SLOT(keyPressEvent(QKeyEvent *)));//send all key events to the character for local handling
		connect(this->character, SIGNAL(create_bullet(QPoint)), this, SLOT(create_bullet(QPoint)));//bullet connection

		// 
	}

	void Character_controller::character_collision() {

		// this is responsible for collisions that reset the entire element
		// needs to signal a life down and complete reset!
		// emit reset();//will be the reset element that is responsible for calling a reset on several different elements

	}

	void Character_controller::create_bullet(QPoint initial) {

		// creates a bullet with initial points and connects 
		// bullets are self living elements
		int index = -1;//need to first see if there is open spot for a new bullet
		// if not later functionality will include a built in signal to send a message to the screen

		for (int i = 0, z = this->bullets.size(); i < z; i++)
			if (!this->bullets[i]) {
				index = i;
				break;
			}

		if (index == -1) return;//cancel out the bullet if it doesn't work
		// would later create a signal emission here to target the game score board to be updated

		this->bullets[index] = new Bullet(this->game_state, (unsigned int)index, initial);//create a new bullet -- later functionality will include a directed bullet
		this->scene->addWidget(this->bullets[index]);
		connect(this->bullets[index], SIGNAL(destroy_bullet(unsigned int)), this, SLOT(destroy_bullet(unsigned int)));
	}

	void Character_controller::destroy_bullet(unsigned int index) {//deletes the bullet in this element

		// destroys the bullet at this place
		if (index < 0 || index >= this->bullets.size()) return;

		if (!this->bullets[index]) return;//makes sure that the bullet works


		this->bullets[index]->disconnect();
		this->bullets[index]->deleteLater();
		this->bullets[index] = NULL;
	}

}