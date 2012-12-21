#include "game_objects/base_object.hpp"

using namespace std;

namespace game {



	Base_object::Base_object(Game_state * game_state, QWidget * parent) : QWidget(parent) , game_state(game_state) {
			
		this->palette = QPalette();
		this->palette.setBrush(QPalette::Background, Qt::transparent);//ensure that the object background is transparent -- override this in any subclassed methods
		this->setPalette(this->palette);
	}

	Base_object::~Base_object() {

		
	}

	void Base_object::paintEvent(QPaintEvent * event) {

			// this function assumes that the proper rectangle and image is set before being called!
			QPainter painter(this);
			painter.setRenderHint(QPainter::Antialiasing, true);
			painter.drawImage(this->rect, this->image);//draws out the current image on the screen!
	}
}//end namespace


