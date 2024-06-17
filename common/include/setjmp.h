#ifndef __LIBSEA_SETJMP_H__
#define __LIBSEA_SETJMP_H__

#include <__setjmp.h>
#include <__visibility.h>

__LIBSEA_API int setjmp(jmp_buf env);
__LIBSEA_API _Noreturn void longjmp(jmp_buf env, int val);

#endif
