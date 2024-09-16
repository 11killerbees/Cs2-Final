#ifndef card_H
#define card_H

#include <iostream>
using namespace std;
#include <array>
#include<array> 
#include <iostream>
using namespace std;
#include <vector>
#include <stdio.h>      
#include <cstdlib>  
#include <fstream>
#include <sstream>
#include <string> 
using namespace std;


class Card{
    private:
    string frountOfCard ; // frount of card 
    string backOfCard ; // back of card 
    string set ; // the set it belongs to 
    
    public:
    // Card construtor 
    Card(string s1, string s2, string s3 ){
         frountOfCard = s1; 
         backOfCard = s2;
         set = s3 ;
         

    }
     // Card without set 
    Card(string s1, string s2){
         frountOfCard = s1; 
         backOfCard = s2;
         

    }

    //funtions 
    string cardToCsv(){
        return   frountOfCard + "," + backOfCard+ "," + set+ ",";
    }

    // getters 

    // returns frount of card 
    string getFrount(){
        return frountOfCard;
    }

    // returns back of card 
    string getBack(){
        return backOfCard;
    }
    
    // returns id of card 
    string getSet(){
        return set ;
    }

    // setters 

    void setFrountOfCard(string s){
        frountOfCard = s;
    }

    void setBackOfCard(string s){
        backOfCard = s;
    }

    void setIdOfCard(string s ){
        set = s; 
        
    }
    
    
};
#endif