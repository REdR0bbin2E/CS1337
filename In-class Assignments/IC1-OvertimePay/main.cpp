/*Get hourly pay rate & # of hours from the user, compute & output the # of regular hours, # of overtime hours & the weekly pay, subject to following conditions:

Do not pay for the extra hours beyond 50.
For the overtime hours (hours beyond regular 40 hours), pay at 1.5 times regular rate.
Here is one sample input & output:

Input hourly pay rate: 10
Input # of hours: 57
Regular hours: 40 Overtime hours: 10
Your weekly pay: 550
*/



#include <iostream>
//including my iostream preprocessor directive

using namespace std;
int main()
{
    double payRate; //declaring and initializing my variables for payrate, hours, etc
    double hours;
    double weeklyWages;
        int regularHours = 0;
        int overtimeHours = 0;

    cout <<  "Input hourly pay rate: " ; //getting hourly from user aka userInput
    cin >> payRate;

    cout <<  "Input # of hours: " ; //getting userInput of # of hours 
    cin >> hours;

//Input validation
   while (hours < 0) {
        cout << "\nInvalid input. Hours cannot be negative" << endl; //checking for any negative hours entered from user
        cout << "Enter a valid value: " ;
        cin >> hours;

    }

    
    
    if(hours > 50) //if user has any hours over 50 discard them and set the regularH and overtime to the maximum
    {
        regularHours = 40;
        overtimeHours = 10;
    }
    else
    {
        if(hours - 40 < 0)
        {
            overtimeHours = 0;
        }
        else
        {
            overtimeHours = hours - 40;
        }
        regularHours = hours - overtimeHours;
    }
   

   weeklyWages = (regularHours*payRate)+(overtimeHours*(payRate*1.5));
      
   
   
   
   // This is how your output shoudl be. 
   //If you declare variables accordingly you should be able to get correct answers.
    cout << "\nRegular hours: " <<  regularHours;
    cout << " Overtime hours: " <<   overtimeHours << endl;
    cout << "Your weekly pay: " << weeklyWages << endl;
   

}
