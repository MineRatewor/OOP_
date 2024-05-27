#include "Matrix.h"
#include <string>

int Matrix::count = 0;
 
Matrix::Matrix(int cols, int rows)
{

	m_cols = cols;
	m_rows = rows;
	count++;
	name = "Matrix " + to_string(count);
	matr.resize(m_cols * m_rows);
}

Matrix::Matrix(Matrix& other)
{
	m_cols = other.m_cols;
	m_rows = other.m_rows;
	matr.resize(m_cols * m_rows);
	count++;
	name = "Matrix " + to_string(count);
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] = other.matr[i * m_cols + j];
		}
	}
}

Matrix::Matrix(Matrix&&other)
{
	m_cols = other.m_cols;
	m_rows = other.m_rows;
	matr.resize(m_cols * m_rows);
	count++;
	name = "Matrix " + to_string(count);
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] = other.matr[i * m_cols + j];
		}
	}
	other.clear();
}


void Matrix::generateRandom()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] = rand() % 10;
		}	
	}
}

void Matrix::inputMatr()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			int num;
			cout << "Enter elment for matrix:" << endl; cin >> num;
			matr[i * m_cols + j] = num;
		}
	}
}

void Matrix::clear()
{
	matr.clear();
	m_cols = 0;
	m_rows = 0;
}

void Matrix::resizeMatrix(int cols, int rows)
{
	m_rows = rows;
	m_cols = cols;
	matr.resize(cols * rows);
}

void Matrix::multiNum(int num)
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] *= num;
		}
	}
}

void Matrix::divisonNum(int num)
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] /= num;
		}
	}
}

void Matrix::sumMatr(Matrix& other)
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] += other.matr[i * m_cols + j];
		}
	}
}

void Matrix::subtractMatr(Matrix& other)
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] -= other.matr[i * m_cols + j];
		}
	}
}

void Matrix::multiMatr(Matrix& other)
{
	if (m_cols != other.m_rows) {
		throw("Матрицы не могут быть умножены.");
		return;
	}

	
	Matrix result(other.m_cols, m_rows);

	
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < other.m_cols; j++) {
			double sum = 0;
			for (int k = 0; k < m_cols; k++) {
				sum += matr[i * m_cols + k] * other.matr[k * other.m_cols + j];
			}
			result.matr[i * other.m_cols + j] = sum;
		}
	}

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] = result.matr[i * m_cols + j];
		}
	}
	
}

void Matrix::transpose()
{
	Matrix transposed(m_rows, m_cols);

	
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			transposed.matr[j * m_rows + i] = matr[i * m_cols + j];
		}
	}

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] = transposed.matr[i * m_cols + j];
		}
	}
	
}

void Matrix::degree(int n )
{
	Matrix tmp(*this);
	for (int i = 0; i < n - 1; i++) {
		multiMatr(tmp);
	}
}

bool Matrix::isSqure()
{
	if (m_rows == m_cols) {
		return true;
	}
	else {
		return false;
	}
}

bool Matrix::isDiagonal()
{
	if (!isSqure()) {
		return false;
	}
	int count = 0;
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			if (i != j and matr[i * m_cols + j] != 0) {
				count++;
			}
		}
	}
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Matrix::isZero()
{
	int count = 0;
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			if (matr[i * m_cols + j] != 0) {
				count++;
			}
		}
	}

	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Matrix::isOne()
{
	if (!isSqure()) {
		return false;
	}

	int count = 0; int count1 = 0;
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			if (i != j) {
				if (matr[i * m_cols + j] != 0) {
					count++;
				}
			}

			if (i == j ) {
				if (matr[i * m_cols + j] != 1) {
					count1++;
				}
			}
		}
	}

	if (count == 0 and count1 == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Matrix::isSymetric()
{
	if (!isSqure()) {
		return false;
	}

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			if ((matr[i * m_cols + j] - matr[j * m_cols + i]) > 0) {
				return false;
			}
		}
	}

	return true;
}

bool Matrix::isUpperTriangular()
{
	if (!isSqure()) {
		return false;
	}
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < i; j++) {
			if (matr[i * m_cols + j] > 0) {
				return false;
			}
		}
	}

	return true;
}

bool Matrix::isLowerTriangular()
{
	if (!isSqure()) {
		return false;
	}

	for (int i = 0; i < m_rows; i++) {
		for (int j = i + 1; j < m_cols; j++) {
			if (matr[i * m_cols + j] > 0) {
				return false;
			}
		}
	}

	return true;
}



Matrix& Matrix::operator+=(int num)
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] += num;
		}
	}
	return*this;
}

Matrix& Matrix::operator+=(Matrix& other)
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] += other.matr[i*m_cols + j];
		}
	}
	return*this;
}

Matrix& Matrix::operator-=(int num)
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] -= num;
		}
	}
	return*this;
}

Matrix& Matrix::operator-=(Matrix& other)
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] -= other.matr[i*m_cols + j];
		}
	}
	return*this;
}

Matrix& Matrix::operator*=(Matrix&other)
{
	multiMatr(other);
	return*this;
}

Matrix& Matrix::operator*=(int num)
{
	multiNum(num);
	return *this;
}

Matrix& Matrix::operator/=(int num)
{
	divisonNum(num);
	return *this;
}

Matrix& Matrix::operator==(Matrix& other)
{
	int count = 0;
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			if (matr[i * m_cols + j] != other.matr[i * m_cols + j]) {
				count++;
			}
		}
	}
	if (count == 0) {
		cout << "Матрицы равны!" << endl;
	}
	else {
		cout << "Матрицы  не равны!" << endl;
	}
	return *this;
}

Matrix& Matrix::operator=(Matrix&other)
{
	m_cols = other.m_cols;
	m_rows = other.m_rows;
	matr.resize(m_cols * m_rows);
	count++;
	name = "Matrix " + to_string(count);
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] = other.matr[i * m_cols + j];
		}
	}
	return *this;
}

Matrix& Matrix::operator=(Matrix&& other)
{
	m_cols = other.m_cols;
	m_rows = other.m_rows;
	matr.resize(m_cols * m_rows);
	count++;
	name = "Matrix " + to_string(count);
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			matr[i * m_cols + j] = other.matr[i * m_cols + j];
		}
	}
	other.clear();
	return *this;
}




void Matrix::print()
{
	if (m_cols == 0 and m_rows == 0) {
		cout << "Matrix is empty!" << endl;
		return;
	}

	cout << name << endl;
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			cout << setw(6) << matr[i * m_cols + j];
		}
		cout << endl;
	}
}


Matrix::~Matrix()
{
	count--;
}

ostream& operator<<(ostream& out, Matrix& x)
{
	if (x.m_cols == 0 and x.m_rows == 0) {
		cout << "Matrix is empty!" << endl;
		return out;
	}
	cout << x.name << endl;
	for (int i = 0; i < x.m_rows; i++) {
		for (int j = 0; j < x.m_cols; j++) {
			out << setw(5) << x.matr[i * x.m_cols + j];
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Matrix&x)
{
	for (int i = 0; i < x.m_rows; i++) {
		for (int j = 0; j < x.m_cols; j++) {
			cout << "Enter the element of matrix:" << endl;
			in >> x.matr[i * x.m_cols + j];
		}
	}
	return in;
}


