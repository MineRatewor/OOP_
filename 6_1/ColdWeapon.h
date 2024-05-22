#pragma once
#include"Exhibit.h"

class ColdWeapon : public Exhibit {
private:
	int startYear;
	int endYear;
public:
	ColdWeapon() : Exhibit() {}
	ColdWeapon(const char arr[], int st, int en) :Exhibit(arr) {
		startYear = st;
		endYear = en;
	}
	ColdWeapon(ColdWeapon& s) : Exhibit(s) {
		if (name == s.name and startYear == s.startYear and endYear == s.endYear) {
			return;
		}
		
		startYear = s.startYear;
		endYear = s.endYear;
	}
	ColdWeapon& operator=(ColdWeapon& s) {
		if (name == s.name and startYear == s.startYear and endYear == s.endYear) {
			return *this;
		}
		Exhibit::operator=(s);
		startYear = s.startYear;
		endYear = s.endYear;
		return *this;
	}
	ColdWeapon(ColdWeapon&& s) : Exhibit(move(s)){
		if (name == s.name and startYear == s.startYear and endYear == s.endYear) {
			s.name = nullptr;
			s.startYear = 0;
			s.endYear = 0;
			return;
		}
		
		startYear = s.startYear;
		endYear = s.endYear;

		s.name = nullptr;
		s.startYear = 0;
		s.endYear = 0;


	}
	ColdWeapon& operator=(ColdWeapon&& s1) {
		if (name == s1.name and startYear == s1.startYear and endYear == s1.endYear) {
			s1.name = nullptr;
			s1.startYear = 0;
			s1.endYear = 0;
			return *this;
		}
		Exhibit::operator=(move(s1));

		startYear = s1.startYear;
		endYear = s1.endYear;

		s1.startYear = 0;
		s1.endYear = 0;

		return *this;
	}
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(3) << name << endl;
		cout << "StartYear:" << setw(5) << startYear << endl;
		cout << "EndYear:" << setw(5) << endYear << endl;
	}
	friend ostream& operator <<(ostream& fout, const ColdWeapon& s) {
		s.print();
		return fout;
	}
};