/* 
 * File:   main.cpp
 * Author: Joseph Cordoba
 * Created on December 5, 2013, 6:37 PM
 * Purpose: Revised, Version 3 : Adding + Clean Up
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//Global Constants and Variables
//Function Prototypes
void levSys(); //Experience table array
void mainMenu(int,int,int,int,int); //Displays MainMenu
char menuAns(); //Answer for MainMenu
void display(int&, int&); //Displays HP and Mob HP for Battle
int death(int,int&); //If player dies
int mobChk(int,int&); //If mob dies
int levUP(int, int); //If player levels up
int cont(int,int&,int&); //Continue after defeat of a monster
void retMenu(); //Return to main menu
char retAns(); //Answer to return for Main Menu
int calcScor(int&,string&); //Calculate Scores
void stats(int[],int); //Stat Roll
void prnStats(int[],int,int); // Print Stats 
void weather(int x=1, int y=2); //Weather


//Begin execution here
int main(int argc, char** argv) {
    //Declare Variables
    string name; //Nickname
    char choice,choice2, choice3, choice4,choice5, ans; //Choices for options on menus
    int baseHP, baseMP, baseAttk, maxHP=100, //Base stats for classes
        level, exp,// Leveling System
        bat, goblin, hatchlng, flymon, boss, kill, //Mobs/Monsters
        mobdmg, mobHP, //Battle System
        travel,basGold, gold, gold2, gold3, // Travel System
        score; //Scoring
    const int SIZE=5;
    int array[SIZE];
    bool b_done = false; //Exit game
    srand(time(NULL));
            
    //Welcome
    cout << "Hello! Welcome to the world of Some World!" << endl;
    cout << "Let's get your adventure started!" << endl;
    cout << "-----------------" << endl;
    //Input Nickname
    cout << "What is your nickname?" << endl;
    cin >> name;
    cout << "Ahh! So your name is " << name << 
            "! Let's continue, shall we?" << endl;
    cout << "-----------------" << endl;
    
    //Class Selection
    do{
    cout << "Please choose a class:" << endl;
    cout << "Enter 1 for Spellcaster!" << endl;
    cout << "Enter 2 for Warrior!" << endl;
    cout << "Enter 3 for Thief!" << endl;
    cout << "Enter 4 for Archer!" << endl;
    cin >> choice;
    cout << "-----------------" << endl;
    
    switch(choice){
        //Mage Selection
        case '1':{
            cout << "Congratulations! You have chosen a "
                    "path of intelligence and wisdom!" << endl;
            ans ='N';
        }
            break;
        //Warrior Selection
        case '2':{
            cout << "Alright! You have chosen a path of power and courage!" << endl;
            ans ='N';
        }
            break;
        //Thief Selection
        case '3':{
            cout << "Sneaky sneaky. You have chosen a path of thievery "
                    "and lurking!" << endl;
            ans ='N';
        }
            break;
        //Archer Selection
        case '4':{
            cout << "Bullseye! You have chosen a path of "
                    "accuracy and range!" << endl;
            ans ='N';
        }
            break;            
        //Wrong Selection
        default:
            cout << "Invalid selection! Please try again!" << endl;
            cout << "Y for Yes. N for No" << endl;
            cin >> ans;
            break;
        }
    }while(ans == 'Y' || ans == 'y');
    
    //Class Base Stats
    //Mage Starter Stats
    if (choice=='1'){
        cout <<"Your stats are: " << endl;
        cout << "HP: 100\n"; //Base Hitpoints
        cout << "Attack: 20\n"; //Base Attack
        baseHP=100; //Base
        baseAttk=20; // Base
        level = 1; // Base
        exp = 0; // Base
        basGold=100; //Base
    }
    
    //Warrior Starter Stats
    if (choice=='2'){
        cout <<"Your stats are: " << endl;
        cout << "HP: 100\n";
        cout << "Attack: 25\n";
        baseHP=100;
        baseAttk=25;
        level = 1;
        exp = 0;
        basGold=100;
    }
    
    //Thief Starter Stats
     if (choice=='3'){
        cout <<"Your stats are: " << endl;
        cout << "HP: 100\n";
        cout << "Attack: 20\n";
        baseHP=100;
        baseAttk=20;
        level = 1;
        exp = 0;
        basGold=100;
    }
    
     //Archer Starter Stats
     if (choice=='4'){
        cout <<"Your stats are: " << endl;
        cout << "HP: 100\n";
        cout << "Attack: 20\n";
        baseHP=100;
        baseAttk=20;
        level = 1;
        exp = 0;
        basGold=100;
    }
    
    //Main Menu
    do{
        if(baseHP<100){ //Reset HP
            baseHP=100;
        }
        if(baseAttk<20){ //Reset Attack
            baseAttk=20;
        }
        mainMenu(baseHP,baseAttk,level,basGold,exp); // Main Menu
        choice2=menuAns(); //Choice for Main Menu

    switch(choice2){
        //Travel
        case '1':{
        gold = (rand()%20)+5; //Random Gold for <=5
        gold2 = (rand()%30)+4; //Random gold for <=40
        gold3 = (rand()%50)+5; //Random Gold for >40
        
        cout << "How far would you like to travel?(Miles)\n";
        cin >> travel;
        if(travel<=5){
            cout << "You have traveled quiet a few miles and found " <<
                    gold << " pieces of gold!" << endl;
            basGold=gold+basGold;
            cout << "-------------------------"<< endl;
            retMenu();
            choice5=retAns();
                break;
        }
        else if(travel>5 && travel<=40){
                cout << "You have traveled a long way and found " <<
                        gold2 << " pieces of gold along the way!" << endl;
                basGold=gold2+basGold;
                cout << "-------------------------"<< endl;
                retMenu();
                choice5=retAns();
                break;
            }
        else if(travel>40){
                cout << "Hey! Where are you going! Come back!" << endl;
                cout << "You went on a journey and fought many monsters,"
                        "and gained " << gold3 << " gold pieces!" << endl;
                basGold=gold3+basGold;
                cout << "-------------------------"<< endl;
                retMenu();
                choice5=retAns();
                break;
                }
        }
    
    //Battle System, Option 2
        case '2':{
    cout << "Welcome!" << endl;
    cout << "Let's begin!" << endl;
    
    //Monster One - Bat
    mobHP = 15; //Mob Monster HP
    while (baseHP > 0 && mobHP > 0){
    mobdmg = (rand()%6)+1; //Mob Attack
    cout << "A wild Bat has attacked and did " << mobdmg 
            << " damage to you!" << endl;
    baseHP=baseHP-mobdmg; //Subtract from HP
    display(baseHP,mobHP); // Display HP for both
    death(mobHP,baseHP); //Check for death
    
    baseAttk = (rand()%baseAttk)+7;
    cout << "You've hit the monster and did " << baseAttk
            << " damage to it!" << endl;
    mobHP=mobHP-baseAttk; // Subtract from Mob
    display(baseHP,mobHP); //Display HP for both
    mobChk(mobHP,baseHP); //Check for Mob death
              }
    exp=5+exp; //Gain experience
    kill++;
    levUP(exp,level); //Check for level up
    
    cont(choice3,baseHP,maxHP);
    
    //Monster Two - Goblin
    mobHP = 30; //Mob Monster HP
    while (baseHP > 0 && mobHP > 0){
    mobdmg = (rand()%9)+1; //Mob Attack
    cout << "A wild Goblin has attacked and did " << mobdmg 
            << " damage to you!" << endl;
    baseHP=baseHP-mobdmg; //Subtract from HP
    display(baseHP,mobHP); // Display HP for both
    death(mobHP,baseHP); //Check for death
    
    baseAttk = (rand()%baseAttk)+7;
    cout << "You've hit the monster and did " << baseAttk
            << " damage to it!" << endl;
    mobHP=mobHP-baseAttk; // Subtract from Mob
    display(baseHP,mobHP); //Display HP for both
    mobChk(mobHP,baseHP); //Check for Mob death
              }
    exp=10+exp; //Gain experience
    kill++;
    levUP(exp,level); //Check for level up

    cont(choice3,baseHP,maxHP);
    
    //Monster Three - Hatchling
    mobHP = 35; //Mob Monster HP
    while (baseHP > 0 && mobHP > 0){
    mobdmg = (rand()%10)+2; //Mob Attack
    cout << "A wild Hatchling has attacked and did " << mobdmg 
            << " damage to you!" << endl;
    baseHP=baseHP-mobdmg; //Subtract from HP
    display(baseHP,mobHP); // Display HP for both
    death(mobHP,baseHP); //Check for death
    
    baseAttk = (rand()%baseAttk)+7;
    cout << "You've hit the monster and did " << baseAttk
            << " damage to it!" << endl;
    mobHP=mobHP-baseAttk; // Subtract from Mob
    display(baseHP,mobHP); //Display HP for both
    mobChk(mobHP,baseHP); //Check for Mob death
              }
    exp=15+exp; //Gain experience
    kill++;
    levUP(exp,level); //Check for level up
    
    cont(choice3,baseHP,maxHP);
    
    //Boss
    mobHP = 40; //Mob Monster HP
    while (baseHP > 0 && mobHP > 0){
    mobdmg = (rand()%12)+2; //Mob Attack
    cout << "The Boss has attacked and did " << mobdmg 
            << " damage to you!" << endl;
    baseHP=baseHP-mobdmg; //Subtract from HP
    display(baseHP,mobHP); // Display HP for both
    death(mobHP,baseHP); //Check for death
    
    baseAttk = (rand()%baseAttk)+7;
    cout << "You've hit the monster and did " << baseAttk
            << " damage to it!" << endl;
    mobHP=mobHP-baseAttk; // Subtract from Mob
    display(baseHP,mobHP); //Display HP for both
    mobChk(mobHP,baseHP); //Check for Mob death
              }
    exp=25+exp; //Gain experience
    kill++;
    levUP(exp,level); //Check for level up

    retMenu();
    choice5=retAns();
    
        }
        break;
        //Shop
        case '3':{
    cout << "Welcome to the shop!" << endl;
    cout << "What would you like to buy?" << endl;
    cout << "(1)Basic Sword (+3 Attack,100 Gold) " << endl;
    cout << "(2)Strong Sword (+5 Attack, +1HP, 200 Gold) " << endl;
    cout << "(3)Heavy Sword (+7 Attack, +3HP, 300 Gold) " << endl;
    cout << "(4)Platinum Sword (+10 Attack, +5HP, 400 Gold) " << endl;
    cout << "(5)Master Sword (+12 Attack, +10HP, 500 Gold) " << endl;
    cin >> choice4;
    
    switch(choice4){
        case '1':{
            //Basic Sword Purchase
            if(basGold >= 100){
                cout << "Here you go!" << endl;
                basGold=basGold-100;
                cout << "You have gained a basic sword!" << endl;
                baseAttk=baseAttk+3;
            }
            else if (basGold < 100){
                cout << "Sorry! You don't have enough money!" << endl;
            }
            break;
        }
        case '2':{
            //Strong Sword Purchase
            if(basGold >= 200){
                cout << "Here you go!" << endl;
                basGold=basGold-200;
                cout << "You have gained a Strong sword!" << endl;
                baseAttk=baseAttk+5;
                baseHP=baseHP+1;
            }
            else if (basGold < 200 ){
                cout << "Sorry! You don't have enough money!" << endl;
            }
            break;
        }
        case '3':{
            //Heavy Sword Purchase
            if(basGold >= 300){
                cout << "Here you go!" << endl;
                basGold=basGold-300;
                cout << "You have gained a Heavy sword!" << endl;
                baseAttk=baseAttk+7;
                baseHP=baseHP+3;
            }    
            else if (basGold < 300 ){
                cout << "Sorry! You don't have enough money!" << endl;
            }
          break;           
        }
        case '4':{
            //Plat Sword Purchase
           if(basGold >= 400){
                cout << "Here you go!" << endl;
                basGold=basGold-400;
                cout << "You have gained a Platinum sword!" << endl;
                baseAttk=baseAttk+10;
                baseHP=baseHP+7;
           }  
           else if (basGold < 400 ){
                cout << "Sorry! You don't have enough money!" << endl;
            }
           break;
        }
        case '5':{
            //Master Sword Purchase
          if(basGold >= 500){
                cout << "Here you go!" << endl;
                basGold=basGold-500;
                cout << "You have gained a Master sword!" << endl;
                baseAttk=baseAttk+12;
                baseHP=baseHP+10;
           }
          else if (basGold < 500 ){
                cout << "Sorry! You don't have enough money!" << endl;
            }
          break;
        }
    }
            retMenu();
            choice5=retAns();
        }
        break;
        
        //Scores
        case '4':{
            cout << "Score:" << endl;
            score=basGold*basGold+exp+kill;
            calcScor(score,name);
            cout << "Kills: " << kill << endl;
            cout << "Gold: " << basGold <<  endl;
            stats(array,SIZE);
            prnStats(array,SIZE,5);
            weather(x,y);
            retMenu();
            choice5=retAns();
            break;
        }
        
        default:{
            choice5='N';
        }
        
    }
        
     }while(choice5=='Y'||choice5=='y');
    //Exit stage right
    return 0;
        
}

//Display HP for both
void display(int& baseHP, int& mobHP){
    cout << "HP: " << baseHP << endl;
    cout << "MonsterHP: " << mobHP << endl;
}

//If Player dies
int death(int mobHP, int& baseHP){
    if(mobHP > 0 && baseHP < 1){
        cout << "You are now dead " << endl;
        cout << "Game over!" << endl;
    }
    return 0;
}

//If Monster dies
int mobChk(int mobHP,int& baseHP){
    if(mobHP <= 0  && baseHP > 0){
        cout << "You have slayed the monster!" << endl;
    }
}

//If player levels up from experience gained
//Code referenced but expanded on
int levUP(int exp, int level){
   static const int expMet[] = {
        0,15,40,60,100,200,300,400
    };
   while(exp >=expMet[level])
       level++;
   cout << "You are level " << level << endl;   
}

//Option to continue? or go to main menu
int cont(int choice3, int& baseHP, int& maxHP){
    if(baseHP<50){
        baseHP=baseHP+30;
    }
    cout << "----------------------" << endl;
    cout << "Type 1 to continue" << endl;
    cout << "(1)Continue " << endl;
    cin >> choice3;
    

    
}
//Return to the Menu
void retMenu(){
    cout << "Would you like to return to the menu?" << endl;
    cout << "Y for Yes. Anything else to quit." << endl;

}
//Answer for return to the menu
char retAns(){
    char choice5;
    cin >> choice5;
    return choice5;
}
//Main Menu Display 
void mainMenu(int baseHP, int baseAttk, int level, int basGold, int exp ){
    cout << "__________________________________" << endl;
    cout << "|| What would you like to do?   ||\n";
    cout << "||(1)Travel  ||(2)Battle        ||" << endl;
    cout << "||(3)Shop    ||(4)View Score    ||" << endl;
    cout << "||(5)Exit Game                  ||" << endl;
    cout << "__________________________________" << endl;
    cout << "________________" << endl;
    cout << "|Stats:          |\n";
    cout << "|HP: " << baseHP << "         |\n"  //HP display
         << "|Attack: " << baseAttk << "      |\n" // Attack display
         << "|Gold: " << basGold << "       |\n"
         << "|Experience: " << exp << "   |\n"; //Experience Display
    cout << "________________"<< endl;
    cout << "Enter a number and press return/enter" << endl;
}
//Answer for Main Menu
char menuAns(){
    char choice2;
    cin >> choice2;
    return choice2;
}

//Calculate scores for file reading and writing
int calcScor(int& finScor,string& finName){
    cout << finName << " " <<  finScor << endl;
    
    //Writing to file
    ofstream inFile;
    inFile.open ("PersScore.txt");
    inFile << "Score: " << finName << " " << finScor << endl;
    
    inFile.close();
}

//Roll for Stats - Still in Testing
void stats (int a[],int n){
    cout << "Test Stats" << endl;
    for (int i=0;i<n;i++){
        a[i]=rand()%10+2;
    }

}
//Print the stats - Still in Testing
void prnStats(int a[], int n, int print){
    for (int i=0;i<n;i++){
        cout << a[i]<<" ";
        if(i%print==(print-1))
            cout << endl;
    }
    
}

//Changing the weather - Will Affect Stats in Future Revisions
void weather(int x, int y){
    char choice6;
    
    cout << "Would you like to change the weather?" << endl;
    cin >> choice6;
    
    if(choice6=='1'){
        cout << "It's now Sunny!" << endl;
        
    }
    else if(choice6=='2'){
        cout << "It's now Rainy!" << endl;
    }
}