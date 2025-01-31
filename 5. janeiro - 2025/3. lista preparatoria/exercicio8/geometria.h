#ifndef GEOMETRIA_H
#define GEOMETRIA_H

typedef enum {
    RETANGULO,
    TRIANGULO,
    CIRCULO
} TipoForma;

typedef struct Forma {
    TipoForma tipo;
    float parametro1; //base ou raio
    float parametro2; //altura 
    struct Forma* proximo;
} Forma;


Forma* criarLista();
Forma* adicionarForma(Forma* lista, TipoForma tipo, float p1, float p2);
void imprimirFormas(Forma* lista);
float calcularArea(Forma* forma);
void liberarLista(Forma* lista);

#endif
