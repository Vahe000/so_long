NAME		= so_long
SRCS		= $(shell find "./src" -name "*.c")
OBJS		= $(SRCS:.c=.o)
CC			= gcc
INCLUDES	= ./includes
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -Imlx -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re