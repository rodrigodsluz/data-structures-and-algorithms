#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

typedef struct element{
    Student student;
    struct element *next;
}Element;

