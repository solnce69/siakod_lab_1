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