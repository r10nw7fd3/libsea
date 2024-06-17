#ifndef __LIBSEA_STDLIB_H__
#define __LIBSEA_STDLIB_H__

#include <__visibility.h>
#include <stddef.h>

__LIBSEA_API _Noreturn void _Exit(int status);
__LIBSEA_API _Noreturn void abort(void);
__LIBSEA_API void* malloc(size_t size);
__LIBSEA_API void free(void* ptr);

__LIBSEA_API int atoi(const char* nptr);
__LIBSEA_API long int atol(const char* nptr);
__LIBSEA_API long long int atoll(const char* nptr);

#endif
