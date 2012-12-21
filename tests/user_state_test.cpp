// standard c++ / c libraries
#include <iostream>
#include <string>

// Project libraries
#include "game_state.hpp"
#include "controllers/application_controller.hpp"
#include "user_api/user_api.hpp"

// QT Libraries
#include <QtGui>
#include <QGraphicsScene>

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
	QGraphicsView view(&scene);//send the location in memory of the scene to the view -- this is what shows the scene on the screen
	view.setWindowTitle("Horizontal Shooter");//


	// initialize scene geometry / scrolling
	view.setGeometry(0,0,width, height);
	view.setFixedSize(width, height);
	view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//prevent scrolling
	view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// view methods to setup the view painting elements
	view.setRenderHint(QPainter::Antialiasing);//update rendering system
	view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);//sets the update method -- how objects are signalled
	view.ensureVisible(scene.sceneRect());

	// view is initalized so need to show it!
	view.show();//show the viewport

	// initialize the application logic and send these objects to them
	User_api user_api;
	Game_state game_state(&scene, &user_api, &app, height, width);//
	Application_controller application_controller(&game_state);//application controller for this application

	return app.exec();//this returns the gui execution of this function -- enables the window mode
}
