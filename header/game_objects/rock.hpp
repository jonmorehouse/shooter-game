#ifndef GAME_ROCK_HPP
#define GAME_ROCK_HPP

// project including
#include "base_qt_animated_object.hpp"//this element is going to be animated!

namespace game {

	class Rock : public Base_qt_animated_object {

		Q_OBJECT

		public:
			Rock(Game_state * game_state, unsigned int id);
			~Rock();

		protected:
			void geometry_init();//initializes the geometry for this object
			void animation_init();//responsible for creating another animation run or simply destroying the element
			void animation_clear();//clears out the containers and disconnects the animations etc!

		public slots:
			virtual void animation_end();

		signals:
			void destroy_rock(unsigned int id);//signals the parent to delete a rock

		protected://variables for this rock element

			unsigned int id;// this is the element's id!

			static const float max_height = 0.25,//this is the maximum height of the rock
				min_height = 0.1,//this is the minimum height of the rock
				max_width = 0.3,//this is the maximum width of the rock
				min_width = 0.1,//this is the minimum width of the rock
				initial_y_offset = 0.25;//this is how far abover the screen the object can go

			//min / maximum speed constants
			static const int min_pixels_per_second = 50,
				max_pixels_per_second = 70;//
	};
}


#endif