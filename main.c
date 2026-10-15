#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "lexerf.h"
#include "parserf.h"
#include "codegeneratorf.h"

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("Error: correct syntax: %s <filename.pk> <output_filename>\n", argv[0]);
    exit(1);
  }
  char output_filename[256];
  snprintf(output_filename, sizeof(output_filename), "%s.asm", argv[2]);

  FILE *file;
  file = fopen(argv[1], "r");

  if(!file){
    printf("ERROR: File not found\n");
    exit(1);
  }
  Token *tokens = lexer(file);

  Node *test = parser(tokens);
  
  generate_code(test, output_filename);
  FILE *assembly_file = fopen(output_filename, "r");
  if(!assembly_file){
    printf("ERRROR");
    exit(1);
  }
  char nasm[128];
  char gcc[256];
  snprintf(nasm, sizeof(nasm),"nasm -f elf64 generated.asm -o generated.o");
  snprintf(gcc, sizeof(gcc),"gcc generated.o -o %s -lc -no-pie", argv[2]);
  system(nasm);
  system(gcc);
  printf("FINISHED\n");
}