
CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT = libft/libft.a
LIBFT_DIR = ./libft

SRC = $(wildcard src/mandatory/*.c)
BONUS_SRC = $(wildcard src/bonus/*.c)

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# 规则：编译所有文件并生成主程序
all: $(NAME)

bonus: $(LIBFT) $(BONUS_OBJ)
	$(CC) $(FLAGS) -g $(BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

# 通用规则：将 .c 文件编译为 .o 文件
%.o : %.c
	$(CC) $(FLAGS) -g -Iinclude -I$(LIBFT_DIR) -c $< -o $@


src/bonus/%.o : src/bonus/%.c
	$(CC) $(FLAGS) -g -Iinclude -I$(LIBFT_DIR) -Isrc/bonus -c $< -o $@


# 规则：编译 libft 库
$(LIBFT):
	make -C $(LIBFT_DIR)

# 规则：生成主程序
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) -g $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

# 清理所有生成的 .o 文件
clean:
	rm -rf $(OBJ) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

# 清理所有生成的文件
fclean: clean
	rm -rf $(NAME) 
	make -C $(LIBFT_DIR) fclean

# 重新编译所有内容
re: fclean all

.PHONY: clean fclean re all bonus
