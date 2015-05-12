#include "stack.h"

void skInit(Stack *sk){
	sk->list = malloc(sizeof(LinkedList));
	listInit(sk->list);
}

void skPush(Stack *sk, void *in){
	ListNode *node = malloc(sizeof(ListNode));
	node->val = in;
	node->next = NULL;
	listInsertFirst(sk->list,node);
}

void *skPop(Stack *sk){
	ListNode *re = listRemoveFirst(sk->list);
	if(re == NULL)
		return NULL;
	void *ret = re->val;
	free(re);
	return ret;
}

void *skPeek(Stack *sk){
	ListNode *re = listGet(sk->list, 0);
	if(re == NULL)
		return NULL;
	return re->val;
}

void skFree(Stack *sk){
	listFree(sk->list);
	free(sk->list);
	sk->list = NULL;
}

int skEmpty(Stack *sk){
	return skPeek(sk) == NULL;
}