#include "game_objects/bullet.hpp"

namespace game {


	Bullet::Bullet(Game_state * game_state, unsigned int id, QPoint initial) : Base_qt_animated_object(game_state), id(id), initial(initial) {

		this->image = QImage("images/general/bullet.png");//load in the image

		this->geometry_init();//initialize the random image and set the widget size
		this->setGeometry(QRect(initial.x(), initial.y(), this->rect.height(), this->rect.width()));//set the geometry on the element

		this->image = this->image.scaled(this->geometry().height(), this->geometry().width());

		// initialize the pieces of the bullet for the animation
		this->destination_init();//initialize the destination of the bullet
		this->animation_init();//initilaize all the animations for this particular element

		// start the animation -- this will be a self - destructing element
		this->animation_group->start(QAbstractAnimation::DeleteWhenStopped);//start the animation -- it will be deleted upon finishing
	}

	Bullet::~Bullet() {//this is actually called from the character_controller in general

		//shouldn't have to manually delete anything here!
	}


	// SLOTS

	void Bullet::animation_end() {

		emit destroy_bullet(this->id);//handles the bullet 
	}

	// worker functions
	void Bullet::geometry_init() {

		float ratio = float(this->image.rect().width()) / float(this->image.rect().height());//need to make sure that our randomly generated image size does not distort the image

		// generate the random height
		int _height = utilities::random_integer(this->game_state->get_height() * min_height, this->game_state->get_height() * max_height),
			_width = _height / ratio;//create a new width based on the ratio of the image

		// set the image to the proper geometry
		this->image = this->image.scaled(_height, _width);//scale the image with the above calculated coordinates -- should still be in scale
		this->rect = this->image.rect();

		// connec the animation group
		connect(this->animation_group, SIGNAL(finished()), this, SLOT(animation_end()));
	}


	void Bullet::destination_init() {

		int delta_x = utilities::random_integer(0, this->game_state->get_width() * delta_x_max),
			delta_y = utilities::random_integer(this->game_state->get_height() * delta_y_min, this->game_state->get_height() * delta_y_max);

		delta_x = (delta_x % 2 == 0) ? (delta_x) : (delta_x * -1); // this is the random error entered into the element!

		int _x = this->initial.x() + delta_x,//x can move left or right of the element
			_y = this->initial.y() - delta_y;//y should always be moving upwards on the screen
 
		// validate the new position to ensure that it is in the screen -- assume the size is relevant as well
		if (_x < 0 || (_x + this->geometry().width()) > this->game_state->get_width()) return destination_init();

		if (_y < 0 || (_y + this->geometry().height()) > this->game_state->get_height()) return destination_init();

		// set the destination elements 
		this->destination = QPoint(_x, _y);//create a position for the destination -- can be used for rotation later

	}

	void Bullet::animation_init() {

		// need to calculate the time needed
		int delta_y = this->initial.y() - this->destination.y(),
			_time = (float)delta_y / (float) pixels_per_second * 1000;//for milisecond animation 

		// create animation for geometry etc

		this->animation_container.push_back(new QPropertyAnimation(this, "geometry"));
		this->animation_container.back()->setDuration(_time);
		this->animation_container.back()->setStartValue(QRect(this->initial.x(), this->initial.y(), this->geometry().height(), this->geometry().width()));
		this->animation_container.back()->setEndValue(QRect(this->destination.x(), this->destination.y(), this->geometry().height(), this->geometry().width()));
		this->animation_container.back()->start();

		// add all animations to the group

		for (int i = 0, z = this->animation_container.size(); i < z; i++) 
			this->animation_group->addAnimation(this->animation_container[i]);

	}
	
}