#ifndef __LIBSEA_CTYPE_H__
#define __LIBSEA_CTYPE_H__

#include <__visibility.h>

__LIBSEA_API int islower(int c);
__LIBSEA_API int isupper(int c);
__LIBSEA_API int isalpha(int c);
__LIBSEA_API int iscntrl(int c);
__LIBSEA_API int isdigit(int c);
__LIBSEA_API int isalnum(int c);
__LIBSEA_API int isspace(int c);
__LIBSEA_API int isblank(int c);
__LIBSEA_API int isgraph(int c);

#endif
