// 43. write a program to perform deletion in binary search tree
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* newNode(int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct node* deleteNode(struct node *root, int data) {
  if (root == NULL) return root;
  else if (data < root->data) root->left = deleteNode(root->left, data);
  else if (data > root->data) root->right = deleteNode(root->right, data);
  else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }
    else if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    else {
      struct node *temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  return root;
}

void preOrder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main() {
  struct node *root = newNode(50);
  root->left = newNode(30);
  root->right = newNode(70);
  root->left->left = newNode(20);
  root->left->right = newNode(40);
  root->right->left = newNode(60);
  root->right->right = newNode(80);

  printf("Original Tree: ");
  preOrder(root);
  printf("\n");

  root = deleteNode(root, 50);
  printf("After Deletion of 50: ");
  preOrder(root);
  printf("\n");

  return 0;
}
