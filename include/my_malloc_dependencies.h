/*
** EPITECH PROJECT, 2022
** my_malloc_dependencies.h
** File description:
** Malloc dependencies (from libC). Undef some values for obvious reasons.
*/

#ifndef __MY_MALLOC_DEPENDENCIES_H__
    #define __MY_MALLOC_DEPENDENCIES_H__

    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <string.h>
    #include <stdint.h>

    #undef malloc
    #undef free
    #undef calloc
    #undef realloc
    #undef reallocarray
#endif
