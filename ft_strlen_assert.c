/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:06:56 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 11:23:08 by cebouhad         ###   ########.fr       */
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
        printf("\texpected measure: %ld\n\treal measure: %ld\n\tresult -> "TEST_OK "\n", len1, len2);
    else
        printf("\texpected measure: %ld\n\treal measure: %ld\n\tresult -> "TEST_NOK "\n", len1, len2);
    assert(len1 == len2);
}

int main(void)
{
    char *test_name = "ft_strlen";
    int test_nb;
    TEST_STAR(test_name);
    test_nb = 1;
    //TEST 1
    ft_strlen_test(test_nb++, "hello_berlin");
    //TEST 2
    ft_strlen_test(test_nb++, "");
    //TEST 3
    ft_strlen_test(test_nb++, "             4242");
    //TEST 4
    ft_strlen_test(test_nb++, "4242             ");
    //TEST 5
    char str[] = {-10,-10,-10,-10,-10,-10, '\0'};
    ft_strlen_test(test_nb++, str);
    NL;
    TEST_END(test_name);
    SEP;
    NL;
}