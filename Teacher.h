#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class temp {
public:
	string time;
	string flag;
};
class teacher {
	unordered_map<string,temp*>app;
public:
	void setup() {
		int i;
		cout << "1.Monday                 2.Tuesday" << endl;
		cout << "3.Wednesday              4.Thursday" << endl;
		cout << "5.Friday                 6.Saturday" << endl;
		cout << "7.Sunday                 0.Exit setup" << endl;
		do {
			cout << "please enter a number:";
			cin >> i;
			cin.sync();
				switch (i)
				{
				case 1: setupdate("Monday");
					break;
				case 2: setupdate("Tuesday");
					break;
				case 3:setupdate("Wednesday");
					break;
				case 4:setupdate("Thursday");
					break;
				case 5:setupdate("Friday");
					break;
				case 6:setupdate("Saturday");
					break;
				case 7:setupdate("Sunday");
					break;
				case 0:
					break;
			}
		}while(i != 0);

		cout << "Setup already!" << endl;
	}

	void setupdate(const string& weekday) {
		string a;
		cout << "Please input the time for " << weekday << endl;
		cin >> a;
		temp* tp = new temp();
		tp->time = a;
		tp->flag = "available";
		app[weekday] = tp;
	}
	void display() {
		ifstream in;
		in.open("outfile.dat");
		if (!in) {
			cout << "Professor,you have not set up yet!!" << endl;
			return -1;
		}
		string line;
		while (getline(in, line)) {
			istringstream ss(line);
			string a;
			string b;
			string c;
			bool p = true;
			bool t = true;
			while (getline(ss, a, '\t')) {
				cout << a << endl;
				if (p) {
					b = a;
					p = false;
				}
				else if(t) {
					c = a;
					t = false;
				}
				temp* tp = new temp();
				tp->time = c;
				tp->flag = a;
				app[b] = tp;
			}
		}
		in.close();
		for (unordered_map<string, temp*>::iterator it = app.begin(); it != app.end(); it++) {
			cout << it->first << "\t" << (it->second)->time << "\t" << (it->second)->flag << "\n";
				
		}
		app.clear();
	}
	void readin() {
		ofstream out;
		out.open("outfile.dat");
		for (unordered_map<string, temp*>::iterator it = app.begin(); it != app.end(); it++) {
			out << it->first << "\t" << (it->second)->time << "\t" << (it->second)->flag<< "\n";
		}
		out.close();
	}
	/*void cancel() {};*/
};
