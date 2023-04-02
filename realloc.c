/*
** EPITECH PROJECT, 2022
** realloc.h
** File description:
** Realloc implementation
*/

#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    block_t *casted_ptr = NULL;
    block_t *res = NULL;

    if (ptr == NULL)
        return malloc(size);
    casted_ptr = (block_t *) ptr - 1;
    if (casted_ptr->size * sizeof(block_t) >= size)
        return ptr;
    if (casted_ptr->size * sizeof(block_t) < size) {
        res = malloc(size);
        if (res == NULL)
            return NULL;
        memcpy(res, ptr, casted_ptr->size * sizeof(block_t));
        free(ptr);
    }
    return res;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (size != 0 && nmemb != (size_t) (nmemb * size) / size)
        return NULL;
    return realloc(ptr, size * nmemb);
}
