#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct movie{
    int is;
    string title;
    string genre;
    int year;
    double rating;
    double price;
    bool available;

};
const int MAX_MOVIES=100;
movie movies[MAX_MOVIES];
int moviecount=0;

void printMenu(){
    cout<<"\n **** MOVIE RENTAL SYSTEM ****\n";
    cout<<"1.Insert a new movie\n";
    cout<<"2.Display all movies\n";
    cout<<"3.Search movie\n";
    cout<<"4.Update movie\n";
    cout<<"5.Delete movie\n";
    cout<<"6.sort movies\n";
    cout<<"7.exit\n";
    cout<<"Enter your choice: ";

}

int main(){
     int choice;
    do{
        printMenu();
       
        cin>>choice;
        switch(choice){
            case 1:cout<<"insert New chosen\n";
            break;
            case 2:cout<<"Dispalay chosen\n";
            break;
            case 3:cout<<"Search chosen\n";
            break;
            case 4:cout<<"Update chosen\n";
            break;
            case 5:cout<<"Delete chosen\n";
            break;
            case 6:cout<<"sort chosen\n";
            break;
            case 7:cout<<"exit chosen\n";
            break;
            default:cout<<"Invalid choice, try again\n";
            break;


        }
     } while (choice != 7);
    
    return 0;
}




