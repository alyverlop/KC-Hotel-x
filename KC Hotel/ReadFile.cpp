#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Header.h"

using namespace std;


void ReadFile(vector<booking>& bookingV, vector <hotel>& hotelV, vector <room>& roomV, vector<string>& errorV) {
    ifstream fin;
    char type;
    int i, j, k;
    room tempRoom;
    hotel tempHotel;
    booking tempBook;
    vector<string> row;
    string error;
    string  tempInput; // Input string
    stringstream inSS(tempInput);

    fin.open("CS201PGM2Hotel.csv"); //opens file

    if (!fin.is_open()) { // returns error if file cant open
        cout << "Could not open input.txt." << endl;
    }

    else {
        while (fin.good() || !fin.eof()) { // goes through loop until error or end of file
            fin >> type; // inputs ype to go through switch
            switch (type) {
                case 'R':
                    getline(fin, tempInput); // pulls in full csv line

                    inSS.clear(); // clears previous stream
                    inSS.str(tempInput); // enters new stream

                    i = 0;

                    while (getline(inSS, tempInput, ',')) { // breaks stream up into each section
                        if (i == 1) {  //starts at one to bypass the empty first imput after taking the type
                            tempRoom.rType = tempInput; // assigns to rtype
                        }
                        else if (i == 2) {
                            tempRoom.cost = stof(tempInput);// assigns to cost
                            roomV.push_back(tempRoom); //pushes struct into vector
                        }
                        i = i + 1; // increments i to move on to next input type
                    }
                    break;
                case 'H':
                    getline(fin, tempInput); // pulls in full csv line

                    inSS.clear(); // clears previous stream
                    inSS.str(tempInput); // enters new stream

                    while (getline(inSS, tempInput, ',')) { // breaks stream up into each section
                        row.push_back(tempInput); // assigns everything into row vectore

                    }

                    if(!IsNumber(row[1])){ // checks if there is an error by checking if the first input is a number
                        error = "Error on room number: " + row[1] +" is not a valid room number."; //creates error if its not a number
                        errorV.push_back(error); //pushes into error vector
                    }
                    else { // if no errors
                        tempHotel.rNum = stoi(row[1]); // assigns each section into the approriate area
                        tempHotel.rType = row[2];
                        tempHotel.avail = 1;
                        hotelV.push_back(tempHotel); // pushes temp into the vector
                    }
                    row.pop_back();// three pop backs to clear vector
                    row.pop_back();
                    row.pop_back();
                    
                    break;
                case 'B':
                    getline(fin, tempInput); // pulls in full csv line

                    inSS.clear(); // clears previous stream
                    inSS.str(tempInput); // enters new stream

                    while (getline(inSS, tempInput, ',')) { // breaks stream up into each section
                        row.push_back(tempInput); // assigns everything into row vector
                    }

                    if (!IsNumber(row[1]) || !IsNumber(row[5])) {// checks if there is an error by checking if the 1st and 5th input is a number
                        error = "Error on customer: "+ row[2] + " " + row[3] + ". Invalid data in input string.";
                        errorV.push_back(error);// adds info into error vector if error present
                    }
                    else { // if no errors
                        tempBook.reservation = stoi(row[1]);// assigns each section into the approriate area
                        tempBook.fName = row[2];
                        tempBook.lName = row[3];
                        tempBook.rType = row[4];
                        tempBook.nights = stod(row[5]);
                        tempBook.rNum = 0;
                        tempBook.totalCost = 0;
                        bookingV.push_back(tempBook); // assigns into vector after every variable is assigned
                    }

                    row.pop_back();// 6 pop backs to clear vector
                    row.pop_back();
                    row.pop_back();
                    row.pop_back();
                    row.pop_back();
                    row.pop_back();
                    break;
                default:
                    break;
            }
            type = 'd'; // resets type each time so it doesnt create an endless loop
        }

        fin.close(); // closes file

        for (j = 0; j < hotelV.size(); j++) { // goes through each room in vector
            for (k = 0; k < roomV.size(); k++) { // goes through room to find the right room for price
                if (hotelV.at(j).rType == roomV.at(k).rType) {
                    hotelV.at(j).cost = roomV.at(k).cost; //assigns available room to the cost of the matching room type
                    
                }
            }
        }
    }
}

