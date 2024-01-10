#ifndef __LIBSEA_ASSERT_H__
#define __LIBSEA_ASSERT_H__

#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>

#define static_assert _Static_assert

#ifdef NDEBUG
#define assert(ignore) ((void) 0);
#else 
// https://stackoverflow.com/a/19343239/19823424
#define __libsea_expansion1(x) #x
#define __libsea_expansion2(x) __libsea_expansion1(x)
#define assert(expr) \
	if(!expr) { \
		const char* assert_str = __FILE__":" __libsea_expansion2(__LINE__) ": Assertion failed: " #expr "\n"; \
		syscall(SYS_write, 1, assert_str, strlen(assert_str)); \
		abort(); \
	}
#endif

#endif
