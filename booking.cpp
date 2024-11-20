#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
void display(string name,string phonenumber);
void bookticket(const std::string& filename);
struct Train {
    char id[5];            
    char name[50];
    char source[50];
    char destination[50];
    char date[11];        
    char time[10];        
};
struct passenger{
    string passid;
    string name;
    string phonenumber;
    string trainid;
};
void writepassengers(const string& filename, const vector<passenger>& pass) {
    ofstream wf(filename, ios::binary|ios::app);
    if (!wf) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (const auto& pass : pass) {
        wf.write(reinterpret_cast<const char*>(&pass), sizeof(pass));
    }
    wf.close();
}

void bookticket(const string& filename){
    srand(time(0));
    ifstream rf(filename,ios::binary);
    if (!rf) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    Train train;
    string name,phonenumber,source,destination,date,time,id;
    cout<<"enter source:";cin>>source;
    cout<<"enter destination:";cin>>destination;
    cout << "Trains availiable:\n";
    int n=0;
    while (rf.read(reinterpret_cast<char*>(&train), sizeof(Train))) {
        if (train.source==source&&train.destination==destination ){
            n+=1;
            cout<<" id:"<<train.id<< " date:"<<train.date<<" time:"<<train.time<<" train:"<<train.name<<endl;
        }
    }
    rf.close();
    if (n==0){
        cout<<"no trains availiable";
    }
    else{
    string id=to_string(rand());
    cout<<"enter trainid:";cin>>train.id;
    cout<<"enter name:";cin>>name;
    cout<<"enter phone number:";cin>>phonenumber;
    vector<passenger> pass;
    pass.push_back({id,name,phonenumber,train.id});
    writepassengers("passengers.dat",pass);
    cout<<"ticket booked"<<endl;
    display(name,phonenumber);}

}
void display(string name,string phonenumber){
    passenger pass;
    Train train;
    ifstream rf("passengers.dat",ios::binary);
    ifstream infile("trains.dat",ios::binary);
    int z;
    while (rf.read(reinterpret_cast<char*>(&pass),sizeof(pass))){
        if (pass.name==name&&pass.phonenumber==phonenumber){
            cout<<"THE TICKET DETAILS ARE:\n"<<"ticketid:"<<pass.passid;
            cout<<" name:"<<name<<" phonenumber:"<<phonenumber;
            while (infile.read(reinterpret_cast<char*>(&train),sizeof(train))){
                if (train.id==pass.trainid){
                    cout<<"\ntrain:"<<train.name<<" train departure:"<<train.source
                    <<" train destination:"<<train.destination
                    <<" date:"<<train.date
                    <<" departure time:"<<train.time;
                }
            }
            z=1;
        }
    }
    if (z!=1){
        cout<<"no details availiable";
    }

}
void cancelTicket(const string& passengerFile, const string& passengerID) {
    ifstream inFile(passengerFile, ios::binary);
    if (!inFile) {
        cerr << "Error opening passenger file for reading." << endl;
        return;
    }

    vector<passenger> passengers;
    passenger pass;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&pass), sizeof(passenger))) {
        if (passengerID != pass.passid) {
            passengers.push_back(pass);  // Keep passenger in the list
        } else {
            found = true;  // Mark as found if passenger ID matches
        }
    }
    inFile.close();

    if (!found) {
        cout << "No reservation found with Passenger ID: " << passengerID << endl;
        return;
    }

    ofstream outFile(passengerFile, ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for writing: " << passengerFile << endl;
        return;
    }

    for (const auto& p : passengers) {
        outFile.write(reinterpret_cast<const char*>(&p), sizeof(passenger));
    }
    outFile.close();

    cout << "Ticket with Passenger ID " << passengerID << " has been canceled successfully.\n";
}