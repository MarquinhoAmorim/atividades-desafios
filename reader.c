#include <stdio.h>
#include <string.h>

int main(){

    FILE *inFile;
    inFile = fopen("desafio.txt", "r");
    if (inFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    char line[100];
    printf("Conteudo do arquivo:\n");
    while (fgets(line, sizeof(line), inFile) != NULL) {
        printf("%s", line);
    }
    fclose(inFile);
    return 0;


}

