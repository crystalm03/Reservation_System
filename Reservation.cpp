/* Authors: Hale Knox
*           Crystal McFarlane
*
* Project 1 for Computational Problem Solving II
*
* File: Reservation.cpp
* Contains: Implementation of Reservation.h
* This file contains the setters, getters, and delete function of
* the reservation system
*
* Addtional Notes/Changes:
*
*
*/

#include "Reservation.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Default constructor
bool Reservation::avail[18] = {
		true, true, true, true, true, true, true, true, true,
		true, true, true, true, true, true, true, true, true
};

//Setting default values for variables
Reservation::Reservation() {
	resNum = -1;
	pass = NULL;
}

//	Defining mutator functions - 
//	SetRes(), SetResDrive()
void Reservation::SetRes(Passenger* userPass, int cred) {
	for (int i = 0; i < 18; i++) {
		if (avail[i]) {
			resNum = i;
			cost = cred;
			avail[i] = false;
			pass = userPass;
			cout << "Reservation confirmed.  Reservation number is: " << resNum << endl;
			break;
		}
	}

}

void Reservation::SetResDrive(Passenger* userPass) {
	resNum = -2;
	pass = userPass;
}

//Delete reservation function
void Reservation::Clear() { 
	avail[resNum] = true;
	resNum = -1;
	pass = NULL;
}


//	Defining accessor functions - 
//		GetResNum(), GetResPass()

int Reservation::GetResNum() {
	return resNum;
}

Passenger* Reservation::GetResPass() {
	return pass;
}

//Printing reservation information
void Reservation::PrintRes() {
	if (pass == NULL) {
		cout << "Name: EMPTY, Seat: ";
	}
	else {
		cout << "Name: " << pass->GetName() << ", Seat: ";
	}
}