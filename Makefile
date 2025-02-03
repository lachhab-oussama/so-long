# Executable name
NAME = so_long

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
LDFLAGS = -L. -lmlx -lX11 -lXext -lm

# Directories
SRC_DIR = .
GET_NEXT_LINE_DIR = ./get_next_line
GAME_DIR = ./game

# Source files
GET_NEXT_LINE_SRCS = 	$(GET_NEXT_LINE_DIR)/get_next_line.c \
						$(GET_NEXT_LINE_DIR)/get_next_line_utils.c

GAME_SRCS =	$(GAME_DIR)/so_long.c \
			$(GAME_DIR)/check_extention_map.c \
			$(GAME_DIR)/ckecker_1.c \
			$(GAME_DIR)/cleanup.c \
			$(GAME_DIR)/flood_fill.c \
			$(GAME_DIR)/flood_fill_utils.c \
			$(GAME_DIR)/get_map_size.c \
			$(GAME_DIR)/imgs_to_maps.c \
			$(GAME_DIR)/init_data_struct.c \
			$(GAME_DIR)/key_hooks.c \
			$(GAME_DIR)/load_map_first.c \
			$(GAME_DIR)/map_border_check.c \
			$(GAME_DIR)/player_moves.c \
			$(GAME_DIR)/prepare_map.c \
			$(GAME_DIR)/print_error.c

SRCS = $(GET_NEXT_LINE_SRCS) $(GAME_SRCS)

# Object files
OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.SECONDARY : $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re