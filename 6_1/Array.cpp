#include"Array.h"


inline Array::Array(Array& arr1)
{
	for (int i = 0; i < arr1.size(); i++) {
		arr.push_back(arr1[i]);
	}
}
inline Array& Array::operator=(Array& arr1)
{
	for (int i = 0; i < arr1.size(); i++) {
		arr.push_back(arr1[i]);
	}
	return *this;
}
inline Array::Array(Array&& arr1)
{
	for (int i = 0; i < arr1.size(); i++) {
		arr.push_back(arr1[i]);
	}
	arr1.clear();

}
inline Array& Array::operator=(Array&& arr1)
{
	for (int i = 0; i < arr1.size(); i++) {
		arr.push_back(arr1[i]);
	}
	arr1.clear();

	return *this;
}
void Array::push_back(Coin& st)
{
	Coin* st1 = new Coin(st);
	arr.push_back(st1);
}

inline void Array::push_back(ColdWeapon& st)
{
	ColdWeapon* st1 = new ColdWeapon(st);
	arr.push_back(st1);
}

inline void Array::push_back(Figurines& st)
{
	Figurines* st1 = new Figurines(st);
	arr.push_back(st1);
}

inline void Array::push_back(Photo& st)
{
	Photo* st1 = new Photo(st);
	arr.push_back(st1);
}

inline void Array::push_back(Picture& st)
{
	Picture* st1 = new Picture(st);
	arr.push_back(st1);
}

inline void Array::pop_back()
{
	arr.pop_back();
}

inline int Array::size()
{
	return arr.size();
}

inline void Array::print()
{
	if (arr.size() == 0) {
		cout << "Is empty!" << endl;
		return;
	}
	for (unsigned int i = 0; i < arr.size(); i++)
		cout << *arr[i] << endl;
}
inline void Array::clear()
{
	arr.clear();
}

inline Array::~Array()
{

}

