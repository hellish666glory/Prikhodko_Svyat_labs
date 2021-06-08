#include <stdio.h>
#include <iostream>

class NodeType1;
class NodeType2;
class NodeType3;

class NodeType1 {
public:

    NodeType1(int x) {
        value = x;
    }

    int value;
    NodeType2* left;
    NodeType2* right;
};

class NodeType2 {
public:

    NodeType2(int x) {
        value = x;
    }

    int value;
    NodeType2* aside;
    NodeType3* next;
};

class NodeType3 {
public:

    NodeType3(int x) {
        value = x;
    }

    int value;
    NodeType3* aside;
    NodeType1* next;
};

void listAddElement(NodeType1* node, int value);

NodeType1* listNew(int value) {
    NodeType1* node = new NodeType1(value);

    node->left = NULL;
    node->right = NULL;

    listAddElement(node, value + 1);

    return node;
}

void listAddElement(NodeType1* node, int value) {

    for (;node->right != NULL;node = node->right->next->next) {}

    node->left = new NodeType2(value);
    node->right = new NodeType2(value + 1);

    node->left->aside = node->right;
    node->right->aside = node->left;

    node->left->next = new NodeType3(value + 2);
    node->right->next = new NodeType3(value + 3);

    node->left->next->aside = node->right->next;
    node->right->next->aside = node->left->next;

    node->left->next->next = new NodeType1(value + 4);
    node->right->next->next = node->left->next->next;

}

void listPrint(NodeType1* node) {
    for (;node->left->next->next->left != NULL; node = node->right->next->next) {
        printf("%d\n", node->value);
        printf("%p\n", node->left);
        printf("%p\n", node->right);


        printf("%d\n", node->left->value);
        printf("%p\n", node->left->aside);
        printf("%p\n", node->left->next);

        printf("%d\n", node->right->value);
        printf("%p\n", node->right->aside);
        printf("%p\n", node->right->next);

        printf("%d\n", node->left->next->value);
        printf("%p\n", node->left->next->aside);
        printf("%p\n", node->left->next->next);

        printf("%d\n", node->right->next->value);
        printf("%p\n", node->right->next->aside);
        printf("%p\n", node->right->next->next);

        printf("%d\n", node->left->next->next->value);
        printf("%p\n", node->left->next->next->left);
        printf("%p\n", node->left->next->next->right);

        if (node->left->next->next->left->next->next->left == NULL) {

            printf("%d\n", node->left->next->next->left->value);
            printf("%p\n", node->left->next->next->left->aside);
            printf("%p\n", node->left->next->next->left->next);

            printf("%d\n", node->left->next->next->right->value);
            printf("%p\n", node->left->next->next->right->aside);
            printf("%p\n", node->left->next->next->right->next);

            printf("%d\n", node->left->next->next->left->next->value);
            printf("%p\n", node->left->next->next->left->next->aside);
            printf("%p\n", node->left->next->next->left->next->next);

            printf("%d\n", node->left->next->next->right->next->value);
            printf("%p\n", node->left->next->next->right->next->aside);
            printf("%p\n", node->left->next->next->right->next->next);

            printf("%d\n", node->left->next->next->left->next->next->value);
            printf("%p\n", node->left->next->next->left->next->next->left);
            printf("%p\n", node->left->next->next->left->next->next->right);
        }
    }
}

int main(void) {

    NodeType1* list = listNew(1);
    listAddElement(list, 7);
    listAddElement(list, 12);
    listAddElement(list, 18);
    listAddElement(list, 24);

    listPrint(list);

    return 0;
}
