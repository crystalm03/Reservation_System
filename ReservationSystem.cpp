
 /* Authors: Hale Knox
 *           Crystal McFarlane
 * 
 * Project 1 for Computational Problem Solving II
 * 
 * Reservation system for Quiddich team split between 5 cars
 * Can add, modify, delete, or print current reservations
 * Made using Parent/Daughter classes, friend funtions, and vectors
 * 
 * 
 * 
 * 
 * Addtional Notes/Changes:
 * 
 *
 * 
 */
   
   


#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Reservation.h"
#include "Passenger.h"
#include <fstream>

using namespace std;

Pickup purplePickup;
Compact redCompact;
Compact blueCompact;
Compact yellowCompact;
Sedan blueSedan;
Sedan greenSedan;

vector<Vehicle> AllCars = {purplePickup, redCompact, blueCompact, yellowCompact, blueSedan, greenSedan};
//AllCars allows for searching through all reservations, car by car.
//Why globals?

void makeRes(Passenger *pass){
    char type;
    char color;
    char seatType;
    int seatNum;
    Reservation *res;                                                               //Current reservation to work on
    if (pass->credits == 0) {                                                       //Check for sufficient credits
        cout << "Not enough credits to proceed, returning to main menu." << endl;
        }
    else{
        cout << "Total available credits: " << pass->credits << endl;               //Print credits

        cout << "Enter type of Car (P - Pickup, C - Compact, S - Sedan)" << endl;
        cin >> type;
    }
    switch(type){
        case 'P':                                                                   //User choses Pickup
            cout << " You have chosen Pickup" << endl;      
            res = AllCars[0].GetSeat(1);                                            //Pickup only has 1 seat available
            if (res->GetResNum() == -1){                                            //Checks if seat is taken (There is only one available)
                if (pass->credits >= 5){                                            //If user has enough credits, deduct from current amount
                    pass->credits = pass->credits - 5;
                    res->SetRes(pass, 5);                                           //Sets reservation
                }
                else{
                    cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                    break;
                }
            }
            else{
                cout << "Seat is taken." << endl;                        
            }
            break;
        case 'C':
            cout << "You have chosen Compact" << endl;                              //User chooses Compact
            cout << "Enter Color (R - Red, B - Blue, Y - Yellow)";
            cin >> color;
            switch(color){
                case 'R':
                    cout << "You have chosen Red Compact." << endl;
                    cout << "***************************" << endl;
                    cout << "*   D          2          *" << endl;
                    cout << "*   3          4          *" << endl;
                    cout << "***************************" << endl;
                    cout << "Seats Available: ";
                    for (int i = 1; i < 4; i++){
                        res = AllCars[1].GetSeat(i);
                        if (res->GetResNum() == -1){
                            cout << i + 1 << " ";
                        }
                    }
                    cout << "Enter seat number: ";
                    cin >> seatNum;
                    res = AllCars[1].GetSeat(seatNum - 1);                          //Sets current reservation to blank one in car
                    
                    if (res->GetResNum() == -1){                                    //Check if seat is taken
                        if (seatNum == 2) {
                            if (pass->credits >= 5){                                //Check credits
                                pass->credits = pass->credits - 5;                  //Deducts credits
                                res->SetRes(pass, 5);                               //Make reservation
                            }
                            else{
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                        
                        else{
                            if (pass->credits >= 3){                                //Check credits
                                pass->credits = pass->credits - 3;                  //Deduct credits
                                res->SetRes(pass, 3);                               //Set reservation
                            }
                            else{
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                        break;
                    }
                    else{
                        cout << "Seat is taken." << endl;
                    }
                case 'B':                                                            //Blue Compact chosen
                    cout << "You have chosen Blue Compact." << endl;                   
                    cout << "***************************" << endl;
                    cout << "*   D          2          *" << endl;
                    cout << "*   3          4          *" << endl;
                    cout << "***************************" << endl;
                    cout << "Seats Available: ";
                    for (int i = 1; i < 4; i++){
                        res = AllCars[2].GetSeat(i);
                        if (res->GetResNum() == -1){
                            cout << i + 1 << " ";
                        }
                    }
                    cout << "Enter seat number: ";
                    cin >> seatNum;
                    res = AllCars[2].GetSeat(seatNum - 1);
                    if (res->GetResNum() == -1){                                       //Checks if seat is taken
                        if (seatNum == 2) {                                            //If front seat
                            if (pass->credits >= 5){                                   //Check credits
                                pass->credits -= 5;                                    //Deducts credits
                                res->SetRes(pass, 5);                                  //Set reservation
                            }
                            else {
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                        else{
                            if (pass->credits >= 3){                                   //Check credits 
                                pass->credits -= 3;                                    //Deduct credits
                                res->SetRes(pass, 3);                                  //Check reservation
                            }
                            else {
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                    }
                    else{
                        cout << "Seat is taken." << endl;
                    }
                    break;
                    
                case 'Y':
                    cout << "You have chosen Yellow Compact." << endl;
                    cout << "***************************" << endl;
                    cout << "*   D          2          *" << endl;
                    cout << "*   3          4          *" << endl;
                    cout << "***************************" << endl;
                    cout << "Seats Available: ";
                    for (int i = 1; i < 4; i++){
                        res = AllCars[3].GetSeat(i);
                        if (res->GetResNum() == -1){                                   //Check if seat taken
                            cout << i + 1 << " ";
                        }
                    }
                    cout << "Enter seat number: " << endl;
                    cin >> seatNum;
                    res = AllCars[3].GetSeat(seatNum - 1);
                    if (res->GetResNum() == -1){
                        if (seatNum == 2) {
                            if (pass->credits >= 5){                                    //Check Credits
                                pass->credits = pass->credits - 5;                      //Deduct Credits
                                res->SetRes(pass, 5);                                   //Create reservation
                            }
                            else {
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                        else{
                            if (pass->credits >= 3){                                    //Check credits
                                pass->credits = pass->credits - 3;                      //Deduct credits
                                res->SetRes(pass, 3);                                   //Set reservation
                            }
                            else{
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                    }
                    else{
                        cout << "Seat is taken." << endl;
                    }
                    break;
                    
            }
            break;
        case 'S':
            cout << "You have chosen Sedan" << endl;                                    //Sedan chosen
            cout << "Enter Color (B - Blue , G - Green)" << endl;
            cin >> color;
            switch (color){
                case 'B':                                                               //Blue Sedan chosen
                    cout << "You have chosen Blue Sedan" << endl;
                    cout << "Enter seat number: " << endl;
                    cout << "****************************" << endl;
                    cout << "*   D           2          *" << endl;
                    cout << "*   3     4     5          *" << endl;
                    cout << "****************************" << endl;
                    cout << "Seats available: ";
                    for (int i = 1; i < 5; i++){
                        res = AllCars[4].GetSeat(i);
                        if (res->GetResNum() == -1){                                    //Check if seat taken
                            cout << i + 1 << " ";
                        }
                    }
                    cin >> seatNum;
                    res = AllCars[4].GetSeat(seatNum - 1);
                    if (res->GetResNum() == -1){                
                        if (seatNum == 2) {                                             //Front seat chosen
                            if (pass->credits >= 5){                                    //Check credits                            
                                pass->credits -= 5;                                     //Deduct credits
                                res->SetRes(pass, 5);                                   //Create reservation
                            }
                            else {
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                        else if (seatNum == 3 || seatNum == 5){                         //Back window seats chosen
                            if (pass->credits >= 2){                                    //Check, deduct, and create reservation
                                pass->credits -= 2;
                                res->SetRes(pass, 2);
                            }
                            else{
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                        
                        else{
                            if (pass->credits >= 1){                                    //Back middle seat chosen
                                pass->credits -= 1;                                     //Check, deduct, and create reservation
                                res->SetRes(pass, 1);
                            }
                            else{
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                    }
                    else{
                        cout << "Seat is taken." << endl;
                    }
                    break;
                case 'G':
                    cout << "You have chosen Green Sedan" << endl;
                     
                    cout << "****************************" << endl;
                    cout << "*   D           2          *" << endl;
                    cout << "*   3     4     5          *" << endl;
                    cout << "****************************" << endl;
                    cout << "Seats Available: ";
                    for (int i = 1; i < 5; i++){
                        res = AllCars[5].GetSeat(i);
                        if (res->GetResNum() == -1){
                            cout << i + 1 << " ";
                        }
                    }
                    cout << "Enter seat number: ";
                    cin >> seatNum;
                    res = AllCars[5].GetSeat(seatNum - 1);
                    if (res->GetResNum() == -1){
                        if (seatNum == 2) {                                             //Front seat chosen
                            if (pass->credits >= 5){                                    //Check, deduct, and create reservation
                                pass->credits = pass->credits - 5;
                                res->SetRes(pass, 5);
                            }
                            else{
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                        else if (seatNum == 4) {                                         //Back middle seat chosen
                            if (pass->credits >= 1){                                     //Check, deduct, and create reservation
                                pass->credits = pass->credits - 1;
                                res->SetRes(pass, 1);
                            }
                            else {
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                        else{
                            if (pass->credits >= 2){                                    //Check, deduct, and create reservation
                                pass->credits = pass->credits - 2;
                                res->SetRes(pass, 2);
                            }
                            else {
                                cout << "Not enough credits for that seat. You have " << pass->credits << " credits." << endl;
                                break;
                            }
                        }
                    }
                    else{
                        cout << "Seat is taken." << endl;
                    }
                    break;
            }
        }
    }

int main(){
    
    for (int i = 0; i < 18; i++){                                                   //Initialize reservation availability
        Reservation::avail[i] = true;
    }                      
    
    
    Passenger *pass;                                                                //Current passenger
    Reservation *resv;
    vector<Passenger> pList (24);                                                   //Stores all passengers
    string userName;
    fstream datafile;
    datafile.open("quidditch_team.dat");         //File path
    string currentName, currentNameF, currentNameL, money;
    int currentCredits;
    bool currentDriver;
    if(datafile.is_open()) {
        for (int i = 0; i < 6; i++){                                                //Read in drivers
            getline(datafile, currentNameF, ' ');
            getline(datafile, currentNameL);
            currentName = currentNameF + " " + currentNameL;
            pList[i].SetPass(currentName, 0, true);
            resv = AllCars[i].GetSeat(0);
            resv->SetResDrive(&pList[i]);
        }
        for (int i = 6; i < 24; i++){                                                //Read in passengers
            getline(datafile, currentNameF, ' ');
            getline(datafile, currentNameL, ' ');
            currentName = currentNameF + " " + currentNameL;
            getline(datafile, money);
            currentCredits = stoi(money);
            pList[i].SetPass(currentName, currentCredits, false);
        }
        datafile.close();
    }
    else {
        cout << "Error, datafile not found!" << endl;
    }
    char commandIn;                                                                     //Command selection
    commandIn = 'x';
    cout << "\033[0m" << endl;
    cout << "*******************************************" << endl;
    cout << "***********Reservation System**************" << endl;
    cout << "*******************************************" << endl;
    while (commandIn != 'E'){
        cout << "Please enter your command:" << endl << "(C - Create, M - Modify, D - Delete, P - Print All, E - Exit)" << endl;
        cin >> commandIn;                                                                //Take in command
        if (commandIn == 'C'){                                                           //Create
            cout << "Please enter your name: ";
            cin.ignore();
            getline(cin, userName);
            for (int i = 0; i < 24; i++){                                                //Find name in list of names
                if (pList.at(i).GetName() == userName){
                    pass = &pList.at(i);
                    makeRes(pass);
                }
            }
        }
    
        else if (commandIn == 'M'){
            int userRes;                                                                //Reservation to edit
            Reservation *res;
            Passenger *pass;
            cout << "Enter reservation number to modify: ";
            cin >> userRes;
            int i = 0;
            bool found = false;
            while (i < 6 && !found) {
                for (int j=0; j < AllCars[i].seats.size(); j++){                        //Find reservation, clear, then make new one
                    res = AllCars[i].GetSeat(j);
                    if (res->GetResNum() == userRes){
                        pass = res->GetResPass();
                        pass->credits += res->cost;
                        res->Clear();
                        makeRes(pass);
                        found = true;
                        break;
                    }
                }

                i++;
            }
            if (!found){
                cout << "Reservation not found." << endl;
            }
        }
        else if (commandIn == 'D'){
            Reservation *res;
            int userRes;                                                                //Reservation to delete
            cout << "Enter reservation number: ";
            Passenger *pass;
            cin >> userRes;
            for (int i = 0; i < 6; i++){
                for (int j=0; j < AllCars[i].seats.size(); j++){                        //Find reservation and clear
                    res = AllCars[i].GetSeat(j);
                    if (res->GetResNum() == userRes){
                        pass = res->GetResPass();
                        pass->credits += res->cost;
                        res->Clear();
                        continue;
                    }
                }
            }
            cout << "Reservation not found." << endl;
        }
        else if (commandIn == 'P'){
            string passwd;
            Reservation *res;
            cout << "Enter password: ";
            cin >> passwd;
            if (passwd == "password"){                                                  //Hardcoded password
                for (int i = 0; i < 6; i++){
                    cout << endl << "Car " << i + 1 << endl;
                    cout << "--------------------------------------" << endl;
                    for (int j=0; j < AllCars[i].seats.size(); j++){
                        res = AllCars[i].GetSeat(j);                                    //Go through each car and seat and print
                        res->PrintRes();
                        cout << j + 1 << endl;                                          //Print seat number
                    }
                }
            }
            else {
                cout << "Incorrect Password" << endl;
                break;
            }
        }
    }
    ofstream outfile;                                                                   //Output file
    outfile.open("out.dat");
    for (int i = 0; i < 6; i++){
        outfile << pList[i].GetName();                                                  //Write drivers (no credits)
    }
    for (int i = 6; i < 24; i++){
        outfile << pList[i].GetName() << " " << pList[i].credits << endl;               //Write names and credits
    }
    outfile.close();
}