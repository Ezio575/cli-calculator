#include <stdio.h>  // для ввода-вывода
#include <stdlib.h> // для функции exit()
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Ошибка: деление на ноль невозможно!\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}
int main() {
    char operator;
    double num1, num2, result;

    printf("Добро пожаловать в CLI калькулятор!\n");

    while (1) {
        printf("\nВведите оператор (+, -, *, /) или 'q' для выхода: ");
        scanf(" %c", &operator);

        if (operator == 'q') {
            printf("Выход из программы. До свидания!\n");
            break;
        }

        if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
            printf("Неверный оператор. Попробуйте снова.\n");
            continue;
        }

        printf("Введите первое число: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Ошибка ввода числа.\n");
            break;
        }

        printf("Введите второе число: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Ошибка ввода числа.\n");
            break;
        }

        switch (operator) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Ошибка: деление на ноль невозможно!\n");
                    continue;
                }
                result = divide(num1, num2);
                break;
        }

        printf("Результат: %.2lf\n", result);
    }

    return 0;
}
