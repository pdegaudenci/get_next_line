
SRCS =  get_next_line.c \
		get_next_line_utils.c \

SRCS_BONUS =  get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
			
OBJS = 		get_next_line.o \
			get_next_line_utils.o \
			get_next_line_bonus.o \
			get_next_line_utils_bonus.o 
CC = gcc

FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=1

INCLUDES = -I get_next_line.h get_next_line_bonus.h


all :
	@$(CC) $(FLAGS) $(SRCS) prueba.c

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

bonus: 
	$(CC) $(FLAGS) $(SRCS_BONUS)

re : fclean all
