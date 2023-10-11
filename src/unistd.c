#include <sys/syscall.h>
#include <stddef.h>

ssize_t write(int fd, const void * buf, size_t size) {
	return syscall(SYS_write, fd, buf, size);
}
