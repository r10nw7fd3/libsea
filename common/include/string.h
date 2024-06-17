#ifndef __LIBSEA_STRING_H__
#define __LIBSEA_STRING_H__

#include <__visibility.h>
#include <stddef.h>

__LIBSEA_API size_t strlen(const char* s);
__LIBSEA_API void* memchr(const void* s, int c, size_t n);
__LIBSEA_API char* strchr(const char* s, int c);
__LIBSEA_API int memcmp(const void* s1, const void* s2, size_t n);
__LIBSEA_API int strcmp(const char* s1, const char* s2);
__LIBSEA_API void* memset(void* s, int c, size_t n);
__LIBSEA_API char* strrchr(const char* s, int c);

#endif
