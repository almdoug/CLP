%Douglas Benevides Almeida

mesclar([], L, L).
mesclar(L, [], L).
mesclar([X|Tx], [Y|Ty], [X|T]) :- X =< Y, mesclar(Tx, [Y|Ty], T).
mesclar([X|Tx], [Y|Ty], [Y|T]) :- X > Y, mesclar([X|Tx], Ty, T).

% Divide a lista em duas metades
dividir(Lista, Esq, Dir) :-
    length(Lista, Len),
    HalfLen is Len // 2,
    length(Esq, HalfLen),
    append(Esq, Dir, Lista).

% Aplica o Merge Sort
merge_sort([], []).
merge_sort([X], [X]).
merge_sort(Lista, Sorted) :-
    dividir(Lista, Esq, Dir),
    merge_sort(Esq, EsqOrdenada),
    merge_sort(Dir, DirOrdenada),
    mesclar(EsqOrdenada, DirOrdenada, Sorted).


% Troca dois elementos em uma lista
trocar([X,Y|T], [Y,X|T]) :- X > Y.
trocar([Z|T1], [Z|T2]) :- trocar(T1, T2).

% Aplica o Bubble Sort na lista
bubble_sort(Lista, Sorted) :-
    trocar(Lista, Lista1),
    !, bubble_sort(Lista1, Sorted).
bubble_sort(Sorted, Sorted).


% Divide a lista em elementos menores e maiores que o pivô
particionar(_, [], [], []).
particionar(Pivo, [X|Resto], [X|Menores], Maiores) :-
    X =< Pivo,
    particionar(Pivo, Resto, Menores, Maiores).
particionar(Pivo, [X|Resto], Menores, [X|Maiores]) :-
    X > Pivo,
    particionar(Pivo, Resto, Menores, Maiores).

% Predicado para aplicar o Quick Sort
quick_sort([], []).
quick_sort([Pivo|Resto], Sorted) :-
    particionar(Pivo, Resto, Menores, Maiores),
    quick_sort(Menores, MenoresOrdenados),
    quick_sort(Maiores, MaioresOrdenados),
    append(MenoresOrdenados, [Pivo|MaioresOrdenados], Sorted).


% Predicado para inserir um elemento em uma lista ordenada
inserir(X, [], [X]).
inserir(X, [Y|Resto], [X,Y|Resto]) :- X =< Y.
inserir(X, [Y|Resto], [Y|ListaOrdenada]) :- X > Y, inserir(X, Resto, ListaOrdenada).

% Predicado para ordenar uma lista usando Insertion Sort
insertion_sort([], []).
insertion_sort([X|Resto], Sorted) :-
    insertion_sort(Resto, SortedResto),
    inserir(X, SortedResto, Sorted).


:- use_module(library(random)).
:- use_module(library(lists)).
:- use_module(library(csv)).
:- use_module(library(statistics)).

% Predicado para gerar uma lista aleatória de tamanho N
gerar_lista_aleatoria(N, Lista) :-
    length(Lista, N),
    maplist(random(0, 1000), Lista).

% Predicado para medir o tempo medio de execução de um algoritmo de ordenação
medir_tempo_medio(Algoritmo, TamanhoLista, TempoMedio) :-
    statistics(cpu_time, _),
    gerar_lista_aleatoria(TamanhoLista, Lista),
    call(Algoritmo, Lista, _), % Chama o algoritmo de ordenação
    statistics(cpu_time, [_, TempoExecucao]),
    TempoMedio is TempoExecucao / 1000.

% Predicados para todos os algoritmos de ordenação
algoritmo(merge_sort, merge_sort).
algoritmo(bubble_sort, bubble_sort).
algoritmo(quick_sort, quick_sort).
algoritmo(insertion_sort, insertion_sort).

% Predicado para medir e salvar os tempos medios em um arquivo CSV
medir_e_salvar_tempos :-
    Tamanhos = [10, 100, 1000],
    Algoritmos = [merge_sort, bubble_sort, quick_sort, insertion_sort],
    cabecalho =.. [row, 'Tamanho da Lista', 'Merge Sort', 'Bubble Sort', 'Quick Sort', 'Insertion Sort'],
    atomic_list_concat(Algoritmos, ',', CabecalhoAlgoritmos),
    atomic_concat('result_ordenacao_prolog.csv', CabecalhoAlgoritmos, NomeArquivo),
    open(NomeArquivo, write, Arquivo, [type(binary)]),
    write(Arquivo, cabecalho),
    nl(Arquivo),
    foreach(member(Tamanho, Tamanhos),
            (   maplist(medir_tempo_medio(Tamanho), Algoritmos, TemposMedios),
                atomic_list_concat([Tamanho|TemposMedios], ',', LinhaCSV),
                write(Arquivo, LinhaCSV),
                nl(Arquivo)
            )),
    close(Arquivo).
