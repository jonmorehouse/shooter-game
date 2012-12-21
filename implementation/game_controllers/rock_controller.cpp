#include "game_controllers/rock_controller.hpp"

using namespace std;

namespace game {

	/******** CONSTRUCTRORS / DESTRUCTORS ********/
	Rock_controller::Rock_controller(Game_state * game_state) : Game_base_controller(game_state) {

		this->rocks = vector<Rock *>(utilities::random_integer(min_rocks, max_rocks), NULL);
		this->create_rocks();//create rocks
		connect(this->game_state->get_timer(), SIGNAL(_triple()), this, SLOT(create_rocks()));
		connect(this->game_state->get_timer(), SIGNAL(_quadruple()), this, SLOT(destroy_random_rock()));
	}


	Rock_controller::~Rock_controller() {

		// responsible calling the delete rocks element
		this->destroy_rocks();//destroy any remaining rocks
	}

	/********** DESTRUCTION FUNCTIONS FUNCTIONS ***********/
	void Rock_controller::destroy_random_rock() {


		int id = utilities::random_integer(0, this->rocks.size());


		if (this->rocks[id]) this->destroy_rock((unsigned int)id);
	}


	void Rock_controller::destroy_rocks() {

		for (int i = 0, z = this->rocks.size(); i < z; i++)
			if (this->rocks[i]) this->destroy_rock(i);

	}	

	void Rock_controller::destroy_rock(unsigned int id) {

		cout << "HELLO FROM DESTROY ROCK" << endl;
		if (this->rocks[id]) {

			this->rocks[id]->disconnect();
			this->rocks[id]->deleteLater();
			this->rocks[id] = NULL;
		}

	}

	/************* CREATION FUNCTIONS ***************/
	void Rock_controller::create_rocks() {
		
		for (int i = 0, z = this->rocks.size(); i < z; i++)
			if (!this->rocks[i])
				this->create_rock(i);//create a new rock on the scene!

	}

	void Rock_controller::create_rock(unsigned int id) {

		if (this->rocks[id]) return;//this rock already exists

		this->rocks[id] = new Rock(this->game_state, id);
		connect(this->rocks[id], SIGNAL(destroy_rock(unsigned int)), this, SLOT(destroy_rock(unsigned int)));
		this->scene->addWidget(this->rocks[id]);
	}

	/*********** GETTER FUNCTIONS ***************/

	void Rock_controller::reset() {

		// responsible for calling delete on all rocks?

	}

}