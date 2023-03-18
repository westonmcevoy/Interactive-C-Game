#include <stdio.h>
#include <assert.h>

#include "object.h"

int pickup(object obj){
    printf("You picked up the %s!\n", obj.label);
    obj.status = 1;
    return(obj.status);
}