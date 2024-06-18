% Douglas Benevides Almeida

% A significa A(M,N)

ackermann(0, N, A) :- A is N + 1.

ackermann(M, 0, A) :-   M > 0, M1 is M - 1,
                        ackermann(M1, 1, A).

ackermann(M, N, A) :-   M > 0, N > 0,
                        M1 is M - 1,
                        N1 is N - 1,
                        ackermann(M, N1, Temp),
                        ackermann(M1, Temp, A).
