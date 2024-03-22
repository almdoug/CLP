// Aluno: Douglas Benevides Almeida

#include <stdio.h>
#define amax 2047
#define levmax 3
#define cxmax 200
#define stacksize 500

enum fct
{
    lit,
    opr,
    lod,
    sto,
    cal,
    INT,
    jmp,
    jpc
};

typedef struct
{
    enum fct f; // tipo da função
    int l;      // nivel
    int a;      // argumento
} instruction;

instruction code[cxmax];
int s[stacksize];

int base(int l)
{
    int b1 = 1; // encontra base l níveis abaixo

    while (l > 0)
    {
        b1 = code[b1].a;
        l--;
    }
    return b1;
}

void interpretador()
{
    int p = 0, b = 1, t = 0; // registros program-, base-, topstack-
    instruction i;           // registro de instrução

    // espaços reservados
    s[1] = 0;
    s[2] = 0;
    s[3] = 0;

    int k = 0;
    // inicializando a pilha
    code[k].f = INT;
    code[k].l = 0;
    code[k].a = 6;
    k++;

    // Representacao de cont = 2
    code[k].f = lit;
    code[k].l = 0;
    code[k].a = 2;
    k++;
    code[k].f = sto;
    code[k].l = 0;
    code[k].a = 3;
    k++;

    // Representacao de do limite = 10
    code[k].f = lit;
    code[k].l = 0;
    code[k].a = 10;
    k++;
    code[k].f = sto;
    code[k].l = 0;
    code[k].a = 4;
    k++;
    // Representacao de soma = 1
    code[k].f = lit;
    code[k].l = 0;
    code[k].a = 1;
    k++;
    code[k].f = sto;
    code[k].l = 0;
    code[k].a = 5;
    k++;

    // Representacao de soma += cont
    code[k].f = lod;
    code[k].l = 0;
    code[k].a = 3;
    k++;
    code[k].f = lod;
    code[k].l = 0;
    code[k].a = 5;
    k++;
    code[k].f = opr;
    code[k].l = 0;
    code[k].a = 2;
    k++;
    code[k].f = sto;
    code[k].l = 0;
    code[k].a = 5;
    k++;

    // Representacao de cont++
    code[k].f = lod;
    code[k].l = 0;
    code[k].a = 3;
    k++;
    code[k].f = lod;
    code[k].l = 0;
    code[k].a = 4;
    k++;
    code[k].f = opr;
    code[k].l = 0;
    code[k].a = 10;
    k++;
    code[k].f = jpc;
    code[k].l = 0;
    code[k].a = 19;
    k++;
    code[k].f = lod;
    code[k].l = 0;
    code[k].a = 3;
    k++;
    code[k].f = opr;
    code[k].l = 0;
    code[k].a = 2;
    k++;
    code[k].f = sto;
    code[k].l = 0;
    code[k].a = 3;
    k++;

    // Finalizacao
    code[k].f = jmp;
    code[k].l = 0;
    code[k].a = 7;
    k++;
    code[k].f = opr;
    code[k].l = 0;
    code[k].a = 0;

    printf("\n   p    b    t                    Pilha");
    printf("\n|====|====|====|=========================================|");

    do
    {
        printf("\n| %2d | %2d | %2d | ", p, b, t);
        i = code[p++];

        switch (i.f)
        {
        case lit: // Coloca no topo o valor de 'i.a'
            t++;
            s[t] = i.a;
            break;
        case opr: // operações
            switch (i.a)
            {
            case 0: // Return
                t = b - 1;
                p = s[t + 3];
                b = s[t + 2];
                break;
            case 1: // neg
                s[t] = -s[t];
                break;
            case 2: // Soma
                t--;
                s[t] = s[t] + s[t + 1];
                break;
            case 3: // Subtração
                t--;
                s[t] = s[t] - s[t + 1];
                break;
            case 4: // Multiplicação
                t--;
                s[t] = s[t] * s[t + 1];
                break;
            case 5: // Divisão
                t--;
                s[t] = s[t] / s[t + 1];
                break;
            case 6: // Resto por 2
                s[t] = (s[t]) % 2;
                break;
            case 8: // Igualdade
                t--;
                s[t] = (s[t] == s[t + 1]);
                break;
            case 9: // Diferença
                t--;
                s[t] = (s[t] != s[t + 1]);
                break;
            case 10: // Menor que
                t--;
                s[t] = (s[t] < s[t + 1]);
                break;
            case 11: // Menor igual
                t--;
                s[t] = (s[t] <= s[t + 1]);
                break;
            case 12: // Maior que
                t--;
                s[t] = (s[t] > s[t + 1]);
                break;
            case 13: // Maior igual
                t--;
                s[t] = (s[t] >= s[t + 1]);
                break;
            }
            break;
        case lod:
            t++;
            s[t] = s[base(i.l) + i.a];
            break;
        case sto:
            s[base(i.l) + i.a] = s[t];
            t--;
            break;
        case cal:
            s[t + 1] = base(i.l);
            s[t + 2] = b;
            s[t + 3] = p;
            b = t + 1;
            p = i.a;
            break;
        case INT:
            t += i.a;
            break;
        case jmp:
            p = i.a;
            break;
        case jpc:
            if (s[t] == 0)
            {
                p = i.a;
                t--;
            }
            break;
        }
        for (int j = 1; j <= t; j++)
        {
            printf(" %d ", s[j]);
        }
    } while (p != 0);
}

int main()
{
    interpretador();
    return 0;
}