#include <stdio.h>
#include <string.h>

int main() {
    FILE *outFile;
    char text[100];

    outFile = fopen("desafio.txt", "w");
    if (outFile == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    printf("Digite os textos: \n");
    do
    {
        scanf("%s", text);
        fprintf(outFile, "%s\n", text);

    }  while (strcmp(text, "0") != 0);
    
    fclose(outFile);

    return 0;
}