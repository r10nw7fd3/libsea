#include <signal.h>
#include <sys/syscall.h>
#include <stddef.h>
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
