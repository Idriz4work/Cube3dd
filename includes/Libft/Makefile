# Library name
NAME = libft.a

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -g
SRCS = ft_isdigit.c ft_strcmp.c ft_strdup.c ft_strlen.c ft_strncmp.c ft_strtrim.c

OBJS = $(SRCS:.c=.o)

# Default target, builds the library
all: $(NAME)

# Archive object files to create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Add bonus functionality to the library
bonus: $(NAME)
	ar rcs $(NAME)

# Clean only object files
clean:
	rm -f $(OBJS) 

# Full clean, removes object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the project from scratch
re: fclean all
