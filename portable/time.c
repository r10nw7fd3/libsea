#include <time.h>
#include <syscall.h>

time_t time(time_t* timer) {
	time_t res = syscall(SYS_time);
	if(timer)
		*timer = res;
	return res;
}
