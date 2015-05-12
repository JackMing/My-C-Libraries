#include "hashMap.h"
#include <string.h>

#define DEFAULT_SIZE 16
#define LOAD_FACTOR 0.75

Entry *newEntry(unsigned int key, void *value){
	Entry *ret = (Entry *)malloc(sizeof(Entry));
	ret->key = key;
	ret->value = value;
	ret->next = NULL;
	return ret;
}

int hash(HashMap *map, unsigned int in){
	return in % map->totalSize;
}

void rehash(HashMap *map){
	Entry **oldTable = map->arr;
	map->arr = (Entry**)malloc(sizeof(Entry*)*map->totalSize*2);
	memset(map->arr, 0, sizeof(Entry*)*map->totalSize*2);
	map->totalSize *= 2;
	map->limit = map->totalSize*LOAD_FACTOR;
	copyTable(map, oldTable);
	free(oldTable);
}

void copyTable(HashMap *map, Entry **old){
	int i;
	for(i=0;i<map->totalSize/2;i++){
		while(old[i] != NULL){
			Entry *e = old[i];
			old[i] = old[i]->next;
			int newIndex = hash(map, e->key);
			Entry *tmp = map->arr[newIndex];
			e->next = tmp;
			map->arr[newIndex] = e;
		}
	}
}

void hashMapInit(HashMap *map){
	map->arr = (Entry**)malloc(sizeof(Entry*)*DEFAULT_SIZE);
	memset(map->arr, 0, sizeof(Entry*)*DEFAULT_SIZE);
	map->size = 0;
	map->totalSize = DEFAULT_SIZE;
	map->limit = DEFAULT_SIZE*LOAD_FACTOR;
}

int hashMapContainsKey(HashMap *map, unsigned int key){
	return hashMapGet(map, key) != NULL;
}

void hashMapPut(HashMap *map, unsigned int key, void *value){
	int e = hash(map,key);
	if(map->arr[e] == NULL){
		map->arr[e] = newEntry(key, value);
	}else{
		Entry *ptr = map->arr[e];
		while(1){
			if(ptr->key == key){
				ptr->value = value;
				return;
			}
			if(ptr->next == NULL){
				ptr->next = newEntry(key, value);
				break;
			}
			ptr = ptr->next;
		}
	}
	if(map->size++ > map->limit)
		rehash(map);
}

void *hashMapGet(HashMap *map, unsigned int key){
	int e = hash(map, key);
	Entry *ptr = map->arr[e];
	while(ptr){
		if(ptr->key == key)
			return ptr->value;
		ptr = ptr->next;
	}
	return NULL;
}

void *hashMapRemove(HashMap *map, unsigned int key){
	int e = hash(map, key);
	void *ret = NULL;
	Entry *ptr = map->arr[e];
	if(ptr != NULL){
		if(map->arr[e]->key == key){
			ret = map->arr[e]->value;
			map->arr[e] = map->arr[e]->next;
			free(ptr);
			map->size--;
			return ret;
		}
		while(ptr->next){
			if(ptr->next->key == key){
				Entry *tmp = ptr->next;
				ret = ptr->next->value;
				ptr->next = ptr->next->next;
				free(tmp);
				map->size--;
				return ret;
			}
			ptr = ptr->next;
		}
	}
	return NULL;
}

void hashMapFree(HashMap *map){
	int i;
	for(i=0;i<map->totalSize;i++){
		while(map->arr[i] != NULL){
			Entry *ptr = map->arr[i];
			map->arr[i] = ptr->next;
			free(ptr);
		}
	}
	free(map->arr); // free the Entry[]
	map->arr = NULL;
}
