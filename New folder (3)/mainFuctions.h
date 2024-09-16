#ifndef mainFuctions_H
#define mainFuctions_H

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
#include "playGame.h"


void shareSet(string fname ){
    string nameOfOtherAcc;
    string shareCode;
    bool check = true ; 
    while(check){

        cout <<"name of the account you want to share to: "<<endl ;
        cin >> nameOfOtherAcc;

        cout<<"Share code for the account: "<<endl ;
        cin >> shareCode; 

        if ((checkUserShareCode(nameOfOtherAcc,shareCode))){
            check = false; 
            shareCards(fname,nameOfOtherAcc);
        }
        else{
            
        }
    }
}

Card makeNewCard(){// works 
    //card vars 
    string frount; 
    string back;
    string set ; 

    bool check = true; // used to make sure input is valid 

    while(check){ // code for frount of crad
        check = false;
        cout<<"Make a card (',' is an invlaid input and will not work)"<<endl ;
        cout << "frount of card: " ;
        cin >> frount ; 

        check = (checkForCama(frount));
        if(check){
            cout << "invalid input" << endl; 
        }
    }
    check = true;
    while(check){// code for back of card
        check = false; 
        cout << "\nBack of card: " ;
        cin >> back ; 

        check = (checkForCama(back));
        if(check){
            cout << "invalid input" << endl; 
        }
    }
    check = true;
    while(check){// code for set
        check = false; 
        cout << "\nSet for the card(EX: bio , caps matter): " ;
        cin >> set ; 

        check = (checkForCama(set));
        if(check){
            cout << "invalid input" << endl; 
        }
    }

    Card newCard(frount,back,set);

    return newCard ;
}



Account logIn(){ // funtion is done 
    string accName ;
    string accPassword ;
    bool check = true ; 
    while(check){
        cout << "Login screen"<< endl ;
        cout << "User Name: "; 
        cin >> accName  ;
        cout << endl  ; 
        cout << "PassWord: "; 
        cin >> accPassword ;
        cout << endl << endl ;
        check = !(checkUserLogin(accName , accPassword));
        if(check){cout << "incorect username / password"<< endl << endl ;}
        else {cout << "logged in "<< endl << endl;}
    }
    string code = getCodeFromCsv(accName);
    Account user(accName,accPassword,code);
    return user ; 
}

 Account makeAccount (){
    bool check = true ; 
    bool pwCheck = false; 
    string userName ; 
    string password; 
    while(check){
        cout << "make account screen \n user name: " << endl ; 
        cin >> userName ;
        cout << endl ;
        if ((checkUser(userName))){
            bool check2 = true ; 
            while (check2){
                cout << "Password: " << endl ; 
                cin >> password ; 
                cout << endl ;
                for(int i = 0 ; i <= password.size(); i ++){
                    string subi = password.substr(i,1);
                    if ( !(subi == "," or subi == " ")){
                        pwCheck = true ; 
                    }
                }
                if (password.size()>= 6 and pwCheck ){check2 = false;}
            }

            check2 = true ; 
            pwCheck = false ; 
            string shareCode ; 
            while (check2){
                cout << "Share code: " << endl ; 
                cin >> shareCode ; 
                cout << endl ;
                for(int i = 0 ; i <= shareCode.size(); i ++){
                    string subi = shareCode.substr(i,1);
                    if ( !(subi == "," or subi == " ")){
                        pwCheck = true ; 
                    }
                }

                if (shareCode.size()>= 6 and pwCheck ){
                    check2 = false;
                }

            }

            Account newUser (userName, password , shareCode);
            // Open the file in append mode
            ofstream file("accounts.csv", ios::app);
    
    
            file << newUser.AccToCsv() << endl;


            file.close();

            string fName = newUser.getUserName();
            string fileName = fName + ".csv"; // Change the file name as needed

            ofstream file2(fileName);

            if (file2.is_open()) {
                file2.close();
        
            } else {
                cerr << "Failed to create CSV file." << endl;
            }

            return newUser ; 
        }
    
    }
   
    
}

void editCard(string fname){
    ifstream file(fname+".csv");
    string line;
    string frount ;
    string back ;
    string set; 
    vector <string> listOfcards;  
    int i =0 ;
    int numToEdit;
    bool check = true ; 

    while (getline(file, line)) { 
        string printLine = "#"+to_string(i+1)+" "+line;
        cout << printLine << endl;
        listOfcards.push_back(line);

        i++ ; 
    }// while loop 

    if(!(i == 0) ){
    
    while(check){
        cout << "pick a num to edit\nNum over "+ to_string(i) +" will not work"<< endl;
        cin >> numToEdit ; 
        numToEdit -- ; 
        if((numToEdit < i)){
            check = false;
        }

    }

    check = true ; 

    while(check){
        cout<<"\nfrount: "<<endl;
        cin >> frount;
        check = checkForCama(frount);
    }

    check = true ;
    while(check){
        cout<<"\nback: "<<endl;
        cin >> back;
        check = checkForCama(back);
    }

    check = true ;
    while(check){
        cout<<"\nset: "<<endl;
        cin >> set;
        check = checkForCama(set);
    }

    listOfcards[numToEdit] = frount+","+back+","+set+"," ;

    cout << "here "<< endl;
    file.close();
    ofstream file2(fname+".csv", std::ios::out);
    for(int i = 0 ; i < listOfcards.size(); i ++){
        string temp = (listOfcards[i])+"\n" ;
        file2 << (temp);
    }
    
                    
                    

         
    file2.close(); // Close the file after reading
    }

    else{cout << "no cards to edit" << endl;}
}

#endif