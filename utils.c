/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:23:13 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 13:01:38 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void delete_split(void *ptr)
{
    char ***split;
    int i;

    split = (char ***)ptr;
    i = 0;
    while ((*split)[i])
    {
        free((*split)[i]);
        (*split)[i] = NULL;
        i++;
    }
    free((*split));
    (*split) = NULL;
}

void delete_tab(void *ptr)
{
    int ***data;
    int i;

    data = (int ***)ptr;
    i = 0;
    while ((*data)[i])
    {
        free((*data)[i]);
        (*data)[i] = NULL;
        i++;
    }
    free(*data);
    *data = NULL;
}

void delete_str(void *ptr)
{
    char *str;

    str = (char *)ptr;
    free(str);
    str = NULL;
}

int **create_arr(int nb, int term)
{
    int i;
    int j;
    int **tab;
    int *arr;

    tab = malloc(sizeof(int **) * (nb + 1));
    if (!tab)
        return (NULL);
    i = 0;
    assert(nb == 5);
    while (i < nb)
    {
        arr = malloc(sizeof(int *) * term);
        if (!arr)
        {
            j = 0;
            while (j < i)
            {
                free(tab[j]);
                tab[j] = NULL;
                j++;
            }
            return (NULL);
        }
        j = 0;
        while (j < term)
        {
            arr[j] = j;
            j++;
        }
        tab[i] = arr;
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

void clear_list(void *ptr)
{
    return ;
}

t_list **create_lst(size_t size)
{
    size_t i;
    t_list **list;
    t_list *node;


    i = 0;
    list = malloc(sizeof(t_list *));
    if (!list)
        return (NULL);
    *list = NULL;
    while (i < size)
    {
        node = ft_lstnew(NULL);
        if(!node)
        {
            ft_lstclear(list, clear_list);
            free(list);
            return (NULL);
        }
        ft_lstadd_back(list, node);
        i++;   
    }
    if (i != size)
    {
        printf("Size of the list is node as expected in %s\n", __func__);
        ft_lstclear(list, clear_list);
        return (NULL);
    }
    return (list);
    
}

void delete_lst(t_list *list)
{
    t_list *tmp;

    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void string_capitalise(void *ptr)
{
    char *str;
    int i;

    str = (char *)ptr;
    i = 0;
    while (str[i])
    {
        if(str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
        i++;
    }
}