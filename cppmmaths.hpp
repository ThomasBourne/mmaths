
//THIS IS NOT THE C++ ALTERNATE FUNCTIONS BUT EXTRA FUNCTIONS ONLY IN C++

#ifndef CPPMMATHS_HPP
#define CPPMMATHS_HPP

#include <limits>
#include <string>
#include <vector>
#include <cstdarg>
#include <iostream>

extern "C" {
#include "cmmaths.h"
}

namespace mmaths {
	extern "C" {
		double (*const mean)(int, ...) { &mmaths_mean };

		double (*const sqrt)(int) { &mmaths_sqrt };

		double (*const fmax)(double, double) { &mmaths_fmax };
		double (*const fmin)(double, double) { &mmaths_fmin };
		int (*const imax)(int, int) { &mmaths_imax };
		int (*const imin)(int, int) { &mmaths_imin };

		int (*const uround)(double) { &mmaths_uround };
		int (*const dround)(double) { &mmaths_dround };

		unsigned int (*const concat_int)(unsigned int, unsigned int) { &mmaths_concat_int };

		char (*const itcc_s)(int, MmathsErrorReport*) { &mmaths_itcc_s };
		char (*const itcc)(int) { &mmaths_itcc };
		const char* (*const itsc)(int) { &mmaths_itsc };

		int (*const ctic)(char, MmathsErrorReport*) { &mmaths_ctic };
		int (*const stic)(const char*) { &mmaths_stic };
	}
}

namespace mmaths {
	struct pfloat { //idea is a precise, slow float alternative that useds a u long long to store the deciamls
	public:
		int whole;
		unsigned long long point;
		pfloat(int whole, unsigned long long point) {
			this->whole = whole;
			this->point = point;
		}

		std::string dVal() {
			std::string strVal = itsc(this->point);
			return strVal;
		}

		//inline pfloat operator+ () {

		//}
	};

	template<typename A, typename B>
	bool CompareTypes(A a, B b) { //takes in 2 variables and compares types
		return typeid(a) == typeid(b) ? true : false;
	}
	template<typename A, typename B>
	bool CompareTypes() { //overload for 2 data types and no variables
		return typeid(A) == typeid(B) ? true : false;
	}

	template<typename T>
	struct Vec {
		std::vector<T> dimensions;

		Vec(int num, ...) {
			va_list valist;
			va_start(valist, num);
			for (int i = 0; i < num; i++) {
				this->dimensions[i] = va_arg(valist, T);
			}
			va_end(valist);
		}

		void PrintVec() {
			for (auto& p : this->dimensions) {
				std::cout << p;
			}
			std::cout << std::endl;
		}
	};
}
#endif