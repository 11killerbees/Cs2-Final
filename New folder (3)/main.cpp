
#include <iostream>
using namespace std;
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>  // for rand and srand
#include <fstream>
#include <sstream>
#include "card.h"
#include "csvFunctions.h"
#include "account.h"
#include "mainFuctions.h"
#include "playGame.h"



int main(){
    int num ; // used for input 
    
   
   // choice for loged or make acc 
    cout << "app start screen " << endl ; 
    cout << "#1 to make an account \n#2 to login\nanything else to exit\n" ;
    cin >> num; 
    cout << endl ; 

    if(num == 1 ){// #1 make and acc 
        Account newUser = makeAccount();
        num = 2;
    }

    if (num == 2){//#2  loged in 
        Account user = logIn();                               // user is the name of acc class when loging in 
           // Account user= ;
             
            while(true){// main loop

                cout<< "#1 make a new card\n#2 Edit a card\n#3 Share a set\n#4 Play a game with a set\nAnything else to exit\n  " << endl ; 
                cin >> num; 
                cout << endl;

                if(num == 1 ){ // make card 
                    Card newCard = makeNewCard(); // found in main factions 
                
                    ofstream file(user.getUserName()+".csv", std::ios::app);
                    file << newCard.cardToCsv()+"\n";
                    file.close();

                }
                else if(num == 2 ){ //edit card
                     editCard(user.getUserName());
                }
                
                else if(num == 3 ){// share a set 
                    shareSet(user.getUserName());

                }
                else if(num == 4 ){// play game
                    cout<< "#1 View cards in a set (or all)\n#2 Match cards\nAnything else to exit\n  " << endl ; 
                    cin >> num ; 
                    cout<<"\n";

                    if(num == 1){// view cards 
                        viewCardsinSet(user.getUserName());
                    }

                    else if (num ==2 ){// match the cards 
                        matchGame(user.getUserName());
                    }
                }
                else {return 0;}

            }
    }

    else { // not 1 or 2 
        cout << "Exiting" << endl; 
        return 0 ; 
    }
        
    cout << endl ; 
    
    return 0 ;
}