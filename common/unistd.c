#include <sys/syscall.h>
#include <unistd.h>

pid_t getpid(void) {
	return syscall(SYS_getpid);
}

uid_t getuid(void) {
	return syscall(SYS_getuid);
}

gid_t getgid(void) {
	return syscall(SYS_getgid);
}

ssize_t write(int fd, const void* buf, size_t size) {
	return syscall(SYS_write, fd, buf, size);
}
