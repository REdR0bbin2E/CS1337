#include <iostream> // including the necessary preprocessor directives for time,cin/cout, and iomanip stuff
#include <iomanip>
#include <cstdlib>
#include <ctime> 
using namespace std;

#define SIZE 40

void printArray(int randArray[]);	//Creating my Function prototypes
void bubbleSort(int* list[]);	// Function prototype
void printPointerArray(int* ptrArray[]); // Function prototype	
void swapIntPtr(int** xptr, int** yptr); // Function prototype	

int main()
{

	int seed ; //creating the seed and allowing the ZyLabs to generate one
	cout << "Enter seed: ";
	cin >> seed;
    srand(seed);

	int dataArray[SIZE] = { 0 }; //
	int* pointerArray[SIZE];
	
	// Initializing values in Data Array
	for (int index = 0; index < SIZE; index++)
	{
		dataArray[index] = rand() % 3000;
	}

	// Printing four different data sets
	printf("Before Sorting, values in Data Array: \n");
	printArray(dataArray);
	printf("\n");

	// Initializing Pointer array with the address of each element in data array
	for(int i = 0; i < SIZE; i++)
	{
	   pointerArray[i] = &dataArray[i];
	   
	}
	

	printf("Before Sorting, values in Pointer Array and the value it is pointing at: \n");
	printPointerArray(pointerArray);
	printf("\n");

	// Calling function Bubble SOrt
	bubbleSort(pointerArray);

	// After Sorting printing the values
	printf("\n");
	printf("After Sorting, values in Pointer Array and the value it is pointing at:  \n");
	printPointerArray(pointerArray);
	printf("\n");
	

	printf("\n");
	printf("After Sorting, values in Data Array: \n");
	printArray(dataArray);
	printf("\n");
   return 0;
}

// Function that prints the array of pointers
void printPointerArray(int* ptrArray[])
{
    for (int i = 0; i < SIZE; i++)
    {
        // Print the pointer value
        cout << setw(6) << ptrArray[i];
        // Print the value pointed to by the pointer
        cout << setw(6) << *ptrArray[i];
        // Print a new line every 10 elements
        if (i % 10 == 9)
        {
            cout << endl;
        }
    }
}

// Function that swaped the values that two pointers are pointing to
void swapIntPtr(int** xptr, int** yptr)
{
    int* temp = *xptr;
    *xptr = *yptr;
    *yptr = temp;
}

// Function to sort an array of pointers using bubble sort
void bubbleSort(int* list[])
{
    int n = SIZE; // Initialize n with the size of the array
    bool swap; // Flag to track if any swaps occurred

    do {
        swap = false; // Reset the flag at the beginning of each pass
        for (int j = 0; j < n - 1; j++)
        {
            // Compare the values pointed to by the pointers
            if (*list[j] > *list[j + 1])
            {
                // Swap the pointers if the current one is greater than the next
                swapIntPtr(&list[j], &list[j + 1]);
                swap = true; // Set the flag to true if a swap occurred
            }
        }
        n--; // Reduce the range of comparison for the next pass
    } while (swap); // Repeat until no swaps occur
}

// Prints the array of integers
void printArray(int randArray[])
{
    for (int i = 0; i < SIZE; i++)
    {
        // Print each element of the array
        cout << setw(6) << randArray[i];
        // Print a new line every 10 elements
        if (i % 10 == 9)
        {
            cout << endl;
        }
    }
}

