/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_assert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:35:56 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 11:35:29 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void ft_atoi_test(char *s, int test_nb)
{
    int original;
    int ft;

    original = atoi(s);
    ft = atoi(s);
    printf("Test %d:\n", test_nb);
    if(original == ft)
    {
        printf("\tinput:" C_PBG "%s"C_RESET"\n",s);
        printf("\toriginal atoi output:" C_BBG"%d"C_RESET"\n", original);
        printf("\tft_atoi output:" C_BBG"%d"C_RESET"\n\tresult -> " TEST_OK "\n", ft);
    }
    else
    {
        printf("\tinput:" C_PBG "%s"C_RESET"\n",s);
        printf("\toriginal atoi output:" C_BBG"%d"C_RESET"\n", original);
        printf("\tft_atoi output:" C_BBG"%d"C_RESET"\n\t result -> " TEST_NOK "\n", ft);
    }
    
}

int main(void)
{
    TEST_STAR("ft_atoi");
    int test_nb;

    test_nb = 1;
    /* test 1 */
    ft_atoi_test("      ++++---+++42", test_nb++);
    /* test 2 */
    ft_atoi_test("      +42", test_nb++);
    /* test 3 */
    ft_atoi_test("      42", test_nb++);
    /* test 4 */
    ft_atoi_test("+-0", test_nb++);
    /* test 5 */
    ft_atoi_test("+42", test_nb++);
    /* test 6 */
    ft_atoi_test("42", test_nb++);
    /* test 7 */
    ft_atoi_test("42", test_nb++);
    /* test 8 */
    ft_atoi_test("42              ", test_nb++);
    /* test 9 */
    ft_atoi_test("4 2              ", test_nb++);
    /* test 10 */
    ft_atoi_test("0001", test_nb++);
    /* test 11 */
    ft_atoi_test("2147483647", test_nb++);
    /* test 12 */
    ft_atoi_test("21474836470000", test_nb++);
    /* test 13 */
    ft_atoi_test("2147483648", test_nb++);
    /* test 14 */
    ft_atoi_test("21474836480000", test_nb++);
    /* test 15 */
    ft_atoi_test("-1", test_nb++);
    /* test 16 */
    ft_atoi_test("-+1", test_nb++);
    /* test 17 */
    ft_atoi_test("-+1", test_nb++);
    /* test 18 */
    ft_atoi_test("          aaaaa1", test_nb++);
    /* test 19 */
    ft_atoi_test("", test_nb++);
    /* test 20 */
    ft_atoi_test("+-10", test_nb++);
    char str1[] = { 50, -10, 0, 12};
    /* test 21 */
    ft_atoi_test(str1, test_nb++);
    char str2[] = {-45, 52,50,-10};
    /* test 22 */
    ft_atoi_test(str2, test_nb++);
    TEST_END("ft_atoi");
    SEP;
    NL;
    return (0);
}