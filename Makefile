NAME = push_swap
CC = cc
SRC_DIR = srcs
SRC = main.c parsing.c fill_tab_pars.c operation.c stack_verrif.c initialize.c push_swap.c \
instruction.c instruction_next.c rev_rotate.c n_move.c split_swap.c
OBJ_DIR = objs
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
CFLAGS = -Wextra -Werror -Wall -g
INCLUDES = -Iincludes -Ilibft 
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $@
	
$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all