#include <signal.h>
#include <sys/syscall.h>
#include <sys/mman.h>
#include <stddef.h>
#include <stdint.h>
#include <ctype.h>

_Noreturn void _Exit(int status) {
	syscall(SYS_exit, status);
	for(;;); // Compiler trick
}

_Noreturn void abort(void) {
	raise(SIGABRT);
	_Exit(1);
}

void* malloc(size_t size) {
	size_t actual_size = size + sizeof(size_t);
	void* actual_addr = mmap(NULL, actual_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(actual_addr == MAP_FAILED)
		return NULL;

	*(size_t*) actual_addr = size;
	void* user_addr = (uint8_t*) actual_addr + sizeof(size_t);
	return user_addr;
}

void free(void* ptr) {
	if(!ptr)
		return;

	void* actual_addr = (uint8_t*) ptr - sizeof(size_t);
	size_t actual_size = *(size_t*) actual_addr + sizeof(size_t);
	munmap(actual_addr, actual_size);
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
