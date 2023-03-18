#include <stdio.h>
#include <assert.h>
#include <stddef.h>

#include "object.h"
#include "location.h"

void printLocation(location crnt_loc){
    printf("You are in %s. The %s.\n", crnt_loc.title, crnt_loc.description);
    return;
}

location forward(location nxt_loc){
    location crnt_loc = nxt_loc;
    return(crnt_loc);
}

int prompt(location crnt_loc){
    char input[25];
    printf("Which side of %s would you like to search? Right or Left?\n", crnt_loc.title);
    scanf("%s",input);
    if(!strcmp(input, "left")){
        return 0;
    }
    else if(!strcmp(input, "right")){
        return 1;
    }
    else{
        printf("Sorry I did not understand that...\n");
        prompt(crnt_loc);
    }
}

void advance(location crnt_loc,location nxt_loc){
    char input[25];
    printf("I wonder if this key unlocks this door on the far side of %s...\n", crnt_loc.title);
    printf("Give it a try?\n");
    scanf("%s", &input);
    if(!strcmp(input, "yes")){
        printf("Trying the key...\n *Lock Noises*\n");
        printf("It worked!\n");
        crnt_loc = forward(nxt_loc);
    }
    else if(!strcmp(input, "no")){
        printf("Weenie...\n");
        advance(crnt_loc, nxt_loc);
    }
    else{
        printf("Sorry I did not understand that...\n");
        advance(crnt_loc, nxt_loc);
    }
    return;
}

void combat(){
    char input[25];
    srand(time(NULL));
    int mon = rand() % 2;
    int scar = rand() % 2;
    int ind = 0;
    int M_health = 5;
    int P_health = 6;
    int fight = 0;
    if(mon == 1){
        ind = 0;
        printf("X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n"
                    "|                           ,,'``````````````',,                            |\n"
                    "X                        ,'`                   `',                          X\n"
                    "|                      ,'                         ',                        |\n"
                    "X                    ,'          ;       ;          ',                      X\n"
                    "|       (           ;             ;     ;             ;     (               |\n"
                    "X        )         ;              ;     ;              ;     )              X\n"
                    "|       (         ;                ;   ;                ;   (               |\n"
                    "X        )    ;   ;    ,,'```',,,   ; ;   ,,,'```',,    ;   ;               X\n"
                    "|       (    ; ',;   '`          `',   ,'`          `'   ;,' ;              |\n"
                    "X        )  ; ;`,`',  _--~~~~--__   ' '   __--~~~~--_  ,'`,'; ;     )       X\n"
                    "|       (    ; `,' ; :  /       \~~-___-~~/       \  : ; ',' ;     (        |\n"
                    "X  )     )   )',  ;   -_\  o    /  '   '  \    o  /_-   ;  ,'       )   (   X\n"
                    "| (     (   (   `;      ~-____--~'       '~--____-~      ;'  )     (     )  |\n"
                    "X  )     )   )   ;            ,`;,,,   ,,,;',            ;  (       )   (   X\n"
                    "| (     (   (  .  ;        ,'`  (__ '_' __)  `',        ;  . )     (     )  |\n"
                    "X  )     \/ , .). ';    ,'`        ~~ ~~        `',    ;  .(. , \/  )   (   X\n"
                    "| (   , ,'|// / (/ ,;  '        _--~~-~~--_        '  ;, \)    \|', ,    )  |\n"
                    "X ,)  , \/ \|  \\,/  ;;       ,; |_| | |_| ;,       ;;  \,//  |/ \/ ,   ,   X\n"
                    "| ,   .| \_ |\/ |#\_/;       ;_| : `~'~' : |_;       ;\_/#| \/| _/ |.   ,   |\n"
                    "X#(,'  )  \\\#\ \##/)#;     :  `\/       \/   :     ;#(\##/ /#///  (  ',)# ,X\n"
                    "|| ) | \ |/ /#/ |#( \; ;     :               ;     ; ;/ )#| \#\ \| / | ( |) |\n"
                    "X\ |.\\ |\_/#| /#),,`   ;     ;./\_     _/\.;     ;   `,,(#\ |#\_/| //.| / ,X\n"
                    "| \\_/# |#\##/,,'`       ;     ~~--|~|~|--~~     ;       `',,\##/#| #\_// \/|\n"
                    "X  ##/#  #,,'`            ;        ~~~~~        ;            `',,#  #\##  //X\n"
                    "|####@,,'`                 `',               ,'`                 `',,@####| |\n"
                    "X#,,'`                        `',         ,'`                        `',,###X\n"
                    "|'                               ~~-----~~                               `' |\n"
                    "X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n");
    }
    if(mon == 0){
        ind = 1;
        printf("                                                                _    \n"
                    "                                                              _( (~\ \n"
                    "       _ _                        /                          ( \> > \\n"
                    "   -/~/ / ~\                     :;                \       _  > /(~\/\n"
                    "  || | | /\ ;\                   |l      _____     |;     ( \/    > >\n"
                    "  _\\)\)\)/ ;;;                  `8o __-~     ~\   d|      \      // \n"
                    " ///(())(__/~;;\                   88p;.  -. _\_;.oP        (_._/ /  \n"
                    "(((__   __ \\   \                  `>,% (\  (\./)8          ;:'  i   \n"
                    ")))--`.'-- (( ;,8 \               ,;%%%:  ./V^^^V'          ;.   ;.  \n"
                    "((\   |   /)) .,88  `: ..,,;;;;,-::::::'_::\   ||\         ;[8:   ;  \n"
                    " )|  ~-~  |(|(888; ..``'::::8888oooooo.  :\`^^^/,,~--._    |88::  |  \n"
                    " |\ -===- /|  \8;; ``:.      oo.8888888888:`((( o.ooo8888Oo;:;:'  |  \n"
                    " |_~-___-~_|   `-\.   `        `o`88888888b` )) 888b88888P '     ;   \n"
                    " ; ~~~~;~~          `--_`.       b`888888888;(., 888b888   ..::;-'   \n"
                    "   ;      ;              ~ -....  b`8888888:::::.`8888. .:;;;''      \n"
                    "      ;    ;                 `:::. `:::OOO:::::::.`OO' ;;;''         \n"
                    " :       ;                     `.       ``::::::''    .'             \n"
                    "    ;                           `.   \_              /               \n"
                    "  ;       ;                       +:   ~~--  `:'  -';                \n"
                    "                                   `:         : .::/                 \n"
                    "      ;                            ;;+_  :::. :..;;;                 \n"
                    "                                   ;;;;;;,;;;;;;;;,;                 \n");


    }
        fight = 1;
        if(ind){
            printf("\nOh zoinks! You seem to have ran into a Minotar!\n");
            fight = 1;
            while(fight){
                int dmg = rand() % 2;
                int att = rand() % 2;
                printf("Fight or Flee?\n");
                scanf("%s", &input);
                if(!strcmp(input, "fight")){
                    printf("You threw a punch and hit Minotar for %ddmg\n", att);
                    M_health = M_health-att;
                    printf("Minotar's health is: %d\n", M_health);
                    printf("Minotar hit you for %ddmg\n", dmg);
                    P_health = P_health-dmg;
                    printf("Your health is: %d\n", P_health);
                    if(M_health == 0){
                        printf("You defeated Minotar!\n");
                        printf("You win!");
                        fight = 0;
                    }
                    if(P_health == 0){
                        printf("You died!");
                        fight = 0;
                    }
                }
                else if(!strcmp(input, "flee")){
                    if(scar == 0){
                        printf("You are too intimidated by Minotar and cannot flee\n");
                    }
                    else{
                        printf("You successfully fled Minotar! They broke down and started crying after you left!\n");
                        fight = 0;
                    }
                }
            }
        }
        if(!ind){
            printf("\nOh zoinks! You seem to have ran into a Goblin!\n");
            while(fight){
                int dmg = rand() % 2;
                int att = rand() % 2;
                printf("Fight or Flee?\n");
                scanf("%s", &input);
                if(!strcmp(input, "fight")){
                    printf("You threw a punch and hit Goblin for %d dmg\n",att);
                    M_health = M_health-att;
                    printf("Goblin's health is: %d\n", M_health);
                    printf("Goblin hit you for %ddmg\n", dmg);
                    P_health = P_health-dmg;
                    printf("Your health is: %d\n", P_health);
                    if(M_health == 0){
                        printf("You defeated Goblin!\n");
                        printf("You win!");
                        fight = 0;
                    }
                    if(P_health == 0){
                        printf("You died!");
                        fight = 0;
                    }
                }
                else if(!strcmp(input, "flee")){
                    if(scar == 0){
                        printf("You are too intimidated by Goblin and cannot flee\n");
                    }
                    else{
                        printf("You successfully fled Goblin! They broke down and started crying after you left!\n");
                        fight = 0;
                    }
                }
            }
        }
    }