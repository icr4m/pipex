NAME = pipex

SRCS = $(addprefix srcs/, main.c)
OBJ = $(SRCS:srcs/%.c=obj/%.o)

INCLUDES = -Iincludes -I$(LIBFT_PATH)/includes

CFLAGS = -Wextra -Werror -Wall

LIBFT_PATH = ./libft

# Rules
all: $(LIBFT_PATH)/libft.a $(NAME)

$(NAME): $(OBJ)
	make $(LIBFT_PATH)
	cc $(CFLAGS) $^ $(LIBFT_PATH)/libft.a -o $(NAME)

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH)

obj/%.o: srcs/%.c
	 cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)
	cd $(LIBFT_PATH) && make clean

fclean: clean
		rm -f $(NAME)
		cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re