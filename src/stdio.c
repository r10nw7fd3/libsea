#include <stdio.h>
#include <sys/syscall.h>

FILE __libsea_stdin = {0, NULL, 0, 0, 0};
FILE __libsea_stdout = {1, NULL, 0, 0, 0};
FILE __libsea_stderr = {2, NULL, 0, 0, 0};

FILE* stdin = &__libsea_stdin;
FILE* stdout = &__libsea_stdout;
FILE* stderr = &__libsea_stderr;

// TODO: This is not the right way to handle streams
int fputc(int c, FILE* stream) {
	if(stream->buf && stream->end) {
		stream->error = 1;
		return EOF;
	}

	if(syscall(SYS_write, stream->fd, (unsigned char*) &c, 1) != 1) {
		stream->error = 1;
		return EOF;
	}

	++stream->cur;

	return c;
}
