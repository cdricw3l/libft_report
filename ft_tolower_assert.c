/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:03:02 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 20:40:38 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

# define RANGE_START -500
# define RANGE_END 500

static void ft_tolower_test(int c, int *r)
{
        if(ft_tolower(c) != tolower(c))
        {
            printf("ft_tolower error with input %d ->"TEST_NOK"\n", c);
            *r = 0;
        }
}

int main(void)
{
    char *name_fonction = "ft_tolower";
    TEST_STAR(name_fonction);
    int start;
    int r;

    r = 1;
    start = RANGE_START;
    printf("Range test from %d to %d\n", RANGE_START, RANGE_END);
    while (start < RANGE_END && r != 1)
    {
            ft_tolower_test(start, &r);
            start++;
    }
    if (r)
        printf("result ->"TEST_OK"\n");
    else
        printf("result ->"TEST_NOK"\n");
    TEST_END(name_fonction);
    SEP;
    NL;
    return (0);
}