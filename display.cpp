#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
void allrecords(){
    Train train;
    ifstream rf("trains.dat",ios::binary);
    if (!rf){
        cerr<<"error opening file!"<<endl;
        return;
    }
    cout<<" train, source, destination, date, time";
    while (rf.read(reinterpret_cast<char*>(&train), sizeof(Train))){
        cout<<train.name<<","
        <<train.source<<","
        <<train.destination<<","
        <<train.date<<","
        <<train.time<<endl;
    }
return;
}
void searchbydate(string date,string time){
    Train train;
    bool f=false;
    ifstream rf("trains.dat",ios::binary);
    if (!rf){
        cerr<<"error opening file!"<<endl;
        return;
    }
    while (rf.read(reinterpret_cast<char*>(&train), sizeof(Train))){
        if (train.date==date&&train.time[0]==time[0]){
        f=true;
        cout<<"train:"<<train.name
        <<" source:"<<train.source
        <<" destination:"<<train.destination
        <<" date:"<<train.date
        <<" time:"<<train.time<<endl;}
    }
    if (f==false){
        cout<<"No trains found";
    }
return;
}
void searchbydestination(string source ,string destination){
    Train train;
    bool f=false;
    ifstream rf("trains.dat",ios::binary);
    if (!rf){
        cerr<<"error opening file!"<<endl;
        return;
    }
    while (rf.read(reinterpret_cast<char*>(&train), sizeof(Train))){
        if (train.source==source&&train.destination==destination){
        f=true;
        cout<<"train:"<<train.name
        <<" source:"<<train.source
        <<" destination:"<<train.destination
        <<" date:"<<train.date
        <<" time:"<<train.time<<endl;}
    }
    if (f==false){
        cout<<"No trains found";
    }
return;
}
void showtraindata(){

    string myFilePath = "timetable.csv";
    ifstream allRecords;
    allRecords.open(myFilePath);



    if(allRecords.fail()){
        cerr<<"Unable to Open the File"<< myFilePath<<endl;
        return ;
    }

    while(allRecords.peek()!=EOF){
        string records;
        getline(allRecords,records);

        cout<<records<<endl;
    }

allRecords.close();

return;
}