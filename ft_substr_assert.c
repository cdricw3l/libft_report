/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:39:21 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 20:37:11 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"


static void ft_substr_test(int test_nb, char *s1, size_t start, size_t len, char *expected)
{
    char *str;
    char *s_input;
    char *s_expect;
    char *s_sub;

    #ifdef __APPLE__
        size_t (*f)(const void *);
        f = malloc_size;
    #endif
    #ifdef __linux__
        size_t (*f)(void *);
        f = malloc_usable_size;
    #endif

    printf("Test %d:\n",test_nb);
    str = ft_substr(s1, start, len);
    if (!str)
        s_sub = NULL_STR;
    else if(str && !strlen(str))
        s_sub = EMPTY_STR;
    else
        s_sub = str;
    if(expected && strlen(expected))
        s_expect = expected;
    else if (expected && !strlen(expected))
        s_expect = EMPTY_STR;
    else
        s_expect = NULL_STR;
    if (!s1)
        s_input = NULL_STR;
    else if (s1 && !strlen(s1))
        s_input = EMPTY_STR;
    else
        s_input = s1;

    if(!expected)
    {
        if (str)
            printf("\tInput: %s\n\tExpected output: %s\n\tEffective output: %s\n\tResult -> "TEST_NOK"\n\tMemory check ->"TEST_NOK"\n", s_input, s_expect, s_sub);
        else
            printf("\tInput: %s\n\tExpected output: %s\n\tEffective output: %s\n\tResult -> "TEST_OK"\n\tMemory check ->"TEST_OK"\n", s_input, s_expect, s_sub);
    }
    else
    {
        if (!strcmp(str, expected))
            printf("\tInput: %s\n\tExpected output: %s\n\tEffective output: ""%s""\n\tString compare->" TEST_OK"\n", s_input, s_expect, s_sub);
        else
            printf("\tInput: %s\n\tExpected output: %s\n\tEffective output: %s\n\tString compare->" TEST_NOK"\n", s_input, s_expect, s_sub);
        if(f(str) == f(expected))
            printf("\tMemory size allocation ->"TEST_OK"\n");
        else
            printf("\tMemory size allocation ->"TEST_NOK"\n");
        free(str);
        free(expected);
    }

}

int main(void)
{
    char *name_fonction = "ft_substr";
    TEST_STAR(name_fonction);
    int test_nb;

    test_nb  = 1;
    /* test 1 */
    ft_substr_test(test_nb++, "hello 42 Berlin", 0, strlen("hello 42 Berlin"), strdup("hello 42 Berlin"));
    /* test 2 */
    ft_substr_test(test_nb++, "hello 42 Berlin", strlen("hello 42 Berlin") - 1, 100, strdup("n"));
    /* test 3 */
    ft_substr_test(test_nb++, "hello 42 Berlin", 3, 3, strdup("lo "));
    /* test 4 */
    ft_substr_test(test_nb++, "hello 42 Berlin", 9, 1, strdup("B"));
    /* test 5 */
    ft_substr_test(test_nb++, "hello 42 Berlin", 9, 100, strdup("Berlin"));
    /* test 6 */
    ft_substr_test(test_nb++, "hello 42 Berlin", 0, 0, strdup(""));
    /* test 7 */
    ft_substr_test(test_nb++, "hello 42 Berlin", 1000, 3, strdup(""));
    /* test 8 */
    ft_substr_test(test_nb++, "hello 42 Berlin", strlen("hello 42 Berlin"), 100, strdup(""));
    /* test 9 */
    ft_substr_test(test_nb++, "hello 42 Berlin", strlen("hello 42 Berlin"), -1000, strdup(""));
    /* test 10 */
    ft_substr_test(test_nb++, "hello 42 Berlin", strlen("hello 42 Berlin"), -1000, strdup(""));
    /* test 11 */
    ft_substr_test(test_nb++, "", 0, 1, strdup(""));
    /* test 12 */
    ft_substr_test(test_nb++, "", 1000, 3, strdup(""));
    /* test 13 */
    ft_substr_test(test_nb++, NULL, 0, 100, NULL);
    TEST_END(name_fonction);
    SEP;
    NL;
    return (0);
}