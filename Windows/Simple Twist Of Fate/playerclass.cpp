#include <iostream>
#include <string>
#include <cctype>
#include "playerclass.h" 
#include "partyclass.h"

using namespace std;

player::player(int attack, int health, int defend) // Contsrutor.
{
	m_attack = attack;
	m_health = health;
	m_defend = defend;
	numberOfMembers = 0; // sets the number in your party to 0.
	numberOfItems = 0; //  sets the number of items in your inventory to 0.
}

int player::playerinfo(int & attack, int & health, int & defend) // Sets up the players, attack, health and defence.
{
	attack = m_attack;
	health = m_health;
	defend = m_defend;

	return 0;
}

int player::getplayerHealth() // Gets the users health.
{
	return m_health;
}

int player::getplayerAttack() // Gets the users attack value.
{
	return m_attack;
}

int player::getplayerDefend() // Gets the users Defence value.
{
	return m_defend;
}                                                            

void player::addTeamMember(char *teamMemberName, int teamAttackValue) // Adds a party member to the party.
{
	
	
	m_members[numberOfMembers].partysetinfo(teamMemberName, teamAttackValue); // sets up the values to be passed into partysetinfo(); method and into the array in the partyclass.
	numberOfMembers = numberOfMembers + 1; // adds 1 member to the array of party memebers.
	m_attack += teamAttackValue; // adds the party members attack to the users attack.

}

void player::displayTeamMembers()// Displays the Members in your party.
{
	string partyname;// stores the memeber(s) name(s).
	int partyattack; // Store the member(s) attack(s) value(s).

	if (numberOfMembers<=0){// checks to see if you have members.
		cout << "you have no team members" << endl;
	}
	for (int i = 0; i < numberOfMembers; i ++){
		
		m_members[i].partyinfo(partyname,partyattack);// gets the party(s) values
		cout << partyname << endl;

	}
}

void player::addItems(char *itemName, int itemAttackValue)// Adds items to item inventory
{
	
	
	m_items[numberOfItems].itemsetinfo(itemName, itemAttackValue); // Sets up the items name and attack and passes them into the array and the itemsetonfo(); method in the itemclass.
	numberOfItems = numberOfItems + 1;// adds 1 to the number of items.

}

int player::displayItems()// Displays the items in a list.
{
	

	string itemname;//stores the item name
	int itemattack;//stores the items attack.
	
	if (numberOfItems<=0){// checks to see if you have item(s)
		cout << "you have no items" << endl;
	}

	for (int i = 0; i < numberOfItems; i ++){//makes the list displayed with numbers.
			
		m_items[i].iteminfo(itemname,itemattack); // gets the items name and attack
		cout << i+1 << " " << itemname << "    " << endl; // Name of item is displayed and a number beside it.
		
	}
	
	return numberOfItems;
}


void player::itemSelect(int itemchoice)// if you selected an item.
{
	cout << "You have selected " << m_items[itemchoice].getItemName(); // displays the item you've choosen
	m_attack += m_items[itemchoice].getItemAttack(); // adds items attack to the  users attack.

}



void player::deitemSelect(int itemchoice)// takes the items attack away from the users attack
{

	m_attack -= m_items[itemchoice].getItemAttack();

}

int player::resetPHealth(int m_phealth)// makes sure the health is the number shown when in a zombie encounter.
{
	m_health = m_phealth;

	return 0;
}


/*void player::resetPAttack(int m_pattack)
{
	m_pattack = m_attack;

}
*/ 