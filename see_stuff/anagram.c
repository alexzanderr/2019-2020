#include <stdio.h>
#include <string.h>

void PrintArray(int *v, int n) {
  for(int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}


int Anagram(char *s1, char *s2) {
  if(strlen(s1) != strlen(s2)) {
    return 0;
  }
  char alpha[27] = "abcdefghijklmnopqrstuvwxyz";
  int frecv1[1000] = {0};
  int frecv2[1000] = {0};
  for(int i = 0; i < strlen(s1); i++) {
    int pos1 = 0;
    int pos2 = 0;
    for(int j = 0; j < strlen(alpha); j++) {
      if(alpha[j] == s1[i]) {
        pos1 = j;
        break;
      }
    }
    for(int j = 0; j < strlen(alpha); j++) {
      if(alpha[j] == s2[i]) {
        pos2 = j;
        break;
      }
    }
    frecv1[pos1]++;
    frecv2[pos2]++;
  }
  PrintArray(frecv1, 27);
  PrintArray(frecv2, 27);
  int egale = 1;
  for(int i = 0; i < strlen(s1); i++) {
    if(frecv1[i] != frecv2[i]) {
      egale = 0;
      break;
    }
  }
  if(egale) {
    return 1;
  }
  return 0;
}

int main(void) {
  char s1[] = "rutina";
  char s2[] = "unitir";
  printf("%d", Anagram(s1, s2));
  return 0;
}