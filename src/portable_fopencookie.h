/* 
 *	Provides a very limited fopencookie() for environments with a libc
 *	that lacks it.
 *
 *	Authors: zhasha & nsz
 *	Modified for libsolv by Neal Gompa
 *	Modified for external use by Neal Gompa
 *
 *	This program is licensed under the BSD license, see LICENSE 
 *	for further information.
 *
 */

#ifndef PORTABLE_FOPENCOOKIE_H
#define PORTABLE_FOPENCOOKIE_H

#include <stdio.h>
#include <stdint.h>

typedef struct cookie_io_functions_t {
    ssize_t (*read)(void *, char *, size_t);
    ssize_t (*write)(void *, const char *, size_t);
    int (*seek)(void *, off_t *, int);
    int (*close)(void *);
} cookie_io_functions_t;

FILE *fopencookie(void *cookie, const char *mode, struct cookie_io_functions_t io);

#endif
