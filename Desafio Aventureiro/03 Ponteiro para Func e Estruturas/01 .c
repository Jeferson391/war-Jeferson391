#include <stdio.h>

void saudacao() {
    printf("Olá, mundo!\n");
    }

    int main() {
        // Declarando um ponteiro 'ptr' para uma função
            // que não retorna nada (void) e não tem parâmetros ().
                void (*ptr)() = saudacao;

                    // Chamando a função através do ponteiro
                        ptr();

                            return 0;
                            }
                            