/* Authors: Hale Knox
*           Crystal McFarlane
*
* Project 1 for Computational Problem Solving II
*
* File: Vehicle.h
* Contains: Vehicle class
* This header file defines all available vehicles
*
* Addtional Notes/Changes:
*
*
*/

#ifndef VEHICLE_H
#define VEHICLE_H
#include "Reservation.h"
class Vehicle
{
private:
	Passenger driver;

protected:

	std::vector<int> cost;

public:
	void PrintList();
	Reservation* GetSeat(int seat);
	std::vector<Reservation> seats;
	void SetSeat(int seat, Reservation pass);
};

class Sedan : public Vehicle
{
public:
	Sedan();
	void PrintSedan();
};

class Pickup : public Vehicle
{

public:
	Pickup();
	void PrintPickup();
};

class Compact : public Vehicle
{

public:
	Compact();
	void PrintCompact();

};
#endif