#pragma once
#include<iomanip>
#include<iostream>
using namespace std;

class ArtObjects : public Exhibit {
protected:
	char* Objects;
	int year;
public:
	ArtObjects() : Exhibit() {
		Objects = nullptr;
	}

	ArtObjects(const char arr1[], const char arr[], int Y) : Exhibit(arr1) {
		char* tmp = new char[strlen(arr) + 1] {};
		for (int i = 0; i < strlen(arr); i++) {
			tmp[i] = arr[i];
		}
		Objects = tmp;
		year = Y;
	}

	ArtObjects(ArtObjects& s) : Exhibit(s){
		char* temp = new char[strlen(s.Objects) + 1] {};
		for (int i = 0; i < strlen(s.Objects); i++) {
			temp[i] = s.Objects[i];
		}
		delete[] Objects;
		Objects = temp;
		year = s.year;
	}
	virtual ArtObjects& operator=(ArtObjects& s) {
		Exhibit::operator=(s);
		char* temp = new char[strlen(s.Objects) + 1] {};
		for (int i = 0; i < strlen(s.Objects); i++) {
			temp[i] = s.Objects[i];
		}
		delete[] Objects;
		Objects = temp;
		year = s.year;

		return *this;
	}
	ArtObjects(ArtObjects&& s): Exhibit(move(s)) {
		char* temp = new char[strlen(s.Objects) + 1] {};
		for (int i = 0; i < strlen(s.Objects); i++) {
			temp[i] = s.Objects[i];
		}
		delete[] Objects;
		Objects = temp;
		year = s.year;
		s.Objects = nullptr;
	}
	virtual ArtObjects& operator=(ArtObjects&& s) {
		Exhibit::operator=(move(s));
		char* temp = new char[strlen(s.Objects) + 1] {};
		for (int i = 0; i < strlen(s.Objects); i++) {
			temp[i] = s.Objects[i];
		}
		delete[] Objects;
		Objects = temp;
		year = s.year;

		s.Objects = nullptr;

		return *this;
	}

	virtual void print()  const {
		if (Objects == nullptr) {
			cout << "Is empty!" << endl;
			return;
		}
		if (name == nullptr) {
			cout << "Is empty!" << endl;
			return;
		}
		cout << "Name:" << setw(5) << name << endl;
		cout << "Objects:" << setw(3);
		for (int i = 0; i < strlen(Objects); i++) {
			cout << Objects[i];
		}
		cout << endl;
		cout << "Year:" << setw(3) << year << endl;
	}

	friend ostream& operator <<(ostream& fout, const ArtObjects& s) {
		s.print();
		return fout;
	}

	virtual ~ArtObjects() {
		delete[] Objects;
	}

};