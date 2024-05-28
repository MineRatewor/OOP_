#pragma once
#include"Exhibit.h"

class Coin : public Exhibit {
private:
	double domination;
	int startYear;
	int endYear;
public:
	Coin() :Exhibit() {}
	Coin(const char arr[], double dom, int st, int en) :Exhibit(arr) {
		
		domination = dom;
		startYear = st;
		endYear = en;
	}
	Coin(Coin& s) :Exhibit(s) {
		if (name == s.name and domination == s.domination and startYear == s.startYear and endYear == s.endYear) {
			return;
		}
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;
	}
	Coin& operator=(Coin& s) {
		if (name == s.name and domination == s.domination and startYear == s.startYear and endYear == s.endYear) {
			return *this;
		}
		Exhibit::operator=(s);
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;
		return *this;
	}

	Coin(Coin&& s) :Exhibit(move(s)) {
		if (name == s.name and domination == s.domination and startYear == s.startYear and endYear == s.endYear) {
			s.domination = 0;
			s.startYear = 0;
			s.endYear = 0;
			return;
		}
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;


		s.domination = 0;
		s.startYear = 0;
		s.endYear = 0;
	}
	Coin& operator=(Coin&& s) {
		if (name == s.name and domination == s.domination and startYear == s.startYear and endYear == s.endYear) {
			s.domination = 0;
			s.startYear = 0;
			s.endYear = 0;
			return *this;
		}
		Exhibit::operator=(move(s));
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;


		s.domination = 0;
		s.startYear = 0;
		s.endYear = 0;
		return *this;
	}
	Coin* clone() {
		return new Coin(*this);
	}
	char* getName() {
		return name;
	}
	double getDomination() {
		return domination;
	}
	int getStartYear() {
		return startYear;
	}
	int getEndYear() {
		return endYear;
	}
	void setName(const char arr[]) {
		Exhibit::setName(arr);
	}
	void setDomination(double dom) {
		domination = dom;
	}
	void setStartYear(int st) {
		startYear = st;
	}
	void setEndYear(int en) {
		endYear = en;
	}
	void clear() {
		Exhibit::clear();
		domination = 0;
		startYear = 0;
		endYear = 0;
	}
	Coin& clone(Coin& s) {
		Coin st(s);
		return st;
		
	}
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(5) << name << endl;
		cout << "Domination:" << setw(3) << domination << endl;
		cout << "StartYear:" << setw(5) << startYear << endl;
		cout << "EndYear:" << setw(5) << endYear << endl;
	}
	friend ostream& operator <<(ostream& fout, const Coin& s) {
		if (s.name == nullptr) {
			cout << "Empty!" << endl;
			return fout;
		}
		fout << "Name:" << setw(3) << s.name << endl;
		fout << "Domination:" << setw(3) << s.domination << endl;
		fout << "StartYear:" << setw(3) << s.startYear << endl;
		fout << "EndYear:" << setw(3) << s.endYear << endl;
		return fout;
	}

};