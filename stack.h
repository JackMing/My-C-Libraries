#include "mylib.h"

extern void listInit(LinkedList *list);
extern ListNode *listRemoveFirst(LinkedList *list);
extern void listInsertFirst(LinkedList *list, ListNode *in);
extern void listFree(LinkedList *list);
extern ListNode *listGet(LinkedList *list, int i);

void skInit(Stack *sk);
void skPush(Stack *sk, void *in);
void *skPop(Stack *sk);
void *skPeek(Stack *sk);
void skFree(Stack *sk);
