#include <stdio.h>
#include <stdlib.h>


typedef int KeyType;
typedef struct node {
    KeyType key;
    struct node *left;
    struct node *right;
    struct node *parent;
} NodeT;

NodeT* root;

NodeT* insertNode( NodeT* root, int key )
{
   if(root == NULL)
   {
       NodeT* p = (NodeT*)malloc(sizeof(NodeT));
       p->key = key;
       p->left = NULL;
       p->right = NULL;
       return p;
   }
   if(root->key == key)
    return NULL;
   if(root != NULL)
   {
       if(key <= root->key)
        root->left = insertNode(root->left, key);
       else
        root->right = insertNode(root->right, key);
    root->parent = root;
   }
   return root;
}

NodeT* searchKey( NodeT* root, int key )
{
    if (root == NULL || root->key == key)
     return root;
    if (root->key < key)
     return searchKey(root->right, key);
    else
     return searchKey(root->left, key);
}

void inOrder( NodeT* p)
{
    if(p != NULL)
    {
        inOrder(p->left);
        printf("%d ",p->key);
        inOrder(p->right);
    }
}

void preOrder( NodeT *p)
{
    if(p != NULL)
    {
        printf("%d ",p->key);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void postOrder( NodeT *p)
{
    if(p != NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        printf("%d ",p->key);
    }
}
NodeT* findMin(NodeT* node)
{
    if(node == NULL)
        return NULL;
    NodeT *p =NULL;
    p = node;
    while(p->left != NULL)
        p = p->left;
    return p;

}

NodeT* findMax(NodeT* node)
{
    if(node == NULL)
        return NULL;
    NodeT *p = node;
    while(p->right != NULL)
        p = p->right;
    return p;
}

NodeT* succesor(NodeT *node)
{
    if(node->right != NULL)
        return findMin(node->right);
    else
    {
        NodeT* p = node->parent;
        while (p != NULL && node == p->right) {
        node = p;
        p = p->parent;
    }
    return p;
    }
}

NodeT* predecesor(NodeT *node)
{
    if(node->left != NULL)
        return findMax(node->left);
    else
    {
        NodeT* p = node->parent;
        while (p != NULL && node == p->left) {
        node = p;
        p = p->parent;
    }
    return p;
    }
}

NodeT* delNode(NodeT* root, int key)
{
    NodeT *p;
/* arbore vid */
    if (root == NULL) return root;
/* Daca cheia key este mai mica decat cheia radacinii, cautarea nodului key
se face in subarborele stang */
    if (key < root->key)
        root->left = delNode(root->left, key);
/* Daca cheia key este mai mare decat cheia radacinii, cautarea nodului key
se face in subarborele drept */
    else if (key > root->key)
        root->right = delNode(root->right, key);
/* cheia radacinii este egala cu key, acesta este nodul ce trebuie sters */
    else
    {
/* Nodul are un singur fiu */
        if (root->left == NULL)
        {
            p = root->right;
            free(root);
            return p;
        }
    else if (root->right == NULL)
        {
            p = root->left;
            free(root);
            return p;
        }
/* Nodul are 2 fii */
     //   p = findMin(root->right);
      //  root->key = p->key;
       // root->right = delNode(root->right, p->key);
    }
    return root;
}

int main()
{

    root = insertNode(root, 15);
    insertNode(root, 6);
    insertNode(root, 56);
    insertNode(root, 20);
    insertNode(root, 17);
    printf("inOrder= ");
    inOrder(root);
    printf("\npostOrder= ");
    postOrder(root);
    printf("\npreOrder= ");
    preOrder(root);
    int k = 20;
    root = searchKey(root,k);
    if(root == NULL)
        printf("\nnodul cu cheia %d nu se afla in arbore",k);
    else printf("\nnodul cu cheia %d se afla in arbore",k);
    root = findMax(root);
    if(root == NULL)
        printf("\narborele nu are noduri");
    else printf("\nnodul cu val max este: %d",root->key);
    root = findMin(root);
    if(root == NULL)
        printf("\narborele nu are noduri");
    else printf("\nnodul cu val min este: %d",root->key);

    //root = succesor(root);
    //printf("\nsuccesorul este: %d",root->key);
     printf("\narborele dupa stergere este: \n");
     delNode(root,18);
     preOrder(root);
    return 0;
}
