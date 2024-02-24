#ifndef __LIBSEA_SETJMP_H__
#define __LIBSEA_SETJMP_H__

#include <__setjmp.h>
#include <__nomangle.h>

NOMANGLE int setjmp(jmp_buf env);
NOMANGLE _Noreturn void longjmp(jmp_buf env, int val);

#endif
