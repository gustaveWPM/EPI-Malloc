/*
** EPITECH PROJECT, 2022
** my_malloc_funs.h
** File description:
** Malloc public and internal functions
*/

#ifndef __MY_MALLOC_FUNS_H__
    #define __MY_MALLOC_FUNS_H__

    #include "my_malloc_dependencies.h"
    #include "my_malloc_datas.h"

    void free(void *);
    void *malloc(size_t);
    void *calloc(size_t, size_t);
    void *realloc(void *, size_t);
    void *reallocarray(void *, size_t, size_t);

    bool malloc_found_best_block(best_fit_t *);
    bool malloc_failed_to_extend_heap(block_t **, size_t);
    void malloc_bestfit_loop(block_t **, block_t **);
    bool malloc_bestfit_perfect_match(block_t **, block_t **, size_t);
    void malloc_update_best_block(
        block_t **, block_t **, block_t **, block_t **
    );

    block_t *malloc_extend_heap(size_t);
    void malloc_split_block(block_t **, size_t);
    void free_coalesce(block_t **, block_t **);
#endif
