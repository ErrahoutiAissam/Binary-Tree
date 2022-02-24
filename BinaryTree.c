#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node *left;
    struct node *right;
}Tree;

Tree *NewTree (int value){

    Tree *N = (Tree*)malloc(sizeof(Tree));

    N->data = value;
    N->left = NULL;
    N->right = NULL;

    return N;  

}
 
 void Printtabs(int numtabs){
   int i;
   for( i = 0; i < numtabs; i++){
      printf("\t");
   }
 }

void PrintTreeRecursive(Tree *root, int levels){

    if(root == NULL){
      Printtabs(levels);
      printf("---empty---\n");
      return;
    }
    Printtabs(levels);
    printf("value=%d\n",root->data,levels);
    Printtabs(levels);
   
    printf("left\n");
   
    PrintTreeRecursive(root->left, levels+1);
    Printtabs(levels);  
   
    printf("right\n");
   
    PrintTreeRecursive(root->right, levels+1);
    Printtabs(levels);
    printf("done\n");

}

void PrintTree(Tree *root){
  PrintTreeRecursive(root,0);
}

void Prefixe(Tree *root){

  if(root == NULL)
    return ;
 
  printf("%d\n",root->data);
  Prefixe(root->left);
  Prefixe(root->right);
  
}

void infixe(Tree *root){
  
  infixe(root->left);
  if(root == NULL)
  return ;
  printf("%d",root->data);
  infixe(root->right);
  
}

void postfixe(Tree *root){

  postfixe(root->left);
  postfixe(root->right);
  if(root != NULL)
    printf("%d",root->data);
  
}

int getcount(Tree *root){

  int count = 0;
  while(root != NULL){
    Prefixe(root);
    count++;
  }
  return count;
}

// show leaves of a tree
void Afficherfeuille(Tree *root){

  if(root != NULL){
  if(root->left == NULL && root->left == NULL ){
    printf("%d",root->data);
  }
  else{
    Afficherfeuille(root->left);
    Afficherfeuille(root->right);
  }
}
}

int CountofLeaves(Tree *root){

    if(root != NULL){
      if(root->left == NULL && root->right == NULL )
      return 1;
      else 
    return CountofLeaves(root->left) + CountofLeaves(root->right);
    } else return 0;
}

void affichernoeudinterne(Tree *root){

    if(root != NULL){
     
      if(root->left != NULL || root->right != NULL ){
        printf("%d\n",root->data);
      }
      if(root->left != NULL);
        affichernoeudinterne(root->left);
      if(root->right != NULL)  
        affichernoeudinterne(root->right);

    }
}

int Cardinal(Tree *root){

  if(root != NULL ){
    return 1+Cardinal(root->left)+Cardinal(root->right);
  }
  return 0;
}

int Hauteur(Tree *root){

  if(root != NULL){
    return 1 + max(Hauteur(root->left),Hauteur(root->right));
  }
  return 0;
}

int max(int a ,int b){

  return (a>b)?a:b ;
}

void afficherniveau(Tree *root,int n){

  if(root != NULL){
    if(n == 0)
      printf("%d",root->data);
    else{
      afficherniveau(root->left,n-1);
      afficherniveau(root->right,n-1);
    }
  }
}

int nbrNoeudNiveau(Tree *root,int n){
  
  if(root != NULL){
    if(n == 0) return 1;
    else{
      return nbrNoeudNiveau(root->left,n-1) + nbrNoeudNiveau(root->right,n-1);
    }
    

  }
  return 0;
}

void afficherttNiv(Tree *root){
  
    int n = Hauteur(root);
    int i = 0;
    while(i<n){
      afficherniveau(root,i);
      printf("\n");
      i++;
    }
}

int main(){

    //create root
    Tree *root = NewTree(1);
     /* following is the tree after above statement
         1
        / \
      NULL NULL
    */
   root->left = NewTree(2);
   root->right = NewTree(3);
    /* 2 and 3 become left and right children of 1
            1
         /    \
        2      3
      /  \    /  \
   NULL NULL NULL NULL
    */
   root->left->right = NewTree(4);

   root->left->left = NewTree(6);

   root->right->left = NewTree(9);
    /*   
           1
         /    \
        25      3
      /  \    /  \
     6    4   9   empty              
   */

   //PrintTree(root);
   Prefixe(root);

   return 0;

}