NAME = get_next_line.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_strlen.c ft_strdup.c ft_strchr.c ft_strjoin.c ft_substr.c get_next_line.c

OBJ = $(SRC:.c=.o)

 
AR = ar -rc
 
all: $(NAME)
 
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) 
 
fclean: clean
	rm -f $(NAME)
 
re: fclean all
 
.PHONY: all fclean clean re