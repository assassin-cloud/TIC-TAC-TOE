#include<iostream>
#include<string>
using namespace std;

void menu(){
    cout << "==================" << endl;
    cout << "   TIC TAC TOE    " << endl;
    cout << "==================" << endl;
    cout << endl;
    cout << "1. PLay" << endl;
    cout << "2. Exit" << endl;
}

string game[3][3] =
{
    {" "," "," "},
    {" "," "," "},
    {" "," "," "}
};

void wait(string& anything){
    cout << "type anything to continue! or q to quit:" << endl;
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
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            game[i][j] = " ";
        }
    }
}

int checkwinner(string& winner, bool& foundwinner){
    for(int i=0;i<3;i++){
        if(game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][0] != " "){
            winner = game[i][0];
            foundwinner = true;
            return 1;
        }
        else if(game[0][i] == game[1][i] && game[1][i] == game[2][i] && game[0][i] != " "){
            winner = game[0][i];
            foundwinner = true;
            return 1;
        }
    }
    if(game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != " "){
        winner = game[0][0];
        foundwinner = true;
        return 1;
    }
    else if(game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[0][2] != " "){
        winner = game[0][2];
        foundwinner = true;
        return 1;
    }
    return 0;
}

bool draw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(game[i][j]==" "){
                return false;
            }
        }
    }
    return true;
}

void putmarker(string& winner, bool& foundwinner){
    bool player1turn {true};
    while(!foundwinner){
        if(player1turn){
            cout << "Player 1 (X) choose your slot" << endl;
        }
        else{
            cout << "Player 2 (O) choose your slot" << endl;
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
                    if(checkwinner(winner, foundwinner) == 1){
                        cout << winner << " WON!!!!!" << endl;
                        break;
                    }
                    else{
                        if(draw()){
                            cout << "It's a draw!" << endl;
                            break;
                        }
                    }
                    player1turn = !player1turn;
                }
            }
        }
    }
}

int main(){
    string winner;
    string anything;
    bool foundwinner { false };
    while(true){
        menu();
        cout << "Input:" << endl;
        int userinput {};
        cin >> userinput;
        if(cin.fail()){
            cinfail();
        }
        else{
            if(userinput == 1){
                drawboard();
                putmarker(winner,foundwinner);
                resetboard();
                foundwinner = false;
                winner = " ";
            }
            else if(userinput == 2){
                break;
            }
            else{
                cout << "Invalid Input!" << endl;
                wait(anything);
            }
        }
    }
}