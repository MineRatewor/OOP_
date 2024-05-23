#include<iostream>
#include<iomanip>
#include"BigNumber.h"
using namespace std;


void BigNumber::create()
{
	number = new int*[N];
	for (int i = 0; i < N; i++) {
		number[i] = new int[9];
	}
}

void BigNumber::Delete()
{
	for (int i = 0; i < N; i++) {
		delete[] number[i];
	}
	delete[] number;
}


BigNumber::BigNumber(int n)
{
	N = n;
	create();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			number[i][j] = 0;
		}
	}
	size = 0;
}

BigNumber::BigNumber(int num, int n)
{
	

	N = n;
	create();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			number[i][j] = 0;
		}
	}
	int tmp = num; int count = 8; int rank = N-1;
	while (tmp > 0) {
		int k = tmp % 10;
		number[rank][count] = k;
		count -= 1;
		tmp /= 10;
		if (count == 0) {
			count = 8;
			rank -= 1;
		}
	}
	
	while (num > 0) {
		num /= 10;
		size++;
	}
}

BigNumber::BigNumber(BigNumber&other)
{
	N = other.N;
	create();
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			number[i][j] = other.number[i][j];
		}
	}
}

BigNumber::BigNumber(BigNumber&& other)
{
	N = other.N;
	create();
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			number[i][j] = other.number[i][j];
		}
	}
	other.clear();
}

void BigNumber::print()
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			if (count == 0) {
				if (number[i][j] != 0) {
					count++;
					cout << number[i][j];
				}
				
			}
			else {
				cout << number[i][j];
			}
			
		}
	}
	cout << endl;
}

void BigNumber::clear()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			number[i][j] = 0;
		}
	}
}

//BigNumber& BigNumber::operator+(BigNumber& other)
//{
//	int digit = 0;
//	for (int i = 8; i >= 0; i--) {
//		for (int j = 8; j >= 0; j--) {
//			number[i][j] += digit; digit = 0;
//			int sum = number[i][j] + other.number[i][j];
//			if (sum > 9) {
//				int k = sum % 10;
//				number[i][j] = k;
//				if (j == 0) {
//					int count = 0;
//					while (sum > 9) {
//						sum -= 10;
//						count++;
//					}
//					number[i - 1][8] += count;
//				}
//				else {
//					int count = 0;
//					while (sum > 9) {
//						sum -= 10;
//						count++;
//					}
//					digit = count;
//				}
//			}
//			else {
//				number[i][j] = sum;
//			}
//		}
//	}
//	return*this;
//}

BigNumber& BigNumber::operator+=(int num)
{
	BigNumber other(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			other.number[i][j] = number[i][j];
		}
	}

	int digit = 0; int tmp = num;
	for (int i = N; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			number[i][j] += digit; digit = 0;
			int k1 = tmp % 10; int sum;
			if (tmp >= 0) {
				sum = k1 + other.number[i][j];
				tmp /= 10;
			}
			else {
				sum = other.number[i][j];
			}
			
			if (sum > 9) {
				
				int k = sum % 10;
				number[i][j] = k;
				if (j == 0) {
						int count = 0;
						while (sum > 9) {
							sum -= 10;
							count++;
						}
						digit = count;
				}
				else {
						int count = 0;
						while (sum > 9) {
							sum -= 10;
							count++;
						}
						digit = count;
				}
				
				
			}
			else {
				number[i][j] = sum;
			}
		}
	}
	return*this;
}

BigNumber& BigNumber::operator+=(BigNumber& other)
{
	int digit = 0;
	for (int i = N-1; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			number[i][j] += digit; digit = 0;
			
			int sum = number[i][j] + other.number[i][j];
			if (sum > 9) {
				int k = sum % 10;
				number[i][j] = k;
				if (j == 0) {
					int count = 0;
					while (sum > 9) {
						sum -= 10;
						count++;
					}
					digit = count;
				}
				else {
					int count = 0;
					while (sum > 9) {
						sum -= 10;
						count++;
					}
					 digit = count;
				}
			}
			else {
				number[i][j] = sum;
			}
		}
	}
	return*this;
}

BigNumber& BigNumber::operator=(BigNumber& other)
{
	for (int i = N-1; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			number[i][j] = other.number[i][j];
		}
	}
	return *this;
}

BigNumber& BigNumber::operator=(BigNumber&& other)
{
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			number[i][j] = other.number[i][j];
		}
	}
	other.clear();
	return *this;
}


BigNumber& BigNumber::operator*=(BigNumber&other)
{
	BigNumber result(N); int count = 0; int countY = 0; int end = 0;
	
		for (int i = N; i >= 0; i--) {
			if (end == 1) {
				break;
			}
			for (int j = 8; j >= 0; j--) {
				BigNumber sum(N);
				 multiNum(number[i][j], other, sum);
				 BigNumber sum1(N);
				 sumMulti(sum, countY, sum1);
				result += sum1;


				count++; countY++;
				if (count == size) {
					end = 1;
				}
			}
		}
	
	

	for (int i = N; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			number[i][j] = result.number[i][j];
		}
	}

	return *this;
}

BigNumber& BigNumber::operator*=(int num)
{
	BigNumber result(N); int count = 0; int countY = 0; int end = 0;
	BigNumber other(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			other.number[i][j] = number[i][j];
		}
	}
	int tmp = num;
	for (int i = N; i >= 0; i--) {
		if (end == 1) {
			break;
		}
		for (int j = 8; j >= 0; j--) {
			
			BigNumber sum(N); int k = tmp % 10;
			
			multiNum(k, other, sum);
		
			BigNumber sum1(N);
			sumMulti(sum, countY, sum1);
			result += sum1;


			count++; countY++;	tmp /= 10;
			if (tmp < 0) {
				end = 1;
			}
			
		}
	}



	for (int i = N-1; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			number[i][j] = result.number[i][j];
		}
	}

	return *this;
}

void BigNumber::multiNum(int num, BigNumber& other, BigNumber& numb)
{
	 int countY = 0;
	int digit = 0;
	for (int i = N-1; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
				int sum = other.number[i][j] * num;
				sum += digit;
				digit = 0;
				if (sum > 9) {
					int k = sum % 10;
					numb.number[i][j] = k;
					int count = 0;

					while (sum > 9) {
						sum -= 10;
						count++;
					}
					digit = count;

				}
				else {
					numb.number[i][j] = sum;
				}
			
		}
	}
}

void BigNumber::sumMulti(BigNumber& other, int count1, BigNumber& sum1)
{
	
	int count = 0; int k = N-1; int l = 8;
	for (int i = N-1; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			if (count == count1) {
				sum1.number[i][j] = other.number[k][l];
				l -= 1;
				if (l < 0) {
					k -= 1;
					l = 8;
				}
			}
			else {
				sum1.number[i][j] = 0;
				count++;
			}
		}
	}

	
}

BigNumber::~BigNumber()
{
	for (int i = 0; i < N; i++) {
		delete[] number[i];
	}
	delete[] number;
}


