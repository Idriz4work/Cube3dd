NAME = cub3d

CXX = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./includes/minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I /usr/include -I ./includes/minilibx-linux

SRC_DIR = ./sources/
OBJ_DIR = ./objs/
LIBFT_DIR = ./includes/Libft
MLX_DIR = ./includes/minilibx-linux

BONUS = 1

LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a

SRC = \
main.c\
movement/move.c \
movement/turn.c \
parsing/load_map.c \
parsing/mapfile_build_list.c \
parsing/mapfile_check_color.c \
parsing/mapfile_check_texture.c \
parsing/mapfile_complain.c \
parsing/mapfile_content.c \
parsing/mapfile_ll_to_grid.c \
parsing/mapfile_open.c \
parsing/mapfile_setup.c \
parsing/mapfile_verify_grid.c \
rendering/make_background.c \
rendering/make_minimap.c \
rendering/update_display.c \
utils/argc_check.c \
utils/atoi_limit.c \
utils/charlist_functions.c \
utils/data_setup.c \
utils/deg_to_rad.c \
utils/end_game.c \
utils/error.c \
utils/find_cins.c \
utils/get_next_line_utils.c \
utils/get_next_line.c \
utils/key_end.c \
utils/key_hook.c \
utils/my_pixel_put.c \
utils/to_rgb.c

SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRC:%.c=%.o)
OBJ_FILES = $(addprefix $(OBJ_DIR), $(OBJS))

all: $(OBJ_DIR) $(LIBFT_LIB) $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ_FILES)
	$(CXX) $(CFLAGS) -DBONUS=$(BONUS) $(OBJ_FILES) \
	$(MLX_FLAGS) $(LIBFT_LIB) -lm -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR) $(MLX_DIR)
	make -C $(MLX_DIR)
	$(CXX) $(CFLAGS) -DBONUS=$(BONUS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)movement
	mkdir -p $(OBJ_DIR)parsing
	mkdir -p $(OBJ_DIR)rendering
	mkdir -p $(OBJ_DIR)utils

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $@

bonus:
	make all BONUS=1

run: $(NAME)
	./$(NAME) "maps/test.cub"

val: $(NAME)
	valgrind --leak-check=full ./$(NAME) "maps/test.cub"

norm:
	norminette ./sources ./includes/Libft ./headers | grep -v "OK!"

clean:
	make -C $(LIBFT_DIR) clean
	make -sC $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all run val norm clean fclean re
.SILENT: clean fclean