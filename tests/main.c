/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Test with my malloc implementation
*/

#include "my_malloc.h"

bool test_malloc_int(void)
{
    int a = 36;
    int *a_ptr = malloc(sizeof(int));
    bool res = false;

    *a_ptr = 36;
    res = a == *a_ptr;
    free(a_ptr);
    return res;
}

bool test_malloc_str(void)
{
    bool res = false;
    char *lol = malloc(4);

    strcpy(lol, "lol");
    lol[3] = '\0';
    res = strcmp("lol", lol) == 0;
    free(lol);
    return res;
}

bool test_big_malloc(void)
{
    void *q = malloc(9000000);
    bool res = false;
    res = q != NULL;
    free(q);
    return res;
}

bool test_calloc_a(void)
{
    int *arr = calloc(10, sizeof(int));

    for (int i = 0; i < 10; i++) {
        if (arr[i] != 0) {
            free(arr);
            return false;
        }
    }
    free(arr);
    return true;
}

bool test_calloc_b(void)
{
    int *arr = calloc(10, sizeof(int));
    bool res = false;

    for (int i = 0; i < 10; i++)
        arr[i] = i + 1;
    res = ((arr[0] == 1) && (arr[9] == 10));
    free(arr);
    return res;
}

bool test_malloc_strcpy(void)
{
    bool res = false;
    char *str = (char *) malloc(15);

    strcpy(str, "tutorialspoint");
    res = strcmp("tutorialspoint", str) == 0;
    free(str);
    return res;
}

bool test_realloc(void)
{
    bool res = false;
    char *str;
    str = (char *) malloc(15);
    strcpy(str, "tutorialspoint");
    str = (char *) realloc(str, 25);
    strcat(str, ".com");

    res = strcmp("tutorialspoint.com", str) == 0;
    return res;
}

bool test_gentle_malloc_a(void)
{
    bool res = false;
    char *str = (char *) malloc(4096);

    res = str != NULL;
    free(str);
    return res;
}

bool test_gentle_malloc_b(void)
{
    bool res = false;
    char *str = (char *) malloc(4096 * 3);

    res = str != NULL;
    free(str);
    return res;
}

bool test_gentle_malloc_c(void)
{
    bool res = false;
    char *str = (char *) malloc(4096 * 11);

    res = str != NULL;
    free(str);
    return res;
}

bool dumb_test(void)
{
    char *a = malloc(0);
    char *b = calloc(0, 0);
    char *d = NULL;
    char *c = reallocarray(d, 0, 0);
    free(a);
    free(b);
    free(c);
    return true;
}

bool test_multiple_calloc(void)
{
    char *a = calloc(10, 10);
    a = calloc(20, 20);
    a = calloc(40, 40);
    a = calloc(100, 10);

    return a[999] == 0;
}

bool test_big_calloc(void)
{
    char *a = calloc(500, 100);
    bool res = false;

    res = a[49999] == 0;
    free(a);
    return res;
}

bool test_multiple_malloc(void)
{
    char *a = malloc(10 * 10);
    a = malloc(20 * 20);
    a = malloc(40 * 40);
    a = malloc(100 * 10);

    return a != NULL;
}

bool test_huge_malloc(void)
{
    char *a = malloc(500 * 100);
    bool res = false;

    res = a != NULL;
    free(a);
    return res;
}

int main(void)
{
    if (!dumb_test())
        return -1;
    if (!test_gentle_malloc_a())
        return -2;
    if (!test_gentle_malloc_b())
        return -3;
    if (!test_gentle_malloc_c())
        return -4;
    if (!test_malloc_int())
        return 1;
    if (!test_malloc_str())
        return 2;
    if (!test_big_malloc())
        return 3;
    if (!test_calloc_a())
        return 4;
    if (!test_calloc_b())
        return 5;
    if (!test_malloc_strcpy())
        return 6;
    if (!test_realloc())
        return 7;
    if (!test_multiple_calloc())
        return 8;
    if (!test_big_calloc())
        return 9;
    if (!test_multiple_malloc())
        return 10;
    if (!test_huge_malloc())
        return 11;
    return 0;
}
