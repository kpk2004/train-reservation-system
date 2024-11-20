#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "booking.cpp"
#include "display.cpp"
#include "food.cpp"
using namespace std;
int main(){
    int choice;
    cout<<"welcome to railways"<<endl<<"what would you like to do?"<<endl;
    cout<<"1.see availiable train data"<<endl;
    cout<<"2.book a ticket"<<endl;
    cout<<"3.cancel a ticket"<<endl;
    cout<<"4.see ticket details"<<endl;
    cout<<"5.search trains"<<endl;
    cout<<"choose:1,2,3,4or5:";cin>>choice;
    switch (choice) {
    case 1:
        showtraindata();
        break;
    case 2:
        bookticket("trains.dat");
        break;
    case 3:{
        string passid;
        cout<<"enter ticketid:";cin>>passid;
        cancelTicket("passengers.dat",passid);
        break;}
    case 4: {
        string name, phonenumber;
        cout << "Enter name: "; 
        cin >> name;
        cout << "Enter phone number: "; 
        cin >> phonenumber;
        display(name, phonenumber);
        break;
    }
    case 5:{
        int c;
        cout<<"1.search by date and time"<<endl;
        cout<<"2.search by source and destination"<<endl<<"choose 1 or 2:";
        cin>>c;
        switch (c){
            case 1:{
            string date,time;
            cout<<"enter date:";cin>>date;
            cout<<"enter time:";cin>>time;
            searchbydate(date,time);
            break;}
            case 2:{
            string source,destination;
            cout<<"enter source:";cin>>source;
            cout<<"enter destination:";cin>>destination;
            searchbydestination(source,destination);
            break;
            }
            default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
        break;
    }
    case 6:{
        string trainId, ticketId;

            cout << "Enter your Train Id : " << endl;
            cin >> trainId;
            cout << "Enter your Ticket Id : " << endl;
            cin >> ticketId;
            validate(trainId, ticketId);
    }
    default:
        cout << "Invalid choice, please try again." << endl;
        break;
}}