#include <bits/stdc++.h>
using namespace std;

// membuat struct dari node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// membuat fungsi InsertEnd
void insertEnd(struct Node** start, int value)
{
    //jika list kosong, maka akan dibuat single node
    if (*start == NULL)
    {
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }

    Node *last = (*start)->prev;

    // membuat node
    struct Node* new_node = new Node;
    new_node->data = value;

    // start berubah menjadi new_node berikutnya
    new_node->next = *start;

    // membuat node baru sebelum start
    (*start)->prev = new_node;

    // membuat previous terakhir dari node baru
    new_node->prev = last;

    // membuat node baru dari yang terakhir
    last->next = new_node;
}

// membuat fungsi insertBegin
void insertBegin(struct Node** start, int value)
{
    // pointer mengarah ke last Node
    struct Node *last = (*start)->prev;

    struct Node* new_node = new Node;
    new_node->data = value;   // memasukkan data

    // mengatur previous dan next dari node baru
    new_node->next = *start;
    new_node->prev = last;

    last->next = (*start)->prev = new_node;

    *start = new_node;
}

// membuat fungsi InsertAfter
void insertAfter(struct Node** start, int value1,
                                      int value2)
{
    struct Node* new_node = new Node;
    new_node->data = value1;

    struct Node *temp = *start;
    while (temp->data != value2)
        temp = temp->next;
    struct Node *next = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}


void display(struct Node* start)
{
    struct Node *temp = start;

    printf("\nTraversal in forward direction \n");
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);

    printf("\nTraversal in reverse direction \n");
    Node *last = start->prev;
    temp = last;
    while (temp->prev != last)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

int main()    // program utama
{
    struct Node* start = NULL;

    insertEnd(&start, 5);
    insertBegin(&start, 4);
    insertEnd(&start, 7);
    insertEnd(&start, 8);
    insertAfter(&start, 6, 5);

    printf("Created circular doubly linked list is: ");
    display(start);

return 0;
