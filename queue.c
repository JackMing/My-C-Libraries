#include "queue.h"

void qInit(Queue *q){
    q->list = malloc(sizeof(LinkedList));
    listInit(q->list);
}

void qOffer(Queue *q, void *in){
    ListNode *node = malloc(sizeof(ListNode));
    node->val = in;
    node->next = NULL;
    listAppend(q->list, node);
}

void *qPoll(Queue *q){
    ListNode *re = listRemoveFirst(q->list);
    void* ret = re->val;
    free(re);
    return ret;
}

void qFree(Queue *q){
    listFree(q->list);
    free(q->list);
    q->list = NULL;
}
