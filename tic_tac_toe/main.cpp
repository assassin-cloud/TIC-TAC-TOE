#include "function.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    string winner {};
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
                    displayscore();
                    int scoreboardmenuinput { takeinputfromuser() };
                    if(cin.fail()){
                        cinfail();
                    }
                    else{
                        if(scoreboardmenuinput == 1){
                            round = 0;
                            scoreofx = 0;
                            scoreofo = 0;
                            numberofdraws = 0;
                        }
                        else if(scoreboardmenuinput == 2){
                            break;
                        }
                        else{
                            cout << "Invalid Input!" << endl;
                        }
                    }
                }
            }
            else if(userinput == 3){
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
                            while(true){
                                changeplayersname();
                                int thirdoptioninput { takeinputfromuser() };
                                if(cin.fail()){
                                    cinfail();
                                }
                                else{
                                    if(thirdoptioninput == 1){
                                        string newname {inputforchangename()};
                                        if(newname.empty()){
                                            cout << "Empty name not allowed" << endl;
                                        }
                                        else{
                                            playeronename = newname;
                                        }
                                    }
                                    else if(thirdoptioninput == 2){
                                        string newname {inputforchangename()};
                                        if(newname.empty()){
                                            cout << "Empty name not allowed" << endl;
                                        }
                                        else{
                                            playertwoname = newname;
                                        }
                                    }
                                    else if(thirdoptioninput == 3){
                                        changenametodefault();
                                        int defaultmenuinput { takeinputfromuser() };
                                        if(defaultmenuinput == 1){
                                            playeronename = "PLAYER 1";
                                            playertwoname = "PLAYER 2";
                                        }
                                        else if(defaultmenuinput == 2){
                                            playeronename = "PLAYER 1";
                                        }
                                        else if(defaultmenuinput == 3){
                                            playertwoname = "PLAYER 2";
                                        }
                                        else{
                                            cout << "Invalid input!" << endl;
                                        }
                                    }
                                    else if(thirdoptioninput == 4){
                                        break;
                                    }
                                    else{
                                        cout << "Invalid Input!" << endl;
                                    }
                                }
                            }
                        }
                        else if(optioninput == 4){
                            break;
                        }
                        else{
                            cout << "Invalid Input!" << endl;
                        }
                        resetboard();
                    }
                }
            }
            else if(userinput == 4){
                break;
            }
            else{
                cout << "Invalid Input!" << endl;
            }
        }
    }
}
