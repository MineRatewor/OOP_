#pragma once
#include"Exhibit.h"
#include"ArtObjects.h"
class Figurines : /*public Exhibit ,*/ public ArtObjects {
private:
	char* author;
public:
	Figurines() : ArtObjects() {}
	Figurines(const char arr[], const char arr1[], const char arr2[], int Year) : ArtObjects(arr, arr1, Year) {
		int s1 = strlen(arr1); int s2 = strlen(arr2);
		for(int i = 0; i < s1; i++) {
			char* tmp2 = new char[s2 + 1] {};
			for (int j = 0; j < s2 ; j++) {
				tmp2[i] = arr2[j];
			}
	        author = tmp2;
	}
	}
	Figurines(Figurines& s) : ArtObjects(s) {
		
		author = s.author;
		
	}
	Figurines& operator=(Figurines& s) {
		ArtObjects::operator=(s);
		author = s.author;

		return *this;
	}

	Figurines(Figurines&& s) : ArtObjects(move(s)) {
		
		author = s.author;
		

		
		s.author = nullptr;

	}
	Figurines& operator=(Figurines&& s) {
		
		ArtObjects::operator=(move(s));

		
		author = s.author;
		

		
		s.author = nullptr;

		return *this;
	}

	 Figurines* clone() {
		return new Figurines(*this);
	}
	char* getName() {
		return Exhibit::name;
	}
	void setName(const char arr[]){
		ArtObjects::setName(arr);
	}
	char* getObjetcs() {
		return Objects;
	}
	void setObjects(const char arr[]) {
		ArtObjects::setObjects(arr);
	}
	char* getAuthor() {
		return author;
	}
	void clear() {
		ArtObjects::clear();
		author = nullptr;
	}
	void setAuthor(const char arr[]) {
		char* temp = new char[strlen(arr)] {};
		int s = strlen(arr);
		for (int i = 0; i < s; i++) {
			temp[i] = arr[i];
		}
		delete[] author;
		author = temp;
	}
	int getYear() {
		return year;
	}
	void setYear(int y) {
		ArtObjects::setYear(y);
	}
	void print() const override {
		
		ArtObjects::print();
		cout << "Author:" << setw(3) << author << endl;
	
	}

	friend ostream& operator <<(ostream& fout, const Figurines& s) {
		if (s.Exhibit::name == nullptr) {
			cout << "Empty!" << endl;
			return fout;
		}
		fout << "Name:" << setw(3) << s.ArtObjects::name << endl;
		fout << "Objects:" << setw(3) << s.Objects << endl;
		fout << "Year:" << setw(3) << s.year << endl;
		fout << "Author:" << setw(3) << s.author << endl;

		return fout;
	}
	~Figurines() {
		author = nullptr;
		delete[] author;
	}

};