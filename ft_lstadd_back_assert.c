/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_assert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:24:03 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 13:03:31 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_lstadd_back_test(int test_number,t_list **liste, t_list *node)
{
    pid_t frk;
    t_list *tmp;
    int stat;
    
    printf("Test %d:\n", test_number);
    if (!liste)
    {
        /* 
            fork for testing the null pointer protection of the fonction. If the childrend programme crash and the status is different than 0, 
            the function is nodt protected
        */
        frk = fork();
        if( frk < 0)
        {
            printf("Error fork in %s line:%d", __func__, __LINE__ - 3);
            return ;
        }
        if(frk == 0)
        {
            ft_lstadd_back(liste, node);
            exit(0);
        }
        else
        {
            waitpid(frk, &stat, 0);
            if(stat == 0)
            {
                printf("\tlst add back ->"TEST_OK"\n");
                printf("\tCheck null protection -> "TEST_OK"\n");
            }
            else
            {
                printf("\tCheck null protection -> "TEST_NOK"\n");
                printf("\tlst add back ->"TEST_NOK"\n");
            }
            return ;
        }
    }
    else
    {
        ft_lstadd_back(&liste, node);
        tmp = liste;
        while (tmp->next)
            tmp = tmp->next;
        if (tmp == node)
            printf("\tlst add back ->"TEST_OK"\n");
        else
            printf("\tlst add back ->"TEST_NOK"\n");
    }

}

int main(void)
{
    char *test_name = "lstadd_back";
    TEST_STAR(test_name);
    int test_number;
    t_list **list;
    t_list *node;
    test_number = 1;

    list = create_lst(5, NULL);
    if(!list)
    {
        printf("Error creation list in %s line %d\n",__func__, __LINE__);
        return (1);
    }
    node = ft_lstnew(NULL);
    if(!node)
    {
        printf("Error creation node in %s line:%d\n", __func__, __LINE__);
        delete_lst(list);
        return  (1);
    }
    /* test 1 */
    ft_lstadd_back_test(test_number++, list, node);
    /* test 2 */
    ft_lstadd_back_test(test_number++, NULL, node);
    delete_lst(list);
    TEST_END(test_name);
    SEP;
    NL;
    return (0);
}