
#ifndef playerclass_H
#define playerclass_H
#include <iostream>
#include <string>
#include <cctype>
#include "partyclass.h"
#include "itemclass.h"
using namespace:: std;

class player{
public:
	player(int attack = 0, int health = 0, int defend = 0);//sets up the initial values to zero to me changed later when the player gets passed in.
	int playerinfo(int  & attack, int & health, int & defend);//sets up the variables to be used in this class.
	int getplayerHealth();//gets the players(users) health value.
	int getplayerAttack();//gets the players attack value.
	int getplayerDefend();//gets the players defence value.
	void addTeamMember(char *teamMemberName, int teamAttackValue);//Adds teammember to the array in the party class.
	void displayTeamMembers();//displays the teammembers in the array.
	void addItems(char *itemName, int itemAttackValue);//Adds Items to the array in item class.
	int displayItems();//Displays the items in the array.
	void itemSelect(int itemchoice);//selects an item and adds it to the players attack.
	void deitemSelect(int itemchoice);//the item that was selected in itemSelect(); now subtracts the items attack from the players attack.
	int resetPHealth(int m_phealth);//returns the health.

private:
	int m_attack;//players attack is stored here.
	int m_health;//players health is stored here.
	int m_defend;//players defence is stored here.
	party m_members[5];//the teammembers array.
	item m_items[50];//the items array.
	int numberOfMembers;//Stores how many teammembers added to the array.
	int numberOfItems;//stored the number of items added to the array.

};

#endif

