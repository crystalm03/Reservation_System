/* Authors: Hale Knox
*           Crystal McFarlane
*
* Project 1 for Computational Problem Solving II
*
* File: Passenger.h
* Contains: Passenger class
* This header file defines Printing and Setting of Passengers inputted
* Determines whether or not a passenger is a driver
*
* Addtional Notes/Changes:
*
*
*/

#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
class Passenger

{
private:
	std::string name;
	bool driver;

public:
	//add a set and get credits function, move credits from line 19 to under private
	void SetPass(std::string nom, int monnais, bool chauffeur);		//Arguements are in other languages to assist with differention														
	int credits;
	std::string GetName();									//Get function for passenger name
};

#endif
