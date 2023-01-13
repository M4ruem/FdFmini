NAME = fdf

CC = clang

LIBFT_PATH = libft/ --no-print-directory
LIBFT_NAME = libft/libft.a

CFLAGS = -Wall -Werror -Wextra -g -O3

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT_NAME)

SRC = ./src/main.c \
	./src/colors.c \
	./src/draw.c \
	./src/init.c \
	./src/key.c \
	./src/mouse.c \
	./src/projections.c \
	./src/utils.c \
	./src/functions.c

OBJ = ${SRC:.c=.o}

all: $(LIBFT_NAME) $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	${CC} $(OBJ) $(MLX) -o ${NAME}

$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean bonus
