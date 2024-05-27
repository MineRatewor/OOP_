#include<iostream>
#include"Matrix.h"
using namespace std;

int main() {
	int n;
	cout << "Enter n:" << endl; cin >> n;

	Matrix A(n, n);
	A.generateRandom();
	cout << A << endl;

	Matrix B(n, n);
	B.generateRandom();
	cout << B << endl;

	Matrix AB = A;

	AB *= B;
	cout << AB << endl;
	

	Matrix BA = B;
	BA *= A;

	cout << BA << endl;

	Matrix C = AB;
	C += BA;
	cout << "Result:" << endl << C << endl;
	return 0;
}