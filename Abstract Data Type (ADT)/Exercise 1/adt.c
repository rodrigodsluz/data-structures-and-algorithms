#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

struct ponto{
	double x;
	double y;
};

Ponto* pontoCriar(double x, double y)
{
  Ponto* p = (Ponto*) malloc(sizeof(Ponto));

  if(p != NULL){
    p->x = x;
    p->y = y;
  }
  
  return p;
}

Ponto *add(Ponto *r, Ponto *s){
    return pontoCriar(r->x + s->x, r->y + s->y);
  
}

Ponto *subtraction(Ponto *r, Ponto *s){
    return pontoCriar(r->x - s->x, r->y - s->y);
}

Ponto *multiplication(Ponto *r, Ponto *s){
    return pontoCriar(((r->x * s->x) - (r->y * s->y)), ((r->y * s->x) + (r->x * s->y)));
}

Ponto *division(Ponto *r, Ponto *s){
    return pontoCriar(((r->x * s->x) + (r->y * s->y)) / (((s->x)*(s->x)) + ((s->y) * (s->y))), ((r->y * s->x) - (r->x * s->y)) / (((s->x) * (s->x)) + (s->y) * (s->y)));
}

void print(Ponto *p){
    printf("a + bi = %.2lf + %.2lfi\n", p->x, p->y);
}

void freeComplexNumber(Ponto *p){
    free(p);
}