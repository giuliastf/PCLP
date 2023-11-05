#include "utils.h"

#define dim_1 300
#define dim_2 30
int MAX(char cuv[]) {
  int poz = 1, i;
  char max;
  max = cuv[1];
  for (i = 2; i < 5; i++)
    if (cuv[i] > max) {
      max = cuv[i];
      poz = i;
    }
  return poz;
}

int PAL(char cuv[]) {
  char ogl[dim_2] = {};
  int i, j = 0;
  for (i = strlen(cuv) - 1; i != 0; i--) {
    ogl[j] = cuv[i];
    j++;
  }
  for (i = 1; i < strlen(cuv); i++)
    if (ogl[i - 1] != cuv[i])
      return 0;
  return 1;
}
int PRIM(char cuv[], int n) {
  int X, d;
  X = 0;
  X = (cuv[n - 2] - '0') * 10 + (cuv[n - 1] - '0');
  if (X <= 1)
    return 0;
  else if (X == 2)
    return 1;
  for (d = 2; d <= X / 2; d++)
    if (X % d == 0)
      return 0;
  return 1;
}

void SolveTask1() {
  int N, M, i, j, p, l, m = 0, nr_misc = 2, k, n, q, S;
  char cod[dim_1], cuv[dim_2], endl[3];
  scanf("%d %d", & N, & M);
  int cale[N][M];
  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
      cale[i][j] = 0;
  i = j = 0;
  cale[i][j] = 1;
  fgets(endl, 3, stdin);
  fgets(cod, dim_1, stdin);
  for (p = 0; p < strlen(cod); p = l + 1) {
    for (l = p; cod[l] != ' ' && cod[l] != '\0'; l++) {
      cuv[m] = cod[l];
      m++;
    }
    cuv[m] = '\0';
    if (cuv[0] == 'a') {
      switch (MAX(cuv)) {
      case 1:
        cale[i][j + 1] = nr_misc;
        j++;
        break;
      case 2:
        cale[i - 1][j] = nr_misc;
        i--;
        break;
      case 3:
        cale[i][j - 1] = nr_misc;
        j--;
        break;
      case 4:
        cale[i + 1][j] = nr_misc;
        i++;
        break;
      }
    }
    if (cuv[0] == 'b') {
      if (PAL(cuv) == 1) {
        if (PRIM(cuv, strlen(cuv)) == 1) {
          cale[i][j - 1] = nr_misc;
          j--;
        } else {
        cale[i][j + 1] = nr_misc;
        j++;
      }
      } else {
      if (PRIM(cuv, strlen(cuv)) == 1) {
        cale[i - 1][j] = nr_misc;
        i--;
      } else {
        cale[i + 1][j] = nr_misc;
        i++;
      }
      }
    }
    if (cuv[0] == 'c') {
      n = cuv[1] - '0';
      k = cuv[2] - '0';
      S = 0;
      for (q = 0; q < n; q++)
        cuv[q] = cuv[q + 3];
      for (q = 0; q < k; q++) {
        S = S + (cuv[(k * q) % n] - '0');
      }
      switch (S % 4) {
      case 2:
        cale[i][j + 1] = nr_misc;
        j++;
        break;
      case 1:
        cale[i - 1][j] = nr_misc;
        i--;
        break;
      case 0:
        cale[i][j - 1] = nr_misc;
        j--;
        break;
      case 3:
        cale[i + 1][j] = nr_misc;
        i++;
        break;
      }
    }
    nr_misc++;
    memset(cuv, 0, strlen(cuv));
    m = 0;
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++)
      printf("%d ", cale[i][j]);
    printf("\n");
  }
}
