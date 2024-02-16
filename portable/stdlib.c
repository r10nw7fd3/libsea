#include <signal.h>
#include <sys/syscall.h>
#include <stddef.h>
#include <ctype.h>
#include <sys/mman.h>

_Noreturn void _Exit(int status) {
	syscall(SYS_exit, status);
	for(;;); // Compiler trick
}

_Noreturn void abort(void) {
	raise(SIGABRT);
	_Exit(1);
}

void* malloc(size_t size) {
	void* ret = mmap(NULL, size, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	return ret == MAP_FAILED ? NULL : ret;
}

#define ATOI_FOR_TYPE(type, name) \
type name(const char* nptr) { \
	while(isspace(*nptr)) \
		++nptr; \
\
	int negate = 0; \
	if(*nptr == '-') { \
		negate = 1; \
		++nptr; \
	} \
	else if(*nptr == '+') { \
		negate = 0; \
		++nptr; \
	} \
\
	type ret; \
	for(ret = 0; *nptr; ++nptr) { \
		if(!isdigit(*nptr)) \
			return 0; \
\
		ret *= 10; \
		ret += *nptr - '0'; \
	} \
\
	return negate ? -ret : ret; \
}

ATOI_FOR_TYPE(int, atoi)
ATOI_FOR_TYPE(long int, atol)
ATOI_FOR_TYPE(long long int, atoll)
