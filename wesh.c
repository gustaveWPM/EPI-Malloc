/*
** EPITECH PROJECT, 2022
** wesh.c
** File description:
** Malloc internal functions
*/

#include "my_malloc.h"

bool malloc_bestfit_perfect_match(block_t **p, block_t **prevp, size_t n_units)
{
    if ((*p)->size == n_units) {
        (*prevp)->next = (*p)->next;
        return true;
    }
    return false;
}

void malloc_bestfit_loop(block_t **p, block_t **prevp)
{
    *prevp = *p;
    *p = (*p)->next;
}

void malloc_update_best_block(
    block_t **p, block_t **best_block_prev,
    block_t **prevp, block_t **best_block
)
{
    *best_block_prev = *prevp;
    *best_block = *p;
}

bool malloc_failed_to_extend_heap(block_t **p, size_t n_units)
{
    *p = malloc_extend_heap(n_units);
    return *p == NULL;
}
