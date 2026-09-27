#pragma once
#include <string>

extern std::string game[3][3];
extern bool firstoption;
extern int exitnumber;
extern std::string playeronename;
extern std::string playertwoname;
extern int round;
extern int scoreofx;
extern int scoreofo;
extern int numberofdraws;

// Backbone of program flow
void menu();
void optionsmenu();
void customexitnumbermenu();
std::string inputforchangename();
void changeplayersname();
void changenametodefault();
void wait(std::string& anything);
void cinfail();
void displayscore();
void drawboard();
bool isdraw();
void resetboard();

// Essential functions
int takeinputfromuser();
bool checkwinner(std::string& winner);
void putmarker(std::string& winner);
