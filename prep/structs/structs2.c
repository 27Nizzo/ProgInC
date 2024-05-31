#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char user[25];

typedef struct 
{
    char name[12];
    int id;
    char password[30];
    
} User;


int main(){

    User user1 = {"Nizzo", 1212314214, "password123"};
    User user2 = {"Ozzin", 1125153655, "password321"};

    printf("Name: %s\nId: %d\nPass: %s\n", user1.name, user1.id, user1.password);
    printf("Name: %s\nId: %d\nPass: %s\n", user2.name, user2.id, user2.password);

    return 0;
}
