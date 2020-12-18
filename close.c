#include "kvs.h"

int close(kvs_t* kvs)
{
	/* do program */
    if (!kvs) {
        return 0;
    }
    if (kvs->db) {      // close linkedlist's node
        node_t *n = kvs->db;
        while(n != NULL){
            node_t *tmp = n;
            n = n->next;
            free(tmp);
        }
    }
    free(kvs);

	return 0;
}
