#include "kvs.h"

int main()
{
	kvs_t* kvs = open();
	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	// KVS created.
	FILE *fp;
	fp=fopen("./student.dat", "rb");
	if(fp == NULL){
	    printf("Failed to open File");
	    exit(EXIT_FAILURE);
	}

	// File open & put kvs
	while(!feof(fp)){
        char key[100] = {' '};
        char* value = (char*) malloc (sizeof(char)* 300);

	    fscanf(fp, "%s %s", key, value);

	    if(key[0] == ' ') break;

        // kvs put
        if(put(kvs, key, value) < 0){
            printf("Failed to put data\n");
            exit(-1);
        }
        free(value);
	}
	fclose(fp);

	// File open again & get kvs
    fp=fopen("./student.dat", "rb");
    while(!feof(fp)){
        char key[100] = {' '};
        char* value = (char*) malloc (sizeof(char)* 300);
        char* rvalue;

        fscanf(fp, "%s %s", key, value);
        free(value);

        if(key[0] == ' ') break;

        // kvs get
        if(!(rvalue = get(kvs, key))){
            printf("Failed to get data\n");
            exit(-1);
        }
        printf("get: %s, %s\n", key, rvalue);
    }
    fclose(fp);

    close(kvs);
	
	return 0;
}
