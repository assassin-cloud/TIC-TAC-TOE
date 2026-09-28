#include "function.h"
#include<iostream>
using namespace std;

void menu(){
    cout << "==================" << endl;
    cout << "   TIC TAC TOE    " << endl;
    cout << "==================" << endl;
    cout << "Note: Type " << exitnumber << " in a ongoing round to exit" << endl;
    cout << endl;
    cout << "1. PLay" << endl;
    cout << "2. See Scoreboard" << endl;
    cout << "3. Options" << endl;
    cout << "4. Exit" << endl;
}

void optionsmenu(){
    cout << "==============" << endl;
    cout << "   OPTIONS    " << endl;
    cout << "==============" << endl;
    cout << "Note: (0) means Disabled and (1) means Enabled" << endl;
    cout << endl;
    cout << "1. Show slot numbers on board(default:disabled): " << firstoption << endl;
    cout << "2. Add Custom Exit Number: " << exitnumber << endl;
    cout << "3. Give custom name to PLAYER 1(X) and PLAYER 2(O)" << endl;
    cout << "4. Reset scores after going to main menu(default: Disabled): " << fourthoption << endl;
    cout << "5. Reset all options to default" << endl;
    cout << "6. Go back" << endl;
    cout << endl;
    cout << "Input:" << endl;
}

void customexitnumbermenu(){
    cout << "===============================" << endl;
    cout << "   INPUT A CUSTOM EXIT CODE    " << endl;
    cout << "===============================" << endl;
    cout << endl;
    cout << "NOTE:" << endl;
    cout << "1. Code should be greater than 9, can't be negative or zero" << endl;
    cout << "2. No special characters or alphabets only 'numbers' allowed" << endl;
    cout << "3. Type 0 to go back to options menu" << endl;
    cout << "4. Type 1 to reset back to default code" << endl;
    cout << endl;
    cout << "Custom Exit Code: " << exitnumber << endl;
    cout << "Input:" << endl;
}

string inputforchangename(){
    cin.ignore();
    string x;
    cout << "Type a new name:" << endl;
    getline(cin, x);
    return x;
}

void changeplayersname(){
    cout << "=============================" << endl;
    cout << "   CHANGE A PLAYER'S NAME    " << endl;
    cout << "=============================" << endl;
    cout << endl;
    cout << "1. Player 1(X) name: " << playeronename << endl;
    cout << "2. Player 2(O) name: " << playertwoname << endl;
    cout << "3. Set to default" << endl;
    cout << "4. Go back" << endl;
    cout << endl;
    cout << "INPUT:" << endl;
}

void changenametodefault(){
    cout << "===========================" << endl;
    cout << "   SET NAMES TO DEFAULT    " << endl;
    cout << "===========================" << endl;
    cout << endl;
    cout << "1. Set both names to default" << endl;
    cout << "2. Set Player 1 name to default" << endl;
    cout << "3. Set player 2 name to default" << endl;
    cout << endl;
    cout << "INPUT:" << endl;
}

void scoreboard(int round, int scoreofx, int scoreofo, int numberofdraws){
    cout << "| " << "ROUND NUMBER: " << round << " |" << endl;
    cout << "| --------------- |" << endl;
    cout << "| " << "SCORE(X): " << scoreofx << "     |" << endl;
    cout << "| --------------- |" << endl;
    cout << "| " << "SCORE(O): " << scoreofo << "     |" << endl;
    cout << "| --------------- |" << endl;
    cout << "| " << "DRAWS: " << numberofdraws << "        |" << endl;
}

void displayscore(){
    cout << "=================" << endl;
    cout << "   SCOREBOARD    " << endl;
    cout << "=================" << endl;
    cout << endl;
    scoreboard(round, scoreofx, scoreofo, numberofdraws);
    cout << "1. Reset Scores and rounds" << endl;
    cout << "2. Go back" << endl;
    cout << "INPUT:" << endl;
}

int takeinputfromuser(){
    int x {};
    cin >> x;
    return x;
}

void wait(string& anything){
    cout << "Type anything to play another round! or (q) to quit:" << endl;
    cin >> anything;
}

void cinfail(){
    cout << "Invalid Input!" << endl;
    cin.clear();
    cin.ignore(1000,'\n');
}

void drawboard(){
    cout << "|" << game[0][0] << "|" << game[0][1] << "|" << game[0][2] << "|" << endl;
    cout << "-------" << endl;
    cout << "|" << game[1][0] << "|" << game[1][1] << "|" << game[1][2] << "|" << endl;
    cout << "-------" << endl;
    cout << "|" << game[2][0] << "|" << game[2][1] << "|" << game[2][2] << "|" << endl;
}
