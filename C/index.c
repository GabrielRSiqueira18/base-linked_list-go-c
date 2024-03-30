#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
} node;

typedef struct LinkedList {
  node *head;
} linkedList;

node* createNode(int data) {
  node *newNode = (node*) malloc(sizeof(node*));

  if (newNode = NULL) {
    printf("No memory!");
    exit(1);
  }

  newNode->prev = NULL;
  newNode->data = data; 
  newNode->prev = NULL;

  return newNode;
}

void insertNext(int data, linkedList **list) {
  node *newNode = createNode(data);

  linkedList *current = *list;

  if (current->head = NULL) {
    current->head = newNode;
    return;
  } 

  node *temp = current->head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
}

int main() {
  
}