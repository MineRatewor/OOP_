#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

class BigNumber {
private:
	int** number; 
	int size;
	int N;

public:
	BigNumber(int );
	BigNumber(int, int);
	BigNumber(BigNumber&);
	BigNumber(BigNumber&&);
	void create();
	void Delete();
	void print();
	void clear();

	BigNumber& operator+=(int);
	BigNumber& operator+=(BigNumber&);
	BigNumber& operator=(BigNumber&);
	BigNumber& operator=(BigNumber&&);
	void multiNum(int, BigNumber&, BigNumber&);
	void sumMulti(BigNumber&, int, BigNumber&);
	BigNumber& operator*=(BigNumber&);
	BigNumber& operator*=(int);
	~BigNumber();
};