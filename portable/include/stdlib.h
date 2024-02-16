#ifndef __LIBSEA_STDLIB_H__
#define __LIBSEA_STDLIB_H__

#include <__nomangle.h>
#include <stddef.h>

NOMANGLE _Noreturn void _Exit(int status);
NOMANGLE _Noreturn void abort(void);
NOMANGLE void* malloc(size_t size);

NOMANGLE int atoi(const char* nptr);
NOMANGLE long int atol(const char* nptr);
NOMANGLE long long int atoll(const char* nptr);

#endif
