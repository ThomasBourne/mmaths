#ifndef CPPSTR_HPP
#define CPPSTR_HPP
//#include "../list/list.hpp"
namespace mmaths {
	class string_box {
	private:

	public:
		string_box() = default;

		inline void operator=(const char*);
		inline void operator=(char*);
	};
	typedef string_box string, *strptr, &strref;
}

typedef mmaths::string_box string, *strptr, &strref;
#endif