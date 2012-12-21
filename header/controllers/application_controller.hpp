#ifndef APPLICATION_CONTROLLER_HPP
#define APPLICATION_CONTROLLER_HPP


// include project libraries
#include "base_controller.hpp"
#include "menu_controller.hpp"
#include "user_controller.hpp"
#include "game_controller.hpp"

//QT Library Dependencies

class Application_controller : public QGraphicsView {

	Q_OBJECT

	public:
		Application_controller(Game_state * game_state);
		~Application_controller();

	public slots:
		void keyPressEvent(QKeyEvent * event);//for now this is all we need for this application -- we could and should use an event filter in the future for more events
		// http://doc.qt.digia.com/qt/eventsandfilters.html
		void application_change();//this will respond to any signals emitted by the current_controller
		void clear_screen();//will clear the screen for any application

	signals:
		void keyPress(QKeyEvent * event);

	private:
		QString current_application;
		Game_state * game_state;
		Base_controller * current_controller;
};

#endif