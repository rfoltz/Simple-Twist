
#ifndef itemclass_H
#define itemclass_H
#include <iostream>
#include <string>
#include <cctype>
using namespace:: std;

class item
{
public:
	item(int iattack = 0, string iname ="");//Constructor
	void iteminfo(string & iname, int & iattack);// Sets up the name of the item and the items name.
	void itemsetinfo(char *iname, int & iattack);//Passes in the item name and items attack and sets the values.
	string getItemName(); // returns the name of an item.
	int getItemAttack(); // returns the items attack value.


private:
	int m_iattack;// variable for the items attack.
	string m_iname;// variable for the items name.


};

#endif