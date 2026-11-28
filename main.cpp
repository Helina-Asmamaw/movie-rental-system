#include <iostream>
#include <fstream>
#include <string>
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



     bool insertMovie() {
        if (moviecount >= MAX_MOVIES){
            cout<<"library is full!\n";
            return false ;

        }
        movie m;
        cout<<"Enter movie ID: ";
        cin>>m.id;
        cin.ignore(1000, '\n');
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
        return true;

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
      int searchMovie(){
        int option;
        cout<<"search movie by 1.ID or 2.Title:";
        cin>>option;
        int id =0;
        string title;
        if (option==1){
            cout<<"Enter movie ID:";
            cin>>id;
        }
        else if(option==2){
            cout<<"Enter movie title:";
            cin.ignore(1000, '\n');
            getline(cin,title);
        }
        else{
            cout<<"Invalid option!\n";
            return -1;
        }
        for(int i=0; i<moviecount; i++){
            if((option==1 && movies[i].id==id) ||
        (option==2 && movies[i].title==title)){
            cout<<"found: "<<movies[i].title<<"(" <<movies[i].year<<"), Id"<<movies[i].id<<"\n";
            return i;
        }
        }
        cout<<"Movie not found!\n";
        return -1;


      }
      void updateMovie(){
        int index = searchMovie();
        if(index== -1){
            return;
        }
        int field;
        cout<<"Update 1.Title 2.Genre 3.Year 4. Rating 5.Price 6.Availability: ";
        cin>>field;
        switch(field){
            case 1: cout<<"New title: ";
              cin.ignore(1000,'\n');
              getline(cin,movies[index].title);
              break;
        case 2: cout<<"New genre: ";
             cin.ignore(1000,'\n');
             getline(cin,movies[index].genre);
             break;
        case 3: cout<<"New year: ";
             cin>>movies[index] .year;
             break;
        case 4: cout<<"New rating: ";
             cin>>movies[index].rating;
             break;
        case 5 : cout<<"New price: ";
        cin>>movies[index].price;
        break;
        case 6:{
            int status;
            cout<<"1.Available 0.Rented:  ";
            cin>>status;
            if(status != 0 && status != 1){
                cout<<"Invalid status!\n";
                return;
            }
            movies[index].available = (status == 1);
            break;
        }         
        }
      }
      void deleteMovie(){
        int index = searchMovie();
        if (index == -1){
            return;
        }
        for (int j =index; j< moviecount -1;movies[j];j++){
            movies[j]=movies[j+1];
        }
        moviecount--;
        cout<<"Movie deleted! \n";
      }
      void sortMovie(){
        if (moviecount == 0){
            cout<<"No movies to sort. \n";
            return;
        }
        int option;
        cout<<"Sort by 1.ID or 2.Title: ";
        cin>>option;
        if (option != 1 && option !=2){
            cout<<"Invalid option! \n";
            return;
        }
        for(int i =0; i<moviecount-1;i++){
            for (int j= i+1; j<moviecount;j++){
                if((option == 1 && movies[j].id<movies[i].id)|| (option==2 && movies[j].title<movies[i].title)){
                    swap(movies[i],movies[j]);
                }
            }
        }
        cout<<"Movies sorted!\n";
        displayMovies();
      }




    int main(){
     int choice;
    do{
        printMenu();
       
        if (!(cin>>choice)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"please enter a  valid number\n";
            choice=0;
            continue;
        }
        switch(choice){
            case 1: insertMovie();
            break;
            case 2: displayMovies();
            break;
            case 3: searchMovie();
            break;
            case 4: updateMovie();
            break;
            case 5: deleteMovie();
            break;
            case 6:sortMovie();
            break;
            case 7:cout<<"exit chosen\n";
            break;
            default:cout<<"Invalid choice, try again\n";
            break;

        }
     } while (choice != 7);
     return 0;
    }

    





