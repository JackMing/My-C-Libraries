#include "mylib.h"

extern void listInit(LinkedList *list);
extern ListNode *listRemoveFirst(LinkedList *list);
extern void listAppend(LinkedList *list, ListNode *in);
extern void listFree(LinkedList *list);

void qInit(Queue *q);
void qOffer(Queue *q, void *in);
void *qPoll(Queue *q);
void qFree(Queue *q);