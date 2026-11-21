#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct movie{
    int id;
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

     bool insertMovie() {
        if (moviecount >= MAX_MOVIES){
            cout<<"library is full!\n";
            return false ;

        }
        movie m;
        cout<<"Enter movie ID: ";
        cin>>m.id;
        cin.ignore();
        cout<<"Enter movie title: ";
        getline(cin, m.title);
        cout<<"Enter movie genre:  ";
        getline(cin, m.genre);
        cout<<"Enter year of the movie: ";
        cin>>m.year;
        cout<<"Enter movie rating: ";
        cin>>m.rating;
        cout<<"Enter movie price: ";
        cin>>m.price;
        m.available =true;
        movies[moviecount]=m;
        moviecount++;
        cout<<"Movie added!\n";
        return 0;

     }
      void displayMovies(){
        if (moviecount==0){
            cout<<"No movies to show.\n";
            return;    
        }
        //header (printed once)
        cout<<"\n" <<left
        << setw(6)<<"ID"
        <<setw(25)<<"Title"
        <<setw(15)<<"Genre"
        <<setw(6)<<"Year"
        <<setw(8)<<"Rating"
        <<setw(8)<<"price"
        <<"status\n";
        cout<<string(77,'-')<<"\n";
        //one row per movie
        for (int i=0; i<moviecount;i++){
            cout<<left
            <<setw(6)<<movies[i].id
            <<setw(25)<<movies[i].title
            <<setw(15)<<movies[i].genre
            <<setw(6)<<movies[i].year
            <<fixed<<setprecision(1)<<setw(8)<<movies[i].rating
            <<fixed<<setprecision(2)<<setw(8)<<movies[i].price
            <<(movies[i].available? "Available":"Rented")
            <<"\n";
        }
      }
    
    





