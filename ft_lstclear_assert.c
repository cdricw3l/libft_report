/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_assert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:20:44 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 15:07:32 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

#define SIZE_LST 10

static t_list **create_split_lst(char *content, char sep, void (*f)(void *ptr))
{
    int i;
    char **split;
    t_list *new_node;
    t_list **lst;

    i = 0;
    split = ft_split(content, sep);
    if(!split)
    {
        printf("Error split creation in %s line:%d\n", __func__, __LINE__ - 3);
        return (NULL);
    }
    lst = malloc(sizeof(t_list *));
    if(!lst)
    {
        printf("Error malloc in %s line:%d\n", __func__, __LINE__ - 3);
        delete_split(split);
        return (NULL);
    }
    *lst = NULL;
    while (split[i])
    {
        new_node = ft_lstnew(ft_strdup(split[i]));
        if (i = 3)
        {
            free(new_node->content);
            free(new_node);
            new_node = NULL;
        }
        if(!new_node)
        {
            ft_lstclear(lst, f);
            free(lst);
            lst = NULL;
            delete_split(split);
            return (NULL);
        }
        ft_lstadd_back(lst, new_node);
        i++;
    }
    delete_split(&split);
    return (lst);
}

void ft_lstclear_test(int test_number, t_list **list, void (*f)(void *ptr))
{   
    
    pid_t   frk;
    int stat;
    
    printf("Test %d:\n", test_number);
    if (!list || !f)
    {
        frk = fork();
        if(frk < 0)
        {
            printf("Error fork in %s line: %d", __func__, __LINE__);
            return ;
        }
        if (frk == 0)
        {
            ft_lstclear(list, f);
            exit(0);    
        }
        else
        {
            waitpid(frk, &stat, 0);
            if(WIFEXITED(stat))
                printf("\tCheck null protection -> "TEST_OK"\n");
            else
                printf("\tCheck null protection -> "TEST_NOK"\n");
            if (list)
                delete_lst(list, delete_str);
            return ;
        }
    }
    
    else
    {
        ft_lstclear(list,f);
        if(*list == NULL)
            printf("\t*list == NULL but check valgrind for each content"TEST_OK"\n");
        else
        {
            delete_lst(list, delete_str);
            printf("\t*list != NULL"TEST_NOK"\n");
        }
    }
}


int main(void)
{
    char *test_name = "ft_lstclear";
    TEST_STAR(test_name);
    int test_nb;
    t_list **list;

    test_nb = 1;
    
    /* test 1 */
    list = create_split_lst("hello_berlin_comment_ca_va_?", '-', delete_str);
    if(!list)
    {
        printf("Error list creation in %s line %d", __func__, __LINE__ - 3);
        return (1) ;
    }
    ft_lstclear_test(test_nb++, list, delete_str);
    free(list);
    
    /* test 2 */
    list = create_split_lst("hello_berlin_comment_ca_va_?", '-', delete_str);
    if(!list)
    {
        printf("Error list creation in %s line %d", __func__, __LINE__ - 3);
        return (1) ;
    }
    ft_lstclear_test(test_nb++, list, NULL);
    
    // /* test 3 */
    // ft_lstclear_test(test_nb++, NULL, NULL);


    TEST_END(test_name);
    SEP;
    NL;
    return (0);
}