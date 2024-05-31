#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Player
{
    char name[12];
    int score;
};


int main(){

    struct Player p1;
    struct Player p2;

    strcpy(p1.name, "Afonso");
    char name1 = p1.name;
    p1.score = 4;
    int score1 = p1.score;
    

    strcpy(p2.name, "Nizzo");
    char name2 = p2.name;
    p2.score = 6;
    int score2 = p2.score;

    printf("%s: %d pontos\n", p1.name, p1.score);
    printf("%s: %d pontos\n", p2.name, score2);


}