#pragma once
#include<iomanip>
#include<iostream>
#include"Vector.h"
#include<string.h>
using namespace std;


class Matrix {
private:
	Vector<double> matr;
	string name;
	static int count;
	int m_cols;
	int m_rows;
public:
	Matrix(int , int );
	Matrix(Matrix&);
	Matrix(Matrix&&);
	void generateRandom();
	void inputMatr(); 
	void clear();
	void resizeMatrix(int, int); // ��������� �������� �������
	void multiNum(int); // ��������� �� �����
	void divisonNum(int); // ������� �� �����
	void sumMatr(Matrix&); // �������� ������
	void subtractMatr(Matrix&);// ��������� ������ 
	void multiMatr(Matrix&);// ��������� ������ 
	void transpose();//���������������� ������� 
	void degree(int);//���������� ������� � �������
	bool isSqure();// �������� �� ���������� ������� 
	bool isDiagonal();// �������� �� ������������ ������� 
	bool isZero();//�������� �� ������� ������� 
	bool isOne(); // �������� �� ��������� �������
	bool isSymetric();// �������� ������� �� ��������������
	bool isUpperTriangular();// �������� �� ������� ����������� �������
	bool isLowerTriangular();// �������� �� ������ ����������� �������
	Matrix& operator+=(int);
	Matrix& operator+=(Matrix&);
	Matrix& operator-=(int);
	Matrix& operator-=(Matrix&);
	Matrix& operator*=(Matrix&);
	Matrix& operator*=(int);
	Matrix& operator/=(int);
	Matrix& operator==(Matrix&);
	Matrix& operator=(Matrix&);
	Matrix& operator=(Matrix&&);
	void print();

	friend ostream& operator<<(ostream& out, Matrix&);
	friend istream& operator>>(istream& in, Matrix&);
	~Matrix(); 
};

