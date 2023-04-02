/*
** EPITECH PROJECT, 2022
** opti.c
** File description:
** Coalescing and splitting
*/

#include "my_malloc.h"

void malloc_split_block(block_t **block, size_t n_units)
{
    if (SPLITTING_ENABLED) {
        (*block)->size -= n_units;
        (*block) += (*block)->size;
    }
    (*block)->size = n_units;
}

void free_coalesce(block_t **b_ptr, block_t **p)
{
    if (!COALESCING_ENABLED) {
        if (*b_ptr + (*b_ptr)->size != (*p)->next)
            (*b_ptr)->next = (*p)->next;
        if (*p + (*p)->size != *b_ptr)
            (*p)->next = *b_ptr;
        return;
    }
    if (*b_ptr + (*b_ptr)->size == (*p)->next) {
        (*b_ptr)->size += (*p)->next->size;
        (*b_ptr)->next = (*p)->next->next;
    } else
        (*b_ptr)->next = (*p)->next;
    if (*p + (*p)->size == *b_ptr) {
        (*p)->size += (*b_ptr)->size;
        (*p)->next = (*b_ptr)->next;
    } else
        (*p)->next = *b_ptr;
}
