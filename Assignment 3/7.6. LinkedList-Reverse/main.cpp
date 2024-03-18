
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

};

// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

//-----------------------------------------------------------------------

void insert_node(SinglyLinkedList *llist, int llist_item){
    SinglyLinkedListNode *temp = new SinglyLinkedListNode(llist_item);
    if (llist->head == NULL){
        llist->head = temp;
    }
    else {
        llist->tail->next = temp;
    }
    llist->tail = temp;
}

void printLinkedList(SinglyLinkedList *llist){
    SinglyLinkedListNode *temp = llist->head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void reverseLinkedList(SinglyLinkedList *llist){
    SinglyLinkedListNode *curr = llist->head;
    SinglyLinkedListNode *prev = NULL;
    SinglyLinkedListNode *next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    llist->head = prev;
}


//-----------------------------------------------------------------------


int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }


    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
