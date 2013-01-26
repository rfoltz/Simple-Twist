
#include <iostream>
#include <string>

#include "Story.h"

using namespace std;

Story::Story()//Constructor
{
	m_item = "";
	m_itemValue = 0;
	m_teammate = "";
	m_teamValue = 0;

}

void Story::setPlayer(player *user)// Sets the player class to be used within this class
{
	m_player = user;
}


/*void Story::addStory(string lineToBeEntered, int choiceOne, int choiceTwo, int choiceThree)
{

	m_lineOfStory = lineToBeEntered;
	m_choiceOne = choiceOne;
	m_choiceTwo = choiceTwo;
	m_choiceThree = choiceThree;


}*/

void Story::addStory(string lineToBeEntered, int choiceOne, int choiceTwo, int choiceThree) // Sets up the variables used to get input for the story.
{

	m_lineOfStory = lineToBeEntered;
	m_choiceOne = choiceOne;
	m_choiceTwo = choiceTwo;
	m_choiceThree = choiceThree;
}


int Story::readStory() // gets the story from the storyclass.
{
	char storedCharacter1;//stores the values in the square brackets in the story (example: '[A]')
	char storedCharacter2;
	char storedCharacter3;
	cutter();//calls the cutter method.
	//search through m_lineofstory for the [ and store the next character, continue and find the next up to 3?
	string bracket = "[";
	int pos = 1;
	int count = 0;
	while(pos != string::npos)//loops through m_lineofstory for the character in the brackets. up to 3 characters.
	{
		pos= m_lineOfStory.find(bracket, pos);
		if(pos != -1)
			pos++;
			count++;
			if ((count == 1) && (m_choiceOne != -1))
				storedCharacter1 = m_lineOfStory.at(pos);			//for example m
			if ((count == 2) && (m_choiceTwo != -1)&& (m_choiceTwo != -2))
				storedCharacter2 = m_lineOfStory.at(pos);			//for example q
			if ((count == 3) && (m_choiceThree != -1)&& (m_choiceThree != -2))
				storedCharacter3 = m_lineOfStory.at(pos);           //for example c
	}



	//print the story ( m_lineofstory)
	char input;
	
	
	//get input from user
	bool check = true;
	int result = 0;
	//int input;
	if (m_itemValue != 0){ // checks to see if an item was added in the story
		m_player ->addItems(m_item,m_itemValue);
	}
	if (m_teamValue !=0 ){ // checks to see if an Teammate was added in the story.
		m_player ->addTeamMember(m_teammate, m_teamValue);
	}
	if  ((m_choiceOne == -1)||(m_choiceTwo == -1)){ // if the story returns -1 then it doesn't go into the loop below.
			check = false;
			result = -1;
	}
	while (check)//checks if 'check' is -1 if not it looks for input.
	{
		cin >> input;
		input=toupper(input);// makes input to uppercase instead of checking for both lower and upper though if statments.

		if (input == 'X' || input == 'I' || input == 'T')
			question(input);
		if (input == storedCharacter1){		//	m == m
			check = false;
			result = m_choiceOne; // returns what the user inputs to result
		}
		if (input == storedCharacter2 && m_choiceTwo != -2){
			check = false;
			result = m_choiceTwo; // returns what the user inputs to result
		}
		if(input == storedCharacter3 && m_choiceThree != -2){
			check = false;
			result = m_choiceThree;// returns what the user inputs to result
		}
		
		//if (input == storedCharacter3)
		//	check = false;
		//	result = m_ChoiceThree;
	}
	
return result;// returns what the player inputs to go to next part in the story.
}


void Story::cutter(){				//prints out the story

	double sizeChar = m_lineOfStory.size(); //gets the number of characters in m_lineofstory
	int numOfLines = sizeChar/80 + 2;	// so if you get 4.3 lines, becomes 5
	int charactersPerLine = sizeChar/numOfLines;// finds out how many characters are on a line.
	int i = 1;
	
	char character;
	int start = 0;
	while (i <= numOfLines){//until number of lines is finished.
		for (int j = start; j <= i * 80; j++) // number of max characters per line is 80
		{
			character = m_lineOfStory.at(j);
			if ((character == '*') || (character == ' ' ) && (j > charactersPerLine * i)){ // checks for the '*' to see if the line of story is done, and checks for spaces if there is a space before the line ends it moves to the next line.
				j = i *80 + 1;	
			}else{
				cout << character;
				start = j + 2;
			}
		}
		cout << endl;
		i++;
	}

}

void Story::question(char input)// Sees if the user has put in 'I', 'T' or 'X' and directs them to the appropiate methods.
{
	//char input;
		switch(input)
			{
			
		
			case 'X':
				exit(0);//exits the program.
				break;//breaks out of the switch statment
		
			case 'I':
				m_player -> displayItems();//Displays Items
				break;//breaks out of the switch statment
		
			case 'T':
				m_player -> displayTeamMembers(); //Displays TeamMembers
				break;//breaks out of the switch statment		
		
			default : 
				break;//breaks out of the switch statment
			}
}

void Story::addItem(char *itemName, int itemValue)//Sets up things to add items in the storyclass.
{
	m_item = itemName;
	m_itemValue = itemValue;
}

void Story::addTeam(char *teamName, int teamValue)//Sets up things to add TeamMembers in the storyclass.
{
	m_teammate = teamName;
	m_teamValue = teamValue;
}