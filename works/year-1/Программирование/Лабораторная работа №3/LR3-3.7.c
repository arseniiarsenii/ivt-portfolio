#include <stdio.h>

void main() {
  int const N = 5;
  int x[N];

  //Ввод
  for (int i = 0; i < N; ++i) {
    printf("X[%d] = ", i + 1);
    scanf("%d", &x[i]);
  }

  //Сортировка
  for(int i = 1; i < N; ++i) {
		for(int j = i; j > 0 && x[j - 1] > x[j]; j--) {
			int tmp = x[j - 1];
			x[j - 1] = x[j];
			x[j] = tmp;
    }
  }

  //Вывод
  printf("\nОтсортированный массив: [");
  for (int i = 0; i < N; ++i) {
    printf(" %d", x[i]);
  }
  printf(" ]\n");
}
