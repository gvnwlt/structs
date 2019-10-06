//============================================================================
// Name        : Lab1-3.cpp
// Author      : Gavin Walters
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// FIXME (1): Define a data structure to hold bid information together as a single unit of storage.
struct BidInfo {
	string title;
	string fund;
	string vehicle;
	double bid_amt;
};

// FIXME (4): Display the bid values passed in data structure
/**
 * Display the bid information
 *
 * @param ?type? data structure containing the bid info
 */
void displayBid(BidInfo user_bid) {
    cout << "Title: " << user_bid.title << endl;
    cout << "Fund: " << user_bid.fund << endl;
    cout << "Vehicle: " << user_bid.vehicle << endl;
    cout << "Bid Amount: " << user_bid.bid_amt << endl;

    return;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


// FIXME (3): Store input values in data structure
/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
BidInfo getBid() {
    BidInfo bid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, bid.vehicle);

    cout << "Enter amount (be sure to enter a '$' before the amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.bid_amt = strToDouble(strAmount, '$');

    return bid;
}



/**
 * The one and only main() method
 */
int main() {

    // FIXME (2): Declare instance of data structure to hold bid information
	BidInfo user_bid;

    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // FIXME (5): Complete the method calls then test the program
        switch (choice) {
            case 1:
            	user_bid = getBid();
                break;
            case 2:
                displayBid(user_bid);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
