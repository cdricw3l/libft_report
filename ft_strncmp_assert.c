/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:33:33 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 20:22:10 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void ft_strncmp_test(int test_nb, char *s1, char *s2, size_t n)
{
    int r1;
    int r2;
    char *str1;
    char *str2;

    str1 = ft_strdup(s1);
    if(!str1)
    {
        printf("Error allocation in %s ligne: %d\n", __func__, __LINE__);
        return ;
    }
    str2 = ft_strdup(s2);
    if(!str2)
    {
        free(str1);
        printf("Error allocation in %s line: %d\n", __func__, __LINE__);
        return ;
    }
    printf("Test %d:\n", test_nb);
    r1 = ft_strncmp(str1, str2, n);
    r2 = strncmp(str1, str2, n);
    if(r1 == r2)
        printf("\toriginal strncmp return: %d\n\tft_strncmp return: %d\n\ttest %d -> "TEST_OK"\n",r2,r1, test_nb);
    else
        printf("\toriginal strncmp return: %d\n\tft_strncmp return: %d\n\ttest %d -> "TEST_NOK"\n",r2,r1, test_nb);
    free(str1);
    free(str2);
}

int main(void)
{
    char *test_name = "ft_strncmp";
    TEST_STAR(test_name);
    int test_nb;

    test_nb = 1;
    /* test 1 */
    ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_berlin", strlen("hello_berlin"));
    /* test 2 */
    ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_berlin", 0);
     /* test 3 */
    ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_berlin", 1000);
     /* test 4 */
    ft_strncmp_test(test_nb++ ,"hello_berlin42", "hello_berlin", 1000);
     /* test 5 */
    ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_berlin42", 1000);
     /* test 6 */
    ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_berlin42", strlen("hello_berlin"));
     /* test 7 */
    ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_b", strlen("hello_berlin"));
     /* test 8 */
    ft_strncmp_test(test_nb++ ,"hello_berlin", "hello_b", strlen("hello_b"));
    /* test 9 */
    char str[] = {-10,-55,-128,-32, 55, 127, 255, '\0'};
    ft_strncmp_test(test_nb++ ,str, str, strlen(str));
    /* test 10 */
    ft_strncmp_test(test_nb++ , str, &str[2], -1);
    /* test 11 */
    ft_strncmp_test(test_nb++ ,str, "hello_berlin", 10);
    /* test 12 */
    ft_strncmp_test(test_nb++ ,"hello_berlin", str, 10);
    /* test 13 */
    ft_strncmp_test(test_nb++ ,"          ", "          42", strlen("          "));
    TEST_END(test_name);
    SEP;
    NL;
    return (0);
}