/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:33:49 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 19:54:33 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int main(void)
{
    char *name_fonction = "ft_memset";
    TEST_STAR(name_fonction);
    char buffer[50];
    int test_nb;
    
    ft_bzero(buffer, 50);
    
    test_nb = 1;
    /* test 1 */
    ft_memset(buffer, 'a', 0);
    if(buffer[0] != 0)
        printf("Test %d:\t"TEST_NOK"\n", test_nb++);
    else
        printf("Test %d:\t"TEST_OK"\n", test_nb++);
    /* test 2 */
    ft_memset(buffer,'a', 10);
    if(buffer[9] == 'a' && buffer[10] == 0)
        printf("Test %d:\t"TEST_OK"\n", test_nb++);
    else
        printf("Test %d:\t"TEST_NOK"\n", test_nb++);
    /* test 3 */
    ft_memset(buffer, 'b', 50);
    if(buffer[49] == 'b')
        printf("Test %d:\t"TEST_OK"\n", test_nb++);
    else
        printf("Test %d:\t"TEST_NOK"\n", test_nb++);
    TEST_END(name_fonction);
    SEP;
    NL;
    return (0);
}