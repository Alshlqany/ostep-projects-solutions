#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data {
    char *key;
    char *value;
};



int main(int argc, char *argv[]) {
    /* 

        1- load database.txt
        2- store its data in hashtable[] (array of data {k,v})
            a- get the line
            b- rallocate memory size  for the hashTable
            c- get the k,v by strsep
            d- increase size
        3- for each arg do :  
        4- extract [command,key,value] from the argv[i] 
        5- based on the command apply the changes to the hashtable
        6- after finishing all args reWrite database.txt with the data inside the hashtable
    */ 
    struct Data *hashTable = NULL;
    int size = 0;
    
    // step 1 
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    file = fopen("./database.txt","r");
    // step 2
    if(file){
        while(getline(&line,&len,file)!=-1){
            hashTable = realloc(hashTable,((size+1)*sizeof(struct Data)));
            hashTable[size].key = strsep(&line,",");
            hashTable[size].value = strdup(strsep(&line,"\n"));
            size++;
        }
        fclose(file);
    }

    int j = 0;
    char *token;
    for(int i = 1;i<argc;i++){
        j = 0;
        char *command[3];
        // step 4
        while((token = strsep(&argv[i],","))){
            command[j++] = token;
        }
        // step 5
        if (strcmp(command[0],"p") == 0){
            // check if the key already exist
            int isUpdated = 0;
            for (int i = 0; i < size; i++){
                if(strcmp(hashTable[i].key,command[1])==0){
                    hashTable[i].value = command[2];
                    isUpdated = 1;
                    break;
                }
            }
            if(!isUpdated){
                hashTable = realloc(hashTable,(size + 1) * sizeof(struct Data));
                hashTable[size].key = command[1];
                hashTable[size].value = command[2];
                size++;
            }
        }
        else if (strcmp(command[0],"g") == 0){
            // check if the key already exist
            int isFounded = 0;
            for (int i = 0; i < size; i++){
                if(strcmp(hashTable[i].key,command[1])==0){
                    printf("%s,%s\n",hashTable[i].key,hashTable[i].value);
                    isFounded = 1;
                    break;
                }
            }
            if(!isFounded){
               printf("%s not found\n", command[1]);
            }
        }
        else if (strcmp(command[0],"d") == 0){
            // check if the key already exist
            int isFounded = 0;
            for (int i = 0; i < size; i++){
                if(strcmp(hashTable[i].key,command[1])==0){
                   
                    // update it with the last record data then reallocate the memory with size - 1
                    hashTable[i].key = hashTable[size-1].key;
                    hashTable[i].value = hashTable[size - 1 ].value;
                    hashTable = realloc(hashTable, (size - 1 )* sizeof(struct Data));
                    size--;
                    isFounded = 1;
                    break;
                }
            }
            if(!isFounded){
               printf("%s not found\n", command[1]);
            }
        }
        else if (strcmp(command[0],"a") == 0){
            for (int i = 0; i < size; i++){
                printf("%s,%s\n",hashTable[i].key,hashTable[i].value);  
            }
        }
        else if (strcmp(command[0],"c") == 0){
            free(hashTable);
            hashTable = NULL;
            size = 0;
        }
        else {
            printf("bad command\n");
        }

    }
    // step 6
    file = fopen("./database.txt", "w+");
    for(int i = 0; i < size; i++){
        fprintf(file,"%s,%s\n",hashTable[i].key,hashTable[i].value);
    }
    fclose(file);
    free(hashTable);
    return 0;
}