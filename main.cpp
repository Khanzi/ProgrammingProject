
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
void addAVideo();
void addACustomer();

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

    //customerExtractor();
    //videoExtractor();
    displayMenu();


    return(0);
}

void customerExtractor() {
    string line;
    ifstream infile;
    infile.open("/home/kahlil/CLionProjects/untitled1/customers.txt");
    do{
        getline(cin, customers[i].firstName);
        getline(cin, customers[i].lastName);
        infile >> customers[i].accountNumber;
        getline(cin, customers[i].rental[0].title);
        getline(cin, customers[i].rental[1].title);
        getline(cin, customers[i].rental[2].title);
        getline(cin, customers[i].rental[3].title);
        getline(cin, customers[i].rental[4].title);
        i++;
    } while (infile.good());
}
void videoExtractor() {
    string line;
    ifstream infile;
    infile.open("/home/kahlil/CLionProjects/untitled1/videos.txt");
    do{
        getline(cin, videos[j].title);
        getline(cin, videos[j].stars);
        getline(cin, videos[j].producer);
        getline(cin, videos[j].director);
        getline(cin, videos[j].company);
        infile >> videos[j].copies;
        j++;
    } while (infile.good());
}
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
/*void addACustomer() {
    int openPos;
    for(int q = 0; q <= 100; q++){
        if(customers[q].firstName==""){
            openPos = q;
            cout << "Enter Customer First Name;" << endl;
            cin >> customers[openPos].firstName;
            cout << "Enter Customer Last Name;" << endl;
            cin >> customers[openPos].lastName;
            customers[openPos].accountNumber=openPos;
            customers[openPos].rental[0] = "-";
            customers[openPos].rental[0] = "-";
            customers[openPos].rental[0] = "-";
            customers[openPos].rental[3] = "-";
            customers[openPos].rental[4] = "-";
            break;
        }
    }
    cout << customers[openPos].firstName << " has been added." << endl;
}*/


void addAVideo() {
    int openPos;
    for(int q = 0; q < 1000; q++){
        if(videos[q].title==""){
            openPos=q;
            cout << " Enter Video title: " << endl;
            getline(cin, videos[openPos].title);
            cout << "Enter Stars: " << endl;
            getline(cin, videos[openPos].stars);
            cout << "Enter Director: " << endl;
            getline(cin, videos[openPos].director);
            cout << "Enter Producer: " << endl;
            getline(cin, videos[openPos].producer);
            cout << "Enter Company :" << endl;
            getline(cin, videos[openPos].company);
            cout << "Enter # of Copies: " << endl;
            cin >> videos[openPos].copies;
            break;
        }
    }
    cout << videos[openPos].title << " has been added" << endl;
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
            void addACustomer();
        }
        if(selection==2){
            void addAVideo();
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
