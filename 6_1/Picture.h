#pragma once
#include"Exhibit.h"
#include"ArtObjects.h"

class Picture :  public ArtObjects
{
private:
	char* author;
	
public:
	Picture() :ArtObjects() {
		author = nullptr;

	}
	Picture(const char arr[], const char arr1[], const char arr2[], int Year) : ArtObjects(arr, arr1,Year) {
	/*	char* tmp1 = new char[strlen(arr1) + 1] {};
		for (int i = 0; i < strlen(arr1); i++) {
			tmp1[i] = arr1[i];
		}
		subject = tmp1;*/
		int s = strlen(arr2);
		char* tmp2 = new char[s + 1] {};
		for (int i = 0; i < s; i++) {
			tmp2[i] = arr2[i];
		}
		author = tmp2;

		//year = Year;
	}

	Picture(Picture& s) : ArtObjects(s) {
		/*subject = s.subject;*/
		author = s.author;
		/*year = s.year;*/
	}
	 Picture& operator=(Picture& s) {
		Exhibit::operator=(s);
		ArtObjects::operator=(s);
		/*subject = s.subject;*/
		author = s.author;
		/*year = s.year;*/

		return*this;
	}

	Picture(Picture&& s) : ArtObjects(move(s)){
		/*subject = s.subject;*/
		author = s.author;
		/*year = s.year;*/


		s.author = nullptr;
		/*s.subject = nullptr;*/
	/*	s.year = 0;*/
	}

	Picture& operator=(Picture&& s) {
		
		ArtObjects::operator=(move(s));
		/*subject = s.subject;*/
		author = s.author;
	/*	year = s.year;*/


		s.author = nullptr;
		/*s.subject = nullptr;*/
		return *this;
	}
	Picture* clone() {
		return new Picture(*this);
	}
	void clear() {
		ArtObjects::clear();
		author = nullptr;
	}
	char* getName() {
		return name;
	}
	void setName(const char arr[]) {
		ArtObjects::setName(arr);
	}
	char* getObjects() {
		return Objects;
	}
	void setObjects(const char arr[]) {
		ArtObjects::setObjects(arr);
	}
	int getYear() {
		return year;
	}
	void setYear(int y) {
		ArtObjects::setYear(y);
	}
	char* getAuthor() {
		return author;
	}
	void setAuthor(const char arr2[]) {
		int s = strlen(arr2);
		char* temp = new char[s + 1] {};

		for (int i = 0; i < s; i++) {
			temp[i] = arr2[i];
		}
		delete[] author;
		author = temp;
	}
	
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		ArtObjects::print();
		cout << "Author:" << setw(3) << author << endl;
		
	}
	friend ostream& operator <<(ostream& fout, const Picture& s){
		if (s.name == nullptr) {
			cout << "Empty!" << endl;
			return fout;
		}
		fout << "Name:" << setw(3) << s.name << endl;
		fout << "Objects:" << setw(3) << s.Objects << endl;
		fout << "Year:" << setw(3) << s.year << endl;
		fout << "Author:" << setw(3) << s.author << endl;
		
		return fout;
	}
	~Picture()  {
		 author = nullptr;
		delete[] author;
	}


};