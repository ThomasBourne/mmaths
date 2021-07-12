
  ///////////////////////////////////
 /// Miscellaneous Maths Library ///
///////////////////////////////////


  ///////////////////////////////////////////
 /// INCLUDE THIS FILE FOR BOT C AND C++ ///
///////////////////////////////////////////


#ifndef MMATHS_MAIN_H
#define MMATHS_MAIN_H

#ifdef __cplusplus
#include "cppmmaths.hpp"
#define mmaths_pfloat(whole, point) mmaths::pfloat(whole, point)
#else
#include "cmmaths.h"
#endif

#endif