#include <sys/syscall.h>
#include <sys/mman.h>

void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset) {
	long ret = syscall(SYS_mmap, addr, length, prot, flags, fd, offset);
	return (void*) ret;
}

int munmap(void* addr, size_t length) {
	return syscall(SYS_munmap, addr, length);
}
