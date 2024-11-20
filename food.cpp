#include <iostream>
#include <vector>
#include <string>
#include <fstream>
void validate(string trainId, string ticketId)
{
    passenger pass;
    Train train;
    bool f = false;
    ifstream rf("passengers.dat", ios::binary);
    if (!rf)
    {
        cerr << "Error opening file!" << endl;
        return;}
    while (rf.read(reinterpret_cast<char *>(&pass), sizeof(passenger)))
    {
        if (pass.trainid == trainId && pass.passid == ticketId)
        {
            f = true;
            int c;
            cout << "1.Look for Menu" << endl;
            cout << "2.Order Food" << endl;
            cout << "Enter your Choice :" << endl;
            cin >> c;
            switch (c)
            {
            case 1:
            {
                ifstream fin;
                fin.open("food.txt");
                string food, id, price;
                getline(fin, food, '*');
                getline(fin, id, '*');
                getline(fin, price, '\n');

                while (!fin.eof())
                {
                    cout << "Id Number : " << id << endl;
                    cout << "Food : " << food << endl;
                    getline(fin, food, '*');
                    getline(fin, id, '*');
                    getline(fin, price, '\n');
                }
            }
            case 2:
            {
                {
                    ifstream fin;
                    fin.open("food.txt");
                    string food, id, price;
                    getline(fin, food, '*');
                    getline(fin, id, '*');
                    getline(fin, price, '\n');

                    while (!fin.eof())
                    {
                        cout << "Id Number : " << id << endl;
                        cout << "Food : " << food << endl;
                        getline(fin, food, '*');
                        getline(fin, id, '*');
                        getline(fin, price, '\n');
                    }
                }

                ifstream file;
                file.open("food.txt");
                string food, id, price;

                getline(file, food, '*');
                getline(file, id, '*');
                getline(file, price, '\n');
                string id1;
                cout << "Enter the id of the food you want to order : " << endl;
                cin >> id1;
                while (!file.eof())
                {
                    if (id1 == id)
                    {
                        cout << food << endl;
                        ifstream file;
                        file.open("bill.txt");
                        string price;
                        getline(file, price, '*');
                        ofstream file1;
                        file1.open("bill1.txt", ios::app);
                        file1 << price << '*' << ticketId;

                        string space = "";
                        file.close();
                        file1.close();
                        ofstream file2;
                        file2.open("bill2.txt");
                        file2 << space << endl;
                        file2.close();
                        remove("bill.txt");
                        rename("bill2.txt", "bill.txt");

                        cout << "Your Total Bill is of Rs. " << price << endl;
                        cout << "Your order has been confirmed with Train Id : " << trainId << " and Ticket Id : " << ticketId << endl;
                    }

                    // break;
                    // }
                    else
                    {
                        getline(file, food, '*');
                        getline(file, id, '*');
                        getline(file, price, '\n');
                    }
                }
                cout << "No food with this Id" << endl;
                ofstream fout;
                fout.open("bill.txt", ios::app);
                fout << price << '*' << ticketId;
            }
             default:
            cout << "Invalid Choice" << endl;
            }
        }
    }
    if (f == false)
    {
        cout << "No Ticket Booked with these credentials.";
    }
    return;
}