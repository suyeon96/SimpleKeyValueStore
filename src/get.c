#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	/* do program here */
    char* value = (char*)malloc(sizeof(char)*10);
    if(!value){
        printf("Failed to malloc\n");
        return NULL;
    }

    node_t *n = kvs->db;
    while(n != NULL){
        if(strcmp(n->key, key) == 0){       // TRUE
            value = n->value;
            break;
        }else{
            n = n->next;
        }
    }

	return value;
}
