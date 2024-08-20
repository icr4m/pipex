NAME = pipex
BONUS_NAME = pipex_bonus

SRCS = $(addprefix srcs/, check_args.c errors.c exec.c free.c init_pipex.c parse_args.c parse_cmds.c)
MAIN = $(addprefix srcs/, main.c)

SRCS_B = $(addprefix srcs_bonus/, check_args_bonus.c)
MAIN_B = $(addprefix srcs_bonus/, main_bonus.c)

OBJ =  $(SRCS:srcs/%.c=obj/%.o)
OBJ_B = $(SRCS_B:srcs/%.c=obj/%.o)
OBJ_MAIN		=	$(MAIN:srcs/%.c=obj/%.o)
OBJ_MAIN_B		=	$(MAIN_B:srcs/%.c=obj/%.o)

ALL_OBJS		+=	$(OBJ)
ALL_OBJS		+=	$(OBJ_B)
ALL_OBJS		+=	$(OBJ_MAIN)
ALL_OBJS		+=	$(OBJ_MAIN_B)

ALL_SRCS +=	$(SRCS)
ALL_SRCS +=	$(MAIN)
ALL_SRCS +=	$(SRCS_B)
ALL_SRCS +=	$(MAIN_B)

INCS = $(addprefix includes/, pipex.h struct.h)
INCS_LIBFT = $(addprefix Libft/libft/includes/, ft_printf.h get_next_line_bonus.h libft.h)

ALL_INCS += $(INCS)
ALL_INCS += $(INCS_LIBFT)

CCFLAGS = -Wall -Wextra -Werror

MAKE_FLAGS		+=	--no-print-directory
MAKE_FLAGS		+=	-C

INCLUDES_OPT = -Iincludes -I$(LIBFT_PATH)/includes

LIBFT_PATH = ./Libft

# Colors
RED	= "\033[0;31m"
GREEN = "\033[0;32m"
NO_COLOR = "\033[0m"

# Rules
all: $(LIBFT_PATH)/libft.a $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	@cc $(CFLAGS) $^ $(LIBFT_PATH)/libft.a -o $(NAME)
	@echo $(GREEN) "making pipex .o files" $(NO_COLOR)

$(LIBFT_PATH)/libft.a:
	@make $(MAKE_FLAGS) $(LIBFT_PATH)

$(BONUS_NAME) : $(OBJ_B) $(OBJ) $(OBJ_MAIN_B)
	@make $(MAKE_FLAGS) $(LIBFT_PATH)
	@cc $(CFLAGS) $^ $(LIBFT_PATH)/libft.a -o $(BONUS_NAME)

bonus: $(LIBFT_PATH)/libft.a $(BONUS_NAME)

obj/%.o: srcs/%.c
	@cc $(CFLAGS) $(INCLUDES_OPT) -c $< -o $@

norm:
	norminette -R CheckForbiddenSourceHeader $(ALL_SRCS)
	norminette -R CheckDefine $(ALL_INCS)

clean:
	@rm -rf $(ALL_OBJS)
	@make $(MAKE_FLAGS) $(LIBFT_PATH) fclean
	@echo $(RED) "deleting pipex .o files" $(NO_COLOR)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo $(RED) "deleting pipex" $(NO_COLOR)
		
re: fclean all

rb: re bonus