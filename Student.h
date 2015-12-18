#include "Teacher.h"
using namespace std; 
class students {
	unordered_map<string, temp*>app;

public:
	void display() {
			ifstream in;
			in.open("outfile.dat");
			if (!in) {
				cout << "The professor have not set up the schedule!" << endl;
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
					if (p) {
						b = a;
						p = false;
					}
					else if (t) {
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
			int t= 1;
			for (unordered_map<string, temp*>::iterator it = app.begin(); it != app.end(); it++) {
				cout << t << ":" << it->first << "\t" << (it->second)->time << "\t" << (it->second)->flag << "\n";
				t++;
			}
	}

	void booking() {
		int k;
		cout << "Please enter the number for the day for booking:";
		cin >> k;
		int i = 1;
		for (unordered_map<string, temp*>::iterator it = app.begin(); it != app.end(); it++) {
			if (k == i) {
				(it->second)->flag = "not available";
			}
			i++;
		}
		readin();

	}
	void readin() {
		ofstream out;
		out.open("outfile.dat");
		if (!out) {
		cout << "file open fail!!" << endl;
		return -1;
		}
		for (unordered_map<string, temp*>::iterator it = app.begin(); it != app.end(); it++) {
			out << it->first << "\t" << (it->second)->time << "\t" << (it->second)->flag << "\n";
		}
		out.close();
	}
};
