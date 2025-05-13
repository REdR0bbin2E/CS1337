#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#define INFONUM 255

// patients structure definition
struct Patients {
    //fields
    int id;
    string fname;
    string lname;
    int vitals[3];
};

int main()
{
   //get the inputfile name from user and open it
  ifstream inputFile;
  string filename = "";
  cout << "Enter filename: \n";
  cin >> filename;
   inputFile.open(filename);
   
   if(!inputFile) // checking file validation
   {
    cout << "Could not open file\nExiting\n";
    exit(0);
   }
    //Dynamically create Patients array
    Patients patientsArray[INFONUM];
    
    
    // Read the header line and parse using istringstream Use setw(10) for First and last name.
   int numPatients = 0;
   string line = "";
   
   
       getline(inputFile, line);
       
           // Read the values into array of structures

       while(getline(inputFile,line) && numPatients < INFONUM)
       {
        istringstream iss(line);
        
        iss >> patientsArray[numPatients].id >> patientsArray[numPatients].fname >> patientsArray[numPatients].lname
            >> patientsArray[numPatients].vitals[0] >> patientsArray[numPatients].vitals[1] >> patientsArray[numPatients].vitals[2];
        numPatients++;
          
       }
       
           //Setw(4) for  for ID and other vitals
        cout << left << setw(4) << "ID" << setw(10) << "FN" << setw(10) << "LN" 
         << setw(4) << "BPU" << setw(4) << "BPL" << setw(4) << "Pulse" << endl;
    

    
    
    // Display the values
    //Use setw(10) for First and last name, Setw(4) for ID and other vitals
     for (int i = 0; i < numPatients-1; i++) {
        cout << left << setw(4) << patientsArray[i].id
             << setw(10) << patientsArray[i].fname
             << setw(10) << patientsArray[i].lname
             << setw(4) << patientsArray[i].vitals[0]
             << setw(4) << patientsArray[i].vitals[1]
             << setw(4) << patientsArray[i].vitals[2] << endl;
    }
    
    //close the file
    inputFile.close();
    
    //delete the pointer
}//end of main

//patientsinfo.txt
