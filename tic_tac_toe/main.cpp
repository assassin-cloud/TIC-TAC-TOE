#include "function.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    string winner;
    while(true){
        menu();
        cout << "Input:" << endl;
        int userinput {takeinputfromuser()};
        if(cin.fail()){
            cinfail();
        }
        else{
            if(userinput == 1){
                drawboard();
                putmarker(winner);
                resetboard();
                winner = " ";
            }
            else if(userinput == 2){
                optionsmenu();
                if(takeinputfromuser()==1){
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            int slotnumber = (i*3)+j+1;
                            game[i][j] = to_string(slotnumber);
                        }
                    }
                }
            }
            else if(userinput == 3){
                break;
            }
            else{
                cout << "Invalid Input!" << endl;
            }
        }
    }
}
