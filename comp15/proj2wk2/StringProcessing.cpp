//Author: Justin Steinberg           //
//Implementations of StringProcessing//
//Wed, April 17th 2019               //
//Project2, Week 2                   //
///////////////////////////////////////

#include<string>
#include<stdio.h>
#include<ctype.h>
#include<bits/stdc++.h>
#include<iostream>
#include "StringProcessing.h"

using namespace std;

//Input: A string
//Output: A string
//Does: Cleans the leading and trailing characters of a string
//of all non-alphanumeric charaters
string StringProcessing::cleanString(string s){
 
    int smallest_index = 0;
    int largest_index = s.size();
    string clean = ""; 
    int size = s.size();

    for(int i = 0; i<size; i++){
        if(isalnum(s[i]))
        {
           smallest_index = i;
           break;
        }
     }

    for(int i = s.size()-1; i>=0; i--){
       	if(isalnum(s[i]))
       	{
           largest_index = i;
       	   break;
       	}
    }

    for(int i = smallest_index; i <= largest_index; i++){
         clean += s[i];
    } 

    return clean;
}

//Main function continually gets a string from the
//command line
/*
int main()
{
    string s;
    while(getline(cin,s)){
        string newString = cleanString(s);
        cout << newString << endl;
    }
    return 0;
}

*/
