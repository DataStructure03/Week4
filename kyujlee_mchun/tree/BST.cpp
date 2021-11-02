#include "BST.hpp"
#include <cmath>

t_BST *createBST(void)
{
    t_BST *ret;
    ret = (t_BST *)malloc(sizeof(t_BST));
    ret->root = (t_BSTnode *)malloc(sizeof(t_BSTnode));
}

static void deleteBSTnode(t_BSTnode *root)
{
    if (!root)
        return ;
    deleteBSTnode(root->left);
    deleteBSTnode(root->right);
    free(root);
}

void deleteBST(t_BST *bst)
{
    deleteBSTnode(bst->root);
    free(bst);
}

t_BSTnode *_search_data(t_BSTnode *root, int data)
{
    if (!root)
        return (NULL);
    
    if (root->data > data)
        _search_data(root->left, data);
    else if (root->data < data)
        _search_data(root->right, data);
    else
        return (root);
}

t_BSTnode *search_data(t_BST *bst, int data)
{
    t_BSTnode *tmp = _search_data(bst->root, data);
    return tmp;
}


void getData(t_BSTnode *parent, queue<int> q){
    q.push(parent->data);
    getData(parent->left, q);
    getData(parent->right, q);
}

void    traverse(t_BST *b)
{
    queue<int> q;
    
    getData(b->root, q);
    int i = -1;
    while (++i < q.size()){
      cout << q.front() << " ";
      q.pop();
    }
    cout << endl;
    return ;
}

//
// void    traverse(t_BST *b)
// {
//     t_BSTnode   *node;
//     int     i  = 1;

//     if (!b->root)
//         return ;

//     queue<t_BSTnode *> q;
//     q.push(b->root);
//     while (!q.empty())
//     {
//         node = q.front(); q.pop();

//     }

//     return ;    
// }


static void _insert_data(t_BSTnode *root, t_BSTnode *tmpNode)
{
    if (root->data == tmpNode->data){
        cout << "ERROR : overlap data " << endl;
        return ;
    }
    if (root->left == NULL && root->right == NULL){
        if (root->data < tmpNode->data)
            root->right = tmpNode;
        else
            root->left = tmpNode;  
        return ;
    }

    if (root->data > tmpNode->data)
      _insert_data(root->left, tmpNode);
    else
        _insert_data(root->right, tmpNode);
}

void    insert_data(t_BST *b, int data)
{
    t_BSTnode *tmpNode;
    
    tmpNode = (t_BSTnode *)malloc(sizeof(t_BSTnode));
    tmpNode->data = data;
    tmpNode->left = NULL;
    tmpNode->right = NULL;
    
    _insert_data(b->root, tmpNode);
}

t_BSTnode *remove_data(t_BSTnode *root, int data)
{
    BSTnode *temp;
    if (root == NULL)
        return ;
    else if (data < root->data)
        root->left = remove_data(root->left, data);     //remove_data에서 연결해줘야 하는 값을 리턴.
    else if (data > root->data)
        root->right = remove_data(root->right, data);       //
    else    //data == root->data (항목을 찾았을 때)
    {
        if (root->left && root->right){ //자식이 둘
            temp = findMax(root->left); //root->left 에서 가장 큰 data를 찾아줌.
            root->data = temp->data;
            root->left = remove_data(root->left, root->data);
        }  
        else    //자식이 하나일 때 
        {
            temp = root;
            if (root->left == NULL)
                root = root->right;
            if (root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
    return (root);
}

  

// void delete(t_BSTnode **T, int key){
//   t_BSTnode **tmp;
  
//   if (*T == NULL)
//     printf ("ERROR");
//   else if(*T->data > key)
//     Delete(*T->left , key);
//   else if(*T->data < key)
//     Delete(*T->right , key);
//   else if (*T->data == key){
//     if ((*T->left == NULL) && (*T->right == NULL)){
//       tmp = T;
//       *T = NULL;
//       free(*tmp);
//     }
//     else if (*T->left == NULL){
//       tmp = T;
//       *T = *T->right;
//       free(*tmp);
//     }
//     else if (*T->right == NULL){
//       tmp = T;
//       *T = *T->left;
//       free(*tmp);
//     }
//     else
//       recursive(*T->right, *T->data);
// }

