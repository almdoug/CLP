// Douglas Benevides Almeida

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 1000
#define TAM_MAX_CHAR 1000
#define N_AR 5
#define CONST_A 5
#define CONST_B 3
#define CONST_C 2

// Estrutura da pilha
typedef struct {
    int elementos[TAM_MAX];
    int topo;
} Pilha;

Pilha pilhaPrincipal, pilhaProducoes;
int arvoreNaria[TAM_MAX], arvoreBinaria[TAM_MAX], tamanhoArvoreBinaria = 0, npr[TAM_MAX], tamanhoNpr = 0;

// Inicializar
void inicializaPilha(int valor, Pilha* pilha) {
    pilha->topo = 0;
    pilha->elementos[pilha->topo] = valor;
}

// Resetar
void resetaPilha(Pilha* pilha) {
    pilha->topo = -1;
}

// Imprimir pilha
void imprimePilha(Pilha* pilha) {
    printf("Pilha: ");
    for(int i = pilha->topo; i >= 0; i--) {
        printf("%d /", pilha->elementos[i]);
    }
    printf("\n");
}

// Empilhar na pilha
void push(int valor, Pilha* pilha) {
    if (pilha->topo < TAM_MAX - 1) {
        pilha->elementos[++pilha->topo] = valor;
    }
    else {
        printf("Estouro de pilha\n");
    }
}

// Remover da pilha
int pop(Pilha* pilha) {
    if (pilha->topo >= 0) {
        int valor = pilha->elementos[pilha->topo];
        pilha->elementos[pilha->topo--] = '\0';
        return valor;
    }
    else {
        printf("Pilha vazia\n");
        return -1;
    }
}

// Controi uma árvore a partir das produções
void constroiArvoreNaria() {
    int n;
    for(int i = 0; i <= pilhaProducoes.topo; i++) {
        switch(pilhaProducoes.elementos[i]) {
            case 0:
                arvoreNaria[0] = 'E';
                inicializaPilha(0, &pilhaPrincipal);
                break;
            case 1:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = '(';
                arvoreNaria[N_AR*n+2] = 'E';
                arvoreNaria[N_AR*n+3] = 'X';
                arvoreNaria[N_AR*n+4] = 'E';
                arvoreNaria[N_AR*n+5] = ')';
                push(N_AR*n+4, &pilhaPrincipal);
                push(N_AR*n+3, &pilhaPrincipal);
                push(N_AR*n+2, &pilhaPrincipal);
                break;
            case 2:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = '0';
                break;
            case 3:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = '1';
                break;
            case 4:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = 'a';
                break;
            case 5:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = 'b';
                break;
            case 6:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = 'c';
                break;
            case 7:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = '+';
                break;
            case 8:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = '-';
                break;
            case 9:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = '*';
                break;
            case 10:
                n = pop(&pilhaPrincipal);
                arvoreNaria[N_AR*n+1] = '/';
                break;
        }
    }
}

// Imprimir arvore
void imprimeArvore(int* arvore) {
    for(int i = 0; i < TAM_MAX; i++) {
        if(arvore[i] != 0) {
            printf("|%3d", i);
        }
    }
    printf("|\n");
    for(int i = 0; i < TAM_MAX; i++) {
        if(arvore[i] != 0) {
            printf("| %c ", arvore[i]);
        }
    }
    printf("|\n");
}

// Imprimir arvore pos ordem
void imprimePosOrdem(int* arvore, int n, int indice) {
    if (indice >= n)
        return;
    int filhoEsquerdo = 2 * indice + 1;
    int filhoDireito = 2 * indice + 2;
    imprimePosOrdem(arvore, n, filhoEsquerdo);
    imprimePosOrdem(arvore, n, filhoDireito);
    printf("%c ", arvore[indice]);
    npr[tamanhoNpr++] = arvore[indice];
}

// Converter para binario
void converteParaBinario() {
    for(int i = 0; i < TAM_MAX; i++) {
        if(arvoreNaria[i] == '(' || arvoreNaria[i] == ')') {
            arvoreNaria[i] = 0;
        }
        else if(arvoreNaria[i] == '0' || arvoreNaria[i] == '1' || arvoreNaria[i] == 'a' || arvoreNaria[i] == 'b' || arvoreNaria[i] == 'c') {
            int pai = (i - 1)/5;
            arvoreNaria[pai] = arvoreNaria[i];
            arvoreNaria[i] = 0;
        }
        else if(arvoreNaria[i] == '+' || arvoreNaria[i] == '-' || arvoreNaria[i] == '*' || arvoreNaria[i] == '/') {
            int pai = (i-1)/N_AR;
            int avo = (pai-3)/N_AR;
            arvoreNaria[avo] = arvoreNaria[i];
            arvoreNaria[pai] = 0;
            arvoreNaria[i] = 0;
        }
    }
    for(int i = 0; i < TAM_MAX; i++) {
        if(arvoreNaria[i] != 0) {
            arvoreBinaria[tamanhoArvoreBinaria++] = arvoreNaria[i];
        }
    }
}

// Gerar pcode
void geraPcode() {
    int x, y;
    for(int i = 0; i < tamanhoNpr; i++) {
        switch(npr[i]) {
            case '0':
                printf("LIT 0 0\n");
                push(0, &pilhaPrincipal);
                break;
            case '1':
                printf("LIT 0 1\n");
                push(1, &pilhaPrincipal);
                break;
            case 'a':
                printf("LOD 0 3\n");
                push(CONST_A, &pilhaPrincipal);
                break;
            case 'b':
                printf("LOD 0 4\n");
                push(CONST_B, &pilhaPrincipal);
                break;
            case 'c':
                printf("LOD 0 5\n");
                push(CONST_C, &pilhaPrincipal);
                break;
            case '+':
                printf("OPR 0 2\n");
                y = pop(&pilhaPrincipal);
                x = pop(&pilhaPrincipal);
                push(x+y, &pilhaPrincipal);
                break;
            case '-':
                printf("OPR 0 3\n");
                y = pop(&pilhaPrincipal);
                x = pop(&pilhaPrincipal);
                push(x-y, &pilhaPrincipal);
                break;
            case '*':
                printf("OPR 0 4\n");
                y = pop(&pilhaPrincipal);
                x = pop(&pilhaPrincipal);
                push(x*y, &pilhaPrincipal);
                break;
            case '/':
                printf("OPR 0 5\n");
                y = pop(&pilhaPrincipal);
                x = pop(&pilhaPrincipal);
                push(x/y, &pilhaPrincipal);
                break;
        }
    }
}

// Analisador
int analisador(char* palavra) {
    for(int i = 0; palavra[i] != '\0'; i++) {
        if(palavra[i] == '\r' || palavra[i] == '\n') {
            palavra[i] = '\0';
            break;
        }
    }
    int indice = 0;
    
    inicializaPilha('E', &pilhaPrincipal);
    inicializaPilha(0, &pilhaProducoes);
    
    while (palavra[indice] != '\0') {
        // Produções
        if      (palavra[indice]=='(' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='E') { pop(&pilhaPrincipal); push(')', &pilhaPrincipal); push('E', &pilhaPrincipal); push('X', &pilhaPrincipal); push('E', &pilhaPrincipal); push('(', &pilhaPrincipal); push(1, &pilhaProducoes); }
        else if (palavra[indice]=='0' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='E') { pop(&pilhaPrincipal); push('0', &pilhaPrincipal); push(2, &pilhaProducoes); }
        else if (palavra[indice]=='1' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='E') { pop(&pilhaPrincipal); push('1', &pilhaPrincipal); push(3, &pilhaProducoes); }
        else if (palavra[indice]=='a' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='E') { pop(&pilhaPrincipal); push('a', &pilhaPrincipal); push(4, &pilhaProducoes); }
        else if (palavra[indice]=='b' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='E') { pop(&pilhaPrincipal); push('b', &pilhaPrincipal); push(5, &pilhaProducoes); }
        else if (palavra[indice]=='c' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='E') { pop(&pilhaPrincipal); push('c', &pilhaPrincipal); push(6, &pilhaProducoes); }
        else if (palavra[indice]=='+' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='X') { pop(&pilhaPrincipal); push('+', &pilhaPrincipal); push(7, &pilhaProducoes); }
        else if (palavra[indice]=='-' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='X') { pop(&pilhaPrincipal); push('-', &pilhaPrincipal); push(8, &pilhaProducoes); }
        else if (palavra[indice]=='*' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='X') { pop(&pilhaPrincipal); push('*', &pilhaPrincipal); push(9, &pilhaProducoes); }
        else if (palavra[indice]=='/' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='X') { pop(&pilhaPrincipal); push('/', &pilhaPrincipal); push(10, &pilhaProducoes); }
        // Leituras
        else if (palavra[indice]=='a' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='a') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]=='b' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='b') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]=='c' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='c') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]=='0' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='0') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]=='1' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='1') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]=='(' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='(') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]==')' && pilhaPrincipal.elementos[pilhaPrincipal.topo]==')') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]=='+' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='+') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]=='-' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='-') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]=='*' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='*') { pop(&pilhaPrincipal); indice++; }
        else if (palavra[indice]=='/' && pilhaPrincipal.elementos[pilhaPrincipal.topo]=='/') { pop(&pilhaPrincipal); indice++; }
        // Exceção
        else    { printf("Caractere invalido. Codigo ASCII: %d\n", palavra[indice]); return 0; }
    }

    if (pilhaPrincipal.topo != -1) {
        return 0;
    }
    return 1;
}

void reseta() {
    for(int i = 0; i < TAM_MAX; i++) {
        arvoreNaria[i] = 0;
        arvoreBinaria[i] = 0;
        npr[i] = 0;
    }
    tamanhoArvoreBinaria = 0;
    tamanhoNpr = 0;
    resetaPilha(&pilhaPrincipal);
    resetaPilha(&pilhaProducoes);
}

void divider() {
    printf("\n=============================================================================================\n");
}

int main() {
    FILE *fp = fopen("entrada.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de entrada");
        return 1;
    }

    char palavra[TAM_MAX_CHAR];

    while(!feof(fp)) {
        reseta();
        fgets(palavra, TAM_MAX_CHAR, fp);
        divider();
        printf(analisador(palavra) ? "\n%s - reconhecida.\n" : "%s Nao reconhecida.\n", palavra);

        constroiArvoreNaria();
        divider();
        printf("\nArvore n-aria:\n\n");
        imprimeArvore(arvoreNaria);

        converteParaBinario();
        divider();
        printf("\nArvore binaria:\n\n");
        imprimeArvore(arvoreBinaria);

        divider();
        printf("\nNPR da arvore binaria:\n\n");
        imprimePosOrdem(arvoreBinaria, tamanhoArvoreBinaria, 0);
        printf("\n");

        divider();
        printf("\nNPR para p-code:\n\n");
        geraPcode();
        divider();
    }

    fclose(fp);
    return 0;
}