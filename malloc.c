/*
** EPITECH PROJECT, 2022
** malloc.c
** File description:
** Malloc implementation
*/

#include "my_malloc.h"

static block_t alloc_b = {0};
static block_t *free_b = NULL;

block_t *malloc_extend_heap(size_t n_units)
{
    char *old_break;
    block_t *new_node;
    size_t sbrk_size = MIN_SBRK;
    size_t size = 0;

    if (n_units < MIN_NUNITS)
        n_units = MIN_NUNITS;
    size = n_units * sizeof(block_t);
    while (sbrk_size < size)
        sbrk_size = sbrk_size * 2;
    old_break = sbrk(sbrk_size);
    if (old_break == (char *) -1)
        return NULL;
    new_node = (block_t *) old_break;
    new_node->size = sbrk_size / sizeof(block_t);
    free((void *) (new_node + 1));
    return free_b;
}

static void *best_fit(block_t *prevp, block_t *p, size_t n_units)
{
    block_t *best_block = NULL;
    block_t *best_blockprev = NULL;

    while (!malloc_bestfit_perfect_match(&p, &prevp, n_units)) {
        if (p->size >= n_units && (!best_block || best_block->size > p->size))
            malloc_update_best_block(&p, &best_blockprev, &prevp, &best_block);
        if (p == free_b && best_block) {
            best_blockprev->next = best_block->next;
            malloc_split_block(&best_block, n_units);
            free_b = best_blockprev;
            return (void *) (best_block + 1);
        }
        if (p == free_b && malloc_failed_to_extend_heap(&p, n_units))
            return NULL;
        malloc_bestfit_loop(&p, &prevp);
    }
    free_b = prevp;
    return (void *) (p + 1);
}

void *malloc(size_t size)
{
    block_t *prevp = free_b;
    size_t n_units;

    if (prevp == NULL) {
        alloc_b.next = &alloc_b;
        free_b = &alloc_b;
        prevp = &alloc_b;
        alloc_b.size = 0;
        malloc_extend_heap(MIN_NUNITS);
    }
    if (size == 0)
        return NULL;
    n_units = (size + sizeof(block_t) - 1) / sizeof(block_t) + 1;
    return best_fit(prevp, prevp->next, n_units);
}

void free(void *ptr)
{
    block_t *b_ptr = (block_t *) ptr - 1;
    block_t *p = NULL;

    if (ptr == NULL)
        return;
    for (p = free_b; !(b_ptr > p && b_ptr < p->next); p = p->next)
        if (p >= p->next && (b_ptr > p || b_ptr < p->next))
            break;
    free_coalesce(&b_ptr, &p);
    free_b = p;
}

void *calloc(size_t nmemb, size_t size)
{
    unsigned char *initial_ptr = NULL;
    size_t total_size = nmemb * size;

    if (size != 0 && nmemb != total_size / size)
        return NULL;
    initial_ptr = malloc(total_size);
    if (initial_ptr == NULL)
        return NULL;
    memset(initial_ptr, 0, total_size);
    return initial_ptr;
}
