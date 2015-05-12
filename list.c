#include "list.h"

void listInit(LinkedList *list){
	list->head = malloc(sizeof(ListNode));
	list->last = list->head;
}

void listAppend(LinkedList *list, ListNode *in){
	list->last->next = in;
	list->last = list->last->next;
}

void listInsertFirst(LinkedList *list, ListNode *in){
	ListNode *tmp = list->head->next;
	if(tmp != NULL)
		in->next = tmp->next;
	else
		list->last = in;
	list->head->next = in;
}


ListNode *listGet(LinkedList *list, int i){
	ListNode *ptr = list->head;
	while(i-- && ptr)
		ptr = ptr->next;
	return ptr->next;
}

ListNode *listRemoveFirst(LinkedList *list){
	if(list->head->next == NULL)
		return NULL;
	
	ListNode *ret = list->head->next;
	list->head->next = list->head->next->next;
	if(list->head->next == NULL)
		list->last = list->head;
	ret->next = NULL;
	return ret;
}

ListNode *listRemoveLast(LinkedList *list){
	ListNode *ptr = list->head;
	if(ptr->next == NULL) return NULL;
	
	while(ptr->next->next)
		ptr = ptr->next;
	
	ListNode *ret = ptr->next;
	list->last = ptr;
	list->last->next = NULL;
	return ret;
}

void NodeFree(ListNode *head){
    if(head->next == NULL)
        return;
    NodeFree(head->next);
    free(head->next);
    head->next = NULL;
    head->val = NULL;
}

void listFree(LinkedList *list){
    NodeFree(list->head);
    free(list->head);
    list->last = NULL;
    list->head = NULL;
}

