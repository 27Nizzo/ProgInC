#include <stdio.h>
#include <math.h>

int main() {
    int num_tests;
    if (scanf("%d", &num_tests) != 1) {
        fprintf(stderr, "Error: Invalid input format.\n");
        return 1;
    }

    for (int i = 0; i < num_tests; ++i) {
        int exponent, mantissa;
        char sign;
        if (scanf("%d %d %c", &exponent, &mantissa, &sign) != 3) {
            fprintf(stderr, "Error: Invalid test case format.\n");
            return 1;
        }

        if (exponent < 1 || exponent > 5 || mantissa < 1 || mantissa > 7) {
            fprintf(stderr, "Error: Invalid parameter values.\n");
            return 1;
        }

        double fraction = 0.0;
        for (int j = exponent + mantissa; j >= exponent + 1; --j) {
            if (sign == '1') {
                fraction += pow(2.0, -(j - exponent));
            }
        }

        int bias = pow(2, exponent - 1) - 1;
        int adjusted_exponent = exponent - bias;

        if (adjusted_exponent == -bias) {
            ++adjusted_exponent;
            if (fraction == 0.0) {
                printf((sign == '-') ? "-0\n" : "0\n");
            } else {
                double normalized_value = fraction * pow(2.0, adjusted_exponent);
                printf("%lg\n", (sign == '-') ? -normalized_value : normalized_value);
            }
        } else if (adjusted_exponent == pow(2, exponent - 1)) {
            printf((fraction == 0.0) ? ((sign == '-') ? "-Infinity\n" :"+Infinity\n") : "NaN\n");
        } else {
            double normalized_value = (1.0 + fraction) * pow(2.0, adjusted_exponent);
            printf("%lg\n", (sign == '-') ? -normalized_value : normalized_value);
        }
    }

    return 0;
}
