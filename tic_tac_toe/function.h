#pragma once
#include <string>

// function.cpp
extern std::string game[3][3];
extern bool firstoption;
extern bool fourthoption;
extern int exitnumber;
extern std::string playeronename;
extern std::string playertwoname;
extern int round;
extern int scoreofx;
extern int scoreofo;
extern int numberofdraws;

// simplefunctions.cpp
void menu();
void optionsmenu();
void customexitnumbermenu();
std::string inputforchangename();
void changeplayersname();
void changenametodefault();
void wait(std::string& anything);
void cinfail();
int takeinputfromuser();
void displayscore(); 
void drawboard();
void scoreboard(int round, int scoreofx, int scoreofo, int numberofdraws);

// function.cpp
bool isdraw();
void resetboard();
bool checkwinner(std::string& winner);
void gameflow(std::string& winner);
bool isdraw();
void resetboard();
