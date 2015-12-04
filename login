#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

class login {
private:
	map<string, string>id_password;
public:
	login() {
		ifstream file("login.txt");
		string line;
		while (getline(file, line)) {
			istringstream ss(line);
			string a;
			string b;
			bool p = true;
			while (getline(ss, a, '\t')) {
				cout << a << endl;
				if (p) {
					b = a;
					p = false;         //p=!p;
				}
				id_password[b] = a; 
			}
		}
		file.close();
		for (map<string, string>::iterator it = id_password.begin(); it != id_password.end(); it++) {
			cout << "student_id:" << it->first << '\t' << "password:" << it->second << endl;
		}
	}

	void search(const string& id, const string& password) {
		bool id_temp = false;
		bool pass_temp = false;
		bool Teacher = false;

		for (map<string, string>::iterator it = id_password.begin(); it != id_password.end(); it++) {
			if (id == it->first) {
				id_temp = true;
				if (password == it->second) {
					pass_temp = true;
					if (it == id_password.begin()) {
						Teacher = true;
					}
				}
			}
		}

		if (id_temp&&pass_temp) {
			if (Teacher) {
				cout << "Welcome Prof" << endl;
			}
			else {
				cout << "Welcome student!!" << endl;
			}
		}else{ 
			cout << "your id or password is wrong!" << endl; }
	}
};


int main() {
	login login;
	string a,b;
	cout << "Please enter your id:";
	cin >> a;
	cout << "Please enter your password:";
	cin >> b;
	login.search(a, b);
	return 0;
}
