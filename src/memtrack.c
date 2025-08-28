#include "memtrack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    size_t size;
} MemHeader;

static size_t mem_usage = 0;

void* mt_malloc(size_t size) {
    MemHeader* header = (MemHeader*)malloc(sizeof(MemHeader) + size);
    if (!header) return NULL;
    header->size = size;
    mem_usage += size;
    return (void*)(header + 1);
}

void* mt_calloc(size_t count, size_t size) {
    MemHeader* header = (MemHeader*)calloc(1, sizeof(MemHeader) + count * size);
    if (!header) return NULL;
    header->size = count * size;
    mem_usage += count * size;
    return (void*)(header + 1);
}

void mt_free(void* ptr) {
    if (!ptr) return;
    MemHeader* header = ((MemHeader*)ptr) - 1;
    mem_usage -= header->size;
    free(header);
}

size_t mt_get_usage(void) {
    return mem_usage;
}