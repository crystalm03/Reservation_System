/* Authors: Hale Knox
*           Crystal McFarlane
*
* Project 1 for Computational Problem Solving II
*
* File: Reservation.h
* Contains: Reservation class
* This header file defines Reservation numbers and passengers
* Sets a reservation number to each passenger
*
* Addtional Notes/Changes:
*
*
*/

#ifndef RESERVATION_H
#define RESERVATION_H
#include <vector>
#include "Passenger.h"

class Reservation
{
private:
	int resNum;
	Passenger* pass;

public:
	Reservation();
	int GetResNum();
	Passenger* GetResPass();
	void SetRes(Passenger* pass, int cred);
	void SetResDrive(Passenger* pass);
	void Clear();
	void PrintRes();
	static bool avail[18];
	int cost;
};
#endif