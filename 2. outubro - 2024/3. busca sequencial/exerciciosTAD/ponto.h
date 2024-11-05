typedef struct ponto Ponto;

// Funções para manipulação dos pontos
Ponto* criaPto (float x, float y);

void liberaPto (Ponto* p);

Ponto* acessaPto (Ponto* P, float* x, float* y);

Ponto* atribuiPto (Ponto p, float x, float y);

float distanciaPto (Ponto* p1, Ponto* p2);c