NAME	= libft.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM 	= rm -f
INCLUDE	= .
INCDIR	= -I$(INCLUDE)

SRCS	= \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlen.c ft_strdup.c ft_strjoin.c ft_substr.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c\
	ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_strchr.c \
	ft_strrchr.c ft_strnstr.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_strmapi.c ft_striteri.c ft_memchr.c ft_memcmp.c ft_atoi.c

BONUS_SRCS	= \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

HEADER	= libft.h

OBJS	= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		ar rcs $@ $^
		touch $@

bonus:	$(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	touch $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@ 

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re bonus
