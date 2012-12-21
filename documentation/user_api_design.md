User API Design Document
=

Read Data / Write Data Classes
-	

-	stand alone classes that use QFile to read and write data from the system
-	assignment standards are hardcoded in

User API Base
-

-	write data in destructor
-	read data in constructor
-	singleton class -- so only one instance

User Display Base
-

-	inherits from base_user_api
-	user_display
-	user_management

User Management Class
-

-	user input / output


User Api Class
-

-	this is the interface that inherits from both user_management and user display
-	responsible as the module that the application interacts with