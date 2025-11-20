SRCS = hooks.c image.c init.c maths.c menu.c tools.c draw.c main.c
SRCS_BONUS = hooks.c image.c init.c maths.c menu.c tools.c colors_bonus.c draw_bonus.c keys_bonus.c main_bonus.c

NAME = fractol
NAME_BONUS = bonus

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

HEADER = fractol.h
HEADER_BONUS = fractol_bonus.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./mlx

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	make -sC ./mlx
	$(CC) $(OBJS) -L./mlx -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(HEADER_BONUS)
	make -sC ./mlx
	$(CC) $(OBJS_BONUS) -L./mlx -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME_BONUS)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	rm -f ${OBJS} ${OBJS_BONUS}
	make -sC ./mlx clean

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	make -sC ./mlx clean

re: fclean all

.PHONY: all bonus clean fclean re
