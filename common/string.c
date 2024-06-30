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

int memcmp(const void* str1, const void* str2, size_t n) {
	const unsigned char* s1 = str1;
	const unsigned char* s2 = str2;
	for(; n-- && *s1 == *s2; ++s1, ++s2);
	return *s1 - *s2;
}

int strcmp(const char* s1, const char* s2) {
	for(; *s1 && *s2 && *s1 == *s2; ++s1, ++s2);
	return *s1 - *s2;
}

void* memset(void* s, int c, size_t n) {
	void* ret = s;
	unsigned char* buf = s;

	while(n--)
		*buf++ = (unsigned char) c;

	return ret;
}

char* strrchr(const char* s, int c) {
	const char* start = s;
	while(*s++);
	for(; s != start; --s)
		if(*s == (char) c)
			return (char*) s;

	return NULL;
}
