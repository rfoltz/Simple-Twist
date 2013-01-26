#include <iostream>
#include <string>
#include <cctype>
#include "partyclass.h" 

using namespace:: std;

party::party(int pattack, string pname) // Constructor
	{
		m_pattack = pattack;
		m_pname = pname;
	}


void party::partyinfo(string & pname, int & pattack) // sets up the persons name and attack value.
{

pname = m_pname;
pattack = m_pattack;

}

void party::partysetinfo(char * pname, int & pattack) // Gets the persons name and attack value.
{
	m_pname = pname;
	m_pattack = pattack;
}




