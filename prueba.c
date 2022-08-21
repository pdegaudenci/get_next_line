#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
    int fd = open("41_with_nl",O_RDONLY);
   printf("%s",get_next_line(fd));
printf("%s",get_next_line(fd));
    //system("leaks a.out");
}