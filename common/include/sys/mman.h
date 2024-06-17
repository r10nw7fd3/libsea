#ifndef __LIBSEA_MMAN_H__
#define __LIBSEA_MMAN_H__

#include <__visibility.h>
#include <stddef.h>
#include <sys/types.h>

#define MAP_FAILED ((void*) -1)

#define PROT_EXEC 4
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_NONE 0

#define MAP_SHARED 1
#define MAP_SHARED_VALIDATE 3
#define MAP_PRIVATE 2

#define MAP_32BIT 0
#define MAP_ANONYMOUS 0x20
#define MAP_ANON MAP_ANONYMOUS
#define MAP_DENYWRITE 0x0800
#define MAP_EXECUTABLE 0x1000
#define MAP_FILE 0
#define MAP_FIXED 0x10
#define MAP_FIXED_NOREPLACE 0x100000
#define MAP_GROWSDOWN 0x0100
#define MAP_HUGETLB 0x040000
#define MAP_HUGE_2MB (21U << 26)
#define MAP_HUGE_1GB (30U << 26)
#define MAP_LOCKED 0x2000
#define MAP_NONBLOCK 0x040000
#define MAP_NORESERVE 0x4000
#define MAP_POPULATE 0x008000
#define MAP_STACK 0x020000
#define MAP_SYNC 0x080000
#define MAP_UNINITIALIZED 0x4000000

__LIBSEA_API void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);
__LIBSEA_API int munmap(void* addr, size_t length);

#endif
