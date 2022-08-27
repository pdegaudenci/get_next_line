NAME = libget_next_linea.a

SRCS =  get_next_line.c \
		get_next_line_utils.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c


			
SURPL_O = 	get_next_line.o \
			get_next_line_utils.o
CC = gcc

F = -Wall -Wextra -Werror -fsanitize=address

INCLUDES = -I get_next_line.h get_next_line_bonus.h

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(F) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
bonus: $(NAME)

test:
	$(CC) $(FLAGS) $(SRCS) prueba.c
	
re : fclean all
