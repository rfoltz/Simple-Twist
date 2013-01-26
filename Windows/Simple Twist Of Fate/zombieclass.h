#ifndef zombieclass_H
#define zombieclass_H
#include <iostream>
#include <string>
#include <cctype>

using namespace:: std;

class zombie
{
public:
	zombie(int zattack = 0, int zhealth = 0, int zdefend = 0);//Sets up the attack, health and zombies defence. 
	int zombieinfo(int  & zattack, int & zhealth, int & zdefend); // Sets the zombies attack, health and defence to the values passed in.
	int getzombieHealth();//Returns the zombies health.
	int getzombieAttack();//Returns the zombies attack.
	int getzombieDefend();//Returns the zombies defence.
	int resetValues();//Resets the values to the orginal values that where passed in zombieinfo(); so if theres a looping fight the zombies health goes back up to its orginal.
private:
	int m_zattack;//the zombies attack value is stored here.
	int m_zhealth;//the zombies health value is stored here.
	int m_zdefend;//the zombies defence value is stored here.
	int m_original_zattack;//variable used to set orginal attack to whats was passed in.
	int m_original_zhealth;//variable used to set orginal health to whats was passed in.
	int m_original_zdefend;//variable used to set orginal defence to whats was passed in.

};

#endif