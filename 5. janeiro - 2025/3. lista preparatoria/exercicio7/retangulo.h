#ifndef RETANGULO_H
#define RETANGULO_H

typedef struct Retangulo {
    float base;
    float altura;
    struct Retangulo* proximo;
} Retangulo;

Retangulo* criarLista();
Retangulo* adicionarRetangulo(Retangulo* lista, float base, float altura);
void imprimirRetangulos(Retangulo* lista);
float calcularArea(Retangulo* ret);
void liberarLista(Retangulo* lista);

#endif
