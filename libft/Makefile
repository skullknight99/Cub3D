NAME = libft.a

SRCS =	ft_strncmp.c ft_strlen.c gnl.c \
		ft_isspace.c ft_strdup.c ft_split.c \
		ft_putstr_fd.c ft_bzero.c ft_memset.c \
		ft_calloc.c ft_strtrim.c ft_memcpy.c \
		ft_memmove.c \

CC = gcc

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

%.o: %.c
	@$(CC) -c $(FLAGS) -o $@ $^
	
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, all, re