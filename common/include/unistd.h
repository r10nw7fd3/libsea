#ifndef __LIBSEA_UNISTD_H__
#define __LIBSEA_UNISTD_H__

#include <__visibility.h>
#include <stddef.h>
#include <sys/types.h>

#define _POSIX_VERSION 200809L
#define _XOPEN_VERSION 700

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

__LIBSEA_API pid_t getpid(void);
__LIBSEA_API uid_t getuid(void);
__LIBSEA_API gid_t getgid(void);
__LIBSEA_API ssize_t write(int, const void*, size_t);

#endif
