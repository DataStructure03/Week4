

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>
#include <iostream>

using namespace std;

typedef struct  s_BSTnode
{
    int     data;
    struct  s_BSTnode *left;
    struct  s_BSTnode *right;
}                t_BSTnode;

typedef struct s_BST
{
    struct s_BSTnode *root;
}              t_BST;

t_BST *createBST(void);
void deleteBST(t_BST *bst);
t_BSTnode *search_data(t_BST *bst, int data);
void    traverse(t_BST *b);
void    insert_data(t_BSTnode *root, int data);
int     remove_data(t_BSTnode *root, int data);
// void delete(t_BSTnode **T, int key);
        //data 없을 수 있으니까.