#include "assertion.h"

void ft_lstnew_test(int test_nb, void *content)
{
    t_list *node;
    t_test *test_node;

    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #endif
    #ifdef  __linux__
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif

    printf("Test %d:\n", test_nb++);
    node = ft_lstnew(content);
    if(!node)
    {
        printf("Error allocation in %s line: %d\n", __func__, __LINE__ - 2);
        return ;
    }
    /* checking of the node content */
    if(node->content == content)
        printf("\tcontent compare ->"TEST_OK"\n");
    else
        printf("\tcontent compare ->"TEST_NOK"\n");
    
    /* compare the size of the structure with the size of t_test structure */
    test_node = malloc(sizeof(t_test));
    if (!test_node)
    {
        printf("Error allocation in %s line:%d\n", __func__, __LINE__);
        return ;
    }
    if (f(node) == f(test_node))
        printf("\tmemory size of node ->"TEST_OK"\n");
    else
        printf("\tmemory size of node ->"TEST_NOK"\n");
    free(test_node);
    /* checking if the next node is NULL */
    if (node->next == NULL)
        printf("\tnext pointer check ->"TEST_OK"\n");
    else
        printf("\tnext pointer check ->"TEST_NOK"\n");

    free(node);
}

int main(void)
{
    char *test_name = "ft_lst_new";
    int test_nb;
    TEST_STAR(test_name);
    char *str;
    int r;
    
    test_nb  = 1;
    /* test 1 */
    str = strdup("hello_berlin");
    ft_lstnew_test(test_nb++,str);
    free(str);
    
    /* test 2 */
    r = 10;
    ft_lstnew_test(test_nb++,&r);
    
    /* test 2 */
    ft_lstnew_test(test_nb++, NULL);
    TEST_END(test_name);
    SEP;
    NL;
    return (0);
}