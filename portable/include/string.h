#ifndef __LIBSEA_STRING_H__
#define __LIBSEA_STRING_H__

#include <__nomangle.h>
#include <stddef.h>

NOMANGLE size_t strlen(const char* s);
NOMANGLE void* memchr(const void* s, int c, size_t n);
NOMANGLE char* strchr(const char* s, int c);
NOMANGLE int memcmp(const void* s1, const void* s2, size_t n);
NOMANGLE int strcmp(const char* s1, const char* s2);
NOMANGLE void* memset(void* s, int c, size_t n);

#endif
