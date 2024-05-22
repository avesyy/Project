#include <stdio.h>
#include <stdlib.h>
#ifndef LR_H
#define LR_H
#include <stdio.h>
int laba1()
{

float x1,x2,d;

d = 1 * 1 - 4 * 1;

x1 = (-1 + d*1/2)/2;

x2 = (-1 - d*1/2)/2;

printf("x1 = %f\n", x1);

printf("x2 = %f", x2);

return 0;
}

#include <stdio.h>
double CalcSum(int N)
{
double S;
double a = 1;
double b = 1;
for (int n = 1; n < N; ++n)
{
a = n*2 + 1;
b = n*3 + 1;
S += a/b;
}
return S;
}
int laba2()
{
int N;
double S;
printf("Введите кол-во элементов ряда: ");
scanf("N= %d", &N);
printf("S= %f\n", CalcSum(N));
return 0;
}

int isSameLength(char* stream) {
int length = 0;
int wordLength = 0;
int isSameLength = 1;
int isWord = 0;
char prevWord[100];
int i = 0;
while (stream[i] != '\0') {
if (stream[i] == ' ' || stream[i] == '\n') {
if (isWord) {
if (i > 0 && length == 0) {
int j = 0;
for (int k = i - wordLength; k < i; k++) {
prevWord[j++] = stream[k];
}
prevWord[j] = '\0';
length = wordLength;
} else if (wordLength != length) {
isSameLength = 0;
break;
}
wordLength = 0;
}
isWord = 0;
} else {
isWord = 1;
wordLength++;
}
i++;
}
return isSameLength;
}

int laba3() {
char stream[1000];
int i = 0;
char ch;
printf("Введите поток символов: ");
while ((ch = getchar()) != EOF && i < sizeof(stream)) {
stream[i++] = ch;
}
stream[i++] = '\n';
stream[i] = '\0';
if (isSameLength(stream)) {
printf("Все слова имеют одинаковую длину.\n");
} else {
printf("Не все слова имеют одинаковую длину.\n");
}
return 0;
}

// Функция для проверки, является ли символ цифрой
int isDigit(char ch) {
 return ch >= '0' && ch <= '9';
}
// Функция для удаления всех чисел из строки
void removeNumbers(char *str) {
 int i = 0, j = 0;
 while (str[i] != '\0') {
 if (!isDigit(str[i])) {
 str[j++] = str[i];
 }
 i++;
 }
 str[j] = '\0';
}

int laba4() {
 char str[100];
 printf("Введите строку: ");
 gets(str);
 removeNumbers(str);
 printf("Строка после удаления чисел: %s\n", str);
 return 0;
}

#include <stdio.h>
int laba5() {
 // Объявление массива из 10 целых чисел
 int array[10];
 // Заполнение массива значениями
 for (int i = 0; i < 10; i++) {
 printf("Введите %d-е число: ", i + 1);
 scanf("%d", &array[i]);
 }
 // Сумма элементов с четными номерами
 int evenSum = 0;
 for (int i = 0; i < 10; i += 2) {
 evenSum += array[i];
 }
 // Сумма элементов с нечетными номерами
 int oddSum = 0;
 for (int i = 1; i < 10; i += 2) {
 oddSum += array[i];
 }
 // Проверка, какая сумма меньше
 if (oddSum < evenSum) {
 // Обнуление элементов с нечетными номерами
 for (int i = 1; i < 10; i += 2) {
 array[i] = 0;
 }
 } else {
 // Обнуление элементов с четными номерами
 for (int i = 0; i < 10; i += 2) {
 array[i] = 0;
 }
 }
 // Вывод массива после изменений
 printf("\nМассив после изменений:\n");
 for (int i = 0; i < 10; i++) {
 printf("%d ", array[i]);
 }
 return 0;
}

#include <stdio.h>
void laba6() {
 // Размер массива
 int N, K;
 printf("Введите N (количество строк): ");
 scanf("%d", &N);
 printf("Введите K (количество столбцов): ");
 scanf("%d", &K);
 // Динамическое выделение памяти для массива
 int** matrix = (int**)malloc(N * sizeof(int*));
 for (int i = 0; i < N; i++) {
 matrix[i] = (int*)malloc(K * sizeof(int));
 }
 // Считывание значений в массив
 printf("Введите элементы массива:\n");
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < K; j++) {
 scanf("%d", &matrix[i][j]);
 }
 }
 // Вычисление среднего арифметического по всему массиву
 int sumTotal = 0;
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < K; j++) {
 sumTotal += matrix[i][j];
 }
 }
 double meanTotal = (double)sumTotal / (N * K);
 // Обнуление строк с низким средним арифметическим
 for (int i = 0; i < N; i++) {
 double sumRow = 0;
 for (int j = 0; j < K; j++) {
 sumRow += matrix[i][j];
 }
 double meanRow = sumRow / K;
 if (meanRow < meanTotal) {
 for (int j = 0; j < K; j++) {
 matrix[i][j] = 0;
 }
 }
 }
 // Печать результирующего массива
 printf("\nМассив после обнуления строк:\n");
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < K; j++) {
 printf("%d ", matrix[i][j]);
 }
 printf("\n");
 }
 // Освобождение выделенной памяти
 for (int i = 0; i < N; i++) {
 free(matrix[i]);
 }
 free(matrix);
}

#include <stdio.h>
int laba7() {
unsigned long long reverseBitsWithMask(unsigned long long n, unsigned long long mask) {
unsigned long long reversed = 0;
for (int i = 0; i < 64; ++i) {
if ((n & (mask >> i)) > 0) {
reversed |= (1 << (63 - i));
}
}
return reversed;
}
unsigned long long n, mask;
printf("Введите длинное целое число: ");
scanf("%llu", &n);
printf("Введите маску: ");
scanf("%llu", &mask);
unsigned long long reversed = reverseBitsWithMask(n, mask);
printf("Число с перевернутыми битами в маске: %llu\n", reversed);
return 0;
}

#include <stdio.h>
int laba8()
{
float x1,x2,d,a,b,c;
printf("Введите a: \n");
scanf("%f", &a);
printf("Введите b: \n");
scanf("%f", &b);
printf("Введите c: \n");
scanf("%f", &c);
d = b * b - 4 * a * c;
x1 = (-b + d*1/2)/(2*a);
x2 = (-b - d*1/2)/(2*a);
printf("Полученные корни: \n");
printf("x1 = %f\n", x1);
printf("x2 = %f", x2);
return 0;
}

#include <stdio.h>
int laba9() {
double CalcSum(int N) {
double S;
double a = 1;
double b = 1;
int n = 0;
int stop = 0;
while (n < N && !stop) {
a = n * 2 + 1;
b = n * 3 + 1;
if (a / b > 10) {
stop = 1;
} else {
S += a / b;
}
n++;
}
return S;
}
int N;
double S;
printf("Введите кол-во элементов ряда: ");
scanf("N= %d", &N);
S = CalcSum(N);
printf("S= %f\n", S);
return 0;
}

#include <stdio.h>
int laba11() {
// Объявление массива из 10 целых чисел
int array[10];
// Заполнение массива значениями
for (int i = 0; i < 10; i++) {
printf("Введите %d-е число: ", i + 1);
scanf("%d", &array[i]);
}
// Сумма элементов с четными номерами
int evenSum = 0;
for (int i = 0; i < 10; i += 2) {
evenSum += array[i];
}
// Сумма элементов с нечетными номерами
int oddSum = 0;
for (int i = 1; i < 10; i += 2) {
oddSum += array[i];
}
// Флаг, который указывает, была ли регрессия
int isRegression = 0; // 0 - регрессии нет, 1 - есть
// Проверка наличия регрессии
for (int i = 1; i < 10; i += 2) {
if (array[i] < array[i - 1]) {
isRegression = 1;
break;
}
}
// Обнуление элементов
if (oddSum < evenSum && !isRegression) {
// Обнуление элементов с нечетными номерами
for (int i = 1; i < 10; i += 2) {
array[i] = 0;
}
} else {
// Обнуление элементов с четными номерами
for (int i = 0; i < 10; i += 2) {
array[i] = 0;
}
}
// Вывод массива после изменений
printf("\nМассив после изменений:\n");
for (int i = 0; i < 10; i++) {
printf("%d ", array[i]);
}
return 0;
}

#include <stdio.h>
// Функция для сортировки массива по среднему значению каждой строки
void insertionSort(double* arr, int* indices, int size) {
for (int i = 1; i < size; i++) {
double key = arr[i];
int keyIndex = indices[i];
int j = i - 1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
indices[j + 1] = indices[j];
j = j - 1;
}
arr[j + 1] = key;
indices[j + 1] = keyIndex;
}
}
int laba12() {
// Размер массива
int N, K;
printf("Введите N (количество строк): ");
scanf("%d", &N);
printf("Введите K (количество столбцов): ");
scanf("%d", &K);
// Считывание значений в массив
printf("Введите элементы массива:\n");
int matrix[N][K];
for (int i = 0; i < N; i++) {
for (int j = 0; j < K; j++) {
scanf("%d", &matrix[i][j]);
}
}
// Вычисление среднего арифметического по всему массиву
int sumTotal = 0;
for (int i = 0; i < N; i++) {
for (int j = 0; j < K; j++) {
sumTotal += matrix[i][j];
}
}
double meanTotal = (double) sumTotal / (N * K);
// Массив для хранения средних значений каждой строки и их индексов
double meanRows[N];
int indices[N];
// Вычисление среднего арифметического для каждой строки и заполнение массива средних значений
for (int i = 0; i < N; i++) {
double sumRow = 0;
for (int j = 0; j < K; j++) {
sumRow += matrix[i][j];
}
meanRows[i] = sumRow / K;
indices[i] = i;
}
// Сортировка строк по среднему значению
insertionSort(meanRows, indices, N);
// Обнуление строк с низким средним арифметическим
for (int i = 0; i < N; i++) {
int row = indices[i];
if (meanRows[i] < meanTotal) {
for (int j = 0; j < K; j++) {
matrix[row][j] = 0;
}
}
}
// Печать результирующего массива
printf("\nМассив после обнуления строк:\n");
for (int i = 0; i < N; i++) {
for (int j = 0; j < K; j++) {
printf("%d ", matrix[i][j]);
}
printf("\n");
}
return 0;
}

#include <stdio.h>
struct Data {
 int sum;
 float average;
};
struct Data data;
void removeNumbers2(char *str, struct Data *data) {
 int i = 0, j = 0, count = 0;
 while (str[i] != '\0') {
 if (!isDigit(str[i])) {
 str[j++] = str[i];
 } else {
 data->sum += str[i] - '0';
 count++;
 }
 i++;
 }
 str[j] = '\0';
 if (count > 0) {
 data->average = (float)data->sum / count;
 }
}
int laba10() {
 char str[100];
 struct Data data;
 printf("Введите строку: ");
 gets(str);
 removeNumbers2(str, &data);
 printf("Сумма чисел: %d\n", data.sum);
 printf("Среднее значение чисел: %.2f\n", data.average);
 printf("Строка после удаления чисел: %s\n", str);
 return 0;
}

#endif /* LR_H */ 