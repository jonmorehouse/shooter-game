// standard c++ / c libraries
#include <iostream>
#include <string>

// Project libraries
#include "game_state.hpp"
#include "user_api/user_api.hpp"
#include "controllers/game_controller.hpp"

// QT Libraries
#include <QtGui>
#include <QGraphicsScene>

using namespace game;

int main(int argc, char ** argv) {
		
	int height = 600,
		width = 600;

	// initialize app
	QApplication app(argc, argv);//q application lives for the life of the main function
	QApplication::setStyle("plastique");

	// initialize seed
	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//random seed function

	// initialize scene and view
	QGraphicsScene scene(0, 0, width, height);//scene lives in this function because it is only alive during the running of the main application
	User_api user_api;
	Game_state game_state(&scene, &user_api, &app, height, width);//

	Game_controller controller(&game_state);//application controller for this application


	controller.setWindowTitle("Horizontal Shooter");//

	// initialize scene geometry / scrolling
	controller.setGeometry(0,0,width, height);
	controller.setFixedSize(width, height);
	controller.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//prevent scrolling
	controller.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// view methods to setup the view painting elements
	controller.setRenderHint(QPainter::Antialiasing);//update rendering system
	// view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);//sets the update method -- how objects are signalled
	controller.ensureVisible(scene.sceneRect());

	// view is initalized so need to show it!
	controller.show();//show the viewport

	// initialize the application logic and send these objects to them

	return app.exec();//this returns the gui execution of this function -- enables the window mode
}
