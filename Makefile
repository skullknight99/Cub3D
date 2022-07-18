NAME	= 	cub3D

CC		= 	gcc

FLAGS	=	-Wall -Wextra -Werror -lmlx  -framework OpenGL -framework AppKit

PATH_LIBFT = ./libft/libft.a

SRCS	=	./src/main.c ./src/utils.c \
			./src/player.c ./src/parsing.c \
			./src/textures.c ./src/colors.c \
			./src/utils1.c ./src/clicks.c \
			./src/rotation.c ./src/check_map.c \
			./src/draw.c ./src/dda.c \

OBJS	=	$(SRCS:.c=.o)

all: 		$(NAME)

$(PATH_LIBFT):
	@make -C ./libft

$(NAME):	$(OBJS) $(PATH_LIBFT)
			@$(CC) $(FLAGS) $(OBJS) $(PATH_LIBFT) -o $(NAME)

clean:
			rm -rf $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -rf $(NAME)
			rm -rf ./libft/libft.a

re:			fclean clean all

.PHONY:		clean fclean re