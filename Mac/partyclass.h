#ifndef partyclass_H
#define partyclass_H
#include <iostream>
#include <string>
#include <cctype>
using namespace:: std;

class party
{
public:
	party(int pattack =0, string pname ="");//Constructor sets the teammembers attack to be zero and sets the teammembers name to nothing. 
	void partyinfo(string & pname, int & pattack);//Sets up the variables to be used.
	void partysetinfo(char *pname, int & pattack);//Sets the teamembers name by passing it in and sets up the teammembers attack to whats passed in.


private:
	int m_pattack;//varible to hold teammembers attack.
	string m_pname;//variable to hold teammembers name.


};




#endif