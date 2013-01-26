#include <iostream>
#include <string>
#include <cctype>
#include "combat.h" 
#include "playerclass.h"
#include "zombieclass.h"
#include "time.h"


using namespace:: std;

combat::combat(player *user, zombie zombie)//Constructor with all are varaibles
	{
		m_user = user;
		m_zombie = zombie;
		m_pattack = m_user->getplayerAttack();
		m_pdefend = m_user->getplayerDefend();
		m_phealth = m_user->getplayerHealth();
		m_zattack = m_zombie.getzombieAttack();
		m_zdefend = m_zombie.getzombieDefend();
		m_zhealth = m_zombie.getzombieHealth();
		srand(time(NULL));
	}


void combat::userAttack(){//The users attack method

	if (m_zdefend > m_pattack){//checks if the zombie defence is higher then the users attack
		 int pdmg = 0;
		m_zhealth = m_zhealth - pdmg; 
	}
else{
	int pdmg =   m_pattack - m_zdefend;// makes damage done 1 third
	int third = (pdmg/3)+1;
	 

   pdmg = pdmg - (rand()%third); 
   
 
	m_zhealth = m_zhealth - pdmg; // Subracts the damage from the zombies health.
}

}

void combat::enemyAttack(){//The enemy's attack.

	int zdmg;
	zdmg = m_zattack - m_pdefend; // checks to see if the players defnece in higher then the zombie attack
	 
	if(zdmg < 0) {
		zdmg = 0;
	}
	int subtractor = zdmg / 3; // makes the dmage 1/3.
	if (subtractor > 0){
	zdmg = zdmg - (rand()%(subtractor));//randomizes the attack damage
	}

	 m_phealth = m_phealth - zdmg; //subracts the damage from players health.
}



string combat ::userTurn(){ // The Zombie Encounter

	string choice;
	cout<<"*****Zombie Encounter*****"<< endl;

	while (m_zhealth > 0 && m_phealth > 0){ // checks if health is over zero, if zero or less it won't go into the loop.

	
		
	cout<< "What will you do, [A]ttack, [E]scape, or use an [I]tem?" << endl; // input question
    
	cin >> choice; // the users input is stored here

	if (choice == "A" || choice == "a") { // if input is 'A' or 'a'  then the user attacks the zombie
		userAttack();
		cout << "You hit the zombie!" << endl;
	}
	
	if (choice == "E" || choice == "e") {// if input is 'E' or 'e' then the user tries to escape.
	
		int r = (rand() %5)+1;
		
		if (r != 3){ // if the random function gets anything other then 3 it says you don't escape.
			cout << "You have failed to escaped" << endl << endl;
		}
	
		if (r == 3){// if the random function is 3 then you escape the Zombie Encounter.
			cout << "You have escaped" << endl;
			break;
		}
	}

	if (choice == "I" || choice == "i") { // if the input is 'I' or 'i' then it displays your inventory.
		
		int	numberofitems = m_user->displayItems(); // calls the display of items.

		if (numberofitems <= 0) { // displays this meesage if no items are present.
			cout << "You have no items in your inventory...." << endl;
		
		}
		else { // if you have items it asks what items you would like to use.

			int itemchoice;//store the choice.

			cout << "What item would you like to use?" << endl;
			cin >> itemchoice; // users choice

			itemchoice = itemchoice-1; //arrays start at 0, shhh don't tell user(makes the display items start at 1 instead of 0.

			m_user->itemSelect(itemchoice); // adds items attack to the users attack.
			m_pattack = m_user->getplayerAttack();// gets the players attack.
			userAttack();//calls the users attack.
			cout << endl << "You hit the zombie!!!" << endl << endl;
			m_user->deitemSelect(itemchoice);//deselects the item so if you select another item it will not add attack on attack and so on. 
		}

	}
	
	
	if (m_zhealth < 0){ // if the zombies health is less then zero.
		cout << "You defeated the zombie! Your health is currently: " << m_phealth << endl;
		break;
	}
	
	enemyAttack(); //  the enemy's attack is called.

	m_user->resetPHealth(m_phealth); // grabs the players health.

	cout << "The zombie attacks! your health is currently: " << m_phealth << endl << endl;

	}
 return choice;// returns what they choose.
}