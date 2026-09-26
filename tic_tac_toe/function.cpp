#include "function.h"
#include<iostream>
#include<string>
using namespace std;

void menu(){
    cout << "==================" << endl;
    cout << "   TIC TAC TOE    " << endl;
    cout << "==================" << endl;
    cout << endl;
    cout << "1. PLay" << endl;
    cout << "2. Options" << endl;
    cout << "3. Exit" << endl;
}


void optionsmenu(){
    cout << "==============" << endl;
    cout << "   OPTIONS    " << endl;
    cout << "==============" << endl;
    cout << "(0) means Disabled and (1) means Enabled" << endl;
    cout << endl;
    cout << "1. Show slot numbers on board(default:disabled): " << firstoption << endl;
    cout << "2. Exit" << endl;
    cout << endl;
    cout << "Input:" << endl;
}

int takeinputfromuser(){
    int x {};
    cin >> x;
    return x;
}

bool firstoption {false};
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

void putmarker(string& winner){
    bool player1turn {true};
    int scoreofx {};
    int scoreofo {};
    int numberofdraws {};
    while(!checkwinner(winner)){
        string anything {};
        if(player1turn){
            cout << "Player 1 (X) type your slot number:" << endl;
        }
        else{
            cout << "Player 2 (O) type your slot number:" << endl;
        }
        int slot {};
        cin >> slot;
        if(cin.fail()){
            cinfail();
        }
        else{
            if(slot<1 || slot>9){
                cout << "Invalid Input!" << endl;
            }
            else{
                slot--;
                int row { slot/3 };
                int column { slot%3 };
                if(game[row][column]=="X" || game[row][column]=="O"){
                    cout << "Slot Occupied!" << endl;
                }
                else{
                    if(player1turn){
                        game[row][column] = "X";
                    }
                    else{
                        game[row][column] = "O";
                    }
                    drawboard();
                    if(checkwinner(winner)){
                        drawboard();
                        cout << winner << " WON!!!!!" << endl;
                        if(winner == "X"){
                            scoreofx++;
                        }
                        else{
                            scoreofo++;
                        }
                        cout << "SCORES: " << endl;
                        cout << "(X): " << scoreofx << endl;
                        cout << "(O): " << scoreofo << endl;
                        wait(anything);
                        if(anything == "q"){
                            break;
                        }
                        else{
                            resetboard();
                            continue;
                        }
                    }
                    else{
                        if(isdraw()){
                            cout << "It's a draw!" << endl;
                            numberofdraws++;
                            cout << "NUmber of Draws:" << numberofdraws << endl;
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
                    player1turn = !player1turn;
                }
            }
        }
    }
}
