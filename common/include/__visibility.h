#ifndef __LIBSEA___VISIBILITY_H__
#define __LIBSEA___VISIBILITY_H__

#ifdef __cplusplus
#define __LIBSEA_API extern "C" __attribute__((visibility("default")))
#else
#define __LIBSEA_API __attribute__((visibility("default")))
#endif

#endif
