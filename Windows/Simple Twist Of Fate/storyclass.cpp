#include <iostream>
#include <string>
#include <cctype>
#include "storyclass.h" 
#include "zombieclass.h"
#include "combat.h"
#include "story.h"
using namespace std;



StoryGroup::StoryGroup(player *user)//Constructor and where all the strings are located from the story.
{
	m_player = user;
	m_phealth = m_player->getplayerHealth();
	m_setphealth = m_player->resetPHealth(m_phealth);
	
	//Below is a string entered into the array called m_story and placed in postion 0.
	string dodo = " I woke up, disoriented trying to remember where I was. It all came back to me at once it was ten days ago that everyone I knew became a zombie. My friends, family they were all dead. We had been at Wal-Mart when it started, and at that instant my life would never be the same. I don't know what happened but the way that everyone seemed to become infected at once, I think it was a bomb. I don't know why I was spared but I wish I wasn't. In the past ten days I haven't seen another human soul. I have given up hope of survivors in this town. Should move on [M] or should I get supplies first [S]. *";
	m_story[0].addStory(dodo, 1,2);

	dodo = " No, I shouldn't waste time looking for supplies in this little crap-hole that was once Churchill. I should move north into Barrie. I can't drive because the roads are filled with the cars of people now wandering the earth aimlessly. Luckily I still have my bicycle in the garage. I can use that to bike up route twelve to Barrie [B] or should I perhaps, for safety reasons bike to the Lake and steal a boat, and cruise to Kempenfelt Bay [K]. *";
	m_story[1].addStory(dodo, 3,4);

	dodo = " I look at my supplies. I realize that I am short on two things, weapons and food. To get food I could use my bike and ride to Picard's Deli on Limerick Street [D] but that could be dangerous without weapons. Perhaps first I should go to Wild Wild West Apparel and try and find a revolver [W]. *";
	m_story[2].addStory(dodo, 5,6);

	dodo = " I go to the garage to find my bike. I find a crowbar and a knapsack. I put the crowbar in my knapsack. I quickly find my bike and start down route twelve. Luckily it isn't as congested as I had thought, so I move through the road without much difficulty. I would occasionally see a zombie on the side of the road but they gave me no trouble. My plan was going well until I came to a fork in the road. I did not know what direction to go Left [L] or Right [R]. *";
	m_story[3].addStory(dodo, 7,8);
	m_story[3].addItem("Crowbar", 3);
	//above is an example of an Item being added into the story at postion 3 in the array.(its also very simular to adding an TeamMember)

	dodo = " I go to the garage to find my bike. I find a crowbar and a knapsack. I put the crowbar in my knapsack. Quickly after, I find my bike and start down to the lake. When I get there I start to look for a boat. I wonder if I should pick a motorboat [M] or sailboat [S]. *";
	m_story[4].addStory(dodo, 9,10);
	m_story[4].addItem("Crowbar", 3);
	
	dodo = " I go to the garage to find my bike. I find a crowbar and a knapsack. I put the crowbar in my knapsack. I quickly find my bike and start down to the Picard's Deli. When I get there the door is locked so I smash it with my crowbar. As soon as I smashed it I hear a woman scream. It was Mary Picard!! I had found a survivor. She came running. She has a gun. She fires a shot. Thank God! It missed. Then she realizes that I am a human. She breaks down in tears. Apparently she has been hiding in her store since the beginning. She wants to come along with me should I let her [C] or should I talk to her more first [H]. *";
	m_story[5].addStory(dodo, 11,12);
	m_story[5].addItem("Crowbar", 3);
	m_story[5].addTeam("Mary Picard", 2);

	dodo = " I go to the garage to find my bike. I find a crow bar and a knapsack. I put the crowbar in my knapsack. I start biking to Wild Wild West Apparel. As I arrive at Wild Wild West Apparel, I see that there are Zombies dressed as cowboys everywhere. I decide that the best course of action is to run into the store and quickly find a gun to kill the zombies. I get by the zombies ok, but when I get into the store I realize it's a clothing store with no guns! [C] *";
	m_story[6].addStory(dodo, 95);
	m_story[6].addItem("Crowbar", 3);

	dodo = " As I turn to the left my bike gets something lodged into it's spokes. I go over the handlebars and break my neck. I know death will quickly follows. At least I won't become a zombie. *";
	m_story[7].addStory(dodo, -1,-1);

	dodo = " I take a right turn; thank god it was the right decision. Soon I am at Maple View Drive. I look to my left and see the Barrie Molson Center. I enter thinking that I could get a hockey stick to use as a weapon. As I enter I notice that it is devoid of any zombies could this be a sign that there are survivors killing zombies in Barrie? God I hope so. I find my self in the Colts' locker room I see a hockey stick, I grab it. I look around for other useful things. I find a hockey skate. I break the blade off of the skate. I look some more and soon find hockey tape. I tape the blade to the hockey stick to create a crude axe.[C] *";
	m_story[8].addStory(dodo, 97);
	m_story[8].addItem("Crude Axe", 10);
  
	dodo = " I jump into the nearest motorboat. I start the motor, the noise attracts zombies. I get out of there as fast as I can. I am in the middle of Kempenfelt Bay and I run out of gas. I was in such a hurry to leave I didn't bring any paddles. I decide try and swim to shore. Bad Idea, it's foggy. I get lost in the fog and drown. *";
	m_story[9].addStory(dodo, -1,-1);

	dodo = " I look around to find a suitable sail boat. I find one that looks like it will fit the bill. I arrive at Johnsons beach in less than three hours thanks to a nice breeze. I need to decide where to set up camp, on the beach [B] or if I should break into one of these abandoned houses [H]. *";
	m_story[10].addStory(dodo, 15,16);

	dodo = " I let her come along. She has a motorcycle. We quickly travel to Barrie. She says her brother lives here and that we should go to his house. I agree, feeling tired I was in no mood to fight about it. We pull in to a quaint little bungalow. As I head up the steps I can tell that it has been abandoned and her brother, is likely dead. She knocks, nobody answers. I kick in the door. After a quick search of the house she realizes, he's gone. She wants to stay and wait for her brother [B]. I just want to get the hell out of here [O]. *";
	m_story[11].addStory(dodo, 18,17);

	dodo = " She starts to tell me her story. She was at home when it started. In a mere instant she was the only member of her family who hadn't become a zombie, she didn't know why. She came to the only other place that she had ever felt safe her deli and has been living here ever since. I decided that I had heard enough and that we should get moving. She says has a motorcycle. We quickly travel to Barrie. She says her brother lives here and that we should go to his house. I agree, feeling tired and I was in no mood to argue. We pull in to a quaint little bungalow. As I head up the steps I can tell that the house has been abandoned and her brother is likely dead. She knocks, nobody answers. I kick in the door. After a quick search of the house she realizes he's gone. She wants to stay and wait for her brother [B]. I want to get the hell out of here [O].   What should we do? *";
	m_story[12].addStory(dodo, 18,17);
 
	dodo = " As I drive past Wal-Mart on my way to Sojourn, I start to have second thoughts. Why should I drive further out of my way when Wal-Mart is right here? I remember that it would probably be better to get well made outdoor gear than the crap Wal-Mart sells. I turn right on to Commerce Park Drive. I am relived to see a startling lack of zombies at Sojourn. I enter the store; luckily the automatic doors still work. I start to pull everything I need off of the shelf: a tent, some clothes, a beautiful knife, water purification tablets, an axe. I decide that this is as safe as any place to take a nap and settle down in a sleeping bag. I wake up several hours later refreshed and happy with the progress that I have made so far. Now I have to find a place to set up a base. I have to make the decision if I should set up in a commercial building [C] or if I should go to a more traditional home style base [H].   *"; 
	m_story[13].addStory(dodo, 19,20);
	m_story[13].addItem("Knife", 5);
	m_story[13].addItem("Axe", 7);

	dodo = " I drive to Wal-Mart and leisurely pull open the door. As I stroll through the aisles, I hear a faint rustling behind me. I pay little attention to it assuming that it was just some rat or mouse. Then it starts to get louder, and louder. I grab a bat from the shelf. I feel something watching me waiting. I yell 'Come out and fight', then laughter. I didn't know if it was mine or whatever was watching me. Then I see two zombies coming at me, both Wal-Mart greeters. [C] *";
	m_story[14].addStory(dodo, 100);
	m_story[14].addItem("Bat", 3);
	
	dodo = " I fall asleep on the beach. I never wake up. *";
	m_story[15].addStory(dodo, -1,-1);

	dodo = " I start to search for an abandoned house.[C] *";
	m_story[16].addStory(dodo, 102);

	dodo = " It takes a lot of convincing but finally she agrees that we need to leave. We discuss where we should go. She wants to investigate the malls to look for survivors like in the movie Dawn of the Dead. This works for me as I want to gather supplies. I ask what mall we should go to Bayfield [B], Georgian [G], or Kozlov [K]. She replies: *"; 
	m_story[17].addStory(dodo, 23,24,22);

	dodo = " So we wait. The minutes dragged on. I was reading one of her brother's books. It was called 'The Fountains of Paradise' by Arthur C. Clarke. Mary had put some music on; apparently Barrie still had some remnants of power. We waited nothing happened. I decide it would be best get a couple hours of sleep. I woke up to a mixture of crying and screaming. I ran down stairs. I had slept longer than I had thought it was 4:00am I fell asleep as 8:00pm. I got to the basement to see Mary crying at the motionless body of a zombie. It was her brother he had returned home guided by some form of basic instinct. She was sobbing like no one I had heard be for. I said she should sleep. I had to make a decision. Move on or stay here and make a base out of this house [B] or move on and go somewhere else.[S] *";
	m_story[18].addStory(dodo, 21,22);

	dodo = " I decide that a commercial building with stocked shelves would be the best option. Since I'm here already, I decide Sojourn would be a great place to set up. I tie up the doors using some of the rope in the store. I glad that I decided to stay here with all the lanterns and heaters. I start to explore the store and hear something in the back room. [C]. *";
	m_story[19].addStory(dodo, 105);
	m_story[19].addItem("Lantern", 6);

	dodo = " Better to go to a house with limited entry points. I exit Sojourn and see a horde of zombies coming towards me. I run to my bike. I jump on it. As I start leaving I look behind. They seem to have lost interest in me. I turn and realize a zombie was right in front of me. We collide. Luckily the impact was enough to kill it, but my bike is ruined. I start running. The zombies are slowing following me. I'll be safe no where. Should I keep going to a house [H] or should I stay and fight [F]? *";
	m_story[20].addStory(dodo, 27,28);

	dodo = " We decide that to stay would be most beneficial to our future. This was a mistake as two days later when we fell asleep, zombies got in to the house. I woke up she didn't [C] *";
	m_story[21].addStory(dodo, 106);
	
	dodo = " She says Kozlov. As we get on the highway we realize that the streets are too congested with cars to get anywhere on her motorcycle. We start driving on the shoulder of the road. A zombie dives in front of our wheel. We flip. She breaks her neck. I break a leg. Zombies attack me. I am helpless. I become one of them. *";
	m_story[22].addStory(dodo, -1,-1);

	dodo = " She says that Bayfield is the best place to go because of how close it is to the highway. We hop on her motorcycle and head down the highway. As we pull off on Bayfield Street The mall appears empty. Zombies are spread sporadically around the doors. To get in we will have to kill some zombies. [C] *";
	m_story[23].addStory(dodo, 108);
 
	dodo = " She says Georgian. As we get on the highway we realize it is to congested with cars to get anywhere on her motorcycle. So we try driving on the shoulder of the road but quickly a zombie dives in front of our car she swerves, flipping us. She breaks her neck. I break a leg and I am quickly attacked by zombies. *";
	m_story[24].addStory(dodo, -1);

	dodo = " I explore the store looking for supplies and zombies. I find nothing. This is surprising. It appears somebody else was here and took all important supplies. I realize that this could mean that there are other survivors. I must try to find them. I look around for some sort of message. I find one! It says 'If anyone finds this go to the Bayfield mall. My group of survivors is heading there.' Should I go to them [G] or not [N]? *";
	m_story[25].addStory(dodo, 31,32);

	dodo = " I assume that I'm okay. I fall asleep. I never wake up, what did you think would happen? *";
	m_story[26].addStory(dodo, -1,-1);

	dodo = " I keep looking for a house. I am aimless. I keep second guessing myself. I slow down. A zombie grabs me. [C] *";
	m_story[27].addStory(dodo, 110);

	dodo = "  I jump off my bike. A zombie lunges at me. [C]*";
	m_story[28].addStory(dodo, 113);

	dodo = " Because of the relative lack of zombies we decide to split up. She takes the upper floor. I take the lower floor and movie theater. I check all of the stores without much incident. I enter the movie theater. I feel a sense of dread building inside of me. I enter theater four. I hear something. I turn with a start thinking that it's a zombie but it's a human. He introduces himself as Dr. Hawks. He tells me that he is not alone there is another survivor in the mall. I tell him that I have someone here with me as well. He tells me to go get her. I agree but ask where we should meet. he say's its up to me, the ticket booth at the theater [B] or at the door to the Winners [W]? *";
	m_story[29].addStory(dodo, 35,36);
	m_story[29].addTeam("Dr. Hawks", 5);

	dodo = " We decide to stick together for safety reasons. We check all the stores on the lower level without much incident but when we get upstairs and start to check the food courts we notice something. We notice that there are zombies everywhere! We can't stay here. We start to run to the front entrance but it has been cut of by zombies we're trapped. What should group of zombies should we face the front entrance zombies [F] or the food court zombies [C]? *";
	m_story[30].addStory(dodo, 37,38);

	dodo = " I decide that it's for the best if I go to Bayfield. I hop on my bike. I bike to the highway. The mall appears empty. Zombies are spread sporadically around the doors. To get in I will have to kill some zombies. [C] *";
	m_story[31].addStory(dodo, 114);

	dodo = " I decide not to go to the Bayfield mall not knowing how long ago that note was written. I go outside and start on my mission to rid the world of all its zombies. I look down at my arsenal of weapons and realize I don't have enough to kill all the zombies. I decide that there is no hope for me in this world and I run wildly into the nearest crowd of zombies.[C] *";
	m_story[32].addStory(dodo, 116);

	dodo = " I assume that I'm okay and fall asleep. I never wake up, what did you think would happen? *";
	m_story[33].addStory(dodo, -1,-1);

	dodo = " I decide to search now. I start by checking the lower floor and Movie Theater. I check all of the stores, empty. I enter the movie theater. I feel a sense of dread starting to build inside of me. I enter theater four. I hear something. I turn with a start thinking that it's a zombie but it's a human. He introduces himself as Dr. Hawks. He tells me he is not alone. He says that there are two more survivors in the mall. I ask where they are and where we need to go to meet up with them. He replies what? the ticket booth at the theater [B] or the door to the Winners [W]? *";
	m_story[34].addStory(dodo, 39,40);
	m_story[34].addTeam("Dr. Hawks", 5);

	dodo = " I tell him that we'll meet in at the ticket booth, he agrees. I run to find Mary and tell her about this amazing development. I find and tell her, she doesn't believe it. We run to the ticket booth. Dr. Hawks lied to me!! There's not just one more survivor in the mall but twenty more. It was a trap. They grab all of our supplies and throw us out to the zombies. We were no match for the zombies with out our gear. *";
	m_story[35].addStory(dodo, -1,-1);

	dodo = " I tell him that I'll meet in at Winners. I run to find Mary and tell her about this amazing development. I find her. I tell her, she doesn't believe it. We run to Winners. We get arrive there. Dr. Hawks is waiting with his fellow survivor. He introduces her as Mrs. McNulty. He explains how after the disease started to spread, he and his research partners stole one of their hospital's ambulances to escape. They had no real plan as to where they were going so when they saw the relatively abandoned mall they settled here. At first there were four survivors but as they were clearing the mall of zombies, two of their friends caught the disease. This was five days ago. We started to talk about what we should do now as it seems we are the last surviving humans on earth. Should we go to the other malls looking for survivors than get out of town [m] or should we just get out of town and start killing zombies [Z]. *";
	m_story[36].addStory(dodo, 41,42);
	m_story[36].addTeam("Mrs. McNulty", 5);

	dodo = " He tells me to follow him to the ticket booth. We walk to the ticket booth. Dr. Hawks appeared to have lied to me because there was not just two more survivor but twenty more. It was a trap. They grabbed all of my supplies and threw me out to the zombies. A zombie grabs me and I bop him on the head with the only thing I have left, my shoe. I'm hopping because I don't want to step on the broken glass that is spread around the ground. A zombie takes the shoe out of my hand. I pull off my shirt and start to choke a zombie with my shirt. The zombie's head pops off from the pressure applied to his neck. Unfortunately my shirt went flying with his head. I stood completely weaponless against a parking lot full of zombies. This is going to be interesting……*";
	m_story[39].addStory(dodo, -1,-1);

	dodo = "We run to Winners. Dr. Hawks is waiting for us with his fellow survivors. He introduces them as Mrs. McNulty and Mary Picard. He explains how after the disease started to spread, he and his research partners stole one of their hospital's ambulances to try and escape. They had no real plan as to where they were going so when they saw the relatively abandoned mall they settled here. At first there were five survivors but as they were clearing the mall of zombies, two of their friends caught the disease. This was five days ago. We start to talk about what we should do now as it seems we are the last surviving humans on earth. Should we look for survivors than get out of town [G] or should we just get out of town and start killing zombies [Z]. *";
	m_story[40].addStory(dodo, 41,42);
	m_story[40].addTeam("Mrs. McNulty", 5);
	m_story[40].addTeam("Mary Picard", 5);

	dodo = "We decide that the best thing we can do is to search the town for other survivors. We have a discussion about where to search. I say that we should search the other malls for people like ourselves. Dr. Hawk suggests that we should check all of the schools in the area for stranded students. Mary and Mrs. Mcnulty both suggest that a house by house search of the east end would be best. What should we do search the malls [M] search the High schools [H], or do a sweep of the east end [E]? *";
	m_story[41].addStory(dodo, 43,44,45);

	dodo = "We decide that we have to get out of town. We have to decide the best way to get out of town. We can't take a car because of the congested roads. We decide that we should take four bicycles from Canadian tire. We have to decide whether to go north [N] or south  [S]? *";
	m_story[42].addStory(dodo, 46,47);

	dodo = "We decide that searching the malls is the best way to find survivors. We need to pick a mall to search first Georgian [G] or Kozlov [K]? *";
	m_story[43].addStory(dodo, 48,49);

	dodo = "We decide that searching the High Schools is the best way to find survivors. We need to pick a school to search first Eastview [E], Central [C], or North [N]? *";
	m_story[44].addStory(dodo, 50,51,52);

	dodo = "We decide to do a sweep of the east end, house by house. Should we start at Duckworth St. and go east [E] or should we start at Georgian Drive and go south [S]? *";
	m_story[45].addStory(dodo, 53,54);

	dodo = "We decide to go north towards Midland, we need to decide which way to take, should we take High 400 up to highway 12[H] or should we take highway 26 until it turns off into highway 25 [W]. *";
	m_story[46].addStory(dodo, 56,55);

	dodo = "We decide to go south towards New Market. We need to decide on the safest route to New Market. Do we take the 400 and get off on highway 88[H] do we take highway 27 until highway 9[W] *";
	m_story[47].addStory(dodo, 57,58);

	dodo = "We decide to search the Georgian mall. We enter, we split up into two groups. Mary and I take the bottom floor and Sears. Dr. Hawk and Mrs. McNulty take the upper floor and the Bay. Thankfully they are not a lot of zombies and they haven't congregated into a single group. [C]. *";
	m_story[48].addStory(dodo, 59,60);

	dodo = "We decide to check out the Kozlov mall. Big mistake there are more zombies here than I have ever seen before. They cut off our retreat. We stand, facing hundreds upon hundreds of zombies. Well, only one way to solve this.[C] *";
	m_story[49].addStory(dodo, 122);

	dodo = "We decide that the best thing that we could do ss to check Eastview, it being close to so many houses. When we arrive we notice something interesting, there are no zombies. We wander through the halls yelling 'Is anyone here'. Nobody answers. We enter the Cafetorium we hear an answer it faint and may not be human should we investigate [Y] or [N] *";
	m_story[50].addStory(dodo, 61,62);

	dodo = "We decide that the best thing that we could do is to check Central first, it being located close to downtown. We arrive and enter the school. There are people here but they are hostile. They capture us. We ask them about our fate. They laugh mercilessly…*";
	m_story[51].addStory(dodo, -1,-1);

	dodo = "We decide to go to north, we never make it, its too far. *"; 
	m_story[52].addStory(dodo, -1,-1);
	
	dodo = "We start in at Duckworth and head east. We find no one in the entire east end, we decide to check Eastview when we're here [E] *";
	m_story[53].addStory(dodo,50);

	dodo = "We start in at Georgian Drive and head south. We find no one in the entire east end we decide to check Eastview when were here [E] *";
	m_story[54].addStory(dodo,50);

	dodo = "We die because we have no idea what were doing. *";
	m_story[55].addStory(dodo, -1,-1);

	dodo = "We die because we have no idea what were doing! *";
	m_story[56].addStory(dodo, -1,-1);

	dodo = "We die because we have no idea what were doing! *";
	m_story[57].addStory(dodo, -1,-1);

	dodo = "We die because we have no idea what were doing! *";
	m_story[58].addStory(dodo, -1,-1);

	dodo = "We decide to check the Schools. We settle on checking eastview [E]*";
	m_story[59].addStory(dodo, 94);

	dodo = "We go to Kozlov, Big mistake there are more zombies here than I have ever seen before. They cut off our retreat. We stand, facing hundreds upon hundreds of zombies. Well, only one way to solve this. [C] *";
	m_story[60].addStory(dodo, 124);

	dodo = "We decide that it is worth while to investigate. We start checking under every bench and table we look in the attached room like the kitchens, then it hits us the stage! We run and start to check behind the curtain and there he is. A boy with a shotgun attached to his back. We can't tell if he's asleep or passed out from exhaustion. We decide to approach him. We need to know the best way to approach him. We have to make a decision, do we take his shotgun and wake him up [W] or just wake him up so we don't frighten him by taking his weapons [F].  *";
	m_story[61].addStory(dodo, 63,64);

	dodo = "We decide not to investigate it. It's probably just a cat or something like that. We decide to go to the gym and get some weapons. We pick up a bat, hockey stick and a net so that if we ever decide to try and capture a zombie we can. We start to leave when we the much louder sound of a shot gun blast we have to make the decision of whether to investigate [Y] or not [N]. *";
	m_story[62].addStory(dodo, 65,66);
	m_story[62].addItem("Bat", 3);
	m_story[62].addItem("Hockey Stick", 4);
	m_story[62].addItem("Net", 1);

	dodo = "We decide that the risk of him being surprised and shooting us is too great to ignore. We carefully remove his shotgun. We nudge him nothing happens. We nudge him a little more, he starts to stir. We nudge him for a third time. He wakes up; he is surprised but not hostile. He says he understands why we had to take his weapon from him but politely asks for it back. Do we give it to him yes [Y] or no [N]. *";
	m_story[63].addStory(dodo, 67,68);
	m_story[63].addItem("Shotgun", 15);

	dodo = "We decide that the risk of him shooting us is minimal and we don't want him to feel like were trying to kill him. We nudge him, nothing happens. We nudge him a little harder,he starts to stir. We nudge him for a third time. He wakes up; he is surprised he pulls his weapon on us. We tell him to put it down, he tells us to explain ourselves. Do we volunteer to put our weapons down if he puts his down [D] or do we demand that just he put his weapon down [W]. *";
	m_story[64].addStory(dodo, 70,69);

	dodo = "We run to the Cafetorium, where the sound originated. We see a teenage boy, he shoots several zombies on the stage. We run to help but don't want to risk getting caught in the crossfire. He easily kills the remaining three zombies. We sees us, we declare ourselves as human as quickly as we can. He asks who we are and why we are here. We explain and ask who he is he says he will only tell us if we all put our weapons down including himself. Do we [W] or don't we [D]? *";
	m_story[65].addStory(dodo, 71,72);

	dodo = "We decide that it is too dangerous to investigate, not wanting to get caught in the crossfire. Unfortunately the boy with the shot gun came running out of the door that we had just passed and mistaking us for zombies open fired. He was quick and only realized his mistake at we had already died …*";
	m_story[66].addStory(dodo, -1,-1);

	dodo = "We decide he seems friendly enough, so we give him his gun back. He thanks us and starts to tell us his story. He told us that his name was Tom. When the plague hit he had been at his home. Not knowing what to with himself he grabbed his father's shotgun. He then ran to his school, which was the only place he could think to go. He had been surviving here alone. There was plenty of food left in the café and the internet and power still worked so he could get news. At this we all asked him what was happing as we had all been cut off for several weeks. He starts to tell us that there is still a safe colony in Little Abitibi Provincial Park. It had about 2500 survivors. We ask him if he has been in contact with them. He says no. We ask him why he says there isn't a way to get in contact with them except to go their in person. We ask him why he hasn't attempted to get there. He replies he has no way to travel there. We decide we need to head there. We wonder whether we should invite him [H] or not [N] *";  
	m_story[67].addStory(dodo, 73,74);

	dodo = "We decide that it is not entirely safe to give him his weapon back yet. He acknowledges why we could fell this way. He then begins to tell us his story. He told us that his name was Tom. When the plague hit he had been at his home. Not knowing what to with himself he grabbed his father's shotgun. He then ran to his school which was the only place he could think to go. He had been surviving here alone. There was plenty of food left in the café and the internet and power still worked so he could get news. At this we all asked him what was happing as we had all been cut off for several weeks. He starts to tell us that there is still a safe colony in Little Abitibi Provincial Park. It had about 2500 survivors. We ask him if he has been in contact with them. He says no. We ask him why he says there isn't a way to get into contact with them except to go their in person. We ask him why he hasn't attempted to get there. He replies he has no way to get there. We decide we need to head there. We wonder whether we should invite him [H] or not [N] *";
	m_story[68].addStory(dodo, 73,74);
 
	dodo = "We're at a deadlock neither my group of survivors nor the boy will put their weapons down. All of a sudden a loud bang is heard, nobody knows what it is. We think that the boy has a partner somewhere shooting at us. People start to shooting. Everyone is fatally wounded, the boy is dead. We still don't know what the bang was. *";
	m_story[69].addStory(dodo, -1,-1);

	dodo = "We're at a deadlock neither my group of survivors nor the boy will put their weapons down. All of a sudden a loud bang is heard, nobody knows what it is. We think that the boy has a partner somewhere shooting at us. People start to shooting. Everyone is fatally wounded, the boy is dead. We still don't know what the bang was. *";
	m_story[70].addStory(dodo, -1,-1);

	dodo = "We decide that he best thing to do is for all of us to put our weapons down. He then begins to tell us his story. He told us that his name was Tom. When the plague hit he had been at his home. Not knowing what to with himself he grabbed his father's shotgun. He then ran to his school which was the only place he could think to go. He had been surviving here alone. There was plenty of food left in the café and the internet and power still worked so he could get news. At this we all asked him what was happening as we had all been cut off for several weeks. He starts to tell us that there is still a safe colony in Little Abitibi Provincial Park. It had about 2500 survivors. We ask him if he has been in contact with them. He says no. We ask him why he says there isn't a way to get into contact with them except to go their in person. We ask him why he hasn't attempted to get there. He replies he has no way to get there. We decide we need to head there. We wonder whether we should invite him[H] or not[N]. *";
	m_story[71].addStory(dodo, 73,74);
 
	dodo = "We're at a deadlock neither my group of survivors nor the boy will put their weapons down. All of a sudden a loud bang is heard, nobody knows what it is. We think that the boy has a partner somewhere shooting at us. People start to shooting. Everyone is fatally wounded, the boy is dead. We still don't know what the bang was. *";
	m_story[72].addStory(dodo, -1,-1);

	dodo = "We tell him that we're going to go there. We say that he is welcome to come. He laughs and says 'How do you think your going to travel several hundred kilometers with out being able drive a car.' I answered with out really thinking 'We'll fly' He agrees to come with us. I realized that too do this we will need both a plane and a pilot. There are two places we could go to the small Barrie Airport [A] or Base Borden [B] at both of these places there will be planes and hopefully a pilot. *";
	m_story[73].addStory(dodo, 75,76);
	m_story[73].addTeam("Tom", 5);

	dodo = "We decide that since we just met him it would be best if we didn't tell him our plan. We told him thank you for the information and that we would leave him alone. He says that we didn't half to leave but we told him that we had somewhere to be. After we left we realized that we didn't know a way to get to the safe haven. We discussed it briefly. We decided that we had to options. We try and find four motorcycles [M] or we take the route risky of using bicycles [B]. *";
	m_story[74].addStory(dodo, 76,77);

	dodo = "We decide that it would be safer to go to the Barrie airport so as to not risk running into any military types. We arrive and talk about what we need. We decide that two things need to be done immediately. We need to find a plane [A] and find a pilot[P]. What should we do first? *";
	m_story[75].addStory(dodo, 78,79);

	dodo = "We decide that we should go to base Borden because they will not only have planes but they will also have weapons. We arrive at the base to find the gate down. Should we turn back[B] or go through[G] *";
	m_story[76].addStory(dodo, 80,81);

	dodo = "We decide to use our motorcycles. However Mary is the only member of the group with any real experience. When we were on the highway I got to close to her clipping her back wheel. We both went flying and took out the other two. We all had broken at least one of our legs and we're trapped. The zombies come, I can only watch helplessly as all my friends in the world get turned into zombies until finally I join them. *";  
	m_story[76].addStory(dodo, -1,-1);

	dodo = "We decide to just use bikes and undertake the long voyage. Several Days into our voyage people in our group start to disappear one by one. I become the last person left. I get taken two weeks into our voyage, and that was it. *";
	m_story[77].addStory(dodo, -1,-1);

	dodo = "We decide to look for a plane but can't find any. We do find a wrench. So we decide to start looking for a pilot [P] *";
	m_story[78].addStory(dodo, 79);
	m_story[78].addItem("Wrench", 3);

	dodo = "We start looking for a pilot. We split up to search the buildings.[C]*";
	m_story[79].addStory(dodo, 127);

	dodo = "We decide to turn back and go to the Barrie airport [A] *";
	m_story[80].addStory(dodo, 75);

	dodo = "We decide to go through anyway. When enter. We are immediately stopped by a man in uniform. He tells us that we are in restricted area and need to leave. What should we do should we yell at him for not helping us and other survivors [S] or should we ask to be taken to who's in charge [A]. *";
	m_story[81].addStory(dodo,83,84);

	dodo = "We approach him. He doesn't hear us say hello to him. In a instant he see's us. He is surprised. He puts handcuffs on us and takes us to Base Borden. [B] *";
	m_story[82].addStory(dodo,85);

	dodo = "To hell with it, these people have been here this whole time and never made an attempt to help any of us. I start yelling. I don't know fully what I'm saying but it all comes out. All of the emotion that I've been feeling for the past few weeks comes out. After I finished the man is just staring at me. He's going to contain us as a threat to the mission. We arrive at a small room. He leaves locking the door behind him. Should we try and escape [E] or should we start banging on the door asking to see who's in charge [W]. *";
	m_story[83].addStory(dodo,85,84);
  
	dodo = "We fear for our lives. We decide that we need to escape. There is a window on the wall. It looks breakable. I take out the crowbar I had found in my garage. The window shatters. This is a loud clanging. We set off an alarm. We get out of the room. We have to choices we can run [R] or hide [H]. *";
	m_story[85].addStory(dodo,86,87);
 
	dodo = "Nowhere in this base is safe. We need to get out of here. We need to run. We start running. We get separated. I get captured. I ask about the others. They say they were killed trying to escape. They say I'm next. They strip me of all my supplies. They put me in a pit. Zombies start appearing in the pit. I do my best but its no use. I'm tired. I give up. *";
	m_story[86].addStory(dodo,-1,-1);

	dodo = "We start running looking for places to hide. There are only two real options. The armory[A] or some office building [O] *";
	m_story[87].addStory(dodo,88,89);

	dodo = "We run into the armory. There are two men in it. They see us. We try to explain we're not here for the weapons. They don't listen. They open fire. *";
	m_story[88].addStory(dodo,-1,-1);
 
	dodo = "We run into the office building. It appears to be some sort of research facility. We hid in a closet. We look out into the room by cracking open the door. We hear the sound of someone being attacked. We see a scientist fending off a zombie. Should we help [H]  or stay hidden [S] *";
	m_story[89].addStory(dodo,90,91);



	dodo = "We decide that we can't risk it. The scientist is killed. The zombie who did it wanders off. People come in and see the dead scientist. Minutes later they find us. They think that we killed the scientist. We try to explain but its no use. We get sentenced to be executed. *";
	m_story[91].addStory(dodo,-1,-1);
 
	dodo = "We are lead across the base to a small office. A man is sitting in at a small desk. He looks up. He asks who we are. Dr. Hawks tells him our story. He tells us to sit down. We ask him if he knows about the zombie free place up north. He laughs and tells us it doesn't exist it's just a rumor. We ask him what we should do. He tells us that we have two options we can stay here and help the military search for a cure[C] or we can leave now and never come back[L] *";
	m_story[84].addStory(dodo,93);
 
/*WTF??*/	dodo = "We decide that we will stay here and help. They swear us in. We're unable to find a cure but we do find a way to eliminated all the zombies in a 100 kilometer area with no danger to the human inhabitants. With this we are able to start up a new city and get a new start. *";
	m_story[92].addStory(dodo,-1,-1);
  
/*WTF??*/	dodo = "We can't live with these people who never came to help us. We leave never to be seen again. *";
	m_story[93].addStory(dodo,-1,-1);  
    
	dodo = " When we arrive we notice something interesting, there are no zombies. We wander through the halls yelling 'Is anyone here'. Nobody answers. We enter the Cafetorium we hear an answer it faint and may not be human should we investigate [Y] or [N] *";
	m_story[94].addStory(dodo, 61,62);


	dodo = "The zombies quickly surround me. I do my best with the crowbar but it is no use. I die. *"  ;
	m_story[96].addStory(dodo, -1);

	dodo = " That was close I should get out of here. Where should I go next Sojourn[S] for supplies or Walmart [W]for supplies? *";
	m_story[98].addStory(dodo, 13,14);

	dodo = " It doesn't matter that I was able to take that one down. Five more had now joined him in attacking me. I became one of them *";
	m_story[101].addStory(dodo, -1);

	dodo = " That was close. I continue my search. That zombie I killed seems to have had friends. I start running away from a horde that's chasing me. I fall. I am soon eaten. *";
	m_story[103].addStory(dodo, -1);
	
	dodo = " That was close. Should I explore the store to check for further zombies [E] or should I assume its safe [A]. *";
	m_story[104].addStory(dodo, 25,26);
		
	dodo = " the zombies were endless. I killed one and another took its place. Death greeted me.[C] *";
	m_story[107].addStory(dodo, -1);

	dodo = " She says that Bayfield is the best place to go because of how close it is to the highway. We hop on her motorcycle and head down the highway. As we pull off on Bayfield Street The mall appears empty. Zombies are spread sporadically around the doors. To get in we will have to kill some zombies. (Zombie encounter) (Zombie encounter) (Zombie encounter) We made it through. We briefly debate whether we should split up [U] or stick together [S] when we search the mall? *";
	m_story[109].addStory(dodo, 29,30);

	dodo = " I was able to fight that one off. there's another, there's another, there's another............ *";
	m_story[111].addStory(dodo, -1);

	dodo = " I was able to fight that one off. there's another, there's another, there's another.... *";
	m_story[113].addStory(dodo, -1);

	dodo = " I decide that it's for the best if I go to Bayfield. I hop on my bike. I bike to the highway. The mall appears empty. Zombies are spread sporadically around the doors. To get in I will have to kill some zombies. (Zombie encounter) (Zombie encounter) (Zombie encounter) I made it through. I briefly debate whether I should rest first [R] or search now. [S]?  *";
	m_story[115].addStory(dodo, 33,34);
	
	dodo = " there's another, there's another, there's another.... *";
	m_story[117].addStory(dodo, -1);

	dodo = " (Zombie encounter) there's one (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) till death *";
	m_story[119].addStory(dodo, -1);

	dodo = " After the search we meet back up at the food court. We found no one. We need to decide now whether to search the schools [S] or to check the Kozlov mall [K]. *";
	m_story[121].addStory(dodo, 59,60);

	dodo = " (Zombie encounter) there's one (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) there's another (zombie encounter) till death *";
	m_story[123].addStory(dodo, -1);

	dodo = " there's another, there's another, there's another.... *";
	m_story[125].addStory(dodo, -1);


	dodo = "At least it was alone. I find nothing but Mary comes running up to me. She says she saw a man in military uniform walking. I recall the group. We discuss what we should do. Do we approach and talk to him [A] or should we forget about flying and should we travel by land[L]. *";
	m_story[128].addStory(dodo, 82,77);

	dodo = " She gets up and asks who we are. We tell her about what has happened to us. She says that she will take us to their leader. [L] *";
	m_story[129].addStory(dodo,84);

	for (int i = 0 ; i <=129; i ++)//sets up the player for all the stories in the array.
	{
		m_story[i].setPlayer(user);
	}
}


void StoryGroup::intro()//where the story begins.
{

	int selection = 0;
	
	while (selection != -1)//checks to see if selection = -1 if it equals negative -1 then it doesn't go into the loop to check if there is a fight scene or not. If its not -1 it checks those if statments and then goes into a fightscene if that selection is selected.
	{
			
		if (selection != 99){ // if selection is not 99 then it calls the read story method from story.cpp if it is 99 ten it goes to the appropiate fight scene.
			selection = m_story[selection].readStory();
			
		}
		if(selection == 95 ){ // if selecton  = 95 then it goes to fightscene2(); and you Encounter a Zombie.
			selection = fightScene2();
		}
		if(selection == 97 ){// if selecton  = 97 then it goes to fightscene1(); and you Encounter a Zombie.
			selection = fightScene1();
		}
		if(selection == 100 ){// if selecton  = 100 then it goes to fightscene18(); and you Encounter a Zombie.
			selection = fightScene18();
		}
		if(selection == 102 ){// if selecton  =102 then it goes to fightscene3(); and you Encounter a Zombie.
			selection = fightScene3();
		}
		if(selection == 105 ){// if selecton  = 105 then it goes to fightscene4(); and you Encounter a Zombie.
			selection = fightScene4();
		}
		if(selection == 106 ){// if selecton  = 106 then it goes to fightscene5(); and you Encounter a Zombie.
			selection = fightScene5();
		}
		if(selection == 108 ){// if selecton  = 108 then it goes to fightscene6(); and you Encounter a Zombie.
			selection = fightScene6();
		}
		if(selection == 110 ){// if selecton  = 110 then it goes to fightscene7(); and you Encounter a Zombie.
			selection = fightScene7();
		}
		if(selection == 112 ){// if selecton  = 112 then it goes to fightscene8(); and you Encounter a Zombie.
			selection = fightScene8();
		}
		if(selection == 114 ){// if selecton  = 114 then it goes to fightscene9(); and you Encounter a Zombie.
			selection = fightScene9();
		}
		if(selection == 116 ){// if selecton  = 116 then it goes to fightscene10(); and you Encounter a Zombie.
			selection = fightScene10();
		}
		if(selection == 37 ){// if selecton  = 37 then it goes to fightscene11(); and you Encounter a Zombie.
			selection = fightScene11();
		}
		if(selection == 38 ){// if selecton  = 38 then it goes to fightscene12(); and you Encounter a Zombie.
			selection = fightScene12();
		}
		if(selection == 120 ){// if selecton  = 120 then it goes to fightscene13(); and you Encounter a Zombie.
			selection = fightScene13();
		}
		if(selection == 122 ){// if selecton  = 122 then it goes to fightscene14(); and you Encounter a Zombie.
			selection = fightScene14();
		}
		if(selection == 124 ){// if selecton  = 124 then it goes to fightscene15(); and you Encounter a Zombie.
			selection = fightScene15();
		}
		if(selection == 127 ){// if selecton  = 127 then it goes to fightscene16(); and you Encounter a Zombie.
			selection = fightScene16();
		}
		if(selection == 90 ){// if selecton  = 90 then it goes to fightscene17(); and you Encounter a Zombie.
			selection = fightScene17();
		}


	}
}

int StoryGroup::fightScene1(){//fightscene1


	//int i = 0;
//	while (i = 1){

		m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
		m_setphealth = m_player->resetPHealth(m_phealth);

		if (m_phealth <=0){
			return -1;
			//break;
		}

		zombie one(20,10,10);//sets up zombies attack, health, and defence.

		combat fight(m_player, one);// sets up user to be passed into the fight.
		fight.userTurn();//The actual fight is called here.

		m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
		m_setphealth = m_player->resetPHealth(m_phealth);
		
		if (m_phealth <=0){
			return -1;
			//break;
		}
		
	
		//i++;
	
//	}

	return 98;
}

	/*m_phealth = m_player->getplayerHealth();

	if(m_phealth >= 0){

	zombie one(30,100,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one); // sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.
	m_phealth = m_player->getplayerHealth();
	}


	return 98;
}*/

int StoryGroup::fightScene2(){	
	
		
	while (m_phealth >= 0){ // checks to see if users health is equal to or below zero if not it exits the loop

	zombie one(20,10,10);//sets up zombies attack, health, and defence.
	
	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	m_phealth = m_player->getplayerHealth(); // gets the users health after each loop and make sure thats the health going into the next loop.
	}
 	return 103;
}

int StoryGroup::fightScene3(){	

	zombie one(20,10,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	return 103;
}

int StoryGroup::fightScene4(){	

	zombie one(20,10,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	m_phealth = m_player->getplayerHealth();

	return 104;
}

int StoryGroup::fightScene5(){	

		int i = 0;
		while (i < 2){

		m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
		m_setphealth = m_player->resetPHealth(m_phealth);

		if (m_phealth <=0){
			return -1;
			//break;
		}

		zombie one(40,20,10);//sets up zombies attack, health, and defence.

		combat fight(m_player, one);// sets up user to be passed into the fight.
		fight.userTurn();//The actual fight is called here.

		m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
		m_setphealth = m_player->resetPHealth(m_phealth);
		
		if (m_phealth <=0){
			return -1;
			//break;
		}
		
	
		i++;
	
	}

	return 107;
}

/*	zombie one(30,100,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	return 107;
}
*/

int StoryGroup::fightScene6(){	

	int i = 0;
	while (i < 4){

		m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
		m_setphealth = m_player->resetPHealth(m_phealth);

		if (m_phealth <=0){
			return -1;
			//break;
		}

		zombie one(20,10,10);//sets up zombies attack, health, and defence.

		combat fight(m_player, one);// sets up user to be passed into the fight.
		fight.userTurn();//The actual fight is called here.
		
		
	
		i++;
	
	}

	return 109;
}

int StoryGroup::fightScene7(){	


	int i = 0;
	while (i < 10){

		m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
		m_setphealth = m_player->resetPHealth(m_phealth);

		if (m_phealth <=0){
			return -1;
			//break;
		}

		zombie one(20,10,10);//sets up zombies attack, health, and defence.

		combat fight(m_player, one);// sets up user to be passed into the fight.
		fight.userTurn();//The actual fight is called here.
		
		
	
		i++;
	
	}

	return 111;
}
/*

	zombie one(30,100,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	return 111;
}

*/
int StoryGroup::fightScene8(){	

	while (m_phealth >= 0){

	zombie one(20,10,10);//sets up zombies attack, health, and defence.
	
	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
	}

	return 113;
}

int StoryGroup::fightScene9(){	


	int i = 0 ;
	while (i < 4){

		m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
	//	m_setphealth = m_player->resetPHealth(m_phealth);

	//	if(m_phealth >= 0)
	//	{
	//		return -1;
	//	}
		zombie one(20,10,10);//sets up zombies attack, health, and defence.

		combat fight(m_player, one);// sets up user to be passed into the fight.
		fight.userTurn();//The actual fight is called here.
	
		m_phealth = m_player->getplayerHealth();
		
		i++;
	}

	return 115;
}

int StoryGroup::fightScene10(){	

	zombie one(20,10,10);//sets up zombies attack, health, and defence.
	
	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
	

	return 117;
}

int StoryGroup::fightScene11(){	

	m_phealth = m_player->getplayerHealth();

	while (m_phealth > 0){

	zombie one(20,10,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	m_phealth = m_player->getplayerHealth();
	}

	return -1;
}

int StoryGroup::fightScene12(){	

	zombie one(20,10,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	return 119;
}

int StoryGroup::fightScene13(){	

	zombie one(20,10,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	return 121;
}

int StoryGroup::fightScene14(){	

	zombie one(20,10,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	return 123;
}

int StoryGroup::fightScene15(){	

	zombie one(20,10,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	return 125;
}

int StoryGroup::fightScene16(){	

	zombie one(20,10,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	return 128;
}

int StoryGroup::fightScene17(){	

	zombie one(20,10,10);//sets up zombies attack, health, and defence.

	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	return 129;
}

int StoryGroup::fightScene18(){	

	while (m_phealth >= 0){

	zombie one(50,50,10);//sets up zombies attack, health, and defence.
	
	combat fight(m_player, one);// sets up user to be passed into the fight.
	fight.userTurn();//The actual fight is called here.

	m_phealth = m_player->getplayerHealth();// gets the users health after each loop and make sure thats the health going into the next loop.
	}

	return 101;
}