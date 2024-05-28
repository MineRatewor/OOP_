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
		int s = strlen(arr);
		char* tmp = new char[s+ 1] {};
		for (int i = 0; i < s; i++) {
			tmp[i] = arr[i];
		}
		Objects = tmp;
		year = Y;
	}

	ArtObjects(ArtObjects& s) : Exhibit(s){
		int s1 = strlen(s.Objects);
		char* temp = new char[s1 + 1] {};
		for (int i = 0; i < s1; i++) {
			temp[i] = s.Objects[i];
		}
		delete[] Objects;
		Objects = temp;
		year = s.year;
	}
	virtual ArtObjects& operator=(ArtObjects& s) {
		Exhibit::operator=(s);
		int s1 = strlen(s.Objects);
		char* temp = new char[s1 + 1] {};
		for (int i = 0; i < s1; i++) {
			temp[i] = s.Objects[i];
		}
		delete[] Objects;
		Objects = temp;
		year = s.year;

		return *this;
	}
	ArtObjects(ArtObjects&& s): Exhibit(move(s)) {
		int s1 = strlen(s.Objects);
		char* temp = new char[s1 + 1] {};
		for (int i = 0; i < s1; i++) {
			temp[i] = s.Objects[i];
		}
		delete[] Objects;
		Objects = temp;
		year = s.year;
		s.Objects = nullptr;
	}
	virtual ArtObjects* clone() {
		return new ArtObjects(*this);
	}
	virtual ArtObjects& operator=(ArtObjects&& s) {
		Exhibit::operator=(move(s));
		int s1 = strlen(s.Objects);
		char* temp = new char[ s1+ 1] {};
		for (int i = 0; i < s1; i++) {
			temp[i] = s.Objects[i];
		}
		delete[] Objects;
		Objects = temp;
		year = s.year;

		s.Objects = nullptr;

		return *this;
	}
	virtual char* getName() {
		return name;
	}
	virtual char* getObjetcs() {
		return Objects;
	}
	virtual int getYear() {
		return year;
	}
	virtual void clear() {
		Exhibit::clear();
		Objects = nullptr;
		year = 0;
	}
	virtual void setName(const char arr[]) {
		Exhibit::setName(arr);
	}

	virtual void setObjects(const char arr1[]) {
		int s = strlen(arr1);
		char* temp = new char[s + 1] {};
		for (int i = 0; i < s; i++) {
			temp[i] = arr1[i];
		}
		delete[] Objects;
		Objects = temp;
	}

	virtual void setYear(int y) {
		year = y;
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

	 friend ostream& operator<<(ostream& fout, const ArtObjects& s)
	{
		 s.print();
		return fout;
	}

	virtual ~ArtObjects() {
		delete[] Objects;
	}

};