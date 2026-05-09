/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:06:56 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 20:16:26 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strlen_test(int test_nb, char *s)
{
    size_t len1;
    size_t len2;
    
    printf("Test %d:\n", test_nb);
    len1 = strlen(s);
    len2 = ft_strlen(s);
    if(len1 == len2)
        printf("\tExpected measure: %ld\n\tEffective measure: %ld\n\tResult -> "TEST_OK "\n", len1, len2);
    else
        printf("\tExpected measure: %ld\n\tEffective measure: %ld\n\tResult -> "TEST_NOK "\n", len1, len2);
    assert(len1 == len2);
}

int main(void)
{
    char *test_name = "ft_strlen";
    int test_nb;
    TEST_STAR(test_name);
    test_nb = 1;
    /* test 1 */
    ft_strlen_test(test_nb++, "hello_berlin");
    /* test 2 */
    ft_strlen_test(test_nb++, "");
    /* test 3 */
    ft_strlen_test(test_nb++, "             4242");
    /* test 4 */
    ft_strlen_test(test_nb++, "4242             ");
    /* test 5 */
    char str[] = {-10,-10,-10,-10,-10,-10, '\0'};
    ft_strlen_test(test_nb++, str);
    TEST_END(test_name);
    SEP;
    NL;
    return (0);
}