#ifndef OBJECT_H_
#define OBJECT_H_

typedef struct{
    char const * label;
    int status;
    int location;
}object;

int pickup(object obj);

#endif