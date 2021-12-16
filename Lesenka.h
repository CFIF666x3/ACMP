#pragma once
double index_0(double n, double h)
{
    return trunc((n - (h + 1) * h / 2) / h) + 1;
}
double kolvo(double **a, double N, double n, double h, double i, int f)
{
    if (h == 1) return f;
    double summ = 0;
    for (int k = 1; k < i + 1; k++)
        summ += kolvo(a, N, n - k, h - 1, k, f * (-1));
    
    if (i == index_0(n, h)) return summ;
    return a[(int)h - 1][(int)(N - n)] * f + summ ;
}
//int main() //Лесенка
//{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    double N, H, I0, S = 0, n, ** a; int* b;
//    cin >> N; H = trunc((sqrt(1 + 8 * N) - 1) * 0.5); //H - максимально возможная высота лесенки
//    a = new double* [H]; b = new int[H]; //b - матрица с длинами строки матрицы a
//    a[(int)H - 1] = new double[1]; b[(int)H - 1] = 1;
//    //Создание разреженной матрицы a
//    I0 = index_0(N, H);  n = N;
//    for (int i = (int)H - 2; i >= 0; i--)
//    {
//        b[i] = b[i + 1] + (int)I0;
//        a[i] = new double[b[i]];
//        n = n - I0;
//        I0 = index_0(n, (double)i + 1);
//    }
//    //Инициализация матрицы a
//    for (int j = 0; j < b[0]; j++) a[0][j] = 1;
//    for (int i = 1; i < H; i++)
//        for (int j = 0; j < b[i]; j++)
//            a[i][j] = kolvo(a, N, N - j, i + 1, index_0(N - j, i + 1), -1);
//    //Вычисление результата
//    for (int i = 0; i < H; i++)
//        S += a[i][0];
//    cout << S;
//}