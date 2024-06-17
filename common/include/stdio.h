#ifndef __LIBSEA_STDIO_H__
#define __LIBSEA_STDIO_H__

#include <stddef.h>
#include <__visibility.h>

#define EOF -1
#define FILENAME_MAX 4096

typedef size_t fpos_t;

typedef struct {
	int fd;
	unsigned char* buf;
	fpos_t cur;
	int error;
	int end;
} FILE;

extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

__LIBSEA_API int fputc(int c, FILE* stream);

#endif
