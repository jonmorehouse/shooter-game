#ifndef GAME_BULLET_HPP
#define GAME_BULLET_HPP

// project includes
#include "base_qt_animated_object.hpp"// this element is not animated 

// qt libraries
#include <QPoint>
#include <QGlobal.h>

namespace game {


	class Bullet : public Base_qt_animated_object {

		Q_OBJECT

		public:
			Bullet(Game_state * game_state, unsigned int id, QPoint initial_position);//takes in an identifier to contact the controller again with and a position to start from
			~Bullet();

		public slots:
			virtual void animation_end();//this is the end of the animation -- needs to emit a signal to character_controller

		private:
			void geometry_init();//initializes the bullet's size and image
			void destination_init();//initialize the destination of the element
			void animation_init();//initialize the animation

		signals:
			void destroy_bullet(unsigned int id);//signals the character_controller!

		protected:
			unsigned int id;//this is the destroy element

		private:

			QPoint initial,//
				destination;

			// max height and width of the bullet -- can vary!
			static const float min_height = 0.01, 
				max_height = 0.05, 
				min_width = 0.01, 
				max_width = 0.05;

			// positional variables
			static const float delta_x_max = 0.1,
				delta_y_max = 0.6,
				delta_y_min = 0.4;

			static const int pixels_per_second = 500;//how fast the animation will run!
	};
}


#endif