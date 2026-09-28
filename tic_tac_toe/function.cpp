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


string game[3][3] =
{
    {" "," "," "},
    {" "," "," "},
    {" "," "," "}
};

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

void gameflow(string& winner){
    bool player1turn {true};
    while(true){
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
                else if(!(putmarkerandcheckslot(player1turn, slot))){
                    continue;
                }
                player1turn = !player1turn;
            }
        }
    }
}
