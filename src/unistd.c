#include <sys/syscall.h>
#include <unistd.h>

pid_t getpid(void) {
	return syscall(SYS_getpid);
}

ssize_t write(int fd, const void * buf, size_t size) {
	return syscall(SYS_write, fd, buf, size);
}
