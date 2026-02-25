Fs = 200;           % Częstotliwość próbkowania [Hz]
Fc = 40;            % Częstotliwość odcięcia [Hz]
N = 31;             % Rząd filtra (liczba wag)

% Projektowanie filtra dolnoprzepustowego metodą okna
h = fir1(N-1, Fc/(Fs/2), 'low', hamming(N));

% Wizualizacja odpowiedzi częstotliwościowej
freqz(h, 1, 1024, Fs);
title('Charakterystyka filtra EKG (40Hz Cutoff)');