
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
void showVideoDetails();
void returnAVideo();
void videosByCustomer();
void customerSave();
void videoSave();

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
    string rental;
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
    customerSave();
    videoSave();

    return(0);
}

void customerExtractor() {
    i = 0;
    ifstream infile;
    infile.open("/home/kahlil/CLionProjects/untitled1/customers.txt");
    do{
        getline(infile, customers[i].firstName);
        getline(infile, customers[i].lastName);
        getline(infile, customers[i].accountNumber);
        getline(infile, customers[i].rental);
        i++;
    } while (infile.good());
    infile.close();
}
void videoExtractor() {
    j = 0;
    string temp;
    ifstream infile;
    infile.open("/home/kahlil/CLionProjects/untitled1/videos.txt");
    do{
        getline(infile, videos[j].title);
        getline(infile, videos[j].stars);
        getline(infile, videos[j].producer);
        getline(infile, videos[j].director);
        getline(infile, videos[j].company);
        getline(infile, temp);
        videos[j].copies = stoi(temp);

        j++;
    } while (infile.good());
    infile.close();
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
void addACustomer() {
    int openPos;
    for(int q = 0; q <= 100; q++){
        if(customers[q].firstName==""){
            openPos = q;
            cout << "Enter Customer First Name;" << endl;
            cin >> customers[openPos].firstName;
            cout << "Enter Customer Last Name;" << endl;
            cin >> customers[openPos].lastName;
            customers[openPos].accountNumber=to_string(openPos);
            customers[openPos].rental = "-";
            break;
        }
    }
    cout << customers[openPos].firstName << " has been added." << endl;
}
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
void showVideoDetails() {
    string query;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "Enter Title To Display Details" << endl;
    getline(cin, query);
    for(int q=0; q <= 1000; q++){
        if(videos[q].title==query){
            cout << "Title: " << videos[q].title << endl;
            cout << "Stars: " << videos[q].stars << endl;
            cout << "Director: " << videos[q].director << endl;
            cout << "Producer: " << videos[q].producer << endl;
            cout << "Production Company: " << videos[q].company << endl;
            cout << "Copies: " << videos[q].copies << endl;
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        }
    }
}
void rentAVideo() {
    string first, last, title;
    int custNum, vidNum;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "RENT A VIDEO" << endl;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "Please insert the customers first name: " << endl;
    getline(cin, first);
    cout << "Please insert the customers last name: " << endl;
    getline(cin, last);
    cout << "Please insert movie title: " << endl;
    getline(cin, title);

    for(int i=0; i <= 100; i++){
        if(customers[i].firstName==first & customers[i].lastName==last){
            custNum = i;
            break;
        }
    }
    for(int i=0; i <= 1000; i++){
        if(videos[i].title==title){
            vidNum = i;
            break;
        }
    }

    if(videos[vidNum].copies<1){ //this should take me back to the menu
        cout << "!!! OUT OF COPIES !!!" << endl;
        return;
    }

    if(customers[custNum].rental!="-"){ //this should take me back to the menu
        cout << "!!! CUSTOMER HAS NOT RETURNED PREVIOUS RENTAL !!!" << endl;
        return;
    }

    customers[custNum].rental = videos[vidNum].title;
    videos[vidNum].copies--;
    cout << videos[vidNum].title << " rented to " << customers[custNum].firstName << " " << customers[custNum].lastName << endl;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

}
void returnAVideo() {
    string first, last, title;
    int custNum, vidNum;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "RETURN A VIDEO" << endl;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "Please insert the customers first name: " << endl;
    getline(cin, first);
    cout << "Please insert the customers last name: " << endl;
    getline(cin, last);
    cout << "Please insert movie title: " << endl;
    getline(cin, title);

    for(int i=0; i <= 100; i++){
        if(customers[i].firstName==first & customers[i].lastName==last){
            custNum = i;
            break;
        }
    }
    for(int i=0; i <= 1000; i++){
        if(videos[i].title==title){
            vidNum = i;
            break;
        }
    }

    if(customers[custNum].rental!=title){
        cout << "ERROR: Customer has not rented out this film: " << title <<  endl;
    }

    customers[custNum].rental="-";
    videos[vidNum].copies++;
    cout << "SUCCESS: " << videos[vidNum].title << " has been returned" << endl;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
}
void videosByCustomer() {
        for(int i=0; i < 100; i++){
            if(customers[i].rental != "-") {
                cout << customers[i].firstName << " " << customers[i].lastName << " : " << customers[i].rental << endl;
            }

        }
}
void displayMenu(){
    string selection;
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
        getline(cin, selection);

        if(selection=="1"){
            addACustomer();
        }
        if(selection=="2"){
            addAVideo();
        }
        if(selection=="3"){
            rentAVideo();

        }
        if(selection=="4"){
            returnAVideo();

        }
        if(selection=="5"){
            printVideoList();
        }
        if(selection=="6"){
            showVideoDetails();

        }
        if(selection=="7"){
            videosByCustomer();

        }
    } while(selection != "0");
}
void customerSave() {
    ofstream outfile;
    outfile.open("/home/kahlil/CLionProjects/untitled1/customers.txt");
    for(int i =0; i < 100; i++){
        outfile << customers[i].firstName << endl;
        outfile << customers[i].lastName << endl;
        outfile << customers[i].accountNumber << endl;
        outfile << customers[i].rental << endl;
    }
    outfile.close();
}
void videoSave() {
    ofstream outfile;
    outfile.open("/home/kahlil/CLionProjects/untitled1/videos.txt");
    for(int i =0; i < 1000; i++){
        outfile << videos[i].title << endl;
        outfile << videos[i].stars << endl;
        outfile << videos[i].producer << endl;
        outfile << videos[i].director << endl;
        outfile << videos[i].company << endl;
        outfile << videos[i].copies << endl;
    }
    outfile.close();
}