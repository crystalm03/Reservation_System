/* Authors: Hale Knox
*           Crystal McFarlane
*
* Project 1 for Computational Problem Solving II
*
* File: Passenger.cpp
* Contains: Passenger class implementation
* This file Sets and gets Passenger name, the amount of credits they currently have,
* and whether or not they are driving
*
* Addtional Notes/Changes:
*
*
*/

#include "Passenger.h"
using namespace std;

//Parses information into different variables
//Arguement names are in different languages to help differentiate between variables
void Passenger::SetPass(string nom, int monnais, bool chauffeur) {
    name = nom;
    credits = monnais;
    driver = chauffeur;
}

//Returns Passenger name
string Passenger::GetName() {
    return name;
}

