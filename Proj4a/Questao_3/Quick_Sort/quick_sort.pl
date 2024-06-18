% Predicado para dividir a lista em elementos menores e maiores que o pivô
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
