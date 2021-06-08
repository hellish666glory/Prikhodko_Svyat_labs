#include <stdio.h>
#include <malloc.h>

typedef struct nodeType1 {
  int value;
  struct nodeType2 *next;
} NodeType1;

typedef struct nodeType2 {
  int value;
  struct nodeType1 *next;
  struct nodeType2 *aside;
} NodeType2;

typedef struct nodePtrs {
  struct nodeType1 *headL;
  struct nodeType1 *headR;
} NodePtrs;

NodePtrs listNew(int);
NodeType1 *elemNew(int);
void listAddElem(NodePtrs, int);
void elemAddNode(NodeType1 *, int);
void listPrint(NodePtrs p);

int main(void) {

  NodePtrs p = listNew(1);
  listAddElem(p, 3);
  listAddElem(p, 5);
  listAddElem(p, 7);
  listAddElem(p, 9);
  listAddElem(p, 11);
  listAddElem(p, 13);
  listAddElem(p, 15);
  listAddElem(p, 17);
  listAddElem(p, 19);
  listAddElem(p, 21);

  listPrint(p);
}

NodePtrs listNew(int value) {
  NodePtrs p;
  p.headL = elemNew(value);
  p.headR = elemNew(value);

  p.headL->next->aside = p.headR->next;
  p.headR->next->aside = p.headL->next;

  return p;
}

NodeType1 *elemNew(int value) {
  NodeType1 *node = (NodeType1 *)malloc(sizeof(NodeType1));
  node->value = value;

  node->next = (NodeType2 *)malloc(sizeof(NodeType2));
  node->next->value = value+1;
  node->next->aside = NULL;
  node->next->next = NULL;

  return node;
}

void listAddElem(NodePtrs p, int value) {
  elemAddNode(p.headL, value);
  elemAddNode(p.headR, value);

  for(;p.headL->next->next != NULL; p.headL = p.headL->next->next) {}
  for(;p.headR->next->next != NULL; p.headR = p.headR->next->next) {}

  p.headL->next->aside = p.headR->next;
  p.headR->next->aside = p.headL->next;
}

void elemAddNode(NodeType1 *node, int value) {
  for(;node->next->next != NULL; node = node->next->next) {}
  node->next->next = elemNew(value);
}

void listPrint(NodePtrs p) {
  for(;p.headL->next->next != NULL;p.headL = p.headL->next->next, p.headR = p.headR->next->next) {
    printf("%d\n",p.headL->value);
    printf("%p\n",p.headL->next);
    printf("%d\n",p.headR->value);
    printf("%p\n",p.headR->next);

    printf("%d\n",p.headL->next->value);
    printf("%p\n",p.headL->next->aside);
    printf("%p\n",p.headL->next->next);
    printf("%d\n",p.headR->next->value);
    printf("%p\n",p.headR->next->aside);
    printf("%p\n",p.headR->next->next);

    if (p.headL->next->next->next->next == NULL) {
      printf("%d\n",p.headL->next->next->value);
      printf("%p\n",p.headL->next->next->next);
      printf("%d\n",p.headR->next->next->value);
      printf("%p\n",p.headR->next->next->next);

      printf("%d\n",p.headL->next->next->next->value);
      printf("%p\n",p.headL->next->next->next->aside);
      printf("%p\n",p.headL->next->next->next->next);
      printf("%d\n",p.headR->next->next->next->value);
      printf("%p\n",p.headR->next->next->next->aside);
      printf("%p\n",p.headR->next->next->next->next);
    }
  }
}
