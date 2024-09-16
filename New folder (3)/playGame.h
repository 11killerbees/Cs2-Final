#ifndef playGame_H
#define playGame_H

#include <array>
#include <iostream>
#include <vector>
#include <stdio.h>      
#include <cstdlib>  
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <random> 

using namespace std;

void viewCardsinSet(string fname){
    ifstream file(fname+".csv");
    string line;
    string frount ;
    string back ;
    string setIN; 
    string set ; 
    vector <string> listOfcardsFrount; 
    vector <string> listOfcardsBack;

    cout<<"type the name of the set you want to see (put -1 to view all cards): "<<endl;
    cin >> setIN ;
     
    while (getline(file, line)) { 
        int j = 0 ; // used for substring 
        int count = 1;

        for(int i = 0 ; i <= line.size(); i ++){
            
            string check = line.substr(i,1); // checks for cama 
        
            // this checks for cama and makes a count to output to 3 differnt strings depeinding on count 
    
            // count3
            if(check == "," & count == 3){
                int len = i-j ;
                set = line.substr(j,len); // makes a sub string of things befor the cama 3rd cell 
            
                j = i+1 ;
                count ++ ;
            }

            // count 2 
            if(check == "," & count == 2){
                int len = i-j ;
                back = line.substr(j,len); // makes a sub string of things befor the cama 
                //
                j = i+1 ;
                count ++ ;
            }

            // count 1
            if(check == "," & count == 1){
                int len = i-j ;
                frount = line.substr(j,len); // makes a sub string of things befor the cama 
                //
                j = i+1 ;
                count ++ ;
            }

        }// for loop

        if (set == setIN){
            listOfcardsFrount.push_back(frount);
            listOfcardsBack.push_back(back);
        }

        else if (setIN == "-1"){
            listOfcardsFrount.push_back(frount);
            listOfcardsBack.push_back(back);
        }

    }// while loop

    for(int i = 0 ; i <= listOfcardsBack.size()-1;i++){
        string temp ;
        cout<<"\nFrount: "+ listOfcardsFrount[i]+"\nType anything to see back: ";
        cin >> temp; 
        cout<<"\nBack: "+listOfcardsBack[i]+"\nType anything to see next card: "; 
        cin >> temp; 
        

    }

}


void matchGame(string fname){

    ifstream file(fname+".csv");
    string line;
    string frount ;
    string back ;
    string setIN; 
    string set ; 
    vector <string> listOfcardsFrount; 
    vector <string> listOfcardsBack;

    cout<<"type the name of the set you want to see (put -1 to view all cards): "<<endl;
    cin >> setIN ;
     
    while (getline(file, line)) { 
        int j = 0 ; // used for substring 
        int count = 1;

        for(int i = 0 ; i <= line.size(); i ++){
            
            string check = line.substr(i,1); // checks for cama 
        
            // this checks for cama and makes a count to output to 3 differnt strings depeinding on count 
    
            // count3
            if(check == "," & count == 3){
                int len = i-j ;
                set = line.substr(j,len); // makes a sub string of things befor the cama 3rd cell 
            
                j = i+1 ;
                count ++ ;
            }

            // count 2 
            if(check == "," & count == 2){
                int len = i-j ;
                back = line.substr(j,len); // makes a sub string of things befor the cama 
                //
                j = i+1 ;
                count ++ ;
            }

            // count 1
            if(check == "," & count == 1){
                int len = i-j ;
                frount = line.substr(j,len); // makes a sub string of things befor the cama 
                //
                j = i+1 ;
                count ++ ;
            }

        }// for loop

        if (set == setIN){
            listOfcardsFrount.push_back(frount);
            listOfcardsBack.push_back(back);
        }

        else if (setIN == "-1"){
            listOfcardsFrount.push_back(frount);
            listOfcardsBack.push_back(back);
        }

    }// while loop

    vector<string> randBack = listOfcardsBack;

    random_device rd;
    default_random_engine rng(rd());

    // Shuffle the elements of the vector
    shuffle(randBack.begin(), randBack.end(), rng);

    for(int i = 0 ; i <= listOfcardsBack.size()-1;i++){
        cout <<"Frount of card: "+listOfcardsFrount[i]<<endl;
        cout<< "which is the back of the card\n";
        for(int j = 0 ; j <= listOfcardsBack.size()-1;j++){
            cout<<"#"+to_string(j)+" "+randBack[j]<<endl;
             
        }
        int guess ;
        cout << "which number belongs to the frount? " ;
        cin >> guess ; 
        if (listOfcardsBack[i] == randBack[guess] ){
            cout<< "\nThats Right!\n";

        }
        else{
            cout <<"\nThats wrong\n";
        }
    }
    

}



void shareCards(string fname, string fname2){ ///// this funtion belongs in csvfutions but is kept here for now 
    ifstream file(fname+".csv");
    string line;
    string frount ;
    string back ;
    string setIN; 
    string set ; 
    vector <string> listOfcardsFrount; 
    vector <string> listOfcardsBack;

    cout<<"type the name of the set you want to share (put -1 to share all cards): "<<endl;
    cin >> setIN ;
     
    while (getline(file, line)) { 
        int j = 0 ; // used for substring 
        int count = 1;

        for(int i = 0 ; i <= line.size(); i ++){
            
            string check = line.substr(i,1); // checks for cama 
        
            // this checks for cama and makes a count to output to 3 differnt strings depeinding on count 
    
            // count3
            if(check == "," & count == 3){
                int len = i-j ;
                set = line.substr(j,len); // makes a sub string of things befor the cama 3rd cell 
            
                j = i+1 ;
                count ++ ;
            }

            // count 2 
            if(check == "," & count == 2){
                int len = i-j ;
                back = line.substr(j,len); // makes a sub string of things befor the cama 
                //
                j = i+1 ;
                count ++ ;
            }

            // count 1
            if(check == "," & count == 1){
                int len = i-j ;
                frount = line.substr(j,len); // makes a sub string of things befor the cama 
                //
                j = i+1 ;
                count ++ ;
            }

        }// for loop

        if (set == setIN){
        
        string fileName = fname2+".csv"; // Change the file name as needed
        cout<<"here"<<endl;
        // Open the file in write mode
        ofstream file2;
        file2.open(fileName, std::ios::app);
        file2 << line+"\n";
        file2.close();

        }

        else if (setIN == "-1"){
            string fileName = fname2+".csv"; // Change the file name as needed
        
        // Open the file in write mode
        ofstream file2;
        file2.open(fileName, std::ios::app);
        file2 << line+"\n";
        file2.close();
        cout<<"\n"; 
        }

    }// while loop


}

#endif