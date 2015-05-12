#include "arrayList.h"

#define DEFAULT_SIZE 20


void arrListInit(ArrayList *list){
	list->arr = malloc(sizeof(void*)*DEFAULT_SIZE);
	list->totalSize = DEFAULT_SIZE;
	list->size = 0;
}

void arrListDoubleSize(ArrayList *list){
	void **old = list->arr;
	void **new = malloc(sizeof(void*)*(list->totalSize*2));
	memcpy(new, old, sizeof(void*)*(list->totalSize));
	free(old);
	list->arr = new;
	list->totalSize *= 2;
}

void arrListAdd(ArrayList *list, void *in){
	if(list->size == list->totalSize)
		arrListDoubleSize(list);
	list->arr[list->size] = in;
	list->size++;
}

void arrListFree(ArrayList *list){
	free(list->arr);
	list->arr = NULL;
	list->totalSize = 0;
	list->size = 0;
}