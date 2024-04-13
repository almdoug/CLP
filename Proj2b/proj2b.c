#include <stdio.h>
#include <stdlib.h>

const char* validarGramatica(const char* str);

int main() {
    FILE *arq;
    arq = fopen("palavras.txt", "r");
    // Verifica se o arquivo foi aberto corretamente
    if (arq == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        return 1;
    }

    char palavra[100];
    // Lê cada palavra do arquivo e imprime se pertence ou não à gramática
    while (fscanf(arq, "%s", palavra) != EOF) {
        printf("%s -> %s\n", palavra, validarGramatica(palavra));
    }

    // Fecha o arquivo
    fclose(arq);
    return 0;
}

int topo, indice;
// Função para adicionar um caractere à pilha
void push(char *pilha, char caractere){
    topo++;
    pilha[topo] = caractere;
}

// Obter o próximo token (caractere) da string
char obtemToken(const char* str){
    return str[indice++];
}

// Remover o elemento do topo da pilha
void pop(){
    topo--;
}

// Valida se uma string pertence à gramática especificada
const char* validarGramatica(const char* str) { 
    topo = -1; // Inicializa o topo da pilha com -1
    indice = 0;

    char pilha[7]; // Pilha para controle dos estados
    char tokenAtual; // Armazena o token atual

    estado_q0:
        push(pilha, 'S'); // Inicia com o estado S
        tokenAtual = obtemToken(str); // Obtém o primeiro token
    goto estado_q1;

    estado_q1:
        // Verifica as transições possíveis e atualiza a pilha conforme a gramática
        if((tokenAtual=='a' && pilha[topo]=='S') ||
           (tokenAtual=='b' && pilha[topo]=='S')) { 
            pop(); 
            push(pilha, 'b'); //
            push(pilha, 'S'); // push -> aSb
            push(pilha, 'a'); //
        } else if (tokenAtual=='c' && pilha[topo]=='S') { pop(); push(pilha, 'c'); } // Transição para c
        else if (tokenAtual=='a' && pilha[topo]=='a') { pop(); tokenAtual = obtemToken(str);} // Consome a
        else if (tokenAtual=='b' && pilha[topo]=='b') { pop(); tokenAtual = obtemToken(str);} // Consome b
        else if (tokenAtual=='c' && pilha[topo]=='c') { pop(); tokenAtual = obtemToken(str);} // Consome c
        else if (tokenAtual=='\0') { // Se chegou ao final da string
            if (topo)
                return "[v] Pertence a gramatica"; // Se a pilha estiver vazia, pertence à gramática
            return "[x] Nao pertence a gramatica"; // Caso contrário, não pertence
        } else {
            return "[x] Nao pertence a gramatica"; // Qualquer outra situação, não pertence
        }
    goto estado_q1; // Retorna ao estado q1 para processar o próximo token
}
