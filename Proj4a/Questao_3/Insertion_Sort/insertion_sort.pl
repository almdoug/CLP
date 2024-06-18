%Douglas Benevides Almeida
inserir(X, [], [X]).
inserir(X, [Y|Resto], [X,Y|Resto]) :- X =< Y.
inserir(X, [Y|Resto], [Y|ListaOrdenada]) :- X > Y, inserir(X, Resto, ListaOrdenada).

% Ordena uma lista usando Insertion Sort
insertion_sort([], []).
insertion_sort([X|Resto], Sorted) :-
    insertion_sort(Resto, SortedResto),
    inserir(X, SortedResto, Sorted).
