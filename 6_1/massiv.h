#pragma once
#include"Coin.h"
#include"ColdWeapon.h"
#include"Exhibit.h"
#include"Figurines.h"
#include"Photo.h"
#include"Picture.h"
#include"Vector.h"


class Massiv {
private:
	Vector<Exhibit*> arr;
public:
	Massiv() {}
	Massiv(Massiv&);
	Massiv(Massiv&& arr1);
	Massiv& operator=(Massiv&);
	Massiv& operator=(Massiv&&);

	template<typename T>
	void push_back(T& st) {
		T* st1 = new T(st);
		arr.push_back(st1);
	}
	void print();
	void pop_back();
	void clear();
	int size();
	~Massiv() {}


	Exhibit*& operator[](int index) {

		if (index < 0 or index > arr.size()) {
			cout << "Index out of range!";
		}
		return arr[index];

	}
};

Massiv::Massiv(Massiv& arr1)
{
	for (int i = 0; i < arr1.size(); i++) {
		arr.push_back(arr1[i]);
	}
}

Massiv::Massiv(Massiv&& arr1)
{
	for (int i = 0; i < arr1.size(); i++) {
		arr.push_back(arr1[i]);
	}
	arr1.clear();
}

Massiv& Massiv::operator=(Massiv& arr1)
{
	for (int i = 0; i < arr1.size(); i++) {
		arr.push_back(arr1[i]);
	}
	return *this;
}

Massiv& Massiv::operator=(Massiv&& arr1)
{
	for (int i = 0; i < arr1.size(); i++) {
		arr.push_back(arr1[i]);
	}
	arr1.clear();
	return *this;
}

inline void Massiv::print()
{
	if (arr.size() == 0) {
		cout << "Is empty!" << endl;
		return;
	}
	for (unsigned int i = 0; i < arr.size(); i++)
		cout << *arr[i] << endl;
}

void Massiv::pop_back()
{
	arr.pop_back();
}

void Massiv::clear()
{
	arr.clear();
}

int Massiv::size()
{
	return arr.size();
}



