#include "user_states/add_user_state.hpp"

using namespace std;

Add_user_state::Add_user_state(Game_state * game_state) : Base_user_management(game_state) {

	// constructors are responsible for setting the title of the layout
	this->body->setTitle("Add User");

	this->create_body();//create the body elements
}	

Add_user_state::~Add_user_state() {



}

/***** SLOTS *****/

void Add_user_state::process(QString message) {

	if (message == "exit" || message == "menu")
		return Base_user_state::process(message);

	// slot that responds to the element
	if (!this->validate()) return;

	// validated properly
	this->submit();

	Base_user_state::process("menu");//show the main menu now!

}

/**** PRIVATE METHODS ********/

void Add_user_state::create_body() {


	// call parent constructor to create parent buttons
	Base_user_state::create_body();//--add the buttons and widgets to the layout

	//create the QLineEdits for this particular class
	for (int i = 0, z = this->form_elements.size(); i < z; i++)
		this->form_elements[i] = new QLineEdit();

	// give labels to each element
	this->form_elements[0]->setText("User Id");
	this->form_elements[1]->setText("Username");
	this->form_elements[2]->setText("Year");

	// add rows to the form
	this->layout->addRow(tr("&User Id"), this->form_elements[0]);
	this->layout->addRow(tr("&Username"), this->form_elements[1]);
	this->layout->addRow(tr("&Year"), this->form_elements[2]);

	// initialize the buttons

	// initialize the submit button
	this->buttons.push_back(new Button("Add User", "submit"));
	connect(this->buttons.back(), SIGNAL(menu_selection(QString)), this, SLOT(process(QString)));//connect slot
	this->layout->addRow(this->buttons.back());

	// add the main menu button
	this->layout->addRow(this->buttons.front());

	// 
	this->create_layout();

	// temp fix for layouts

	// for (int i = 0, z = this->form_elements.size(); i < z; i++) {

	// 	// connect(this, SIGNAL(keyPress(QKeyEvent *)), this->form_elements[i], SLOT(keyPressEvent(QKeyEvent * )));
	// }
}

bool Add_user_state::validate() {

	// check valid id
	long id = this->form_elements[0]->text().toLong();
	int year = this->form_elements[2]->text().toLong();
	QString username = this->form_elements[1]->text();


	if (0 >= id || this->user_api->user_management->user_exists(id)) {
		
		this->form_elements[0]->setText("Please choose another id.");
		return false;
	}

	if (!this->user_api->user_management->valid_username(username)) {

		this->form_elements[1]->setText("Please choose another username.");
		return false;
	}

	if (year < 1990 || year > 2030) {

		this->form_elements[2]->setText("Invalid Year.");
		return false;
	}

	this->user = new User(id);
	this->user->set_username(username);
	this->user->set_year(year);

	return true;

}

void Add_user_state::submit() {

	// submit the user to the user_management and then go back to the main menu	
	this->user_api->user_management->add_user(this->user);
}
