#ifndef storyclass_H
#define storyclass_H
#include <iostream>
#include <string>
#include <cctype>
#include "playerclass.h" 
#include "zombieclass.h"
#include "combat.h"
#include "story.h"


using namespace::std;

class StoryGroup
{
public:
	void intro();//where it goes to check if there is a fightscene.
	//void supplies ();
	StoryGroup(player *user);//where all the story is held in strings.
	int fightScene1();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene2();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene3();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene4();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene5();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene6();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene7();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene8();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene9();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene10();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene11();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene12();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene13();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene14();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene15();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene16();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene17();//an fight scene where it calls the combat class and goes in a battle.
	int fightScene18();//an fight scene where it calls the combat class and goes in a battle.
	
	
private:
	player *m_player;//passes in the player to be used in the story so items and teammembers can be added.
	Story m_story[200];//the array the story is held.
	int m_phealth;//players health is passed in to see if the players health is less then zero, then it goes to a game over screen.
	int m_setphealth;

};

#endif
	
