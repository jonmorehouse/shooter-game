#ifndef GAME_CHARACTER_CONTROLLER_HPP
#define GAME_CHARACTER_CONTROLLER_HPP

//project libraries
#include "game_base_controller.hpp"
#include "game_objects/character.hpp"
#include "game_objects/bullet.hpp"

#include <QGraphicsProxyWidget>
#include <QGlobal.h>
#include <QTime>

// c++ libraries
#include <vector>


namespace game {

	class Character_controller : public Game_base_controller {

		Q_OBJECT

		public:
			Character_controller(Game_state * game_state);
			~Character_controller();

		public slots:

			void character_collision();//will be responsible for returning the character collision
			void create_bullet(QPoint initial);//
			void destroy_bullet(unsigned int identifier);//
			void reset();//this is to reset the entire element

			
		private:
			Character * character;//character controller -- completely encapsulated!
			std::vector<Bullet *>bullets;//this is the maximum number of bullets possible
	};
}

#endif