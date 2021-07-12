#include "cmmaths.h"
#include <string.h>
#include <stdarg.h>

//private funcs (need static declaration)
static int mmaths_p_num_places_int(int n) {
	int r = 1;
	if (n < 0) n = (n == INT_MIN) ? INT_MAX : -n;
	while (n > 9) {
		n /= 10;
		r++;
	}
	return r;
}








//public funcs
double mmaths_mean(int count, ...) {
	double result = 0.0;
	va_list valist;
	va_start(valist, count);
	for (int i = 0; i < count; i++) {
		result += va_arg(valist, int);
	}
	return result / count;
}

double mmaths_sqrt(int num) {
	double sqrt = (float)num / 2;
	double temp = 0;

	while (sqrt != temp) {
		temp = sqrt;

		sqrt = (num / temp + temp) / 2;
	}
	return sqrt;
}

double mmaths_fmax(double a, double b) {
	return a > b ? a : b;
}
double mmaths_fmin(double a, double b) {
	return a > b ? b : a;
}
int mmaths_imax(int a, int b) {
	return a > b ? a : b;
}
int mmaths_imin(int a, int b) {
	return a > b ? b : a;
}

int mmaths_uround(double num) {
	if (num > 0) {
		return (int)(num + (double)0.9);
	}
	else if (num < 0) {
		return (int)(num);
	}
	return 0;
}

int mmaths_dround(double num) {
	if (num > 0) {
		return (int)(num);
	}
	else {
		return (int)(num - (double)0.9);
	}
	return 0;
}

unsigned int mmaths_concat_int(unsigned int x, unsigned int y) { //combines 2 numbers together (in powers of 10)
	//unsigned int pow = 10;
	while (y >= MMATHS_POW)
		if (MMATHS_POW > UINT_MAX / 10)
			return y;
		//pow *= 10; //example had this but it seems to not work loool
	return x * MMATHS_POW + y;
}

char mmaths_itcc_s(int num, MmathsErrorReport* errReport) { //with safty
	if (num > 10) {
		errReport->message = "Number passed in was too large to convert to char";
		errReport->failed = 1;
		return '0';
	}
	return num + '0';
}

char mmaths_itcc(int num) { //without safty
	return num + '0';
}

#include <stdio.h>
const char* mmaths_itsc(int num) { // BUG HERE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	char str[255];
	str[strlen(str)] = '\0';
	int numPlaces = mmaths_p_num_places_int(num);
	for (int i = numPlaces; i > 0; i--) {
		printf("%d\n",( num / 10 * numPlaces));
		char currNum = mmaths_itcc(mmaths_dround((num / 10 * numPlaces)));
		strncat(str, &currNum, 1);
		numPlaces--;
	}
	return str;
}

int mmaths_ctic(char ch, MmathsErrorReport* errReport) { //converts char to int and returns 0 + an error if char was invalid
	int num = ch - '0';
	//printf("%d\n", num);
	if (num > 9 || num < 0) {
		errReport->message = "Char passed in was not a number";
		errReport->failed = 1;
		return 0;
	}
	return num;
}

int mmaths_stic(const char* str) { //converts string to int and ignores non ints
	int result = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		MmathsErrorReport e;
		int ch = mmaths_ctic(str[i], &e);
		if(e.failed == 1) {}
		else {
			result = mmaths_concat_int(result, ch);
		}
	}
	return result;
}