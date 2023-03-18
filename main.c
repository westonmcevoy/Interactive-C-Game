#include <stdio.h>
#include <assert.h>

#include "object.h"
#include "location.h"
#include "setup.h"

int main(){
    srand(time(NULL));
    int app1 = rand() % 2;
    int app2 = rand() % 2;
    int app3 = rand() % 2;
    location locs[] = {{"Car 1","Sleeper Car","Brass Key"},{"Car 2","Bar Car","Silver Key"},{"Car 3","Freight Car","Gold Key"},{"the outside of the train","Safe?","Air"}};
    object objs[] = {{"Brass Key",0,app1},{"Silver Key",0,app2},{"Gold Key",0,app3}};
    location crnt_loc = locs[0];
    object crnt_obj = objs[0];
    int i = 0;
    int j = 0;
    menu();
    getName();
    backstory();
    while(crnt_loc.title != "the outside of the train"){
        i++;
        j++;
        location nxt_loc = locs[i];
        object nxt_obj = objs[j];
        printLocation(crnt_loc);
        int direction = prompt(crnt_loc);
        if(direction == crnt_obj.location == crnt_obj.status){
            crnt_obj.status = pickup(crnt_obj);
        }
        else{
            printf("There's nothing over here...\n");
            direction = prompt(crnt_loc);
            if(direction == crnt_obj.location == crnt_obj.status){
                crnt_obj.status = pickup(crnt_obj);
            }
        }
    advance(crnt_loc,nxt_loc); 
    crnt_loc = nxt_loc;
    crnt_obj = nxt_obj;
    }
    printLocation(crnt_loc);
    printf("\nYou used the gold key to exit the kaboose of the train and jump off the platform to escape.\n");
    combat();
    printf("\n");
    printf("           MADE BY:         \n");
    printf("WESTON McEVOY || CADEN McVEY\n");
    printf("\n");
    printf("\n");
    printf("THANK YOU FOR PLAYING OUR GAME!\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
} 