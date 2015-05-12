#ifndef _MY_LIB_H_
#define _MY_LIB_H_

#include <stdlib.h>

#define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )
#define MIN(a,b) ( ((a) < (b)) ? (a) : (b) )

typedef struct myListNode ListNode;
typedef struct myLinkedList LinkedList;
typedef struct myQueue Queue;
typedef struct myStack Stack;
typedef struct myArrayList ArrayList;
typedef struct myHashMap HashMap;
typedef struct myEntry Entry;


struct myArrayList{
	void **arr;
	int size;
	int totalSize;
};

struct myListNode{
	void *val;
	ListNode *next;
};

struct myLinkedList{
	ListNode *head;
	ListNode *last;
};

struct myQueue{
    LinkedList *list;
};

struct myStack{
    LinkedList *list;
};

struct myEntry{
	unsigned int key;
	void *value;
	Entry *next;
};

struct myHashMap{
	Entry **arr;
	int size;
	int totalSize;
	int limit;
};

#endif
