SRCS = ft_atoi.c     ft_isprint.c       ft_lstlast.c  ft_memmove.c     ft_split.c     ft_strlen.c   ft_tolower.c     print_p.c \
ft_bzero.c    ft_itoa.c          ft_lstmap.c   ft_memset.c      ft_strchr.c    ft_strmapi.c  ft_toupper.c     print_s.c \
ft_calloc.c   ft_lstadd_back.c   ft_lstnew.c   ft_printf.c      ft_strdup.c    ft_strncmp.c  get_next_line.c  print_u.c \
ft_isalnum.c  ft_lstadd_front.c  ft_lstsize.c  ft_putchar_fd.c  ft_striteri.c  ft_strnstr.c  print_x.c \
ft_isalpha.c  ft_lstclear.c      ft_memchr.c   ft_putendl_fd.c  ft_strjoin.c   ft_strrchr.c  \
ft_isascii.c  ft_lstdelone.c     ft_memcmp.c   ft_putnbr_fd.c   ft_strlcat.c   ft_strtrim.c  print_c.c \
ft_isdigit.c  ft_lstiter.c       ft_memcpy.c   ft_putstr_fd.c   ft_strlcpy.c   ft_substr.c   print_d.c \

OBJS = ${SRCS:.c=.o}
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus 
