/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:20:06 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 20:29:21 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strrchr_test(int test_nb, char *s, int c)
{
    char *p1;
    char *p2;
    printf("Test %d:\n", test_nb);
    p1 = strrchr(s,c);
    p2 = ft_strrchr(s,c);
    if(p1 == p2)
        printf("\toriginal strrchr return -> %p\n\tft_strrchr return -> %p\n\tresult -> " TEST_OK "\n", p1, p2);
    else
        printf("\toriginal strrchr return -> %p\n\tft_strrchr return -> %p\n\tresult -> " TEST_NOK "\n", p1, p2);
    
}


int main(void)
{
    char *test_name = "ft_strrchr";
    TEST_STAR(test_name);
    char *str;
    int test_nb;

    test_nb = 1;
    str = ft_strdup("hello_berlin");
    if (!str)
    {
        printf("Error string duplication in %s line:%d\n", __func__, __LINE__ - 3);
        return (1);
    }
    /* test 1 */
    ft_strrchr_test(test_nb++, str, 'x');
    /* test 2 */
    ft_strrchr_test(test_nb++, str, 'h');
    /* test 3 */
    ft_strrchr_test(test_nb++, str, 'l');
    /* test 4 */
    ft_strrchr_test(test_nb++, str, 'b');
    /* test 5 */
    ft_strrchr_test(test_nb++, str, '\0');
    free(str);
    str = ft_strdup("");
    if (!str)
    {
        printf("Error string duplication in %s line:%d\n", __func__, __LINE__ - 3);
        return (1);
    }
    /* test 6 */
    ft_strrchr_test(test_nb++, str, '\0');
    /* test 7 */
    ft_strrchr_test(test_nb++, str, 'A');
    free(str);
    
    char s0[] = {-10, -12, -127, 32, 97, 98, -127, '\0'};
    /* test 8 */
    ft_strrchr_test(test_nb++, s0, -127);
    char s1[] = {-10, -12, -127, 32, 97, 98,'\0'};
    /* test 9 */
    ft_strrchr_test(test_nb++, s1, INT_MAX);
    NL;
    TEST_END(test_name);
    SEP;
    return (0);
}