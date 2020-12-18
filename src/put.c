#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value)
{
	printf("put: %s, %s\n", key, value);

	/* do program here */
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	strcpy(newNode->key, key);
    newNode->value = strdup(value);
    newNode->next = NULL;

    if(kvs->items == 0){
        kvs->db = newNode;
    }else{
        node_t *tmp = kvs->db;
        newNode->next = tmp;
        kvs->db = newNode;
    }
    kvs->items++;

	return 0;
}
