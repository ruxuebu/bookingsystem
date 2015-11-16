#include<iostream>
#include<fstream>
#include "record.h"

void record::getDatafromFile(ifstream& file)
{
    int flag=0;
    file >> day >> month >> section>>flag>>ID;
    if(flag==1)status=true;
    else status=false;
}

void record::outputData()
{
    cout << day << "     " << month << "     " <<section << "     ";
    if (status)
    {
        cout << "Booked";
    }
    else
    {
        cout << "Available";
    }
    cout <<"     "<<ID<< endl;
}