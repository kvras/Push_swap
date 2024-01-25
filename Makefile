CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCM = longest_increasing_subsequence.c stack.c longest_increasing_subsequence_caller.c
OBJM = $(SRCM:.c=.o)
NAME = push_swap

# %.o:%.c libft.h
# 	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJM)
	 $(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJM)

fclean : clean
	rm -f $(NAME)

re : fclean all