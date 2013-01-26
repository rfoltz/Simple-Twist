#include <iostream>
#include <string>
#include <cctype>
#include "playerclass.h"
#include "storyclass.h"    
  

using namespace:: std;


// Welcome Function.
void menu (){
	cout << "************************************WELCOME*************************************" << endl 
	 << "Welcome to 'A Simple Twist of Fate'" << endl
	 << "To give the game input type your answer and press the enter key" << endl
	 << "Give the input 'I' to view your inventory, 'T' to view your team members, "<< endl
	 << "and 'X' to exit"<< endl << endl
	 << "If you have any other questions view the readme file included with the game," << endl
	 << "Developed By: Ian Paton, Mark Fifield and Robert Foltz.  "<< endl
	 << "If you have any question please don't hesitate to email us" << endl
	 << "Emails Ian: ian.m.paton@gmail.com Mark:? Robert: robert@robertfoltz.com" <<endl
	 << "********************************************************************************" << endl << endl << endl;

}
// Game Over Function.
void gameover(){
	cout << "***********************************Game*Over************************************";
	cout << endl << endl << "Would you like to play again? [Y]es or e[X]it" << endl;
	
	char input; // stores users input
	cin >> input;
	input=toupper(input); // changes lower case to upper case.

	if (input == 'X') // if 'X' or 'x' is then it exits the program.
		exit(0);

	if (input == 'Y'){ // if input is 'Y' or 'y' then takes you to the welcome screen and restarts the game from the start.
		player user(20,100,10);// sets players attack health and defence.
		StoryGroup storytime(&user);//sets up the story.
		menu();//Calls the Welcome Function
		storytime.intro();// Starts the story.
		//user.resetPHealth(100); // makes sure the players health is 100.
	}


	cout << endl;

		
}



int main(){


player user(20,100,10); // sets players attack health and defence.
	//cout << user.getplayerHealth() << endl;
StoryGroup storytime(&user); // sets up the story.


	menu();// Calls the Welcome Function
	storytime.intro();// Starts the story.
//	user.resetPHealth(100);// makes sure the players health is 100.
	


gameover();
return 0;

}