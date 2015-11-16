//
//  main.cpp
//  cstring
//
//  Created by Ruxue Bu on 11/6/15.
//  Copyright © 2015 Ruxue Bu. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "record.h"
using namespace std;

int main()
{
    string cmd = "null";
    record table[6];
    int studentID = 0;
    string password = "";
    bool match = false;
    
    while (!match)
    {
        cout << "Student ID:";
        cin >> studentID;
        cout << endl << "Password:";
        cin >> password;
        
        ifstream login("login.txt");
        int it_ID;
        string it_PW;
        while (!login.eof())    //reach the end of file
        {
            login >> it_ID >> it_PW;
            if (it_ID == studentID && it_PW == password)
                match = true;
        }
        login.close();
        if (!match)
            cout << "Wrong ID or Password" << endl;
    }
    
    
    while (cmd != "exit")
    {
        cin >> cmd;
        if (cmd == "list")
        {
            ifstream data("data.txt");
            int index = 0;
            cout << "Index   Day   Month   Section   Status   Student_ID" << endl;
            cout << "--------------------------------" << endl;
            while (!data.eof())
            {
                cout<<index<<"     ";
                table[index].getDatafromFile(data);
                table[index].outputData();
                index++;
            }
            data.close();
        }
        else if (cmd=="book")
        {
            cout << "Please input index" << endl;
            int book_index;
            cin >> book_index;
            if (table[book_index].status)
            {
                cout << "Not available" << endl;
            }
            else
            {
                table[book_index].ID = studentID;
                table[book_index].status = true;
                ofstream data("data.txt");
                for (int i = 0; i < 6; i++)
                {
                    data << table[i].day <<" "<< table[i].month <<" "<< table[i].section<<" ";
                    if (table[i].status)data << 1;
                    else data << 0;
                    data << " "<<table[i].ID;
                    if(i!=5)data << endl;
                }
            }
        }
    }
}