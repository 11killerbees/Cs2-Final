#ifndef csvFuntions_H
#define csvFuntions_H

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "card.h"

bool checkForCama(string s){
    for(int i = 0 ; i <= s.size() ;i ++){
            string Sub = s.substr(i,1);

            if(Sub == ","){
                return true ; // found
            }
    }
    return false; // not found 
}


bool checkUserLogin(string user , string password){ // funtion works as intended 

    ifstream file("accounts.csv");
    string line;
    string subUser;
    string subPassword; 

    bool superCheckCellOne = false; // the check for cell 1 
    bool superCheckCellTwo = false; // the check for cell 2 


    while (getline(file, line)) {
        superCheckCellOne = false; 
        superCheckCellTwo = false; 

        int j = 0 ; // used for substring 
        int count = 1; // used for count for cell 

        for(int i = 0 ; i <= line.size(); i ++){

            

            string check = line.substr(i,1); // checks for cama 
        
            // this checks for cama and makes a count to output to 3 differnt strings depeinding on count 
    
            // count3 aslo 3rd cell 
            // not need for this , kept for c/p
            if(check == "," & count == 3){
                count ++ ;
            }

            // count 2 also seccond cell 
            if(check == "," & count == 2){
                 int len = i-j ;
                subPassword = line.substr(j,len); // makes a sub string of things befor the cama 
                 
                if (subPassword == password){
                    superCheckCellTwo = true ;
                }

                else{
                    superCheckCellTwo = false;
                    superCheckCellOne = false; 
                }

                j = i+1 ;
                count ++ ;
            }

            // count 1 also first cell 
            if(check == "," & count == 1){ 
                int len = i-j ;
                subUser = line.substr(j,len); // makes a sub string of things befor the cama 
                
                if (subUser == user){
                    
                    superCheckCellOne = true;
                }

                else{
                    superCheckCellOne = false; 
                }

                j = i+1 ;
                count ++ ;
            }

            if(superCheckCellOne and superCheckCellTwo){
                return true; 
            }

        }// for loop
    }// while loop 

        return false;
    file.close(); // Close the file after reading
}


////////////////////////////////////////Next funtion///////////////////////////////////////////////////

bool checkUser(string user ){ // funtion works as intended 

    ifstream file("accounts.csv");
    string line;
    string subUser;
    string subPassword; 

    while (getline(file, line)) { 

        int j = 0 ; // used for substring 
        int count = 1; // used for count for cell 

        for(int i = 0 ; i <= line.size(); i ++){

            string check = line.substr(i,1); // checks for cama 
        
            // this checks for cama and makes a count to output to 3 differnt strings depeinding on count 
    
            // count3 aslo 3rd cell 
            // not need for this , kept for c/p
            if(check == "," & count == 3){
                count ++ ;
            }

            // count 2 also seccond cell 
            // not need for this , kept for c/p
            if(check == "," & count == 2){
                count ++ ;
            }

            // count 1 also first cell 
            if(check == "," & count == 1){ 
                int len = i-j ;
                subUser = line.substr(j,len); // makes a sub string of things befor the cama 
                
                if (subUser == user){
                    return false;
                }

                
                j = i+1 ;
                count ++ ;
            }

        }// for loop
    }// while loop 

        return true ;
    file.close(); // Close the file after reading
}


////////////////////////////////////////Next funtion///////////////////////////////////////////////////

Card makeCardToObj(){ //  have not checked
 ifstream opendCardCsv("Cards.csv");
    ifstream file("Cards.csv");

    string line;

    int cardCount = 0 ;
    
    while (getline(file, line)) {

        int j = 0 ; // used for substring 
        int count = 1; // used for count for cell 

        for(int i = 0 ; i <= line.size(); i ++){

            string check = line.substr(i,1); // checks for cama 
        
            // this checks for cama and makes a count to output to 3 differnt strings depeinding on count 
    
            // count3
            if(check == "," & count == 3){
                int len = i-j ;
                string subBack = line.substr(j,len); // makes a sub string of things befor the cama 
                cout << subBack << endl ; 
                j = i+1 ;
                count ++ ;
            }

            // count 2 
            if(check == "," & count == 2){
                int len = i-j ;
                string subFrount = line.substr(j,len); // makes a sub string of things befor the cama 
                cout << subFrount << endl ; 
                j = i+1 ;
                count ++ ;
            }

            // count 1
            if(check == "," & count == 1){
                int len = i-j ;
                string subId = line.substr(j,len); // makes a sub string of things befor the cama 
                cout << subId << endl ; 
                j = i+1 ;
                count ++ ;
            }

        }// for loop

       // Card cardCount(subId,subFrount,subBack); 

        
    }// while loop 

    file.close(); // Close the file after reading

    
}
////////////////////////////////////////Next funtion///////////////////////////////////////////////////

string  getCodeFromCsv(string username){ //  Wroks
 ifstream opendCardCsv("accounts.csv");
    ifstream file("accounts.csv");

    string line;

    int cardCount = 0 ;
    
    while (getline(file, line)) {

        int j = 0 ; // used for substring 
        int count = 1; // used for count for cell 

        bool checkUser = false;

        for(int i = 0 ; i <= line.size(); i ++){

            string check = line.substr(i,1); // checks for cama 
        
            // this checks for cama and makes a count to output to 3 differnt strings depeinding on count 
    
            // count3
            if(check == "," & count == 3){
                int len = i-j ;
                string subBack = line.substr(j,len); // makes a sub string of things befor the cama 
                if (checkUser){return subBack;}
                j = i+1 ;
                count ++ ;
            }

            // count 2 
            if(check == "," & count == 2){
                int len = i-j ;
                string subFrount = line.substr(j,len); // makes a sub string of things befor the cama 
                j = i+1 ;
                count ++ ;
            }

            // count 1
            if(check == "," & count == 1){
                int len = i-j ;
                string userName = line.substr(j,len); // makes a sub string of things befor the cama 
                if (userName == username)
                {checkUser = true;} 
                else{
                    checkUser = false; 
                }

                j = i+1 ;
                count ++ ;
            }

        }// for loop

    }// while loop 

    file.close(); 

    
}


bool checkUserShareCode(string user , string password){ // funtion works as intended 

    ifstream file("accounts.csv");
    string line;
    string subUser;
    string subPassword; 

    bool superCheckCellOne = false; // the check for cell 1 
    bool superCheckCellTwo = false; // the check for cell 2 


    while (getline(file, line)) {
        superCheckCellOne = false; 
        superCheckCellTwo = false; 

        int j = 0 ; // used for substring 
        int count = 1; // used for count for cell 

        for(int i = 0 ; i <= line.size(); i ++){

            

            string check = line.substr(i,1); // checks for cama 
        
            // this checks for cama and makes a count to output to 3 differnt strings depeinding on count 
    
            // count3 aslo 3rd cell 
            // not need for this , kept for c/p
            if(check == "," & count == 3){
                int len = i-j ;
                subPassword = line.substr(j,len); // makes a sub string of things befor the cama 
                
                if (subPassword == password){
                    superCheckCellTwo = true ;
                }

                else{
                    superCheckCellTwo = false;
                    superCheckCellOne = false; 
                }

                j = i+1 ;
                count ++ ;
            }

            // count 2 also seccond cell 
            if(check == "," & count == 2){
                j = i+1 ;
                count ++ ;
            }

            // count 1 also first cell 
            if(check == "," & count == 1){ 
                int len = i-j ;
                subUser = line.substr(j,len); // makes a sub string of things befor the cama 
                
                if (subUser == user){
                    
                    superCheckCellOne = true;
                }

                else{
                    superCheckCellOne = false; 
                }

                j = i+1 ;
                count ++ ;
            }

            if(superCheckCellOne and superCheckCellTwo){
                return true; 
            }

        }// for loop
    }// while loop 

        return false;
    file.close(); // Close the file after reading
}
    

#endif