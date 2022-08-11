#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Header.h"

using namespace std;

int main() {
    vector<booking> bookingV; // creates vectors
    vector<hotel> hotelV;
    vector<room> roomV;
    vector<string> errorV;

    

    
    ReadFile(bookingV, hotelV, roomV, errorV); //passes vectors through to each program
    
    AssignRooms(bookingV, hotelV, roomV, errorV);
    
    PrintReport(bookingV, errorV);
    


}
