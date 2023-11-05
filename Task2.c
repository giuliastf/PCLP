#include "utils.h"
#define litere 27
#define nr 11
#define dim 1000

void SolveTask2() {
  char cifru[nr], S[dim]="", K2[dim]="", N1[dim], N2[dim], sum[dim] = "";
  char cifre[nr], min[litere], maj[litere];
  int K, i, j, l, n1, n2, dif, r = 0, K2nr[dim]={0};
  for (i = 0; i < 10; i++)
    cifre[i] = i + '0';
  cifre[10]='0';
  for (i = 0; i < 26; i++)
    min[i] = i + 'a';
  min[26]='a';
  for (i = 0; i < 26; i++)
    maj[i] = i + 'A';
  maj[26]='A';
  scanf("%s", cifru);
  if (strcmp(cifru, "caesar") == 0) {
    scanf("%d", & K);
    scanf("%s", S);
    for (i = 0; i < strlen(S); i++) {
      if (S[i] >= 'a' && S[i] <= 'z') {
        for (j = 0; j < 26; j++)
          if (S[i] == min[j]) {
            if (j - K >= 0)
              S[i] = min[(j - K) % 26];
            else
              S[i] = min[26 + ((j - K) % 26)];
            break;
          }
      }
      if (S[i] >= 'A' && S[i] <= 'Z') {
        for (j = 0; j < 26; j++)
          if (S[i] == maj[j]) {
            if (j - K >= 0)
              S[i] = maj[(j - K) % 26];
            else
              S[i] = maj[26 + ((j - K) % 26)];
            break;
          }
      }
      if (S[i] >= '0' && S[i] <= '9') {
        for (j = 0; j < 10; j++)
          if (S[i] == cifre[j]) {
            if (j - K >= 0)
              S[i] = cifre[(j - K) % 10];
            else
              S[i] = cifre[10 + ((j - K) % 10)];
            break;
          }
      }
    }
    printf("%s\n", S);
  }
  if (strcmp(cifru, "vigenere") == 0) {
    scanf("%s", K2);
    scanf("%s", S);
    l = strlen(K2);
    for (i = 0; i < strlen(S); i++)
      K2[i] = K2[i % l];
    for (i = 0; i < strlen(S); i++)
      for (j = 0; j < 26; j++)
        if (K2[i] == maj[j])
          K2nr[i] = j;
    for (i = 0; i < strlen(S); i++) {
      if (S[i] >= 'a' && S[i] <= 'z') {
        for (j = 0; j < 26; j++)
          if (S[i] == min[j]) {
            if (j - K2nr[i] >= 0)
              S[i] = min[(j - K2nr[i]) % 26];
            else
              S[i] = min[26 + ((j - K2nr[i]) % 26)];
            break;
          }
      }
      if (S[i] >= 'A' && S[i] <= 'Z') {
        for (j = 0; j < 26; j++)
          if (S[i] == maj[j]) {
            if (j -K2nr[i] >= 0)
              S[i] = maj[(j - K2nr[i]) % 26];
            else
              S[i] = maj[26 + ((j - K2nr[i]) % 26)];
            break;
          }
      }
      if (S[i] >= '0' && S[i] <= '9') {
        for (j = 0; j < 10; j++)
          if (S[i] == cifre[j]) {
            if (j - K2nr[i] >= 0)
              S[i] = cifre[(j - K2nr[i]) % 10];
            else
              S[i] = cifre[10 + ((j - K2nr[i]) % 10)];
            break;
          }
      }
    }
    printf("%s\n", S);
  }
  if (strcmp(cifru, "addition") == 0) {
    scanf("%d", & K);
    scanf("%s", N1);
    scanf("%s", N2);
    for (i = 0; i < strlen(N1); i++) {
      for (j = 0; j < 10; j++)
        if (N1[i] == cifre[j]) {
          if (j - K >= 0)
            N1[i] = cifre[(j - K) % 10];
          else
            N1[i] = cifre[10 + ((j - K) % 10)];
          break;
        }
    }
    for (i = 0; i < strlen(N2); i++) {
      for (j = 0; j < 10; j++)
        if (N2[i] == cifre[j]) {
          if (j - K >= 0)
            N2[i] = cifre[(j - K) % 10];
          else
            N2[i] = cifre[10 + ((j - K) % 10)];
          break;
        }
    }
    n1 = strlen(N1);
    n2 = strlen(N2);
    dif = n1 - n2;
    while (dif > 0) {
      for (i = n2 + 1; i > 0; i--)
        N2[i] = N2[i - 1];
      N2[0] = '0';
      dif--;
      n2++;
    }
    while (dif < 0) {
      for (i = n1 + 1; i > 0; i--)
        N1[i] = N1[i - 1];
      N1[0] = '0';
      dif++;
      n1++;
    }
    for (i = n1 - 1; i >= 0; i--)
      if (r + N1[i] + N2[i] - '0' > '9') {
        sum[i] = r + N1[i] + N2[i] - '0' - 10;
        r = 1;
      } else {
        sum[i] = r + N1[i] + N2[i] - '0';
        r = 0;
      }
    sum[n1] = '\0';
    if (r == 1) {
      for (i = n1 + 1; i > 0; i--)
        sum[i] = sum[i - 1];
      sum[0] = '1';
      n1++;
    }
    while (sum[0] == '0') {
      for (i = 0; i < n1; i++)
        sum[i] = sum[i + 1];
      n1--;
    }
    printf("%s\n", sum);
  }
}
