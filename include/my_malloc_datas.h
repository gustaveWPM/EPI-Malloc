/*
** EPITECH PROJECT, 2022
** my_malloc_datas.h
** File description:
** Malloc data structs and computing macros
*/

#ifndef __MY_MALLOC_DATAS_H__
    #define __MY_MALLOC_DATAS_H__

    #include "my_malloc_dependencies.h"
    #define MIN_SBRK (getpagesize() * 2)
    #define MIN_NUNITS (getpagesize() * 2) / sizeof(block_t)

    typedef struct block_s {
        size_t size;
        struct block_s *next;
    } block_t;

    typedef struct best_fit_s {
        block_t **p;
        block_t **prevp;
        block_t **bestp;
        block_t **bestprevp;
        size_t n_units;
    } best_fit_t;
#endif
