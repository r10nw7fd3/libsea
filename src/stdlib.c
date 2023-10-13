#include <signal.h>
#include <sys/syscall.h>

_Noreturn void _Exit(int status) {
	syscall(SYS_exit, status);
	for(;;); // Compiler trick
}

_Noreturn void abort(void) {
	raise(SIGABRT);
	_Exit(1);
}
