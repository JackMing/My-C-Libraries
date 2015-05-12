#include "mylib.h"

void listInit(LinkedList *list);
void listAppend(LinkedList *list, ListNode *in);
void listInsertFirst(LinkedList *list, ListNode *in);
ListNode *listGet(LinkedList *list, int i);
ListNode *listRemoveFirst(LinkedList *list);
ListNode *listRemoveLast(LinkedList *list);
void NodeFree(ListNode *head);
void listFree(LinkedList *list);