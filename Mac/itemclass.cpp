
#include <iostream>
#include <string>
#include <cctype>
#include "itemclass.h" 

using namespace:: std;


item::item(int iattack, string iname) // Contrustor.
	{
		m_iattack = iattack;
		m_iname = iname;
	}


void item::iteminfo(string & iname, int & iattack) // Sets up the items name and attack value.
{

iname = m_iname;
iattack = m_iattack;

}

void item::itemsetinfo(char *iname, int & iattack) // Gets the items name and attack.
{
	m_iname = iname;
	m_iattack = iattack;
}

string item::getItemName()// Gets name sperate from attack
{

	return m_iname;
}

int item::getItemAttack() // Gets attack avalue seprate from the name of the item.
{
	return m_iattack;
}