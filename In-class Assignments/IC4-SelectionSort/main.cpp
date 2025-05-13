#include <iostream> //including my preprocessor directive
using namespace std;
#define SIZE 10

void SelectionSort(int [], int size ); //defining my prototype
 int main()
{
   
   int numOfElements = 0;
   
   // input validation for user input
     cout << "How many elements?: ";
   cin >> numOfElements;
   while(numOfElements > 10 || numOfElements < 1)
   {
    cout <<"The number of elements should be less than 10 and greater than 0 \n";
     cout << "number of elements: ";
   cin >> numOfElements;
   }
   
 
   
   // Read data from  keyboard and populate arrays
   //getting user input for each array element
   int userArray[10] = {};
   cout << "Enter the elements: ";
   for(int i = 0; i < numOfElements;i++)
   {
    cin >> userArray[i];  
   }
   
   
   // calling the selection sort function
   SelectionSort(userArray,numOfElements);
   
   
   // SelectionSort(numberList, numberRec);
    
    // Display the sorted array
    cout << "The sorted array is: ";
    for(int z = 0; z < numOfElements;z++)
    {
     cout << userArray[z] << " ";  
    }
}

void SelectionSort(int numbers[], int size) //performs the selection sorting algorithm
{
   
   int minIndex, minValue;
   
   for(int beg = 0; beg < size -1;beg++) //itterates through each index in the array
   {
      
      minIndex = beg;
      
      minValue = numbers[beg];
      
      for(int index = beg + 1; index < size; index++) 
      {  
         
       if(numbers[index] < minValue)
       {
        minValue = numbers[index];
        minIndex = index;
          
       }
          
      }
      
      //updates the array indexs with swapped values     
     int holder = numbers[minIndex];
      numbers[minIndex] = numbers[beg];
      numbers[beg] = holder;
      
}
}
