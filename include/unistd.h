#ifndef __LIBSEA_UNISTD_H__
#define __LIBSEA_UNISTD_H__

#include <__nomangle.h>
#include <stddef.h>
#include <sys/types.h>

#define _POSIX_VERSION 200809L
#define _XOPEN_VERSION 700

NOMANGLE pid_t getpid(void);
NOMANGLE ssize_t write(int, const void *, size_t);

#endif
