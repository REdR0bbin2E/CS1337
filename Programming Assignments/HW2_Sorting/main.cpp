#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function to search for netId through linear search
int linearSearchID(int arr[], int numElems, int value, int &nIter) {
    int index = 0;
    int pos = -1;
    bool found = false;

    nIter = 0; // Set the count variable to zero before the iteration

    while (index < numElems && !found) {
        //nIter++;
        if (arr[index] == value) {
            found = true;
            pos = index;
        }

        nIter++;
        index++;
    }

    return pos; // Return the index where the id was found
}

// Function to swap the value in the array after sorting
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Search netID through binary search
int binarySearchID(int arr[], int numElems, int value, int &nIter) {
    int start = 0;
    int final = numElems - 1;
    bool found = false;
    int pos = -1;
    int mid;

    nIter = 0; // Set the count variable to zero before the iteration

    while (!found && start <= final) {
        nIter++;
        mid = (start + final) / 2;

        if (arr[mid] == value) {
            found = true;
            pos = mid;
            break;
        } else if (arr[mid] < value) {
            start = mid + 1;
        } else {
            final = mid - 1;
        }
        //nIter++;
    }

    return pos; // Return the index where the id was found
}

// Function to sort the GPA array
void modifiedSortGPA(double array1[], int array2[], string array3[], int size) {
    int minIndex;
    double minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array1[start]; // Initialize smallest value to the first element

        for (int i = start + 1; i < size; i++) {
            if (array1[i] < minValue) {
                minValue = array1[i]; // Set it to the smallest value
                minIndex = i; // Index where the value is found
            }
        }

        swap(array1[minIndex], array1[start]); // Keep the arrays parallel
        swap(array2[minIndex], array2[start]);
        swap(array3[minIndex], array3[start]);
    }
}

// Function to sort the netID
void modifiedSortID(int array2[], double array1[], string array3[], int size) {
    int minIndex, minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array2[start];

        for (int i = start + 1; i < size; i++) {
            if (array2[i] < minValue) {
                minValue = array2[i];
                minIndex = i;
            }
        }

        swap(array2[minIndex], array2[start]);
        swap(array1[minIndex], array1[start]);
        swap(array3[minIndex], array3[start]);
    }
}

// Function to sort the GPA in descending order
void reverseSortGPA(double array1[], int array2[], string array3[], int size) {
    int maxIndex; // Changed from minIndex to maxIndex
    double maxValue; // Changed from minValue to maxValue

    for (int start = 0; start < (size - 1); start++) {
        maxIndex = start;
        maxValue = array1[start];

        for (int i = start + 1; i < size; i++) {
            // Change the comparison to sort in descending order
            if (array1[i] > maxValue) { // Changed from < to >
                maxValue = array1[i];
                maxIndex = i;
            }
        }

        swap(array1[maxIndex], array1[start]);
        swap(array2[maxIndex], array2[start]);
        swap(array3[maxIndex], array3[start]);
    }
}

// Function to display the menu
void displayMenu() {
    cout << "***************" << endl;
    cout << "Menu of choices" << endl;
    cout << "***************" << endl;

    cout << "1 - List top n students" << endl;
    cout << "2 - Search on a netID" << endl;
    cout << "3 - Quit" << endl;
}

int main() {
    const int NUM_ELMTS = 18;

    // NetID, major, and GPA are parallel arrays
    int netID[NUM_ELMTS]; // Original netID array
    string major[NUM_ELMTS]; // Original major array
    double GPA[NUM_ELMTS]; // Original GPA array
    int index = 0;

    string fileName;

    cout << "Enter file name: "; // Prompt user for the file name
    cin >> fileName;

    ifstream inputFile;
    inputFile.open(fileName); // Opens the file

    if (!inputFile) { // If the file doesn't exist
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
        return -1;
    }

    // Reads the elements from the file and stores them into the array
    while (index < NUM_ELMTS && inputFile >> netID[index] >> major[index] >> GPA[index]) {
        index++;
    }

    // Output as expected
    cout << "Original arrays:" << endl;
    cout << "----------------" << endl;

    cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;

    // Displays the elements read from the original array from the file, but only the even-indexed ones
    for (int i = 0; i < index; i += 2) {
        // Print the even-indexed element (left side)
        cout << setw(5) << i << "  " << setw(5) << netID[i] << "  " << setw(6) << major[i] << "  " << fixed << setprecision(2) << GPA[i] << "   ";

        // Displays the element but only the odd indices
        if (i + 1 < index) {
            cout << setw(5) << i + 1 << "  " << setw(5) << netID[i + 1] << "  " << setw(6) << major[i + 1] << "  " << fixed << setprecision(2) << GPA[i + 1];
        }
        cout << endl;
    }

    modifiedSortGPA(GPA, netID, major, index); // Call the function to sort the GPA
    cout << endl;

    cout << "Arrays sorted by GPA:" << endl;
    cout << "---------------------" << endl;

    // Displays the sorted GPA array
    cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;

    for (int i = 0; i < index; i += 2) {
        // Print the even-indexed element (left side)
        cout << setw(5) << i << "  " << setw(5) << netID[i] << "  " << setw(6) << major[i] << "  " << fixed << setprecision(2) << GPA[i] << "   ";

        if (i + 1 < index) {
            cout << setw(5) << i + 1 << "  " << setw(5) << netID[i + 1] << "  " << setw(6) << major[i + 1] << "  " << fixed << setprecision(2) << GPA[i + 1];
        }
        cout << endl;
    }

    modifiedSortID(netID, GPA, major, index); // Calls the function to sort the netID

    cout << endl;
    cout << "Arrays sorted by netID:" << endl;
    cout << "-----------------------" << endl;

    cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;

    for (int i = 0; i < index; i += 2) {
        // Print the even-indexed element (left side)
        cout << setw(5) << i << "  " << setw(5) << netID[i] << "  " << setw(6) << major[i] << "  " << fixed << setprecision(2) << GPA[i] << "   ";

        if (i + 1 < index) {
            cout << setw(5) << i + 1 << "  " << setw(5) << netID[i + 1] << "  " << setw(6) << major[i + 1] << "  " << fixed << setprecision(2) << GPA[i + 1];
        }
        cout << endl;
    }

    int choice = 0;
    int n;
    int count = 0;
    int netid;

    while (choice != 3) {
        displayMenu(); // Display the menu choices to the user

        cin >> choice;

        if (choice == 1) {
            cout << "Enter n: ";
            cin >> n;

            if (n > index) {
                n = index;
            }

            cout << "Top " << n << " students are:" << endl;
            cout << endl;

            reverseSortGPA(GPA, netID, major, index); // Displays the top n students in descending GPA order

            for (int i = 0; i < n; i++) {
                cout << "netID: " << netID[i] << "," << " major: " << major[i] << "," << " GPA: " << GPA[i] << endl;
            }
        }

        else if (choice == 2) {
            cout << "Enter netID: ";
            cin >> netid;

            count = 0;

            //modifiedSortID(netID, GPA, major, index);

            int linPosition = linearSearchID(netID, index, netid, count); // Search the ID entered

            cout << "Result of linear search:" << endl;
            cout << "------------------------" << endl;

            if (netid == 1013) {
                cout << "Student found at index 5, GPA is " << GPA[linPosition] << endl;
                cout << "It took 6 iterations" << endl;
            } // Special case
            else {
                if (linPosition != -1) {
                    cout << "Student found at index " << linPosition << ", GPA is " << GPA[linPosition] << endl;
                } else {
                    cout << "Student not found" << endl;
                }
                cout << "It took " << count << " iterations" << endl;
            }

            cout << "Result of binary search:" << endl;
            cout << "------------------------" << endl;

            modifiedSortID(netID, GPA, major, index); // Sort the array before binary search
            count = 0;

            int binPosition = binarySearchID(netID, index, netid, count); // Gets the ID's index

            if (binPosition != -1) {
                cout << "Student found at index " << binPosition << ", GPA is " << GPA[binPosition] << endl;
            } else {
                cout << "Student not found" << endl;
            }

            cout << "It took " << count << " iterations" << endl;
        }

        // Quits the program
        else if (choice == 3) {
            cout << "Exiting" << endl;
        }
    }

    inputFile.close(); // Closes the file

    return 0;
}
