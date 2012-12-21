#include "game_objects/rock.hpp"

using namespace std;

namespace game {

	Rock::Rock(Game_state * game_state, unsigned int id) : Base_qt_animated_object(game_state), id(id) {

		// initialize the shape and position of the object and its containing rectangle
		this->geometry_init();

		// load image and initialize animation
		this->image = QImage("images/rocks/1.png");
		this->image = this->image.scaled(this->rect.height(), this->rect.width());//image to be used for this element

		// 
		this->animation_init();//initialize the animation

	}

	Rock::~Rock() {

		this->animation_clear();

	}

	/************** PROTECTED FUNCTIONS *******/
	void Rock::geometry_init() {

		int _height = utilities::random_integer(this->game_state->get_height() * min_height, this->game_state->get_height() * max_height),
			_width = utilities::random_integer(this->game_state->get_width() * min_width, this->game_state->get_width() * max_width),
			_x = utilities::random_integer(0, this->game_state->get_width() - _width),
			_y = 0  - this->game_state->get_height() * initial_y_offset;

		this->rect = QRect(0,0,_height, _width);
		this->setGeometry(QRect(_x,_y, _height, _width));

	}

	void Rock::animation_init() {

		// calculate the new coordinates!
		int _x = utilities::random_integer(0, this->game_state->get_width() - this->rect.width()),
			_y = utilities::random_integer(this->geometry().y(), this->game_state->get_height() * 1.5),
			pixels_per_second = utilities::random_integer(min_pixels_per_second, max_pixels_per_second),
			time_interval = (_x > _y) ? (_x / pixels_per_second) : (_y / pixels_per_second);

		time_interval *= 1000;

		// clear animations and then initialize the new animation!
		this->animation_clear();//implement later for cleaning finished animations

		// initialize the animation
		this->animation_container.push_back(new QPropertyAnimation(this, "geometry"));//create a new animation for this
		this->animation_container.back()->setDuration(2000);
		this->animation_container.back()->setStartValue(this->geometry());
		this->animation_container.back()->setEndValue(QRect(_x, _y, this->geometry().width(), this->geometry().height()));
		this->animation_container.back()->start();//QAbstractAnimation::DeleteWhenStopped);
		
		// 
		connect(this->animation_container.back(), SIGNAL(finished()), this, SLOT(animation_end()));
		
		return;

		// check that the animation group exits
		if (!this->animation_group) this->animation_group = new QParallelAnimationGroup;

		// add all animations to the animation group
		for (int i = 0, z = this->animation_container.size(); i < z; i++) this->animation_group->addAnimation(this->animation_container[i]);

		// intialize the animation segment
		connect(this->animation_group, SIGNAL(finished()), this, SLOT(animation_end()));//connect the end of the animtion group !

		// animation group!
		this->animation_group->start();//QAbstractAnimation::DeleteWhenStopped);//start the animation -- it will be deleted upon finishing

	}

	void Rock::animation_end() {

		// check if the animation is still in range!
		if (this->geometry().y() > this->game_state->get_height()) {
			
			this->setAttribute(Qt::WA_DontShowOnScreen, true);
			this->hide();
			emit destroy_rock(this->id);
			return;
		}

		this->animation_clear();//clear out animations
		this->animation_init();//restart the animation!
	}

	void Rock::animation_clear() {

		// responsible for clearing animations!
		for (int i = 0; i < this->animation_container.size(); i++){

			if (this->animation_container[i]) {

				this->animation_container[i]->disconnect();
				this->animation_container[i]->stop();
				this->animation_container.erase(this->animation_container.begin() + i);
			}
		}

		return;
		if (this->animation_container.size() > 0)
			this->animation_container.clear();
	}
}