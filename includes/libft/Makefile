# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarc <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 15:43:24 by mcarc             #+#    #+#              #
#    Updated: 2019/09/23 18:45:45 by mcarc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCPATH = srcs/
SRC += $(SRCPATH)ft_btree_create_node.c
SRC += $(SRCPATH)ft_btree_apply_prefix.c
SRC += $(SRCPATH)ft_btree_apply_infix.c
SRC += $(SRCPATH)ft_btree_apply_suffix.c
SRC += $(SRCPATH)ft_btree_insert_data.c
SRC += $(SRCPATH)ft_memset.c
SRC += $(SRCPATH)ft_bzero.c
SRC += $(SRCPATH)ft_memcpy.c
SRC += $(SRCPATH)ft_memccpy.c
SRC += $(SRCPATH)ft_memmove.c
SRC += $(SRCPATH)ft_memchr.c
SRC += $(SRCPATH)ft_memcmp.c
SRC += $(SRCPATH)ft_strlen.c
SRC += $(SRCPATH)ft_strdup.c
SRC += $(SRCPATH)ft_strnew.c
SRC += $(SRCPATH)ft_memalloc.c
SRC += $(SRCPATH)ft_strcpy.c
SRC += $(SRCPATH)ft_strncpy.c
SRC += $(SRCPATH)ft_strcat.c
SRC += $(SRCPATH)ft_strncat.c
SRC += $(SRCPATH)ft_strchr.c
SRC += $(SRCPATH)ft_strrchr.c
SRC += $(SRCPATH)ft_strstr.c
SRC += $(SRCPATH)ft_strnstr.c
SRC += $(SRCPATH)ft_strcmp.c
SRC += $(SRCPATH)ft_strncmp.c
SRC += $(SRCPATH)ft_isalpha.c
SRC += $(SRCPATH)ft_isalnum.c
SRC += $(SRCPATH)ft_memdel.c
SRC += $(SRCPATH)ft_strdel.c
SRC += $(SRCPATH)ft_strclr.c
SRC += $(SRCPATH)ft_striter.c
SRC += $(SRCPATH)ft_striteri.c
SRC += $(SRCPATH)ft_strmap.c
SRC += $(SRCPATH)ft_strmapi.c
SRC += $(SRCPATH)ft_strequ.c
SRC += $(SRCPATH)ft_strnequ.c
SRC += $(SRCPATH)ft_strsub.c
SRC += $(SRCPATH)ft_strjoin.c
SRC += $(SRCPATH)ft_putchar.c
SRC += $(SRCPATH)ft_putstr.c
SRC += $(SRCPATH)ft_putendl.c
SRC += $(SRCPATH)ft_putnbr.c
SRC += $(SRCPATH)ft_isdigit.c
SRC += $(SRCPATH)ft_isascii.c
SRC += $(SRCPATH)ft_isprint.c
SRC += $(SRCPATH)ft_toupper.c
SRC += $(SRCPATH)ft_tolower.c
SRC += $(SRCPATH)ft_atoi.c
SRC += $(SRCPATH)ft_strlcat.c
SRC += $(SRCPATH)ft_strtrim.c
SRC += $(SRCPATH)ft_strsplit.c
SRC += $(SRCPATH)ft_itoa.c
SRC += $(SRCPATH)ft_putchar_fd.c
SRC += $(SRCPATH)ft_putstr_fd.c
SRC += $(SRCPATH)ft_putendl_fd.c
SRC += $(SRCPATH)ft_putnbr_fd.c
SRC += $(SRCPATH)ft_lstnew.c
SRC += $(SRCPATH)ft_lstdelone.c
SRC += $(SRCPATH)ft_lstdel.c
SRC += $(SRCPATH)ft_lstadd.c
SRC += $(SRCPATH)ft_lstiter.c
SRC += $(SRCPATH)ft_lstmap.c
SRC += $(SRCPATH)get_next_line.c

SRCDEL = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCDEL)
	@ar rc $(NAME) $(SRCDEL)

%.o: %.c
	@gcc -c -I. -Wall -Wextra -Werror $< -o $@

clean:
	@/bin/rm -f $(SRCDEL)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
