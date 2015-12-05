#include "Students.h"
class login {
private:
	unordered_map<string, string>id_password;
public:
	//read a text file and store the data of student's Id with it's password in a map called id_password;
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
					p = false;
				}
				id_password[b] = a;
			}
		}
		file.close();
		/*for (map<string, string>::iterator it = id_password.begin(); it != id_password.end(); it++) {
			cout << "student_id:" << it->first << '\t' << "password:" << it->second << endl;
		}*/
	}
	//match the input id and password with data which stored in map 
	void search(const string& id, const string& password) {
		bool id_temp = false;
		bool pass_temp = false;
		bool Teacher = false;
			for (unordered_map<string, string>::iterator it = id_password.begin(); it != id_password.end(); it++) {
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
			//Judge whether the individual is profressor or student, then making or cancelling an appointment
			if (id_temp&&pass_temp) {
				if (Teacher) {
					cout << "Welcome Prof" << endl;
					//call the class for the profressor.
					teacher obj;
					int i;
					do {
						cout << "1.Setup time for appointment." << endl;
						cout << "2.Display the time for appintment." << endl;
						cout << "3.Cancel the appointment" << endl;
						cout << "0.log out!" << endl;
						cin >> i;
						switch (i)
						{
						case 1: obj.setup();
							obj.readin();
							break;
						case 2: obj.display();
							break;
						case 3:/*a.cancel();*/
							break;
						case 0:
							break;
						}
					} while (i != 0);
				}
				else {
					cout << "Welcome student!!" << endl;
					students stu;
					int i;
					do {
						cout << "1.booking time for appointment." << endl;
						cout << "2.Display the time for appintment." << endl;
						cout << "3.Cancel the appointment" << endl;
						cout << "0.log out!" << endl;
						cin >> i;
						switch (i)
						{
						case 1:stu.booking();
							break;
						case 2: stu.display();
							break;
						case 3:/*a.cancel();*/
							break;
						case 0:
							break;
						}
					} while (i != 0);
				}
			}
			else {
				cout << "your id or password is wrong! Please try again!!" << endl;
			}
	}
	

	void Login_temp() {
		while (true) {
			string a, b;
			cout << "Please enter your id:";
			cin >> a;
			cout << "Please enter your password:";
			cin >> b;
			cin.sync();
			search(a, b);
		}
	}
	
};


int main() {
	login login;
	login.Login_temp();
	return 0;
}
