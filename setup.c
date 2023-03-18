#include <stdio.h>
#include <assert.h>


int menu(){
    //Displays the opening title
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("================================\n");
    printf("||                            ||\n");
    printf("||       Escape the Train     ||\n");
    printf("||                            ||\n");
    printf("================================\n");
    printf("\n");
    printf("\n");
    //Promps player
    printf("ENTER 1 TO PLAY\n");
    printf("ONLY RESPOND IN LOWER CASE LETTERS || ALSO THIS GAME HAS SOME REPLAYABILITY;");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    //Listens for player response
    char c = '0';
    scanf("%c",&c);
        if(c=='1'){
            return 0;
        }
        else{
            printf("SORRY I DID NOT UNDERSTAND THAT\n");
            menu();
        }
    return 0;
}

void getName(){
    char name[100];
    printf("Before you begin, I must know...What is your name?\n");
    scanf("%s", &name);
    printf("Hello, %s!\n", &name);
    return;
}

void backstory(){
    printf("You wake up with amnesia inside of a train cart with a row of empty beds.\n"
           "You see only one door at the end of the hallway. The door is locked.\n");
    return;
}

