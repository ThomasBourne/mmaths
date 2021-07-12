# mmaths
Instructions for use:

FOR C:

to get the functions:

#include "mmaths.h"

to access functions/macros:

the function/macro follow naming scheme mmaths[operation]

e.g:

mmaths_sqrt(10);

or

mmaths_concat_int(10, 205)

FOR C++:

#include "mmaths.h"

to access functions:

EITHER:

follow C way (NOT RECCOMENDED)

or

the function name in namespace mmaths 

e.g:

mmaths::sqrt(100);

or

mmaths::concat_int(10, 205);

to access macros:

use c style naming convention

e.g:

mmaths_pfloat(10, 45631);
