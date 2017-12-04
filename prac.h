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
    string stars[3];
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
    video videos[5];
public:
};
