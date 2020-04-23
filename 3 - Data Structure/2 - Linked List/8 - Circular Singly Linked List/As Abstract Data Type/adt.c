#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

struct produto{
	int codigo;
	char descricao[30];  
	float preco;
	int qtd;
};

struct elemento{
  Produto *produto;
  struct elemento *prox;
};