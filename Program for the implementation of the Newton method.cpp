#include <cmath>
#include <iostream>

using namespace std;

float f(float x)
{
    return 2 * x * x * x + 3 * x * x + x - 10;
}

float df(float x)
{
    return 6 * x * x + 6 * x + 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int exit = 0, i = 0;
    float a, b, epsilon, xi = 0;

    printf("                                Метод Ньютона\n");
    printf("           Задача программы: найти корень функции при помощи метода Ньютона\n");
    printf("Функция: 2*x^3 + 3*x^2 + x - 10\n");
    printf("Производная от функции: 6*x^2 + 6*x + 1\n\n");

    do
    {
        cout << "Введите границы отрезка поиска [a;b]\n";
        cout << "Введите нижнюю границу отрезка a\n=>";
        cin >> a;
        cout << "Введите верхнюю границу отрезка b\n=>";
        cin >> b;
        cout << "\nВведите точность вычислений epsilon\n=>";
        cin >> epsilon;

        if (a > b)
        {
            xi = a;
            a = b;
            b = xi;
        }

        if (f(a) * f(b) > 0)
        {
            cout << "\nError! В заявленном отрезке нет корня!\n";
        }
        else
        {
            int iterator = 0;
            xi = a;
            float eps = epsilon;
            float last_xi = 0;

            printf("+----+-------------+-------------+-------------+-------------+-------"
                "-----+\n");
            printf("|  i |     x_i     |    f(xi)    |    f'(xi)   |   x_i + 1   |   "
                "epsilon  |\n");
            printf("+----+-------------+-------------+-------------+-------------+-------"
                "-----+\n");

            while (1)
            {
                float fxi = f(xi);
                float _fxi = df(xi);
                float xi_1 = xi - (fxi / _fxi);
                eps = abs(xi - last_xi);
                printf("|%3d |%12.8f |%12.8f |%12.8f |%12.8f |%12.8f|\n", iterator, xi, fxi,
                    _fxi, xi_1, eps);
                iterator++;
                last_xi = xi;
                xi = xi_1;
                eps = abs(xi - last_xi);
                if (eps <= epsilon)
                {
                    printf("+----+-------------+-------------+-------------+-------------+---"
                        "---------+\n");
                    break;
                }
            }
            cout << "Приблизительное значение корня функции x при погрешности epsilon = ";
            printf("%1.8f", epsilon);
            cout << ":\n x = ";
            printf("%1.8f", xi);
        }
        cout << "\nВы хотите выйти из программы? Если да, введите '1', иначе - '0'\n";
        cin >> exit;
    } while (exit != 1);
    return 0;
}
