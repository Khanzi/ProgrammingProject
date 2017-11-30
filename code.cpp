//
// Created by Kahlil Wehmeyer on 11/21/17.
//
#include <iostream>//includes iostream for cout and cin
#include <string.h> //includes string functions
#include <cmath> //includes math functions
#include <fstream> //includes file reading functions
#include <iomanip> //includes manip functions
#include <string>
#include <time.h>
#include "prac.h"
using namespace std;

void videos::videoList() {
    ofstream list;
    string videoname, con;
    list.open("/Videos/List.txt");
    while(getline(list, videoname)){
            cout << videoname << endl;
    }
    cout << "This is the current list of videos, would you like to add more videos?" << endl;
    cin >> con;
    if (con == "Yes" | con == "yes" | con == "y" | con == "y"){
        addVideo();

}}
void videos::addVideo(){
    string moviename, stars, producer, director, company;
    int copies;

    cout << "Enter movie title" << endl;
    cin >> moviename;

    ofstream movie, list;
    movie.open("/Videos/" + moviename + ".txt");

    cout << "Enter Stars(Format: Name One, Name Two, Name Three, Name Four.):" << endl;
    getline(cin, stars);

    cout << "Enter Director Name:" << endl;
    getline(cin, director);

    cout << "Enter Producer Name:" << endl;
    getline(cin, producer);

    cout << "Enter Production Company:" << endl;
    getline(cin, company);

    cout << "Enter number of copies:" << endl;
    cin >> copies;

    movie << copies << endl;
    movie << moviename << endl;
    movie << stars << endl;
    movie << director << endl;
    movie << producer << endl;
    movie << company << endl;
    cout << movie.uppercase << " has been added." << endl;

    list.open("/Videos/List.txt");
    list << moviename << endl;


}

void customer::newCustomer(){ //Adds a new customer
    string customerName, lastFourSocial, email;
    long dateOfBirth;

    cout << "Please enter the customers first and last name" << endl;
    getline(cin, customerName);
    ofstream file;
    file.open("Customers/"+ customerName + ".txt");

    cout << "Date of Birth(DDMMYYYY):" << endl;
    cin >> dateOfBirth;

    cout << "Please enter email:" << endl;
    cin >> email;

    cout << "Last four numbers of social security number:" << endl;
    cin >> lastFourSocial;

    cout << "Customer Created" << endl;
    string customerID = customerName.substr(customerName.find_last_of(' ')+1) + lastFourSocial;
    file << customerID << endl;
    file << customerName <<  endl;
    file << dateOfBirth << endl;
    file << email << endl;
    file << "Customer Since:" << __DATE__ << endl;
    file.close();
    ofstream listFile;
    listFile.open("Customers/listofcustomers.txt");
    listFile << customerName << endl;

}
 //This prints the customer name and ID
void customer::printCustomerInfo(){
    string customerName;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~CUSTOMER LOOKUP~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Please enter the customer name:" << endl;
    cin >> customerName;
    cout << "Searching... " << endl;

    string namePending;
    ofstream listFile;
    listFile.open("Customers/listofcustomers.txt");
    while(getline(listFile, namePending)){
        if(namePending==customerName){
            string customerID;
            cout << customerName << endl;
            ofstream customerFile;
            customerFile.open("Customers/" + customerName + ".txt");
            getline(customerFile, customerID);
            cout << "Account ID: " << customerID << endl;
            customerFile.close();
            listFile.close();
            break;
        }

    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DONE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}