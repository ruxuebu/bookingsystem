#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class record
{
public:
    int day;
    int month;
    int section;
    bool status;
    int ID;
    record() {};
    record(int d, int m, int s, bool f, int num)
    {
        day = d;
        month = m;
        section = s;
        status = f;
        ID = num;
    }
    void getDatafromFile(ifstream& file);
    void outputData();
};