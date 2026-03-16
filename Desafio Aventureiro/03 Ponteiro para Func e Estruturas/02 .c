#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main() {
    // p é um ponteiro para uma Pessoa
    Pessoa* p = (Pessoa*)malloc(sizeof(Pessoa));

    printf("Digite o nome: ");
    scanf("%s", p->nome); // Usamos a seta!

    printf("Digite a idade: ");
    scanf("%d", &p->idade); // E a seta aqui também!

    printf("%s tem %d anos.\n", p->nome, p->idade);

    free(p);
    return 0;
}