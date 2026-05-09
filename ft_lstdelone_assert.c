#include "assertion.h"

void ft_lstdelone_test(int test_nb, t_list **node, void ***content , void (*f)(void *ptr))
{
    pid_t frk;
    int stat;

    printf("Test %d:\n", test_nb);
    if (!node || !f)
    {
        /*
            nul protection check
        */
        frk = fork();
        if( frk < 0)
        {
            printf("Error fork in %s line: %d\n", __func__, __LINE__);
            return ;
        }
        if(frk == 0)
        {
            ft_lstdelone(*node, f);
            exit(0);
        }
        else
        {
            waitpid(frk, &stat, 0);
            if(WIFEXITED(stat) == 0)
                printf("\tCheck null protection -> "TEST_OK"\n");
            else
                printf("\tCheck null protection -> "TEST_NOK"\n");
            return ;
        }
    }
    else
    {
        (void)content;
        printf("node %p\n",(*node)->content);
        ft_lstdelone(*node, f);
        printf("node %p\n",(*node)->content);

        // assert(!(*node)->content);
        // if (!*content)
        //     printf("\tDelete content node"TEST_OK"\n");
        // else
        //     printf("\tDelete content node"TEST_NOK"\n");
    }
    
}

int main(void)
{
    char *test_name = "ft_lstdelone";
    TEST_STAR(test_name);
    t_list *node;
    char **split;
    void ***content;
    int **data;
    int test_nb;

    //Test 1
    test_nb = 1;
    split = ft_split("hello_berlin_comment_ca_va?", '_');
    if(!split)
    {
        printf("Error split creation in %s line:%d\n", __func__, __LINE__ - 3);
        return(1);
    }
    node = malloc(sizeof(t_list));
    if (!node)
    {
        printf("Error node creation in %s line:%d\n", __func__, __LINE__ - 3);
        delete_split(&split);
        return (1);
    }
    node->content = &split;
    node->next = NULL;
    content = (void ***)&split;
    printf("node %p\n", node);
    ft_lstdelone_test(test_nb++, &node, content, delete_split);
    
    //Test 2
    data = create_arr(5, 5);
    if (!data)
    {
        printf("Error split creation in ft_lstdelone_assert\n");
        return(2);
    }
    node = malloc(sizeof(t_list));
    if (!node)
    {
        printf("Error node creation in %s line:%d\n", __func__, __LINE__ - 3);
        return (1);
    }
    node->content = &data;
    node->next = NULL;
    ft_lstdelone_test(test_nb++, node, (void **)data, delete_tab);
    
    //Test 3
    ft_lstdelone_test(test_nb++, NULL, NULL, NULL);

    TEST_END(test_name);
    SEP;
    NL;
    return (0);
}