typedef struct ponto Ponto;

Ponto *pontoCriar(double x, double y);

Ponto *add(Ponto *r, Ponto *s);

Ponto *subtraction(Ponto *r, Ponto *s);

Ponto *multiplication(Ponto *r, Ponto *s);

Ponto *division(Ponto *r, Ponto *s);

void print(Ponto *p);

void freeComplexNumber(Ponto *p);
