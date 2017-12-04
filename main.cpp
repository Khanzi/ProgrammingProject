#include "prac.h"

using namespace std;


customer customers[100];
video videos[1000];
int i = 0;
int main() { //starts the main function

    customerExtractor();
    videoExtractor();
    //displayMenu();
    cout << customers[1].firstName << endl;


    return(0);
}

void customerExtractor() {
    string line;
    ifstream infile;
    infile.open("/home/kahlil/CLionProjects/untitled/customers.txt");
    do{
        infile >> customers[i].firstName;
        infile >> customers[i].lastName;
        infile >> customers[i].accountNumber;
        infile >> customers[i].videos[0].title;
        infile >> customers[i].videos[1].title;
        infile >> customers[i].videos[2].title;
        infile >> customers[i].videos[3].title;
        infile >> customers[i].videos[4].title;
        i++;
    } while (infile.good());
}
void videoExtractor() {
    string line;
    ifstream infile;
    infile.open("/home/kahlil/CLionProjects/untitled/videos.txt");
    do{
        infile >> videos[i].title;
        infile >> videos[i].stars;
        infile >> videos[i].producer;
        infile >> videos[i].director;
        infile >> videos[i].company;
        infile >> videos[i].copies;
        i++;
    } while (infile.good());
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
