#include <stdio.h>
#include <stdint.h>
#include "fdacoefs_float_double.h"

#define BUFFER_SIZE 11
#define COEFF_SIZE 123 // Wykorzystujemy rozmiar zdefiniowany w pliku nagłówkowym
#define Q15_SCALE (1 << 15) // Skalowanie do Q15: 2^15

// Funkcja realizująca filtrację FIR na danych stałoprzecinkowych (Q15)
int16_t filtrFIR_fixed(int16_t bufor[], int16_t coeff[], int idx_probki, int N)
{
    int32_t output = 0;
    for (int i = 0; i < N; i++) {
        int buf_idx = (idx_probki - i + N) % N;
        output += (int32_t)bufor[buf_idx] * (int32_t)coeff[i];
    }
    return (int16_t)(output / Q15_SCALE); // Skalowanie wyniku z Q15
}

// Funkcja konwertująca współczynniki z floating point na Q15
void konwertujNaQ15(const double wspolczynniki_float[], int16_t wspolczynniki_fixed[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++) {
        wspolczynniki_fixed[i] = (int16_t)(wspolczynniki_float[i] * Q15_SCALE);
    }
}

int main() {
    // Tablice przechowujące próbki wejściowe, współczynniki i wyniki
    int16_t bufor[BUFFER_SIZE] = {0};
    int16_t wspolczynniki_fixed[COEFF_SIZE] = {0};
    double wspolczynniki_float[COEFF_SIZE] = {0};
    double probki_wejsciowe[BUFFER_SIZE] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double probki_wyjsciowe[COEFF_SIZE] = {0};

    // Konwersja współczynników z pliku nagłówkowego z floating point na Q15
    konwertujNaQ15(B, wspolczynniki_fixed, COEFF_SIZE);

    // Symulacja filtracji dla danych stałoprzecinkowych (Q15)
    printf("Wyniki dla danych staloprzecinkowych :\n");
    for (int i = 0; i < COEFF_SIZE; i++) {
        // Wprowadzenie próbki do bufora
        bufor[i % BUFFER_SIZE] = (int16_t)(probki_wejsciowe[i % BUFFER_SIZE] * Q15_SCALE);
        // Filtracja próbki i zapisanie wyniku
        probki_wyjsciowe[i] = filtrFIR_fixed(bufor, wspolczynniki_fixed, i, COEFF_SIZE);
        

        printf("%.10f",probki_wyjsciowe[i]);
        printf(",");
        printf("\n");
    }

    return 0;
}
