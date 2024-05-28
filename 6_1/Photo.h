#pragma once
#include"Exhibit.h"
#include"ArtObjects.h"
class Photo : public ArtObjects {
public:
	Photo() :  ArtObjects() {}
	Photo(const char arr[], const char arr1[], int Year) : ArtObjects(arr, arr1,Year){
	}

	Photo(Photo& s) :ArtObjects(s) {
	}

	Photo& operator=(Photo& s) {
		
		ArtObjects::operator=(s);
		return*this;
	}

	Photo(Photo&& s) : ArtObjects(move(s)) {
	}

	Photo& operator=(Photo&& s) {
		ArtObjects::operator=(move(s));

		return*this;
	}
	Photo* clone() {
		return new Photo(*this);
	}
	char* getName() {
		return name;
	}
	char* getObjects() {
		return Objects;
	}
	int getYear() {
		return year;
	}
	void setName(const char arr[]) {
		ArtObjects::setName(arr);
	}
	void setObjects(const char arr[]) {
		ArtObjects::setObjects(arr);
	}
	void setYear(int y) {
		ArtObjects::setYear(y);
	}
	void clear() {
		ArtObjects::clear();
	}
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		ArtObjects::print();
	}
	
	friend ostream& operator <<(ostream& fout, const Photo& s) {
		if (s.name == nullptr) {
			cout << "Empty!" << endl;
			return fout;
		}
		fout << "Name:" << setw(3) << s.name << endl;
		fout << "Objects" << setw(3) << s.Objects << endl;
		fout << "Year:" << setw(3) << s.year << endl;
		
		return fout;
	}
	~Photo() {	
	}
};
