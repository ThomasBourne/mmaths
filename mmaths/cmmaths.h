#ifndef MMATHS_H
#define MMATHS_H

#include <limits.h>

/* NOTES
* BITWISE OPERATORS:
* Example int's for example results							: 0011 1100		0000 1101
* & : Binary AND				: copies bit if in both		: 0000 1100
* | : Binary OR					: copies bit if in either	: 0011 1101
* ^ : Binary XOR				: copies bit if in one		: 0011 0001
* ~ : Binary Ones Compliment	: flips bits				: 1100 0011 (flipped the first ex num)
*/

#define MMATHS_POW 10
#define MMATHS_PRECISE_PI 3.14159265358979323846
#define MMATHS_PI 3.1415926

typedef struct {
	const char* message;
	unsigned char failed;
} MmathsErrorReport;

typedef struct {
	int x;
	int y;
}cmmaths_v2;

typedef struct {
	int x;
	int y;
	int z;
}cmmaths_v3;

void mmaths_strrev(char*); //returns the reverse of the string
int mmaths_strlen(char*); //returns the length of the string
double mmaths_mean(int, ...); //returns the mean of ints passed int
double mmaths_sqrt(int); //return the square root of an interger
int mmaths_pow(int, int); //return int1 ^ int2;
double mmaths_fmax(double, double); //return largest of the 2 params
double mmaths_fmin(double, double); //return smallest of the 2 params
int mmaths_imax(int, int); //return largest of the 2 params
int mmaths_imin(int, int); //return smallest of the 2 params
int mmaths_uround(double); //round float up
int mmaths_dround(double); //round float down
unsigned int mmaths_concat_int(unsigned int, unsigned int); //return the two numbers glued [12][345] = [1245]
char mmaths_itcc_s(int, MmathsErrorReport*); //int to char conversion (with conversion safety)
char mmaths_itcc(int); //int to char conversion (without conversion safety)
char* mmaths_itsc(int);//int to string conversion
int mmaths_ctic(char, MmathsErrorReport*); //char to int conversion
int mmaths_stic(const char*); //string to int conversion


#define mmaths_copy_sign(a, b) (b >= 0 ? (a >= 0 ? a : -(a)) : (a >= 0 ? -(a) : a)) //returns a with sign (+, -) of b where 0 counts as +

#define mmaths_devide_larger(a, b) (a > b ? a / b : (a == b ? 0 : b / a)) //returns the larger devided by the smaller

#define mmaths_base10 10
#define mmaths_hex 16
#define mmaths_binary 2

#define mmaths_int_float(a) ((float)a)
#define mmaths_float_int(a) (mmaths_dround(a))

#define mmaths_int_max INT_MAX
#define mmaths_int_min INT_MIN

#define mmaths_uint_max UINT_MAX
#define mmaths_uint_min 0x00000000

#define mmaths_max(a, b) (a > b ? a : b) //return largest of 2 numbers
#define mmaths_min(a, b) (a > b ? b : a) //return smallest of 2 numbers

#endif