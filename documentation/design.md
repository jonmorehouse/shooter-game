Game Design
=

High Level
-

-	the point of this game is to move your ship left and right and shoot at items and destroy them, while avoiding falling objects that could possibly harm you

High Level Characters / Objects
-

-	Robot
	-	user can move this left / right horizontally across the screen
	-	can shoot by pressing space bar -- maybe more shooting functionality in the future
	-	shooting objects gives points, getting hit loses lives
-	Objects:
	-	Rocks - these are asteroids that will blow up at certain intervals?
		-	for now they just disappear though
		-	Will have a parent rock class and then children that inherit
		-	different sizes etc
	-	Enemies - these are enemies that will require being shot to die
		-	some enemies require multiple hits etc
		-	some enemies move faster than others / rotate / resize dynamically

	-	Bullets - these are shot by both the robot and the enemies
		-	can be different sizes etc

Classes
-

-	Robot Class
	-	this is the main class of the game - the game character
	-	recieves basic input left / right and will move to avoid objects
	-	this robot can shoot when the user hits space
	-	animation of the rotation when the user moves this character or shoots
	-	Not run on a timer -- but needs to send animations to a ParallelAnimationGroup

-	Game State Class
	-	this is the universal gamestate class that is worked on by each element
	-	Needs to be locked to be protected from corruption -- use qt thread
	-	Responsible for activating / deactivating the 
	-	Holds pointers to other objects -- a linked list of all enemies / objects, bullets etc
	-	Holds score / lives / points for the element

	-	This is responsible for data / settings / running etc

-	Game controller -- this is responsible for displaying the game menu and then initializing each element
	-	will check the game state each time to see whether or not to deactivate the game, delete its objects and then show the menu
	-	will initialize an enemy / rock controller
		-	responsible for 


-	Controller Classes -- enemy_controller / rock_controller
	-	responsible for initializing a linked list of enemies / rocks based upon the game state methods
	-	these are called with the game_controller timer event
	-	


High Level
-	

-	game state is passed around -- this is a global object which is worked on by all objects across the game -- set level, color, speed etc
-	game controller - this is responsible for determining when the game is over and when the game is beginning
	-	responsible for calling the menu screen to initialize the elements / database elements
-	fly controller -- holds a linked list of enemy objects / rocks which all are self containing -- they move themselves automatically
-	robot controller -- this is a self containing widget -- responsible for its own animation etc 

Some Notes on Updating / Timers
-

-	I create the game controller class -- this extends qtimer 
	-	will call the paint element of each of its items
	-	but will be deleted when I delete the class -- which will be 

-	In game controller, I will have a global timer
	-	I will delete / remove this based upon the game update because that is the only one that needs the timer
	-	will connect the signals etc to the paint events for my objects in the rock_controller etc


Notes
-

-	I have used the STL Libraries because I had trouble getting my external linked_list library to compile as a static library for use in this project. I have included the source code in the libraries directory and will update this later after meeting ta's for further help. The problem with the libraries' comilation has to do with the fact that the templates implementation files are seperated from the actual header files.

Random Notes
-

-	Signals should not be virtual for custom implementations
-	Look at event filters and signal mappers!
-	Watch diving ints for a float -- need to cast them both as floats otherwise you will get an int answer!


Game Development Notes
-	

-	Game Controller Slots for updating the game -- from the robot, the mountains and the enemies


Rock
=

-	Random rocks are hit at certain intervals 
-	triple timer connect to something that will destroy the rocks at a certain time
-	rocks can then be flagged for deletion as well -- when they pass a certain area
