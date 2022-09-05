factorial(1, 1).
factorial(N, F):-
    N >= 0,
	N1 is N-1,
	factorial(N1, F1),
  F is F1*N.

% В Прологе пробелы, табуляция и новые строки работают также, как C/C++.
% Главное в конце закончить предикат точкой.

fib(1, 1).
fib(2, 1).

fib(N, F):-
    N >= 3,
    N1 is N-1,
    N2 is N-2,
    fib(N1, F1),
    fib(N2, F2),
    F is F1 + F2.
