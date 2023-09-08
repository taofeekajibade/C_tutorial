#include <stdio.h>
#include <stdlib.h>

void open_file(FILE **fp, char *filename) {
  *fp = fopen(filename, "w");
  if (*fp == NULL) {
    printf("Failed to create file...\n");
    exit(1);
  }
}

void read_string(char *name) {
  puts("Enter your string here...\n");
  fgets(name, sizeof(name), stdin);
}

void write_string(FILE *fp, char *name) {
  fprintf(fp, "%s\n", name);
}

int main(void) {
  FILE *fp;
  char *name;

  open_file(&fp, "modular.txt");
  read_string(name);
  write_string(fp, name);
  fclose(fp);

  return 0;
}
