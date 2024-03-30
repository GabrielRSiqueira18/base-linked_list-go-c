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
  node *newNode = (node*) malloc(sizeof(node));
  if (newNode == NULL) {
    printf("No memory!");
    exit(1);
  }

  newNode->prev = NULL;
  newNode->data = data; 
  newNode->next = NULL;

  return newNode;
}

void insertNext(int data, linkedList **list) {
  node *newNode = createNode(data);
  linkedList *current = *list;

  if (current->head == NULL) {
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

void insertPrev(int data, linkedList **list) {
  node *newNode = createNode(data);

  linkedList *current = *list;

  if (current->head == NULL) {
    current->head = newNode;
    return;
  }

  newNode->next = current->head;
  current->head->prev = newNode;
  current->head = newNode;
}

void display(linkedList *list) {
  if (list->head == NULL) {
    printf("Empty List");
    return;
  }

  node *current = list->head;

  while (current != NULL) {
    printf("Valor: %d\n", current->data);
    current = current->next;
  }
}

int main() {
  linkedList *list = (linkedList*) malloc(sizeof(linkedList));
  list->head = NULL;

  insertNext(10, &list);
  insertNext(20, &list);
  insertNext(30, &list);
  insertNext(40, &list);

  insertPrev(1, &list);
  insertPrev(2, &list);
  insertPrev(3, &list);
  insertPrev(4, &list);

  display(list);
}