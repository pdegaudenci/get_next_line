#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;
    printf("------------------------------------------\n");
    printf("ARCHIVO NULO\n");

    fd = open("files/nl", O_RDONLY);
    line = get_next_line(fd);
    printf("Archivo : %s\n", line);
    if (line != NULL)
        free(line);

    printf("------------------------------------------\n");
    printf("ARCHIVOS DE UNA LINEA \n");
    fd = open("files/41_no_nl", O_RDONLY);
    line = get_next_line(fd);
    printf("Archivo 1 : %s\n", line);
    free(line);

    printf("------------------------------------------\n");
    printf("ARCHIVOS DE 2 LINEAS \n");
    fd = open("files/41_with_nl", O_RDONLY);
    line = get_next_line(fd);
    printf("Archivo 1 : %s\n", line);
    free(line);

    printf("------------------------------------------\n");
    printf("ARCHIVOS VARIAS LINEAS 1 \n");
    fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
    line = get_next_line(fd);
    printf("LINEA 1 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 2 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 3 : %s\n", line);
    free(line);


    printf("------------------------------------------\n");
    printf("ARCHIVOS GRANDE con SALTO D ELINEA 2\n");
    fd = open("files/big_line_with_nl", O_RDONLY);
    line = get_next_line(fd);
    printf("LINEA 1 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 2 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 3 : %s\n", line);
    free(line);

    printf("------------------------------------------\n");
    printf("ARCHIVOS VARIAS LINEAS 1 \n");
    fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
    line = get_next_line(fd);
    printf("LINEA 1 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 2 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 3 : %s\n", line);
    free(line);

    printf("------------------------------------------\n");
    printf("ARCHIVOS CON SALTO DE LINEAS SIN CONTENIDO\n");
    fd = open("files/multiple_nlx5", O_RDONLY);
    line = get_next_line(fd);
    printf("LINEA 1 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 2 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 3 : %s\n", line);
    free(line);

    printf("------------------------------------------\n");
    printf("ARCHIVOS VARIAS LINEAS 1 \n");
    fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
    line = get_next_line(fd);
    printf("LINEA 1 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 2 : %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("LINEA 3 : %s\n", line);
    free(line);


    printf("------------------------------------------\n");
    
    printf("LECTURA CON 3 ARCHIVOS \n");


    int fd2[3];
    fd2[0]= open("files/alternate_line_nl_no_nl", O_RDONLY);
    fd2[1]= open("files/41_with_nl", O_RDONLY);
    fd2[2]= open("files/big_line_with_ln", O_RDONLY);
 

    line = get_next_line(fd2[0]);
    printf("Line 1 de archivo 1 : %s\n", line);
    line = get_next_line(fd2[1]);
    printf("Line 1 de archivo 2 : %s\n", line);
    line = get_next_line(fd2[0]);
    printf("Line 2 de archivo 1 : %s\n", line);

    line = get_next_line(fd2[2]);
    printf("Line 1 de archivo 3 : %s\n", line);
    line = get_next_line(fd2[0]);
    printf("Line 2 de archivo 1 : %s\n", line);

    line = get_next_line(fd2[1]);
    printf("Line 2 de archivo 2: %s\n", line);


    line = get_next_line(fd2[2]);
    printf("Line 2 de archivo 3 : %s\n", line);
    system("leaks a.out");
}