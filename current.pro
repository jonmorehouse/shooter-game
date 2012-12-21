TEMPLATE = app
TARGET = 
DEPENDPATH += . header libraries implementation
INCLUDEPATH += . header libraries implementation 
DESTDIR = ./project


CONFIG += core gui qt debug
# thread debug
# QT += network xml


#INCLUDE C++ CONNECTOR
# LIBS += -L/usr/local/Cellar/mysql-connector-c++/1.1.0/lib -lmysqlcppconn

#INCLUDE GOOGLE SPARSEHASH
# LIBS += -I/usr/local/Cellar/google-sparsehash/2.0.2/include

#INCLUDE CUSTOM LIBRARIES
#LIBS += -Llibraries -llist_templates

# CHANGE MOC AND .O OUTPUT DIRECTORIES
CONFIG(debug, debug|release) {
	
	OBJECTS_DIR = ./_object
    MOC_DIR = ./_moc
}


# CONTROLLER HEADERS
HEADERS = controllers/base_controller.hpp \
	controllers/application_controller.hpp \
	controllers/user_controller.hpp \
	controllers/menu_controller.hpp \
	controllers/game_controller.hpp \

# USER STATE State Headers
HEADERS += user_states/base_user_state.hpp \
	user_states/base_user_management.hpp \
	user_states/base_user_display.hpp \
	user_states/add_user_state.hpp \
	user_states/delete_user_state.hpp \
	user_states/login_user_state.hpp \
	user_states/high_scores_state.hpp \
	user_states/show_users_state.hpp \
	user_states/friend_management_state.hpp \

#GAME HEADERS
HEADERS += game_controllers/game_base_controller.hpp \
	game_controllers/character_controller.hpp \
	game_controllers/rock_controller.hpp \

# GAME ELEMENTS
HEADERS += game_objects/base_object.hpp \
	game_objects/base_animated_object.hpp \
	game_objects/base_qt_animated_object.hpp \
	game_objects/character.hpp \
	game_objects/timer.hpp \
	game_objects/bullet.hpp \
	game_objects/rock.hpp \
 
#ELEMENT HEADERS
HEADERS += elements/button.hpp \


#CURRENT APPLICATION
SOURCES += tests/game.cpp \

# GLOBAL SOURCES
SOURCES += utilities.cpp \
	game_state.cpp

# USER INFORMATION SOURCES
SOURCES += user_api/user.cpp \
	user_api/save_data.cpp \
	user_api/read_data.cpp \
	user_api/user_management.cpp \
	user_api/user_display.cpp \
	user_api/user_api.cpp

# controller sources
SOURCES += controllers/base_controller.cpp \
 	controllers/application_controller.cpp \ 
 	controllers/user_controller.cpp \
 	controllers/menu_controller.cpp \
 	controllers/game_controller.cpp  

# sources
SOURCES += user_states/base_user_state.cpp \
	user_states/base_user_management.cpp \
	user_states/base_user_display.cpp \
	user_states/add_user_state.cpp \
	user_states/delete_user_state.cpp \ 
	user_states/login_user_state.cpp \
	user_states/high_scores_state.cpp \
	user_states/show_users_state.cpp \
	user_states/friend_management_state.cpp

# GAME CONTROLLERS
SOURCES += game_controllers/game_base_controller.cpp \
	game_controllers/character_controller.cpp \
	game_controllers/rock_controller.cpp \

# GAME OBJECTS
SOURCES += game_objects/base_object.cpp \
	game_objects/base_animated_object.cpp \
	game_objects/base_qt_animated_object.cpp \
	game_objects/character.cpp \
	game_objects/timer.cpp \
	game_objects/bullet.cpp \
	game_objects/rock.cpp \

#element sources
SOURCES += elements/button.cpp \



