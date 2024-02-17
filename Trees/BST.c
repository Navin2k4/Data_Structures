 #include<stdio.h>
 #include<stdlib.h>

 struct node{
    int data;
    struct node *left,*right;
 };

struct node *create(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *findmin(struct node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

struct node *insert(struct node *root,int value){
    if(root==NULL) {  return create(value);  }
    else if (value < root->data) {  root->left = insert(root->left,value); }
    else if (value > root->data) {  root->right = insert(root->right,value); }
    return root;
}

struct node *delete(struct node *root,int value){
    if(root==NULL) { return root; }
    else if(value < root->data) { root->left = delete(root->left,value); }
    else if (value > root->data) { root->right = delete (root->right,value); }
    else{
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = findmin(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data); 
    }
    return root;
}

void preorder(struct node *root){
    if(root != NULL){
    printf(" %d ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

int main(){
    struct node *root;
    root = insert(root,10);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 21);
    root = insert(root, 28);
    printf("Preorder traversal : ");
    preorder(root);
    root  = delete(root,8);
    printf("Preorder traversal after deletion : ");
    preorder(root);
    return 0;
}