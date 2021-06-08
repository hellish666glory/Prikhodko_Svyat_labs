#include <stdio.h>

class List;
class NodeType1;
class NodeType2;

class NodeType2 {
    public:

      NodeType2(int value) {
        this->value = value;
        this->aside = NULL;
        this->next = NULL;
      }

      int value;
      NodeType2 *aside;
      NodeType1 *next;

};

class NodeType1 {
  public:

  NodeType1(int value) {
    this->value = value;
    this->next = new NodeType2(value+1);
  }

    int value;
    NodeType2 *next;

};

class List {
  public:

    NodeType1 *nodeL;
    NodeType1 *nodeR;

    List(int value) {
      nodeL = new NodeType1(value);
      nodeR = new NodeType1(value);

      nodeL->next->aside = nodeR->next;
      nodeR->next->aside = nodeL->next;
    }

    void addElement(int value) {
      NodeType1 *localL = nodeL;
      NodeType1 *localR = nodeR;
      for(;localL->next->next != NULL; localL = localL->next->next, localR = localR->next->next) {}

      localL->next->next = new NodeType1(value);
      localR->next->next = new NodeType1(value);

      localL->next->next->next->aside = localR->next->next->next;
      localR->next->next->next->aside = localL->next->next->next;
    }

    void print() {
      NodeType1 *localL = nodeL;
      NodeType1 *localR = nodeR;

      for(;localL->next->next != NULL; localL = localL->next->next, localR = localR->next->next) {
          printf("%d%11d\n",localL->value, localR->value);
          printf("%p%11p\n",localL->next, localR->next);
          printf("\n");

          printf("%d%11d\n",localL->next->value, localR->next->value);
          printf("%p%11p\n",localL->next->aside, localR->next->aside);
          printf("%p%11p\n",localL->next->next, localR->next->next);
          printf("\n");

        if (localL->next->next->next->next == NULL) {
          printf("%d%11d\n",localL->next->next->value, localR->next->next->value);
          printf("%p%11p\n",localL->next->next->next, localR->next->next->next);
          printf("\n");

          printf("%d%11d\n",localL->next->next->next->value, localR->next->next->next->value);
          printf("%p%11p\n",localL->next->next->next->aside, localR->next->next->next->aside);
          printf("%p%11p\n",localL->next->next->next->next, localR->next->next->next->next);
          printf("\n");
        }
      }
    }
};

int main(void) {
  List *list = new List(1);
  list->addElement(3);
  list->addElement(5);
  list->addElement(7);
  list->addElement(9);


  list->print();
}
