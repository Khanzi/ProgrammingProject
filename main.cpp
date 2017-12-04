
#include <iostream>//includes iostream for cout and cin
#include <string.h> //includes string functions
#include <cmath> //includes math functions
#include <fstream> //includes file reading functions
#include <iomanip> //includes manip functions
#include <string>
#include <time.h>

using namespace std;
void videoExtractor();
void customerExtractor();
void displayMenu();

struct video {
    string title;
    string stars;
    string producer;
    string director;
    string company;
    int copies;
public:
};

struct customer {
    string firstName;
    string lastName;
    string accountNumber;
    video rental[5];
public:
    void printInfo();
};


customer customers[100];
video videos[1000];
int i = 0;
int j = 0;
int main() { //starts the main function

    customerExtractor();
    videoExtractor();
    displayMenu();
    cout << videos[0].stars << endl;


    return(0);
}

void customerExtractor() {
    string line;
    ifstream infile;
    infile.open("/home/kahlil/CLionProjects/untitled1/customers.txt");
    do{
        infile >> customers[i].firstName;
        infile >> customers[i].lastName;
        infile >> customers[i].accountNumber;
        infile >> customers[i].rental[0].title;
        infile >> customers[i].rental[1].title;
        infile >> customers[i].rental[2].title;
        infile >> customers[i].rental[3].title;
        infile >> customers[i].rental[4].title;
        i++;
    } while (infile.good());
}
void videoExtractor() {
    string line;
    ifstream infile;
    infile.open("/home/kahlil/CLionProjects/untitled1/videos.txt");
    do{
        infile >> videos[j].title;
        infile >> videos[j].stars;
        infile >> videos[j].producer;
        infile >> videos[j].director;
        infile >> videos[j].company;
        infile >> videos[j].copies;
        j++;
    } while (infile.good());
}
/*
void customer::printInfo(){
    cout << "First Name:" <<firstName << endl;
    cout << "Last Name:" << lastName << end;
    cout << "Acc. Number" << accountNumber << endl;
    cout << "Rentals:" << endl;
    cout << rental[0] << endl;
    cout << rental[1] << endl;
    cout << rental[2] << endl;
    cout << rental[3] << endl;
    cout << rental[5] << endl;
}*/

void printVideoList(){
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "VIDEOS ON FILE" << endl;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    int r=0;
    while(r <= 100){
        if(videos[r].title==""){
            break;
        }
    cout << videos[r].title << " --- Copies: " << videos[r].copies << endl;
        r++;

}cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "" << endl;
    cout << "" << endl;}


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
            printVideoList();
        }
        if(selection==6){

        }
        if(selection==7){

        }
    } while(selection != 0);
}
