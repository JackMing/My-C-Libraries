#include "mylib.h"

Entry *newEntry          (unsigned int key, void *value);
int   hash               (HashMap *map, unsigned int in);
void  rehash             (HashMap *map);
void  copyTable          (HashMap *map, Entry **old);

void  hashMapInit        (HashMap *map);
void  hashMapPut         (HashMap *map, unsigned int key, void *value);
int  hashMapContainsKey (HashMap *map, unsigned int key);
void *hashMapGet         (HashMap *map, unsigned int key);
void *hashMapRemove      (HashMap *map, unsigned int key);
void  hashMapFree        (HashMap *map);
