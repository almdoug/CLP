// Douglas Benevides Almeida

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADD_OP 2
#define SUB_OP 3
#define MUL_OP 4
#define DIV_OP 5

void gerar_codigo_pcode(FILE *entrada);

int main() {
    FILE *arquivoEntrada = fopen("entrada.txt", "r");
    if (arquivoEntrada == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }
    
    gerar_codigo_pcode(arquivoEntrada);
    fclose(arquivoEntrada);

    return 0;
}

void gerar_codigo_pcode(FILE *entrada) {
    char linha[256];
    int numero;

    while (fgets(linha, sizeof(linha), entrada)) {
        char *comando = linha;

        if (strncmp(comando, "PUSH(", 5) == 0) {
            comando += 5;
            sscanf(comando, "%d)", &numero);
            printf("LIT 0 %d\n", numero);
        } else if (strncmp(comando, "y=POP(); x=POP(); PUSH(x ADD y)", 31) == 0) {
            printf("OPR 0 %d\n", ADD_OP);
        } else if (strncmp(comando, "y=POP(); x=POP(); PUSH(x SUB y)", 31) == 0) {
            printf("OPR 0 %d\n", SUB_OP);
        } else if (strncmp(comando, "y=POP(); x=POP(); PUSH(x MUL y)", 31) == 0) {
            printf("OPR 0 %d\n", MUL_OP);
        } else if (strncmp(comando, "y=POP(); x=POP(); PUSH(x DIV y)", 31) == 0) {
            printf("OPR 0 %d\n", DIV_OP);
        }
    }
    printf("OPR 0 0\n");
}
