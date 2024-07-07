#include <stdio.h>
#include <string.h>

int factorial(int n) {
    if (n == 0) return 1;
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    char word[14];
    int len;
    int an = 1;

    printf("Enter word (14 symbols max):\n");
    scanf("%13s", word);

    len = strlen(word);

    for (int i = len; i > 0; i--) {
        an *= i;
    }

    int letter_counts[256] = {0};

    for (int i = 0; i < len; i++) {
        letter_counts[(int)word[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (letter_counts[i] > 0) {
            an /= factorial(letter_counts[i]);
        }
    }

    printf("Quantity of anagrams: %d\n", an);

    return 0;
}
