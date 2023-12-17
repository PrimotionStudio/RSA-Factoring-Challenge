#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int is_prime(long long int num) {
    if (num < 2) {
        return 0;  // Not prime
    }
    for (long long int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // Not prime
        }
    }
    return 1;  // Prime
}

int main(int ac, char const *av[]) {
    if (ac != 2) {
        fprintf(stderr, "Usage: %s <file>\n", (char *)av[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(av[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: Can't open file %s\n", (char *)av[1]);
        exit(EXIT_FAILURE);
    }

    char buffer[10000];
    long long int product;

    while (fgets(buffer, 10000, fp)) {
        product = atoll(buffer);

        for (long long int val1 = 2; val1 * val1 <= product; val1++) {
            if (product % val1 == 0 && is_prime(val1)) {
                long long int val2 = product / val1;
                if (is_prime(val2)) {
                    printf("%lld=%lld*%lld\n", product, val1, val2);
                    break;
                }
            }
        }
    }

    fclose(fp);
    return 0;
}
