// Douglas Benevides Almeida

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OPER_ADD 2
#define OPER_SUB 3
#define OPER_MUL 4
#define OPER_DIV 5

void gerar_codigo_pcode(FILE *entrada, int memoria[]);

int main() {
    int memoria[8]; // Memória para variáveis a, b, c, d, e

    memoria[3] = 1; // Valor de a
    memoria[4] = 5; // Valor de b
    memoria[5] = 4; // Valor de c
    memoria[6] = 2; // Valor de d
    memoria[7] = 3; // Valor de e

    FILE *arquivoEntrada = fopen("entrada.txt", "r");
    if (arquivoEntrada == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    gerar_codigo_pcode(arquivoEntrada, memoria);
    fclose(arquivoEntrada);

    return 0;
}

void gerar_codigo_pcode(FILE *entrada, int memoria[]) {
    char linha[256];
    int valor, tamanho_memoria, indice = 0, codigo_atual = 1;

    printf("-> CODIGO %d\n", codigo_atual);
    printf("INT 0 7\n");
    while (fgets(linha, sizeof(linha), entrada)) {
        char *comando = linha;

        // Identifica novo código intermediário na entrada
        if (strncmp(comando, "###", 3) == 0) {
            codigo_atual++;
            printf("OPR 0 0\n");
            printf("\nPROXIMO CODIGO\n");
            printf("-> CODIGO %d\n", codigo_atual);
            printf("INT 0 7\n");
            continue;
        }

        if (strncmp(comando, "PUSH(", 5) == 0) {
            comando += 5;
            char variavel;
            sscanf(comando, "%c)", &variavel);
            switch (variavel) {
                case 'a':
                    valor = memoria[3];
                    indice = 3;
                    break;
                case 'b':
                    valor = memoria[4];
                    indice = 4;
                    break;
                case 'c':
                    valor = memoria[5];
                    indice = 5;
                    break;
                case 'd':
                    valor = memoria[6];
                    indice = 6;
                    break;
                case 'e':
                    valor = memoria[7];
                    indice = 7;
                    break;
                default:
                    break;
            }
            printf("LOD 0 %d\n", indice);
        } else if (strncmp(comando, "y=POP(); x=POP(); PUSH(x ADD y)", 31) == 0) {
            printf("OPR 0 %d\n", OPER_ADD);
        } else if (strncmp(comando, "y=POP(); x=POP(); PUSH(x SUB y)", 31) == 0) {
            printf("OPR 0 %d\n", OPER_SUB);
        } else if (strncmp(comando, "y=POP(); x=POP(); PUSH(x MUL y)", 31) == 0) {
            printf("OPR 0 %d\n", OPER_MUL);
        } else if (strncmp(comando, "y=POP(); x=POP(); PUSH(x DIV y)", 31) == 0) {
            printf("OPR 0 %d\n", OPER_DIV);
        }
    }
    printf("OPR 0 0\n");
}
