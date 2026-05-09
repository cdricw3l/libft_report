/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:15:55 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 18:49:05 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void *get_string_capitalise(void *ptr)
{
    char *str;
    int i;

    str = strdup((char *)ptr);
    if(!str)
        printf("Error strdup in %s\n",__func__);
    
    i = 0;
    while (str[i])
    {
        if(str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}

void ft_lstmap_test(int test_number, t_list *liste, void *(*f)(void *), void (*del)(void *))
{
    pid_t frk;
    t_list *tmp;
    t_list *new_list;
    char *ptr;
    int stat;
    
    printf("Test %d:\n", test_number);
    if (!liste || !f || !del)
    {
        frk = fork();
        if( frk < 0)
        {
            printf("Error fork in %s", __func__);
            return ;
        }
        if(frk == 0)
        {
            new_list = ft_lstmap(liste, f, del);
            /*check the null protection of the delete fonction*/
            if (liste && f && !del && !new_list)
                printf("\tCheck null protection -> "TEST_NOK"\n");
            else
                printf("\tCheck null protection -> "TEST_OK"\n");
            
            while (new_list)
            {
                tmp = new_list;
                new_list = new_list->next;
                free(tmp->content);
                free(tmp);
            }
            
            exit(0);
        }
        else
        {
            waitpid(frk, &stat, 0);
            if(stat == 0)
                printf("\tCheck null protection -> "TEST_OK"\n");
            else
                printf("\tCheck null protection -> "TEST_NOK"\n");
            ft_lstclear(&liste, delete_str);
            return ;
        }
    }
    else
    {
        new_list =  ft_lstmap(liste, f, del);
        if (!new_list)
        {
            printf("Error list creation in %s line:%d ->"TEST_NOK"\n", __func__, __LINE__);
            return ;
        }
        tmp = new_list;
        while (tmp)
        {
            ptr = (char *)tmp->content;
            while (*ptr)
            {
                if(*ptr >= 65 && *ptr <= 90)
                    ptr++;
                else
                {
                    printf("\tresult check of the iteration ->"TEST_NOK"\n");
                    ft_lstclear(&new_list,delete_str);
                    return;
                }
            }
            tmp = tmp->next;

        }
        ft_lstclear(&new_list, delete_str);
        free(new_list);
        new_list = NULL;
        printf("\tresult check of the iteration ->"TEST_OK"\n");
    }


}

int main(void)
{
    char *test_name = "ft_lstmap";
    TEST_STAR(test_name);

    char **split;
    t_list **list;
    t_list *node;
    int i;
    int test_number;
    
    list = malloc(sizeof(t_list * ));
    if(!list)
    {
        printf("Error list initialisation in %s\n",__func__);
        return(1);
    }
    split = ft_split("hello_berlin_how_are_u", '_');
    if(!split)
    {
        printf("Error split in %s\n", __func__);
        return(1);
    }
    i = 0;
    *list = NULL;
    while (split[i])
    {
        node = ft_lstnew(ft_strdup(split[i]));
        if(!node)
        {
            ft_lstclear(list, delete_str);
            delete_split(&split);
            free(list);
            return(1);
        }
        ft_lstadd_back(list, node);
        i++;
    }
    delete_split(&split);
    test_number = 1;
    /* test 1 */
    //ft_lstmap_test(test_number++, *list, get_string_capitalise, delete_str);
    /* test 2 */
    //ft_lstmap_test(test_number++, NULL, get_string_capitalise, delete_str);
    // /* test 3 */
    //ft_lstmap_test(test_number++, NULL, get_string_capitalise, NULL);
    // /* test 4 */
    ft_lstmap_test(test_number++, *list, get_string_capitalise,  NULL);
    // /* test 5 */
    // ft_lstmap_test(test_number++, *list, NULL,  delete_str);
    // /* test 6 */
    // ft_lstmap_test(test_number++, NULL, NULL, NULL);
    ft_lstclear(list, delete_str);
    free(list);
    TEST_END(test_name);
    SEP;
    NL;
    return(0);
}