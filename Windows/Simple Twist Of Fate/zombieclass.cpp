#include <iostream>
#include <string>
#include <cctype>
#include "zombieclass.h" 

using namespace std;

zombie::zombie(int zattack, int zhealth, int zdefend)//Constructor.
{
	m_zattack = zattack;
	m_zhealth = zhealth;
	m_zdefend = zdefend;
	m_original_zattack = zattack;
	m_original_zhealth = zhealth;
	m_original_zdefend = zdefend;
}

int zombie::zombieinfo(int & zattack, int & zhealth , int & zdefend)//Sets up the variables used for the zombies attack, health and defence.
{
	zattack = m_zattack;
	zhealth = m_zhealth;
	zdefend = m_zdefend;

	return 0;
}

int zombie::getzombieHealth()//Gets the zombies health
{
	return m_zhealth;
}

int zombie::getzombieAttack()//Gets the zombies attack
{
	return m_zattack;
}

int zombie::getzombieDefend()//Gets the zombies defence.
{
	return m_zdefend;
}

int zombie::resetValues()//Resets the zombies attack, health and defence to the original values when initialized.
{
	m_zattack = m_original_zattack;
	m_zhealth = m_original_zhealth;
	m_zdefend = m_original_zdefend;

	return 0;
}