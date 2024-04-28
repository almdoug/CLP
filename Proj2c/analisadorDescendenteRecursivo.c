// Douglas Benevides Almeida

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int operador(char c);
int espaco(char c);
void consomeEspaco(char **str);
void expr(char **str);
void term(char **str);
void factor(char **str);


int main() {
    char entrada[100];

    FILE *arquivo = fopen("expressoes.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("===================================\n\n");

    while (fgets(entrada, sizeof(entrada), arquivo)) {
        char *ptr = entrada;

        printf("Analisando: %s\n", entrada); // Print da linha lida
        expr(&ptr);
        consomeEspaco(&ptr);
        
        if (*ptr != '\0') {
            printf("\n[x] Erro: Caracteres adicionais apos a expressao\n");
        } else {
            printf("\n[v] Sucesso: aceito.\n");
        }
        
        printf("\n===================================\n\n");
    }

    fclose(arquivo);
    return 0;
}

// Verifica se um caractere é um operador
int operador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Verifica se um caractere é um espaco em branco
int espaco(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

void consomeEspaco(char **str) {
    while (espaco(**str))
        (*str)++;
}

void expr(char **str) {
    term(str);
    while (**str == '+' || **str == '-') {
        printf("<expr> -> <term>\n");
        (*str)++;
        term(str);
    }
}

void term(char **str) {
    factor(str);
    while (**str == '*' || **str == '/') {
        printf("<term> -> <factor>\n");
        (*str)++;
        factor(str);
    }
}

void factor(char **str) {
    if (isdigit(**str)) {
        printf("<factor> -> int_constant\n");
        while (isdigit(**str))
            (*str)++;
    } else if (**str == '(') {
        printf("<factor> -> ( <expr> )\n");
        (*str)++;
        expr(str);
        if (**str != ')')
            printf("Esta faltando o caractere ')' após a expressao dentro dos parenteses");
        (*str)++;
    } else {
        printf("<factor> -> id\n");
    }
}