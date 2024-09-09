# NAME = so_long
# SRC = $(addprefix src/, main.c utils.c draw.c map_parser.c path_checker.c game_utils.c map_parser_utils.c free.c)
# GNL_SRC = $(addprefix gnl/, gnl.c gnl_utils.c)
# PRINTF_SRC = $(addprefix ft_printf/, ft_print_c.c ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c)

# OBJ := $(SRC:%.c=%.o)
# GNL_OBJ := $(GNL_SRC:%.c=%.o)
# PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

# CC = gcc
# CCFLAGS = -Wextra -Wall -Werror

# all: $(NAME)

# $(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
#     $(CC) $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# %.o: %.c
# 	gcc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

# clean:
# 	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

# fclean: clean
# 	make clean -C mlx/
# 	rm -f $(NAME)

# re : fclean all

NAME = so_long
# CFLAGS = -Wall -Wextra -Werror -O3 -flto
CFLAGS = -g -Og

LIBFTDIR = ./libft
MLXDIR = ./minilibx

SRCS = \
	src/so_long.c\
	src/win.c\
	src/sprite/assets.c\
	src/util/asset.c\
	src/render/render_level.c\
	src/loop/cam.c\
	src/loop/input.c\
	src/parse/validate.c\
	src/mlximg/sprite.c\
	src/loop/collision.c\
	src/mlximg/mlximg.c\
	src/render/render_objects.c\
	src/parse/parse.c\
	src/render/render.c\
	src/mlximg/mlximg2.c\
	src/mlximg/mlximg_split_sprite.c\
	src/util/level.c\
	src/util/pos.c\
	src/util/tile.c\
	src/util/level_info.c\
	src/util/img.c\
	src/util/spos.c\
	src/util/action.c\
	src/util/coins.c\

OBJ = $(SRCS:.c=.o)

%.o: %.c
	cc $(CFLAGS) -c -I$(LIBFTDIR) -I$(MLXDIR) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR) CFLAGS='$(CFLAGS)'
	$(MAKE) -C $(MLXDIR)
	cc $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -lXext -lX11 -lm -o $(NAME)

debug: CFLAGS += -DDEBUG
debug: all

# bonus: CFLAGS += -DBONUS
# bonus: all

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
