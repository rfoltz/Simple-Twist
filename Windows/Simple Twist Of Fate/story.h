#ifndef Story_H
#define Story_H
#include <iostream>
#include <string>
#include "playerclass.h" 


using namespace::std;

class Story
{
public:
	Story();
	//void addStory(string line, int choiceOne = 0, int choiceTwo = 0, int choiceThree = 0);
	void addStory(string lineToBeEntered, int choiceOne, int choiceTwo = -2, int choiceThree = -2);//Sets up the variables to be used.
	void setPlayer(player *user);//sets up the player to be passed in.
	void cutter();//prints the story out in a neat fashion no words that run off to the next line.
	int readStory();//looks for the characters in the square brackets and then looks for input from the user and can only the characters after the square brackets or x , i or t.
	void question(char input);//where we look for input of the characters.
	void addItem(char *itemName, int itemValue);//adds items to the array from the story.
	void addTeam(char *teamName, int teamValue);//adds teammebers to the array from the story.
private:
	string m_lineOfStory; // the story to be entered into the cutter and printed on the screen.
	int m_choiceOne;//the first character after a sqaure bracket.
	int m_choiceTwo;//the second character after a sqaure bracket.
	int m_choiceThree;//the third character after a sqaure bracket.
	player *m_player;//passes in the player.
	char *m_item;//passes the item name in.
	int m_itemValue;//passes the items attack value.
	char *m_teammate;//passes in the teammembers name.
	int m_teamValue;//passes in the temembers attack value.
	//int m_choiceThree;
};


#endif