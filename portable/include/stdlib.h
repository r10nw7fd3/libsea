#ifndef __LIBSEA_STDLIB_H__
#define __LIBSEA_STDLIB_H__

#include <__nomangle.h>
#include <stddef.h>

NOMANGLE _Noreturn void _Exit(int status);
NOMANGLE _Noreturn void abort(void);
NOMANGLE void* malloc(size_t size);

#endif
