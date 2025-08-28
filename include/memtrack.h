#ifndef MEMTRACK_H
#define MEMTRACK_H

#include <stddef.h>

void* mt_malloc(size_t size);
void* mt_calloc(size_t count, size_t size);
void mt_free(void* ptr);
size_t mt_get_usage(void);

#endif // MEMTRACK_H