#include "pch.h"
#include <iostream>
#include <iomanip>
#include <stdio.h> 
#include <conio.h> 
using namespace std;
void BinOut(unsigned char* Buf, int len) {
	int i, j;
	unsigned char byte;
	for (i = len - 1; i >= 0; i--)
		for (j = 1, byte = Buf[i]; j <= 8; byte <<= 1, j++)
			_putch(byte & 0x80 ? '1' : '0');
	printf("\n");
}
void BinIn(unsigned char* Buf, int len) {
	int i, j;
	char ch;
	for (i = len - 1; i >= 0; i--)
		for (j = 1, Buf[i] = 0; j <= 8; Buf[i] = (Buf[i] << 1) + (ch - '0'), j++) {
			while ((ch = _getch()) != '0' && ch != '1');
			_putch(ch);
		}
	printf("\n");
}
int main(int argc, char* argv[]) {
	int n;
	cout << "Enter number of a int type: ";
	cin >> n;
	cout << "This is its binary representation:" << endl;
	BinOut((unsigned char*)&n, sizeof(n));
	cout << "Enter binary representation of a int number:" << endl;
	BinIn((unsigned char*)&n, sizeof(n));
	cout << "This is its value: " << n << endl;
	double y;
	cout << "Enter number of a double type: ";
	cin >> y;
	cout << "This is its binary representation:" << endl;
	BinOut((unsigned char*)&y, sizeof(y));
	cout << "Enter binary representation of a double number:" << endl;
	BinIn((unsigned char*)&y, sizeof(y));
	cout << "This is its value: " << setprecision(20) << y << endl;
	typedef unsigned long arr[7];
	arr A;
	for (int i = 0; i < 7; i++) {
		cout << "Enter number of a unsigned long type (A[" << i + 1 << "]): ";
		cin >> A[i];
	}
	BinOut((unsigned char*)&A, sizeof(A));
	cout << "Enter binary representation of a double number:" << endl;
	BinIn((unsigned char*)&A, sizeof(A));
	cout << "This is its value: ";
	for (int i = 0; i < 7; i++) {

		cout << A[i] << " ";
	}
	return 0;
}