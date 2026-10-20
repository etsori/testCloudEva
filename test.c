
#include <stdio.h>
#include <math.h>

/**
 * @brief Перечисление доступных операций для работы с треугольником.
 * @brief Операция для вычисления только периметра треугольника 
 * @brief Операция для вычисления только площади треугольника 
 * @brief Операция для одновременного вычисления и периметра, и площади
 * Используется в главном меню программы для управления логикой switch-case.
 */
enum TriangleOperation {
    PERIMETER = 1,
    AREA,
    BOTH,
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
double perimeter(double a, double b, double c) {
    return a + b + c;
}

/**
 * @brief Вычисляет площадь треугольника по формуле Герона
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @param c Длина третьей стороны
 * @return Вычисленная площадь
 */
double area(double a, double b, double c) {
    double p = (a + b + c) / 2.0; 
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении, иначе 1
 */
int main() {
    double x1, y1;
    double x2, y2;
    double x3, y3;
    int choice;

    printf("Введите координаты первой вершины (x1 y1): ");
    if (scanf("%lf %lf", &x1, &y1) != 2) return 1;

    printf("Введите координаты второй вершины (x2 y2): ");
    if (scanf("%lf %lf", &x2, &y2) != 2) return 1;

    printf("Введите координаты третьей вершины (x3 y3): ");
    if (scanf("%lf %lf", &x3, &y3) != 2) return 1;

    double a = get_side_length(x1, y1, x2, y2);
    double b = get_side_length(x2, y2, x3, y3);
    double c = get_side_length(x3, y3, x1, y1);


    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Ошибка: Треугольник с такими координатами не существует (точки лежат на одной линии).\n");
        return 1;
    }

    printf("\nВыберите операцию:\n");
    printf("%d - Найти периметр\n", PERIMETER);
    printf("%d - Найти площадь\n", AREA);
    printf("%d - Найти и периметр, и площадь\n", BOTH);
    printf("Ваш выбор: ");
    if (scanf("%d", &choice) != 1) return 1;

    double P = 0.0;
    double S = 0.0;

    switch ((enum TriangleOperation)choice) {
        case PERIMETER:
            P = perimeter(a, b, c);
            printf("\nПериметр треугольника: P = %.4f\n", P);
            break;

        case AREA:
            S = area(a, b, c);
            printf("\nПлощадь треугольника: S = %.4f\n", S);
            break;

        case BOTH:
            P = perimeter(a, b, c);
            S = area(a, b, c);
            printf("\nПериметр: P = %.4f\nПлощадь: S = %.4f\n", P, S);
            break;

        default:
            printf("\nОшибка: Неверный пункт меню.\n");
            return 1;
    }

    return 0;
}
