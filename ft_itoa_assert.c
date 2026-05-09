/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_assert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:30:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 16:50:56 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void ft_itoa_test(int nb, char *expected, int test_nb)
{
    char *ft;
    char *s;

    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #else
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif
    
    s = strdup(expected);
    ft = ft_itoa(nb);
    printf("Test %d :\n", test_nb);
    printf("\tInput: " C_PBG "%d"C_RESET"\n",nb);
    printf("\tExpected: %s\n", s);
    printf("\tOutput: %s\n",ft);
    if(!strcmp(s,ft))
        printf("\tResult -> "TEST_OK"\n");
    else    
        printf("\tResult -> "TEST_NOK"\n");
    /* checking if the memory size allocation of itoa is the same as the allocation of strdup exepected*/
    if(f(ft) == f(s))
        printf("\tMemory check: -> " TEST_OK "\n");
    else
        printf("\tMemory check: -> " TEST_NOK "\n");
    free(ft);
    free(s);
}

int main(void)
{
    char *test_name = "ft_itoa";
    TEST_STAR(test_name);
    int test_nb;

    test_nb = 1;
    /* test 1 */
    ft_itoa_test(0,"0", test_nb++);
    /* test 2 */
    ft_itoa_test(INT_MIN,"-2147483648", test_nb++);
    /* test 3 */
    ft_itoa_test(INT_MAX,"2147483647", test_nb++);
    /* test 4 */
    ft_itoa_test(42,"42", test_nb++);
    /* test 5 */
    ft_itoa_test(-1,"-1", test_nb++);
    /* test 6 */
    ft_itoa_test(001,"1", test_nb++);
    /* test 7 */
    ft_itoa_test(002,"2", test_nb++);
    /*https://www.geeksforgeeks.org/c/octal-literals-in-c/ -> "When we initialize a value by putting '0' before a number, the number is treated as octal"*/
    /* test 8 */
    ft_itoa_test(012,"10", test_nb++);
    /* test 7 */
    ft_itoa_test(0166,"118", test_nb++);
    /* test 8 */
    ft_itoa_test(0xA,"10", test_nb++);
    TEST_END(test_name);
    SEP;
    NL;
    return (0);
}