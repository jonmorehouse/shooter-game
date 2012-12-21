#ifndef GAME_CHARACTER_HPP
#define GAME_CHARACTER_HPP
	
// project includes
#include "base_animated_object.hpp"

// c++ libraries
#include <cmath>

namespace game {

	class Character : public Base_animated_object {

		Q_OBJECT

		public:
			Character(Game_state * game_state);//
			~Character();

		public slots:
			void reset();//resets the image

		private:
			QRect generate_geometry();//generates the geometry of this widget and sets the widget up properly

		protected slots:
			void keyPressEvent(QKeyEvent *event);

		// custom signals
		signals:
			void create_bullet(QPoint current);//create a bullet

		private://variables
			// size variables
			static const float character_height = 0.1,//this is the height of the character
				character_width = 0.1,//this is the object width
				_bottom_offset = 0.01;//this is how far from the bottom the character is
	};
}

#endif