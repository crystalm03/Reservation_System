/* Authors: Hale Knox
*           Crystal McFarlane
*
* Project 1 for Computational Problem Solving II
*
* File: Vehicle.cpp
* Contains: Vehicle class implementation
* This file contains the setters and getters for the seats available in each vehicle
* as well as prints available seats
*
* Addtional Notes/Changes:
*
*
*/

#include "Vehicle.h"
#include <iostream>
#include <vector>
#include "Reservation.h"
using namespace std;

//	Defining mutator functions - 
//	SetSeat()
//Sets a seat to a passenger
void Vehicle::SetSeat(int userSeat, Reservation userPass) {
	seats[userSeat] = userPass;
}

//Get seat function returns a passenger's seat
Reservation* Vehicle::GetSeat(int userSeat) {
	return &seats[userSeat];
}

//Prints a list of all available vehicles
void Vehicle::PrintList() {
	for (int i = 0; i < seats.size(); i++) {
		seats.at(i).PrintRes();
	}
}

//Interates through available seats in class: Sedan
Sedan::Sedan() {
	for (int i = 0; i < 5; i++) {
		seats.push_back(Reservation());
	}
}

//Prints all seats in Sedan
void Sedan::PrintSedan() {
	for (int i = 0; i < 5; i++) {
		seats.at(i).PrintRes();
	}
}

//Interates through available seats in class: Pickup
Pickup::Pickup() {
	for (int i = 0; i < 2; i++) {
		seats.push_back(Reservation());
	}
}

//Prints all seats in Pickup
void Pickup::PrintPickup() {
	for (int i = 0; i < 2; i++) {
		seats.at(i).PrintRes();
	}
}

//Interates through available seats in class: Compact
Compact::Compact() {
	for (int i = 0; i < 4; i++) {
		seats.push_back(Reservation());
	}
}

//Prints all seats in Compact
void Compact::PrintCompact() {
	for (int i = 0; i < 4; i++) {
		seats.at(i).PrintRes();
	}
}