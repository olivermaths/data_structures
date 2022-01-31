#include <stdlib.h>
#include <stdio.h>
typedef struct bst bst;

typedef struct bst
{
    int value;
    struct bst *left;
    struct bst *right;
} bst;

bst *create(int element)
{
    bst *bst = malloc(sizeof(bst));
    bst->value = element;
    bst->left = NULL;
    bst->right = NULL;
    return bst;
}

int insert(bst **bst, int element)
{

    if ((*bst) == NULL)
    {
        (*bst) = create(element);
        return 1;
    }
    if ((*bst)->value == element)
    {
        return 0;
    }
    if (element < (*bst)->value)
    {
        return insert(&(*bst)->left, element);
    }
    if (element > (*bst)->value)
    {
        return insert(&(*bst)->right, element);
    }
}

int findNumber(bst *bst, int element)
{
    if (bst == NULL)
    {
        return 0;
    }
    else
    {
        if (element == bst->value)
        {
            return 1;
        }
        if (element < bst->value)
        {
            return findNumber(bst->left, element);
        }
        if (element > bst->value)
        {
            return findNumber(bst->right, element);
        }
    }
}

void printInOrder(bst *bst)
{
    int counting = 1;
    if (bst == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("the element is: %d\n", bst->value);
        printInOrder(bst->left);
        printInOrder(bst->right);
    }
}

int main()
{
    bst *bst = create(9);
    insert(&bst, 20);
    insert(&bst, 19);
    insert(&bst, 22);
    insert(&bst, 30);
    printf("the number %d is on the tree: %d\n", 19, findNumber(bst, 19));
    printf("the number %d is on the tree: %d\n", 9, findNumber(bst, 9));
    printf("the number %d is on the tree: %d\n", 8, findNumber(bst, 8));
    printf("the number %d is on the tree: %d\n", 20, findNumber(bst, 20));
    printf("the number %d is on the tree: %d\n", 30, findNumber(bst, 30));
}