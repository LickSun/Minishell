
NAME = libft.a

SRC = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c  ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c  \
		ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
		get_next_line.c get_next_line_utils.c

SRCO = $(SRC:.c=.o)

OK_COLOR=\x1b[32;01m

DELETE_COLOR=\x1b[31;01m

HEADERS = libft.h get_next_line.h

FLAGS = -Wall -Wextra -Werror -c


all: $(NAME)


$(NAME): $(SRCO) $(HEADERS)
	@ar rcs $(NAME) $(SRCO)
	@echo "$(OK_COLOR)Libft was successfully compiled"

%.o: %.c
	@gcc $(FLAGS) $< -o $@

clean:
	@rm -f $(SRCO)
	@echo "$(DELETE_COLOR)Cleaned libft objects files"

fclean: clean
	@rm -f $(NAME)
	@echo Cleaned libft.a

re: fclean all
