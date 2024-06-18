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
