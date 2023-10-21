#ifndef __LIBSEA_CTYPE_H__
#define __LIBSEA_CTYPE_H__

#include <__nomangle.h>

NOMANGLE int islower(int c);
NOMANGLE int isupper(int c);
NOMANGLE int isalpha(int c);
NOMANGLE int iscntrl(int c);
NOMANGLE int isdigit(int c);
NOMANGLE int isalnum(int c);
NOMANGLE int isspace(int c);
NOMANGLE int isblank(int c);
NOMANGLE int isgraph(int c);

#endif
