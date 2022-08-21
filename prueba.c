#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
    int fd = open("./files/example1",O_RDONLY);
   printf("%s",get_next_line(fd));
printf("%s",get_next_line(fd));
    //system("leaks a.out");
}