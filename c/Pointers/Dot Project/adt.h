
// --------------------------
// definição de structs 
// --------------------------

// como "struct ponto" foi definida no arquivo ponto.c, esse tipo não pode ser usado em ponto.h, portanto, é necessário redefini-lo aqui.
// o comando "typedef" renomeia "struct ponto" (conforme definido em ponto.c) para "Ponto" (agora, "Ponto" pode ser usado como tipo de dados nos protótipos abaixo)
typedef struct ponto Ponto;



// --------------------------
// protótipos das funções
// --------------------------

// função para criar um novo ponto
Ponto* pontoCriar(float x, float y);

// função para atribuir valores para as coordenadas x e y do ponto
int pontoAtribuir(Ponto* p, float x, float y);

// função para acessar os valores das coordenadas x e y do ponto
int pontoAcessar(Ponto* p, float *x, float *y);

// função para imprimir um ponto
void pontoImprimir(Ponto* p);

// função para liberar a memória de um ponto
void pontoLiberar(Ponto* p);




