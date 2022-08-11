#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Header.h"

using namespace std;

void AssignRooms(vector<booking>& bookingV, vector <hotel>& hotelV, vector <room>& roomV, vector<string>& errorV) {
    int i, j;
    string error;
    
    for (i = 0; i < bookingV.size(); i++) { //goes through booking vector to start assigning rooms
        for (j = 0; j < hotelV.size(); j++) { // goes through hotel vector to find correct room and make it unavailable
            if (bookingV.at(i).rType == hotelV.at(j).rType) { // if the booking room type equals the hotel room
                if (hotelV.at(j).avail == 1) { // checks if the room is available
                    bookingV.at(i).rNum = hotelV.at(j).rNum;
                    bookingV.at(i).totalCost = hotelV.at(j).cost * bookingV.at(i).nights;
                    hotelV.at(j).avail = 0;
                    break;
                }

            }
        }
    }

    for (i = 0; i < bookingV.size(); i++) { // goes through again to find errors
        if (bookingV.at(i).rNum == 0) {
            bookingV.at(i).rType = bookingV.at(i).rType + "***"; //adds * to stand out the error
            error = "Error on Reservation: " + to_string(bookingV.at(i).reservation) + ". There is no room available.";
            errorV.push_back(error); // pushes error into vector
        }

    }

}
