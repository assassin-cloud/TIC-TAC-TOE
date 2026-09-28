#include "function.h"
#include<iostream>
#include<string>
using namespace std;

bool firstoption {false};
bool fourthoption {false};
int exitnumber {404};
string playeronename {"PLAYER 1"};
string playertwoname {"PLAYER 2"};
int round {};
int scoreofx {};
int scoreofo {};
int numberofdraws {};

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

string game[3][3] =
{
    {" "," "," "},
    {" "," "," "},
    {" "," "," "}
};

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

void resetboard(){
    if(firstoption){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int slotnumber = (i*3)+j+1;
                game[i][j] = to_string(slotnumber);
            }
        }
    }
    else{
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                game[i][j] = " ";
            }
        } 
    }
}

bool checkwinner(string& winner){
    for(int i=0;i<3;i++){
        if(game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][0] != " "){
            winner = game[i][0];
            return true;
        }
        else if(game[0][i] == game[1][i] && game[1][i] == game[2][i] && game[0][i] != " "){
            winner = game[0][i];
            return true;
        }
    }
    if(game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != " "){
        winner = game[0][0];
        return true;
    }
    else if(game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[0][2] != " "){
        winner = game[0][2];
        return true;
    }
    return false;
}

bool isdraw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int slotnumber = (i*3)+j+1;
            if(game[i][j] == " " || game[i][j] == to_string(slotnumber)){
                return false;
            }
        }
    }
    return true;
}

void chooseslot(bool player1turn, int& slot){
    if(player1turn){
        cout << playeronename << " (X) type your slot number:" << endl;
    } 
    else{
        cout << playertwoname << " (O) type your slot number:" << endl;
    }
    slot = takeinputfromuser();
}

bool putmarkerandcheckslot(bool player1turn, int slot){
    slot--;
    int row { slot/3 };
    int column { slot%3 };
    if(game[row][column]=="X" || game[row][column]=="O"){
        cout << "Slot Occupied!" << endl;
        return false;
    }
    else{
        if(player1turn){
            game[row][column] = "X";
        }
        else{
            game[row][column] = "O";
        }
    }
    return true;
}

int updatescore(string winner){
    if(checkwinner(winner)){
        if(winner == "X"){
            scoreofx++;
            round++;
            return 1;
        }
        else{
            scoreofo++;
            round++;
            return 1;
        }
    }
    else{
        if(isdraw()){
            numberofdraws++;
            round++;
            return 1;
        }
    }
    return 0;
}

void gameflow(string winner){
    bool player1turn {true};
    while(!checkwinner(winner)){
        int slot {};
        string anything {};
        chooseslot(player1turn, slot);
        if(cin.fail()){
            cinfail();
        }
        else{
            if((slot<1 || slot>9) && slot != exitnumber){
                cout << "Invalid Input!" << endl;
            }
            else if(slot == exitnumber){
                break;
            }
            else{
                if(putmarkerandcheckslot(player1turn, slot)){
                    drawboard();
                    if(updatescore(winner) == 1){
                        scoreboard(round, scoreofx, scoreofo, numberofdraws);
                        wait(anything);
                        if(anything == "q"){
                            break;
                        }
                        else{
                            resetboard();
                            continue;
                        }
                    }
                }
                else{
                    continue;
                }
                player1turn = !player1turn;
            }
        }
    }
}
