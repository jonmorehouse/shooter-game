#include "game_objects/character.hpp"

using namespace std;

namespace game {

	Character::Character(Game_state * game_state) : Base_animated_object(game_state) {
		
		// initialize character images
		this->images->push(QImage("images/character/1.png"));//
		this->images->push(QImage("images/character/2.png"));//
		this->animation_update();//initialize the first image

		// connect animation timers to update images periodically
		connect(this->game_state->get_timer(), SIGNAL(_single()), this, SLOT(animation_update()));//update the animation timer every few seconds

		// initialize the various pieces of the character here
		this->reset();//reset the character
		this->update();//call the parent painter on the widget!
	}

	Character::~Character() {

		// character destructor goes here -- unnecessary at this point
	}

	void Character::keyPressEvent(QKeyEvent * event) {

		if (event->key() == 32) {//we have emitted a space bar
			emit create_bullet(QPoint(this->position.x() + (this->image.width()*0.5), this->position.y()));
			return;
		}

		int direction = 0;//direction of the offset
		float _x;//this is how much the offset is going to be 
		QPoint new_coordinates = this->position;//set the 

		if (event->key() == 16777234 || event->key() == 65) direction = -1;

		else if (event->key() == 16777236 || event->key() == 70) direction = 1;
		
		else return;//key does not do anything for this application

		// now validate the positional movement and set the movement here
		_x = direction * pow(this->game_state->get_level() * 3, 3.0);

		// create new coordinates for the movement
		new_coordinates.setX(new_coordinates.x() + _x);

		// ensure that the character stays in teh viewport of the game
		if (new_coordinates.x() < 0 || new_coordinates.x() > this->game_state->get_width() * (1-character_width)) return;//do nothing 

		// coordinates validated
		this->move(new_coordinates.x(), new_coordinates.y());//move the widget on the screen

		// reset the position of the coordinates globally
		this->position = new_coordinates;
	}

	void Character::reset() {

		QRect temp = this->generate_geometry();

		this->setGeometry(temp);//sets the widget geometry
		this->position = QPoint(temp.x(), temp.y());//this is the widgets current position
		this->rect = temp;
		this->image = this->image.scaled(temp.height(), temp.width());

		this->update();
	}

	QRect Character::generate_geometry() {

		// need to create the height / width of the elements etc
		int _height = this->game_state->get_height() * character_height,//initialize the heigh
			_width = this->game_state->get_width() * character_width,//initialize the width
			_x = (this->game_state->get_width() - _width) * 0.5,//this is for centering the element initially
			_y = this->game_state->get_height() - (this->game_state->get_height() * _bottom_offset) - _height;

		return QRect(_x, _y, _height, _width);

	}
}

