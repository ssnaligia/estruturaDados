typedef struct ponto Ponto; 
typedef struct ponto {
    float x;
    float y;
} Ponto;

// Funções para manipulação dos pontos
Ponto* criaPto (float x, float y);
//Libera um novo ponto
void liberaPto (Ponto* p);
//Acessa valores de x e y
Ponto* acessaPto (Ponto* P, float* x, float* y);
//Atribui valores de x e y ao ponto p
Ponto* atribuiPto (Ponto p, float x, float y);
//Calcula distância entre dois pontos
float distanciaPto (Ponto* p1, Ponto* p2);