#include<iostream>
#include"BigNumber.h"
using namespace std;

void fact(int num, BigNumber&);

int main() {
    cout << "Enter rank:" << endl; int n;//����� ��������� ��������� 100! ����� ������� ���� 18 � ����
    cin >> n;
    BigNumber num(1, n);
    fact(100, num);
    BigNumber num1(move(num));
    
    num1.print();
    cout <<"///////" <<  endl;
    num.print();
}

void fact(int num, BigNumber& n)
{
    for (int i = 1; i <= num; i++) {
        n *= i;
    }
}
