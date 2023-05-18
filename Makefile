# Makefile for ftf

# Variables
NAME = ftf

# Prints DEBUG Messages
DEBUG = 1

# Compiler options
CC = cc
CFLAGS = -D DEBUG=$(DEBUG) -g #-Wall -Werror -Wextra #-fsanitize=address #
CLIBS = -L$(LIB_FOLDER)libft_printf -L$(LIB_FOLDER)minilibx
CINCLUDES  = -I$(INCLUDE_FOLDER) -I$(MLX_FOLDER)
RM = rm -f

# ->Folders
SRC_FOLDER = ./src/
LIB_FOLDER = ./lib/
INCLUDE_FOLDER = ./include/
MLX_FOLDER = $(LIB_FOLDER)minilibx
MAPS_FOLDER = ./maps/

# ->Files
LIBFT_PRINTF = $(LIB_FOLDER)/libft_printf/libft_printf.a
SRCS = $(SRC_FOLDER)main.c \
	$(SRC_FOLDER)parser.c \
	$(SRC_FOLDER)node.c

# Object files
OBJS = $(SRCS:.c=.o)

# TARGETS
.PHONY: all clean fclean re r rr god

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PRINTF)
	$(CC) $(OBJS) $(CLIBS) $(CINCLUDES) -lft_printf -lmlx -lX11 -lXext -lm -o $(NAME)

$(LIBFT_PRINTF):
	@echo "\ncompiling libft_printf.a...\n"
	@make -C $(LIB_FOLDER)libft_printf
	@echo "\nlibft_printf.a compiled!\n"

clean:
	$(RM) $(OBJS)
	make -C $(LIB_FOLDER)libft_printf clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIB_FOLDER)libft_printf fclean

re: fclean all

r: all
	./$(NAME) ./maps/astein.fdf

rr: re
	./$(NAME) ./maps/astein.fdf
god:
	git status
	git add .
	git status
	git commit -m " -> Makefile Commit <- "
	git status
