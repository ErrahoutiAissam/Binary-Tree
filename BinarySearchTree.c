#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

    int data;
    struct node* left;
    struct node* right;
}BstNode;

BstNode *GetNewNode(int data){
    
    BstNode *NewNode = (BstNode*)malloc(sizeof(BstNode));
    NewNode->data = data;
    NewNode->left = NewNode->right = NULL;
    return NewNode;
}

void InsertNode(BstNode **root,int data){

    if((*root) == NULL){
        (*root) = GetNewNode(data);
    }
    else if(data <= (*root)->data ){
         InsertNode(&(*root)->left,data);
    }else InsertNode(&(*root)->right,data);
}

bool SearchTree(BstNode *root,int data){
    if(root == NULL)
    return false;
    else if (root->data == data ) return true;
    else if (data <= root->data) return SearchTree(root->left,data);
    else return SearchTree(root->right,data);
}
BstNode* FindMin(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

BstNode *DeleteNode(BstNode *root,int data){
        if(root == NULL)
        return root;
        else if (data < root->data)
       root->left  = DeleteNode(root->left,data);
        else if(data > root->data)
        root->right = DeleteNode(root->right,data);
        
        // once  the node is found ... now the deletion comes
        else{

            // case 1 : node without a child
            if(root->left == NULL && root->right == NULL){
                free(root);
                root = NULL;
            }
            // case 2 : only 1 child
            else if(root->left == NULL){
                BstNode *tmp = root;
                root = root->right;
                free(tmp);
            }
            else if (root->right == NULL){
                BstNode *tmp = root;
                root = root->left;
                free(tmp);
            }
            // case 3 : 2 children
            else{
                BstNode *tmp = FindMin(root);
                root->data = tmp->data;
                root->right = DeleteNode(root->right,tmp->data);
            }
        }
        return root;
}

//Function to visit nodes in Inorder
void Inorder(BstNode *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}


int main(){
    BstNode *root = NULL;
    int nbr;
    InsertNode(&root,5);
    InsertNode(&root,3);
    InsertNode(&root,1);
    InsertNode(&root,91);
    /* printf("entrer un nombre \n");
    scanf("%d",&nbr);
    if(SearchTree(root,nbr) == true)
    printf(" your number is found\n");
    else printf("Not Found :/ \n");*/
    DeleteNode(root,91);
    Inorder(root);

    return 0;
}