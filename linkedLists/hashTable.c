#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETE_NODE (person*)(0XFFFFFFFFFFFFFFFFUL)

typedef struct 
{
    char name[MAX_NAME];
    int age;
}person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE; 
    }
    
    return hash_value;
} 

void init_hash_table() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL; 
    }
}

void print_table() {
    printf("Start\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(hash_table[i] == NULL) {
            printf("\t%i\t---\n",i);
        } else if (hash_table[i] == DELETE_NODE){
            printf("\t%i\t---<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }

    printf("End\n");
}

bool hash_table_insert(person *p) {
    if(p == NULL) return false;
    int index = hash(p->name);

    for(int i = 0;i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        
        if(hash_table[try] == NULL || hash_table[try] == DELETE_NODE) {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup (char *name) {
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++) {

        int try = (index + i) % TABLE_SIZE;
        
        if(hash_table[try] == NULL) {
            return false; 
        }

        if(hash_table[try] == DELETE_NODE) {
            continue;
        }

        if(hash_table[try] != NULL &&
        strncmp(hash_table[try] -> name, name, TABLE_SIZE) == 0) {
        return hash_table[try];
         }
    }
   return NULL; 
}

person *hash_table_delete(char *name) {
     int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++) {

        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL) {
            return NULL;
        }

        if(hash_table[try] == DELETE_NODE) {
            continue;
        }

        if(hash_table[try] != NULL &&
        strncmp(hash_table[try] -> name, name, TABLE_SIZE) == 0) {
        
        person* tmp = hash_table[try];
        hash_table[try] = NULL; 
        return tmp;   
        }
    }
   return NULL;
}

int main() {
    init_hash_table();
    print_table();

    person jacob ={.name = "Jacob", .age = 16};
    person afonso ={.name = "Afonso", .age = 20};
    person ana ={.name = "Ana", .age = 21};
    person natalie ={.name = "Natalie", .age = 26};
    person rob ={.name = "Rob", .age = 22};
    person eliza ={.name = "Eliza", .age = 13};
    person jane ={.name = "Jane", .age = 24};
    person edna ={.name = "Edna", .age = 56};
    person maren ={.name = "Maren", .age = 18};

    hash_table_insert(&jacob);
    hash_table_insert(&afonso);
    hash_table_insert(&ana);
    hash_table_insert(&natalie);
    hash_table_insert(&rob);
    hash_table_insert(&eliza);
    hash_table_insert(&jane);
    hash_table_insert(&edna);
    hash_table_insert(&maren);



    print_table();

    person *tmp = hash_table_lookup("Afonso");

   if(tmp == NULL) {
    printf("Not Found!");
   } else {
    printf("Found %s!\n", tmp -> name);
   }

   tmp = hash_table_lookup("Diogo");
   if(tmp == NULL) {
    printf("Not Found!\n");
   } else {
    printf("Found %s\n", tmp -> name);
   }

   hash_table_delete("Edna");
   tmp = hash_table_lookup("Edna");
   if(tmp == NULL) { 
    printf("Not found!\n");
   } else {
    printf("Found %s\n", tmp -> name);
   }

   print_table();


   /* printf("Jacob => %u\n", hash("Jacob"));
    printf("Natalie => %u\n", hash("Natalie"));
    printf("Ana => %u\n", hash("Ana"));
    printf("Afonso => %u\n", hash("Afonso"));*/
    
    
    return 0; 
}
