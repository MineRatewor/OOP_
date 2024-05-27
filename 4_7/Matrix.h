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
	void resizeMatrix(int, int); // изменение размеров матрицы
	void multiNum(int); // умножение на число
	void divisonNum(int); // деление на число
	void sumMatr(Matrix&); // сложение матриц
	void subtractMatr(Matrix&);// вычитание матриц 
	void multiMatr(Matrix&);// умножение матриц 
	void transpose();//транспонирование матрицы 
	void degree(int);//возведение матрицы в степень
	bool isSqure();// проверка на квадратную матрицу 
	bool isDiagonal();// проверка на диагональную матрицу 
	bool isZero();//проверка на нулевую матрицу 
	bool isOne(); // проверка на единичную матрицу
	bool isSymetric();// проверка матрицы на симметричность
	bool isUpperTriangular();// проврека на верхнюю треугольную матрицу
	bool isLowerTriangular();// проверка на нижнюю треугольную матрицу
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

