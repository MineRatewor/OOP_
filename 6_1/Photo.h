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
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		ArtObjects::print();
	}
	friend ostream& operator <<(ostream& fout, const Photo& s) {
		s.print();
		return fout;
	}
	~Photo() {
		
	}
};
