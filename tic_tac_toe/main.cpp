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
                while(true){
                    optionsmenu();
                    int optioninput { takeinputfromuser() };
                    if(cin.fail()){
                        cinfail();
                    }
                    else{
                        if(optioninput == 1 && firstoption == false){
                            firstoption = true;
                        }
                        else if(optioninput == 1 && firstoption){
                            firstoption = false;
                        }
                        else if(optioninput == 2){
                            while(true){
                                customexitnumbermenu();
                                int secondoptioninput { takeinputfromuser()} ;
                                if(cin.fail()){
                                    cinfail();
                                }
                                else{
                                    if(secondoptioninput == 0){
                                        break;
                                    }
                                    else if(secondoptioninput == 1){
                                        exitnumber = 404;
                                    }
                                    else if(secondoptioninput <= 9 && secondoptioninput != 0 && secondoptioninput != 1){
                                        cout << "Invalid Input!" << endl;
                                    }
                                    else{
                                        exitnumber = secondoptioninput;
                                    }
                                }
                            }
                        }
                        else if(optioninput == 3){
                            break;
                        }
                        resetboard();
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
