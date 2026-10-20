
#include <stdio.h>
#include <math.h>

/**
 * @brief Перечисление доступных операций для работы с треугольником.
 * 
 * Используется в главном меню программы для управления логикой switch-case.
 */
enum TriangleOperation {
    /** @brief Операция для вычисления только периметра треугольника */
    OP_PERIMETER = 1,
    
    /** @brief Операция для вычисления только площади треугольника */
    OP_AREA,
    
    /** @brief Операция для одновременного вычисления и периметра, и площади */
    OP_BOTH,
    
    /** @brief Выход из управляющего меню и завершение программы */
    OP_EXIT
};

/**
 * @brief Вычисляет расстояние между двумя точками (длину стороны) по их координатам
 * @param x1 Координата X первой точки
 * @param y1 Координата Y первой точки
 * @param x2 Координата X второй точки
 * @param y2 Координата Y второй точки
 * @return Расстояние между точками в виде double
 */
double get_side_length(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/**
 * @brief Вычисляет периметр треугольника по длинам трех сторон
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @param c Длина третьей стороны
 * @return Вычисленный периметр
 */
double calculate_perimeter(double a, double b, double c) {
    return a + b + c;
}

/**
 * @brief Вычисляет площадь треугольника по формуле Герона
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @param c Длина третьей стороны
 * @return Вычисленная площадь
 */
double calculate_area(double a, double b, double c) {
    double p = (a + b + c) / 2.0; // Полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении, иначе 1
 */
int main() {
    // Переменные для хранения координат трех вершин треугольника
    double x1, y1;
    double x2, y2;
    double x3, y3;
    int choice;

    // 1. Ввод координат вершин треугольника
    printf("Введите координаты первой вершины (x1 y1): ");
    if (scanf("%lf %lf", &x1, &y1) != 2) return 1;

    printf("Введите координаты второй вершины (x2 y2): ");
    if (scanf("%lf %lf", &x2, &y2) != 2) return 1;

    printf("Введите координаты третьей вершины (x3 y3): ");
    if (scanf("%lf %lf", &x3, &y3) != 2) return 1;

    // 2. Расчет длин сторон по координатам
    double a = get_side_length(x1, y1, x2, y2);
    double b = get_side_length(x2, y2, x3, y3);
    double c = get_side_length(x3, y3, x1, y1);

    // Проверка существования треугольника (не лежат ли точки на одной прямой)
    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Ошибка: Треугольник с такими координатами не существует (точки лежат на одной линии).\n");
        return 1;
    }

    // 3. Меню выбора операции
    printf("\nВыберите операцию:\n");
    printf("%d - Найти периметр\n", OP_PERIMETER);
    printf("%d - Найти площадь\n", OP_AREA);
    printf("%d - Найти и периметр, и площадь\n", OP_BOTH);
    printf("%d - Выход\n", OP_EXIT);
    printf("Ваш выбор: ");
    if (scanf("%d", &choice) != 1) return 1;

    double P = 0.0;
    double S = 0.0;

    // 4. Логика switch-case с использованием enum
    switch ((enum TriangleOperation)choice) {
        case OP_PERIMETER:
            P = calculate_perimeter(a, b, c);
            printf("\nПериметр треугольника: P = %.4f\n", P);
            break;

        case OP_AREA:
            S = calculate_area(a, b, c);
            printf("\nПлощадь треугольника: S = %.4f\n", S);
            break;

        case OP_BOTH:
            P = calculate_perimeter(a, b, c);
            S = calculate_area(a, b, c);
            printf("\nПериметр: P = %.4f\nПлощадь: S = %.4f\n", P, S);
            break;

        case OP_EXIT:
            printf("\nВыход из программы.\n");
            break;

        default:
            printf("\nОшибка: Неверный пункт меню.\n");
            break;
    }

    return 0;
}
