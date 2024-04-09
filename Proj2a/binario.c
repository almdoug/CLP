// Douglas Benevides Almeida

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificarGramatica(const char* palavra);

int main() {
    FILE* arquivo = fopen("entrada.txt", "r");

    if (!arquivo) {
        fprintf(stderr, "Erro, arquivo nao encontrado");
        return 1;
    }

    char palavra[100];
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        if (verificarGramatica(palavra)) 
            printf("%s \treconhecida\n", palavra);
        else 
            printf("%s \trejeitada\n", palavra);
    }

    fclose(arquivo);
    return 0;
}

int verificarGramatica(const char* palavra) {
    char p = 'p';
    int tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++) {
        char c = palavra[i];
        switch (p) {
            case 'p':
                if (c == '0')
                    p = '1';
                else if (c == '1')
                    p = '2';
                else
                    return 0;
                break;
            case '1':
                if (c == '0' || c == '1')
                    p = '1';
                else
                    return 0;
                break;
            case '2':
                if (c == '0' || c == '1')
                    p = '2';
                else
                    return 0;
                break;
        }
    }

    return p == '1' || p == '2';
}