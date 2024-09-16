#ifndef account_H
#define account_H

#include <array>
#include <iostream>
#include <vector>
#include <stdio.h>      
#include <cstdlib>  
#include <fstream>
#include <sstream>
#include <string> 

using namespace std;


class Account{
    private:

    string userName ; 
    string password ; 
    string code ; 

    public:
    // construtor
    Account (string user , string pass , string Fcode){
         userName = user ; 
         password = pass ; 
         code = Fcode ;
    }
   
    //funtions 
    string AccToCsv(){
        
        return userName+","+ password+","+ code+",";
    }
    

    // getters 
    string getUserName(){// retruns username
        return userName; 
    }

    string getPassword(){// returns password 
        return password; 
    }

    string getCode(){// returns code for shareing 
        return code; 
    }

    
    // setters 

    
};
#endif