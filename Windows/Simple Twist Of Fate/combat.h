
#ifndef combat_H
#define combat_H
#include <iostream>
#include <string>
#include <cctype>
#include "playerclass.h"//imports playerclass.
#include "zombieclass.h"//imports zombieclass.
using namespace::std;

class combat
{
public:
	combat(player *user, zombie zombie);//constructor.
	void userAttack();// this is the users attack
	void enemyAttack();// this is the zombies attack
	string userTurn(); // this is where we combine the users attack and zombie attack in a turn based attack system.

	
private:

	player *m_user;// passes in the user.
	zombie m_zombie;// passes in the zombie.

	int m_iattack;//items attack
	int m_pattack;//users attack
	int m_pdefend;//users defence
	int m_phealth;//users health
	int m_zattack;//zombies attack
	int m_zdefend;//zombies defence
	int m_zhealth;//zombies health.


};

#endif