#ifndef __LIBSEA___SETJMP_H__
#define __LIBSEA___SETJMP_H__

#include <stdint.h>

// rbx, rsp, rbp, r12, r13, r14, r15, return address.
// No need to save scratch registers
typedef uint64_t jmp_buf[8];

#endif
