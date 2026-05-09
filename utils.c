/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:23:13 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/09 15:16:30 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"


/**
 * @brief clean un atbleau de string allouer va la fonction ft_split.
 * @param ptr Un pointeur char ** vers un tableau de string
 * @return void.
 */
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
    (void)ptr;
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
    return (list);
}

void delete_lst(t_list **list, void (*f)(void *ptr))
{
    t_list **tmp_lst;
    t_list *tmp_node;

    tmp_lst = list;
    while (*tmp_lst)
    {
        tmp_node = *tmp_lst;
        *tmp_lst = (*tmp_lst)->next;
        if(f)
            f(tmp_node->content);
        free(tmp_node);
        tmp_node = NULL;
    }
    free(list);
    list = NULL;
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