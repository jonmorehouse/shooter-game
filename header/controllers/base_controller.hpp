#ifndef BASE_CONTROLLER_HPP
#define BASE_CONTROLLER_HPP

// projectl libraries to include
#include "utilities.hpp"
#include "game_state.hpp"
#include "elements/button.hpp"

// project utilities to include
#include "list_templates/list_templates"

// qt libraries to include
 #include <QGraphicsLinearLayout>


class Base_controller : public QGraphicsView {

	Q_OBJECT

	public:
		Base_controller(Game_state * game_state, QWidget * parent = NULL);
		~Base_controller();

	public slots://slots -- will emit signal keyPress Event which will be caught in the character_controll
		void keyPressEvent(QKeyEvent * event);//keypress event -- emits a signal if we are going to use it -- impleemnt on this function

	signals://keypress
		void keyPress(QKeyEvent * event);//
		
	protected:
		Game_state * game_state;
		QGraphicsScene * scene;

	signals:
		void application_update();//will be responsible for calling any parent application changes

};

#endif