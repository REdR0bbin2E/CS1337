#include <iostream>
#include <string>
//including my preprocessor directives for string and iostream

using namespace std;

int main()

{
 string holder = ""; //declaring and initializing two empty string vars.
 string holder2 = "";
 
 string s = ""; //declaring and getting userInput string
 cin >> s;
 
 int k = 0; //declaring and getting userInput rotational number
 cin >> k;
 
 for(int i = 0; i < k; i++) //assigning holder to the first k digits of s
 holder+=s[i];  
 
 for(int i = k; i < 1*(s.length());i++) //assigning holder to the kth digit to the end of userInput string
 holder2+=s[i];
 
 s = holder2+holder; //updating s's value and printing it to the console
 cout << s;
 
 
 
   
}