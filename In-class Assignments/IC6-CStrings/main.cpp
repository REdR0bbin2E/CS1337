#include <iostream> //including my preprocessor directives
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
   //my arrays with preset elements
    string article[] = { "The", "A", "One", "Some", "Any" };
    string noun[] = { "boy", "girl", "dog", "town", "car" };
    string verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
    string preposition[] = { "to", "from", "over", "under", "on" };
    
    string sentence = ""; // completed sentence
    int seed; 
    cout << "Enter a seed Value: ";
    cin >> seed;
    srand(seed); //seeding my environment
    
    
    cout << endl;
    char strHold = '0';
    string secArticle = "";
    
    for(int i = 0; i < 8;i++) //for loop for 8 sentences
    {
     
     for(int z = 0; z < 6;z++) //for loop for 6 words in each sentence
     {
        switch(z) //switch for each z value
        {
           case 0:
           sentence += article[rand() % 5] + " ";
           break;
           
           case 1:
           sentence += noun[rand() % 5] + " ";
           break;
           
           case 2:
           sentence += verb[rand() % 5] + " ";
           break;
           
           case 3:
           sentence += preposition[rand() % 5] + " ";
           break;
           
           case 4://for the second article navigate to the word that was randomly picked and set its first index to lowercase
           
           secArticle = article[rand() % 5];
           strHold = secArticle.at(0);
           strHold = tolower(strHold);
           sentence += strHold + secArticle.substr(1,secArticle.length()) + " ";
           
           break;
           
           case 5:
            sentence += noun[rand() % 5] + ".";
           break;
           
     }
     
    }
    cout << sentence << endl; //displaying the sentence and resetting it back to an empty string
     sentence = "";
       
    }
}
