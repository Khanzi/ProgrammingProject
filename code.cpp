//
// Created by kahlil on 12/3/17.
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

void customerExtractor() {
        string line;
        int counter=0;
        ifstream file;
        file.open("/home/kahlil/CLionProjects/untitled/customers.txt");
        while(getline(file, line)){
            customer(counter);
            counter.firstName = line;

        }
}
void videoExtractor() {
    string line;
    ifstream file;
    int numberOfLines;
    file.open("/home/kahlil/CLionProjects/untitled/customers.txt");
    while(getline(file, line)){

    }

}

void displayMenu(){
    int selection;
    do {
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "Video Store Interface:" << endl;
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "[1] Add a new customer" << endl;
        cout << "[2] Add a new video" << endl;
        cout << "[3] Rent a video" << endl;
        cout << "[4] Return a video" << endl;
        cout << "[5] List videos in the store" << endl;
        cout << "[6] Show video details" << endl;
        cout << "[7] List of videos rented by each customer" << endl;
        cout << "[0] Save & Exit" << endl;
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cin >> selection;

        if(selection==1){

        }
        if(selection==2){

        }
        if(selection==3){

        }
        if(selection==4){

        }
        if(selection==5){

        }
        if(selection==6){

        }
        if(selection==7){

        }
    } while(selection != 0);
}


/*
void videos::videoList() {
    ifstream list;
    string videoname, con;
    list.open("/home/kahlil/CLionProjects/untitled/Videos/List.txt");
    while(getline(list, videoname)){
        cout << videoname << endl;
    }
    cout << "This is the current list of videos, would you like to add more videos?(Y/N)" << endl;
    cin >> con;
    if (con == "Yes" | con == "yes" | con == "y" | con == "y"){
        addVideo();

    }}

void videos::addVideo(){
    string moviename, stars, producer, director, company;
    int copies;

    cout << "Enter movie title" << endl;
    getline(cin, moviename);

    ofstream movie, list;
    movie.open("/home/kahlil/CLionProjects/untitled/Videos/" + moviename + ".txt");

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
    cout << "Movie been added." << endl;

    list.open("/home/kahlil/CLionProjects/untitled/Videos/List.txt");
    list << moviename << endl;


}

void customer::newCustomer(){ //Adds a new customer
    string customerName, lastFourSocial, email;
    long dateOfBirth;

    cout << "Please enter the customers first and last name" << endl;
    getline(cin, customerName);
    ofstream file;
    file.open("/home/kahlil/CLionProjects/untitled/Customers/"+ customerName + ".txt");

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
    listFile.open("/home/kahlil/CLionProjects/untitled/Customers/listofcustomers.txt");
    listFile << customerName << endl;

}

//This prints the customer name and ID
void customer::printCustomerInfo(){
    string customerName;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~CUSTOMER LOOKUP~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Please enter the customer name:" << endl;
    getline(cin, customerName);
    cout << "Searching... " << endl;

    string namePending;
    ifstream listFile;
    listFile.open("/home/kahlil/CLionProjects/untitled/Customers/listofcustomers.txt");
    while(getline(listFile, namePending)){
        if(namePending==customerName){
            string customerID;
            cout << customerName << endl;
            ifstream customerFile;
            customerFile.open("/home/kahlil/CLionProjects/untitled/Customers/" + customerName + ".txt");
            getline(customerFile, customerID);
            cout << "Account ID: " << customerID << endl;
            customerFile.close();
            listFile.close();
            break;
        }

    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DONE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}*/