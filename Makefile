NAME = cub3d

CXX = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L./includes/minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDES = -I /usr/include -I ./includes/minilibx-linux 

SRC_DIR = ./sources/
OBJ_DIR = ./objs/
NORMAL_DIR = normal/
BONUS_DIR = bonus/
LIBFT_DIR = ./includes/Libft
MLX_DIR = ./includes/minilibx-linux

BONUS_NAME = $(NAME)_bonus

LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a

HOOK_SRC = $(addprefix hooks/, \
action_trigger \
game_loop \
key_end \
setup_hooks)
MOVEMENT_SRC = $(addprefix movement/, \
move \
turn \
move_camera)
PARSING_SRC = $(addprefix parsing/, \
load_map \
mapfile_build_list \
mapfile_check_color \
mapfile_check_texture \
mapfile_complain \
mapfile_content \
mapfile_ll_to_grid \
mapfile_open \
mapfile_setup \
mapfile_verify_grid)
RAYCASTING_SRC = $(addprefix raycasting/, \
cast_ray \
colission \
get_wall_side \
render_image \
step_ray)
RENDER_SRC = $(addprefix rendering/, \
make_background \
make_minimap \
minimap_background \
minimap_frame \
render_ray \
render_wall)
UTILS_SRC = $(addprefix utils/, \
angle_vector \
argc_check \
atoi_limit \
charlist_functions \
data_setup \
deg_to_rad \
end_game \
error \
find_cins \
get_next_line_utils \
get_next_line \
my_pixel_put \
oob_check \
setup_mlx \
to_rgb \
wall_check)
SRC = $(addsuffix .c, main $(HOOK_SRC) $(MOVEMENT_SRC) $(PARSING_SRC) $(RAYCASTING_SRC) $(RENDER_SRC) $(UTILS_SRC))
# BONUS_SRC = category/name_bonus.c

NORM_OBJS = $(addprefix $(OBJ_DIR)$(NORMAL_DIR), $(SRC:%.c=%.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)$(BONUS_DIR), $(SRC:%.c=%.o))
# BONUS_OBJS += $(addprefix $(OBJ_DIR)$(BONUS_DIR), $(BONUS_SRC:%.c=%.o))

#######################################################################################

all: $(MLX_DIR) $(OBJ_DIR) $(LIBFT_LIB) $(NAME)

bonus: $(BONUS_NAME)

# Compile normal program
$(NAME): $(LIBFT_LIB) $(NORM_OBJS)
	$(CXX) $(CFLAGS) -DBONUS=0 $(NORM_OBJS) \
	$(MLX_FLAGS) $(LIBFT_LIB) -o $@

# Compile bonus program
$(BONUS_NAME): $(LIBFT_LIB) $(BONUS_OBJS)
	$(CXX) $(CFLAGS) -DBONUS=1 $(BONUS_OBJS) \
	$(MLX_FLAGS) $(LIBFT_LIB) -o $@

# Compile objects in normal mode
$(OBJ_DIR)$(NORMAL_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR) $(MLX_DIR)
	make -C $(MLX_DIR)
	$(CXX) $(CFLAGS) -DBONUS=0 $(INCLUDES) -c $< -o $@

# Compile objects in bonus mode
$(OBJ_DIR)$(BONUS_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR) $(MLX_DIR)
	make -C $(MLX_DIR)
	$(CXX) $(CFLAGS) -DBONUS=1 $(INCLUDES) -c $< -o $@

# Create directories for objects
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(NORMAL_DIR)
	mkdir -p $(OBJ_DIR)$(BONUS_DIR)
	mkdir -p $(OBJ_DIR)$(NORMAL_DIR)hooks
	mkdir -p $(OBJ_DIR)$(NORMAL_DIR)movement
	mkdir -p $(OBJ_DIR)$(NORMAL_DIR)raycasting
	mkdir -p $(OBJ_DIR)$(NORMAL_DIR)parsing
	mkdir -p $(OBJ_DIR)$(NORMAL_DIR)rendering
	mkdir -p $(OBJ_DIR)$(NORMAL_DIR)utils
	mkdir -p $(OBJ_DIR)$(BONUS_DIR)hooks
	mkdir -p $(OBJ_DIR)$(BONUS_DIR)movement
	mkdir -p $(OBJ_DIR)$(BONUS_DIR)raycasting
	mkdir -p $(OBJ_DIR)$(BONUS_DIR)parsing
	mkdir -p $(OBJ_DIR)$(BONUS_DIR)rendering
	mkdir -p $(OBJ_DIR)$(BONUS_DIR)utils

# Compile Libft Library
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

# Download MLX directory
$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $@

# Quick run program on example map
run: $(BONUS_NAME)
	./$(BONUS_NAME) "maps/test.cub"

# Quick run program with valgrind
val: $(NAME)
	valgrind --leak-check=full ./$(BONUS_NAME) "maps/test.cub"

# Performs norm check, only showing fails
norm:
	norminette ./sources $(LIBFT_DIR) ./headers | grep -v "OK!"

# Prepares repo for committing
commit:
	rm -rf $(MLX_DIR)

# Removes Object Files
clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

# Deletes all compiled files
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

# Deletes and compiles everything
re: fclean all

.PHONY: all run val norm clean fclean re
.SILENT: clean fclean