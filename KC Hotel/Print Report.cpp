#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "Header.h"

using namespace std;

void PrintReport(vector<booking>& bookingV, vector<string>& errorV) {
    ofstream fout("output.txt");
    int i;

    fout << " " << setw(40) << right << "Kansas City Internation Hotel" << " " << endl; // centers title

    for (i = 0; i < bookingV.size(); i++) { // goes through each booking and prints with formatting
        fout << bookingV.at(i).reservation << " " << setw(10) << left << bookingV.at(i).fName << " " << setw(13) << left << bookingV.at(i).lName;
        fout << setw(10) << left << bookingV.at(i).rType << setw(5) << right << bookingV.at(i).rNum << setw(10) << right << fixed << setprecision(2) << bookingV.at(i).totalCost << endl;
    }

    fout << endl << endl << "Error Records:" << endl << endl; // prints error section

    for (i = 0; i < errorV.size(); i++) { // prints all errors in vector
        fout << errorV.at(i) << endl;
    }

}
