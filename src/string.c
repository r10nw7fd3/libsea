#include <stddef.h>

size_t strlen(const char* str) {
	const char* start = str;
	while(*str)
		++str;

	return str - start;
}

void* memchr(const void* s, int c, size_t n) {
	const unsigned char* s_uc = s;
	for(size_t i = 0; i < n; ++i)
		if(s_uc[i] == (unsigned char) c)
			return (void*) &s_uc[i];

	return NULL;
}

char* strchr(const char* s, int c) {
	if(!c)
		return (char*) s + strlen(s);

	for(; *s; ++s)
		if(*s == (char) c)
			return (char*) s;

	return NULL;
}
