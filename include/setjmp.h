#ifndef __LIBSEA_SETJMP_H__
#define __LIBSEA_SETJMP_H__

#include <__nomangle.h>
#include <stdint.h>

// rbx, rsp, rbp, r12, r13, r14, r15, return address.
// No need to save scratch registers
typedef uint64_t jmp_buf[8];

NOMANGLE int setjmp(jmp_buf env);
NOMANGLE _Noreturn void longjmp(jmp_buf env, int val);

#endif
