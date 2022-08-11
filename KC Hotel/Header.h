#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct booking { // create structs in header to be used everywhere
    int reservation;
    string fName;
    string lName;
    string rType;
    int nights;
    int rNum;
    double totalCost;
};

struct hotel {
    int rNum;
    string rType;
    bool avail;// when read in, all should be marked ‘available’
    double cost;
};

struct room {
    string rType;
    double cost;
};

//all vectors are passby so they can be edited in each fuction

void ReadFile(vector<booking>& bookingV, vector <hotel>& hotelV, vector <room>& roomV, vector<string>& errorV);

void AssignRooms(vector<booking>& bookingV, vector <hotel>& hotelV, vector <room>& roomV, vector<string>& errorV);

void PrintReport(vector<booking>& bookingV, vector<string>& errorV);

bool IsNumber(string input); // returns true if its a number
