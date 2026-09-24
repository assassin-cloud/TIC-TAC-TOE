#include "function.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    string winner;
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
                putmarker(winner);
                resetboard();
                winner = " ";
            }
            else if(userinput == 2){
                break;
            }
            else{
                cout << "Invalid Input!" << endl;
            }
        }
    }
}
