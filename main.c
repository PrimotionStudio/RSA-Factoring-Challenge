#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

long long int _atoi(const char *str) {
    long long int result = 0, sign = 1;
    while (*str == ' ') {
        str++;
    }
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    result *= sign;
    return result;
}

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
    FILE *fp;
    char buffer[10000];
    long long int val1, val2, product;

    if (ac != 2) {
        fprintf(stderr, "Usage: %s <file>\n", (char *)av[0]);
        exit(EXIT_FAILURE);
    }
    fp = fopen((char *)av[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: Can't open file %s\n", (char *)av[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, 10000, fp)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        product = (long long int)_atoi(buffer);

        if (is_prime(product)) {
            printf("%lld=%lld*%lld\n", product, product, 1LL);
        } else {
            for (val1 = 2; val1 * val1 <= product; val1++) {
                if (product % val1 == 0) {
                    val2 = product / val1;
                    printf("%lld=%lld*%lld\n", product, val2, val1);
                    break;
                }
            }
        }
    }

    fclose(fp);
    return 0;
}