#include "utils.h"
#define dim 1000
#define dim_cuv 30
void SolveTask3() {
  char line[dim], cuv[dim][dim_cuv], bigram[dim][dim_cuv*2];
  int i, j = 0, k = 0, len, count = 1, h;
  while (fgets(line, dim, stdin)) {
    if (strcmp(line, "\n") == 0)
      continue;
    len = strlen(line);
    if (line[len - 1] == '\n')
      line[len - 1] = ' ';
    for (i = 0; i < strlen(line); i++) {
      if (line[i] != ';' && line[i] != '.' && line[i] != ',') {
        if (line[i] != ' ' && line[i] != '!') {
          cuv[k][j] = line[i];
          j++;
          if (i == strlen(line) - 1)
            k++;
        } else {
          if (line[i] != ' ' && line[i + 1] == ' ')
            i++;
          cuv[k][j] = '\0';
          k++;
          j = 0;
        }
      } else {
        if (line[i] != ' ' && line[i + 1] == ' ')
          i++;
        cuv[k][j] = '\0';
        k++;
        j = 0;
      }
    }
  }
  k--;
  for (i = 0; i <= k; i++) {
    snprintf(bigram[i], dim, "%s", cuv[i]);
    bigram[i][strlen(cuv[i])] = ' ';
    snprintf(bigram[i] + 1 + strlen(cuv[i]), dim, "%s", cuv[i + 1]);
  }
  for (i = 0; i < k; i++) {
    for (j = i + 1; j < k; j++) {
      if (strcmp(bigram[i], bigram[j]) == 0) {
        count++;
        for (h = j; h < k - 1; h++)
          snprintf(bigram[h], dim, "%s", bigram[h + 1]);
        k--;
      }
    }
    len = strlen(bigram[i]);
    bigram[i][len] = ' ';
    snprintf(bigram[i] + len + 1, dim, "%d", count);
    count = 1;
  }
  printf("%d\n", k);
  for (i = 0; i < k; i++)
    printf("%s\n", bigram[i]);
}
