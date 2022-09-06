% Это факты
older(sasha, lesha, fact). % Саша старше Лёши
older(misha, sasha, fact). % Миша старше Саши
older(misha, dasha, fact). % Миша старше Даши
older(masha, misha, fact). % Маша старше Миши

% Это правило
older(X,Y, rule) :- older(X, Z, fact), older(Z,Y, _).

% X старше Y, если X старше Z и Z старше Y
% Проще: X > Y, если X > Z и Z > Y
%
% X, Y, Z - это переменные.
% Пролог перебирает все возможные X, Y, Z. 
% Вместо X, Y, Z подставляются misha, dasha, sasha, lesha
% Например: Миша старше Лёши, если Миша старше Саши и Саша старше Лёши