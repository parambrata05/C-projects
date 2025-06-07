#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846

// Function to calculate factorial
unsigned long long factorial(int x) {
    if (x == 0 || x == 1) return 1;
    unsigned long long fact = 1;
    for (int i = 2; i <= x; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    printf("Please enter choice:\n");
    printf("1 for +\n2 for -\n3 for *\n4 for /\n5 for square root\n6 for cube root\n");
    printf("7 for nPr\n8 for nCr\n9 for a^b\n10 for log base a of b\n");
    printf("11 for Trigonometric operations\n");

    int choice;
    scanf("%d", &choice);

    int n, r;
    double a, b, result;
    char trig_choice[10];

    switch (choice) {
        case 1:  // Addition
            printf("Enter number of numbers to be added: ");
            scanf("%d", &n);
            result = 0;
            for (int i = 1; i <= n; i++) {
                printf("Enter number %d: ", i);
                scanf("%lf", &a);
                result += a;
            }
            printf("Sum = %lf\n", result);
            break;

        case 2:  // Subtraction
            printf("Enter number of numbers to be subtracted: ");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                printf("Enter number %d: ", i);
                scanf("%lf", &a);
                if (i == 1)
                    result = a;
                else
                    result -= a;
            }
            printf("Result = %lf\n", result);
            break;

        case 3:  // Multiplication
            printf("Enter number of numbers to be multiplied: ");
            scanf("%d", &n);
            result = 1;
            for (int i = 1; i <= n; i++) {
                printf("Enter number %d: ", i);
                scanf("%lf", &a);
                result *= a;
            }
            printf("Product = %lf\n", result);
            break;

        case 4:  // Division
            printf("Enter number of numbers to divide (first ÷ rest): ");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                printf("Enter number %d: ", i);
                scanf("%lf", &a);
                if (i == 1)
                    result = a;
                else {
                    if (a == 0) {
                        printf("Error: Division by zero!\n");
                        return 1;
                    }
                    result /= a;
                }
            }
            printf("Quotient = %lf\n", result);
            break;

        case 5:  // Square root
            printf("Enter number to find square root: ");
            scanf("%lf", &a);
            if (a < 0) {
                printf("Error: Cannot find square root of a negative number!\n");
            } else {
                result = sqrt(a);
                printf("Square root = %lf\n", result);
            }
            break;

        case 6:  // Cube root
            printf("Enter number to find cube root: ");
            scanf("%lf", &a);
            result = cbrt(a);
            printf("Cube root = %lf\n", result);
            break;

        case 7:  // Permutation
            printf("Enter n and r for nPr: ");
            scanf("%d %d", &n, &r);
            if (n < r || n < 0 || r < 0) {
                printf("Invalid input! n should be >= r and non-negative.\n");
            } else {
                result = (double)factorial(n) / factorial(n - r);
                printf("Permutation (nPr) = %lf\n", result);
            }
            break;

        case 8:  // Combination
            printf("Enter n and r for nCr: ");
            scanf("%d %d", &n, &r);
            if (n < r || n < 0 || r < 0) {
                printf("Invalid input! n should be >= r and non-negative.\n");
            } else {
                result = (double)factorial(n) / (factorial(r) * factorial(n - r));
                printf("Combination (nCr) = %lf\n", result);
            }
            break;

        case 9:  // Power a^b
            printf("Enter base (a): ");
            scanf("%lf", &a);
            printf("Enter exponent (b): ");
            scanf("%lf", &b);
            result = pow(a, b);
            printf("%lf ^ %lf = %lf\n", a, b, result);
            break;

        case 10:  // Logarithm
            printf("Enter number: ");
            scanf("%lf", &a);
            printf("Enter base: ");
            scanf("%lf", &b);
            if (a <= 0 || b <= 0 || b == 1) {
                printf("Error: Invalid input for logarithm.\n");
            } else {
                result = log(a) / log(b);
                printf("log base %lf of %lf = %lf\n", b, a, result);
            }
            break;

        case 11:  // Trigonometric operations
            printf("Enter operation (sin, cos, tan, cot, sec, cosec, asin, acos, atan): ");
            scanf("%s", trig_choice);

            if (strcmp(trig_choice, "asin") == 0 || strcmp(trig_choice, "acos") == 0 || strcmp(trig_choice, "atan") == 0) {
                printf("Enter value (range: -1 to 1 for asin/acos): ");
                scanf("%lf", &a);
                if ((strcmp(trig_choice, "asin") == 0 || strcmp(trig_choice, "acos") == 0) && (a < -1 || a > 1)) {
                    printf("Invalid input: domain error.\n");
                    break;
                }

                if (strcmp(trig_choice, "asin") == 0) result = asin(a) * (180 / PI);
                else if (strcmp(trig_choice, "acos") == 0) result = acos(a) * (180 / PI);
                else result = atan(a) * (180 / PI);

                printf("Result (in degrees) = %lf\n", result);
            } else {
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                double radians = a * PI / 180;

                if (strcmp(trig_choice, "sin") == 0) result = sin(radians);
                else if (strcmp(trig_choice, "cos") == 0) result = cos(radians);
                else if (strcmp(trig_choice, "tan") == 0) result = tan(radians);
                else if (strcmp(trig_choice, "cot") == 0) result = 1.0 / tan(radians);
                else if (strcmp(trig_choice, "sec") == 0) result = 1.0 / cos(radians);
                else if (strcmp(trig_choice, "cosec") == 0) result = 1.0 / sin(radians);
                else {
                    printf("Invalid trigonometric function.\n");
                    break;
                }

                printf("Result = %lf\n", result);
            }
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
