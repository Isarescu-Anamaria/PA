#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    int id;
    struct node_type* left;
    struct node_type* right;
}NodeT;

NodeT* createBinTree(FILE* f)
{
    int id;
    fscanf(f,"%d",&id);
    if(id == 0)
        return NULL;
    NodeT* pNew = (NodeT*)malloc(sizeof(NodeT));
    pNew->id = id;
    pNew->left = createBinTree(f);
    pNew->right = createBinTree(f);
    return pNew;
}
void preorder( NodeT *pNew )
{
    if ( pNew != NULL )
    {
        printf( "%d ", pNew->id );
        preorder( pNew->left);
        preorder( pNew->right);
    }
}

void postorder( NodeT *pNew )
{
    if ( pNew != NULL )
    {
        postorder( pNew->left);
        postorder( pNew->right);
        printf( "%d ", pNew->id );
    }
}

void inorder( NodeT *pNew )
{
    if ( pNew != NULL )
    {
        inorder( pNew->left);
        printf( "%d ", pNew->id );
        inorder( pNew->right);
    }
}

int leaf_node(NodeT *node)
{
    if(node == NULL)
        return 0;
    else
        if(node->left == NULL && node->right == NULL)
            return 1;
        else
            return leaf_node(node->left) + leaf_node(node->right);
}
int intern_nodes(NodeT* node)
{
    if(node == NULL)
        return 0;
    else
        if(node->left == NULL && node->right == NULL)
            return 0;
        else
            if(node->left != NULL || node->right != NULL)
                return 1 + intern_nodes(node->left) + intern_nodes(node->right);

}

int diameter(NodeT* tree)
{
    // base case where tree is empty
    if (tree == NULL)
        return 0;

    // get the height of left and right sub-trees
    int lheight = height(tree->left);
    int rheight = height(tree->right);

    // get the diameter of left and right sub-trees
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree +
    // 1

    return max(lheight + rheight + 1,max(ldiameter, rdiameter));
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else return b;
}

int height(NodeT* node)
{
    // base case tree is empty
    if (node == NULL)
        return 0;

    // If tree is not empty then height = 1 + max of left
    // height and right heights
    return 1 + max(height(node->left), height(node->right));
}

NodeT *search(NodeT *node, int key)
{

    if(node == NULL)
        return NULL;

    if(node->id == key)
        return node;
    if(key < node->id)
        search(node->left,key);
    if(key > node->id)
        search(node->right,key);
}

void mirror(NodeT* node)
{
    if (node == NULL)
        return;
    else {
        NodeT* temp;

        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);

        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int main()
{
    FILE *f = fopen("ArboreBinar.txt", "r");
    if (!f)
    {
        printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
        return -1;
    }
    NodeT* root = createBinTree(f);
    printf("Parcurgerea in preordine a arborelui este:\n");
    preorder(root);
    printf("\n");
    printf("Parcurgerea in postordine a arborelui este:\n");
    postorder(root);
    printf("\n");
    printf("Parcurgerea in inordine a arborelui este:\n");
    inorder(root);
    int nr = 0;
    nr = leaf_node(root);
    printf("\nNumarul de frunze este: %d",nr);
    nr = 0;
    nr = intern_nodes(root);
    printf("\nNumarul de noduri interne este: %d",nr);
    int key = 5;
   // root = search(root,key);
   // if(root == NULL)
     //   printf("\nnodul cu cheia %d nu se afla in arbore\n",key);
    //else printf("\nnodul cu cheia %d se afla in arbore\n",key);

    int i = height(root);
    printf("inaltimea arborelui este: %d\n", i);

    int d = diameter(root);
    printf("diametrul arborelui este: %d\n", d);

   // mirror(root);
   // printf("subarborele inversat este:");
    //preorder(root);

    fclose(f);
    return 0;
}
