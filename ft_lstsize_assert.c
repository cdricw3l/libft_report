/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:36:49 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 19:18:30 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_lstsize_test(int test_number, size_t size)
{
    t_list **list;
    int r;

    printf("Test %d:\n", test_number);
    list = create_lst(size);
    if (!list && size > 0)
    {
        printf("Error list creation in %s\n", __func__ );
        return ;
    }    
    r = ft_lstsize(*list);
    if (r == (int)size)
        printf("\texpected size: %ld\n\tsize return: %d\n\tresult ->"TEST_OK"\n", size, r);
    else
        printf("\texpected size: %ld\n\tsize return: %d\n\tresult ->"TEST_NOK"\n", size, r);
    delete_lst(list, NULL);
}

int main(void)
{
    char *test_name = "ft_lstsize";
    int test_number;
    TEST_STAR(test_name);

    test_number = 1;

    /* test 1 */
    ft_lstsize_test(test_number++, 10);
    
    /* test 2 */
    ft_lstsize_test(test_number++, 1);

    /* test 3 */
    ft_lstsize_test(test_number++, 0);

    TEST_END(test_name);
    SEP;
    NL;
    return (0);
}