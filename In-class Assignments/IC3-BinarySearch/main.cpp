#include <iostream>

using namespace std;

//prototype
int binarySearch(int list[], int key, int low, int high);

// function main begins program execution
int main()
{
    int list[] = { 2, 4, 7, 10, 11, 28, 34, 45, 50, 59, 60, 66, 69, 70, 75, 89, 95 };

    int key, first = 0, last = 16;
    cout <<"Enter the element to search: ";
    cin >> key;
    /*
    Enter your code for the function call
    if key is found output the following statement
    cout << key <<  " is at index " << i << endl;
    */
     
 binarySearch(list,key,first,last);
}

   // function definition
  // Write your  Function header
int binarySearch(int list[], int key, int low, int high)
 {
   int count = 0;

   while(low <= high)
   {
      int mid = low + (high - low) / 2;
      ++count;  
     if(list[mid] < key)
     {
      low = mid+1;
        
        
     }
     if(list[mid] > key)
     {
       high = mid-1;
        
     }
     else if(list[mid] == key)
     {
        cout << "It takes "<< count << " iterations to find the key " << key  << endl;
            cout << key << " is at index " << mid << endl;
            return 0;
     }
  }
   
  // Write your code here and the two cout statements be inserted into your code wherever necessary
   cout << "After  "<< count << " iterations "<< key << " is not found!" << endl;
    
}
