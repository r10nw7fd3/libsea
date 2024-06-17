#include <ctype.h>

int islower(int c) {
	return c >= 'a' && c <= 'z';
}

int isupper(int c) {
	return c >= 'A' && c <= 'Z';
}

int isalpha(int c) {
	return islower(c) || isupper(c);
}

int iscntrl(int c) {
// TODO: Lookup control characters
	return c >= 0 && c <= 31;
}

int isdigit(int c) {
	return c >= '0' && c <= '9';
}

int isalnum(int c) {
	return isalpha(c) || isdigit(c);
}

int isspace(int c) {
	return c == ' ' ||
		c == '\f' ||
		c == '\n' ||
		c == '\r' ||
		c == '\t' ||
		c == '\v';
}

int isblank(int c) {
	return c == ' ' || c == '\t';
}

int isgraph(int c) {
// TODO: Lookup printing characters
	return c > ' ' && c != 127;
}
