/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_assert.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:24:03 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 14:27:43 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_lstadd_front_test(int test_number,t_list **liste, t_list *node)
{
    pid_t frk;
    int stat;
    
    printf("Test %d:\n", test_number);
    if (!liste || !node)
    {
        /* 
            fork for testing the null pointer protection of the fonction. If the childrend programme crash and the status is different than 0, 
            the function is nodt protected
        */
        frk = fork();
        if( frk < 0)
        {
            printf("Error fork in %s", __func__);
            return ;
        }
        if(frk == 0)
        {
            ft_lstadd_front(liste,node);
            exit(0);
        }
        else
        {
            waitpid(frk, &stat, 0);
            if(WIFEXITED(stat))
            {
                printf("\tft_lstadd_front ->"TEST_OK"\n");
                printf("\tCheck null protection -> "TEST_OK"\n");
            }
            else
            {
                printf("\tCheck null protection -> "TEST_NOK"\n");
                printf("\tft_lstadd_front ->"TEST_NOK"\n");
            }
            return ;
        }
    }
    else
    {
        ft_lstadd_front(liste, node);
        if (*liste == node)
            printf("\tlst add front ->"TEST_OK"\n");
        else
            printf("\tlst add front ->"TEST_NOK"\n");
    }

}

int main(void)
{
    char *test_name = "ft_lstadd_front";
    TEST_STAR(test_name);
    int test_number;
    t_list **list;
    t_list *node1;
    t_list *node2;
    test_number = 1;

    list = create_lst(0);
    if(!list)
    {
        printf("Error creation list in %s line %d\n",__func__, __LINE__);
        return (1);
    }
    assert(!ft_lstsize(*list));
    /* test 1 */
    node1 = ft_lstnew(NULL);
    if(!node1)
    {
        printf("Error creation node in %s line:%d\n", __func__, __LINE__);
        delete_lst(list);
        return (1);
    }
    ft_lstadd_front_test(test_number++, list, node1);
    assert(ft_lstsize(*list) == 1);
    /* test 2 */
    node2 = ft_lstnew(NULL);
    if(!node2)
    {
        printf("Error creation node in %s line:%d\n", __func__, __LINE__);
        delete_lst(list);
        return  (1);
    }
    ft_lstadd_front_test(test_number++, list, node2);
    /* test 3 */
    ft_lstadd_front_test(test_number++, list, NULL);
    /* test 3 */
    ft_lstadd_front_test(test_number++, NULL, NULL);

    delete_lst(list);
    SEP;
    NL;
    TEST_END(test_name);
    return(0);
}