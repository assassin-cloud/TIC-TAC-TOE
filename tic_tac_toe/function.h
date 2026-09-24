#pragma once
#include <string>

extern std::string game[3][3];

// Backbone of program flow
void menu();
void optionsmenu();
void wait(std::string& anything);
void cinfail();
void drawboard();
bool isdraw();
void resetboard();

// Essential functions
int takeinputfromuser();
bool checkwinner(std::string& winner);
void putmarker(std::string& winner);
