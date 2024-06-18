%Douglas Benevides Almeida

phi(M, N, 0, Result) :- Result is M + N.
phi(_, 0, 1, 0).
phi(_, 0, 2, 1).
phi(M, 0, P, M) :- P > 2.

% Caso recursivo: phi(m, n, p) = phi(m, phi(m, n-1, p), p-1), n e p > 0
phi(M, N, P, Result) :-
                        N > 0, 
                        P > 0,
                        N1 is N - 1,
                        P1 is P - 1,
                        phi(M, N1, P, Result2),
                        phi(M, Result2, P1, Result).