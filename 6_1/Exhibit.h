#pragma once
#include<iomanip>
#include<iostream>
using namespace std;

class Exhibit {
protected:
	char* name;
public:
	Exhibit() {
		name = nullptr;
	}
	Exhibit(const char arr[]) {
		int s = strlen(arr);
		char* tmp = new char[s + 1] {};
		for (int i = 0; i < s; i++) {
			tmp[i] = arr[i];
		}
		name = tmp;
	}
	Exhibit(Exhibit& s) {
		int s1 = strlen(s.name);
		char* temp = new char[s1 + 1] {};
		for (int i = 0; i < s1; i++) {
			temp[i] = s.name[i];
		}
		delete[] name;
		name = temp;

	}

	virtual Exhibit& operator=(Exhibit& s) {
		int s1 = strlen(s.name);
		char* temp = new char[s1 + 1] {};
		for (int i = 0; i < s1; i++) {
			temp[i] = s.name[i];
		}
		delete[] name;
		name = temp;

		return *this;
	}

	virtual Exhibit* clone()  {
		return new Exhibit(*this);
	}
	Exhibit(Exhibit&& s) {
		name = s.name;
		s.name = nullptr;
	}

	virtual Exhibit& operator=(Exhibit&& s) {
		int s1 = strlen(s.name);
		char* temp = new char[s1 + 1] {};
		for (int i = 0; i < s1; i++) {
			temp[i] = s.name[i];
		}
		delete[] name;
		name = temp;

		s.name = nullptr;
		return *this;
	}
	virtual char* getName()  {
		return name;
	}
	

	virtual void setName(const char arr[]) {
		int s = strlen(arr);
		char* temp = new char[s + 1] {};
		for (int i = 0; i < s; i++) {
			temp[i] = arr[i];
		}
		delete[] name;
		name = temp;
	}
	virtual void clear() {
		name = nullptr;
	}

	virtual void print() const {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(3);
		for (int i = 0; i < strlen(name); i++) {
			cout << name[i];
		}
	}
	friend ostream& operator<<(ostream& fout, const Exhibit& s){
		s.print();
		return fout;
	}

	virtual ~Exhibit() {
		delete name;
	}

};