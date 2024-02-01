CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCM = longest_increasing_subsequence.c stack.c longest_increasing_subsequence_caller.c ft_atoi.c ft_split.c ft_memmove.c ft_memcpy.c
SRCB = stack.c ft_atoi.c ft_split.c ft_memmove.c ft_memcpy.c longest_increasing_subsequence_caller stack.c
OBJM = $(SRCM:.c=.o)
OBJB = $(SRCB:.c=.o)
NAME_M = push_swap
NAME_B = checker

all : $(NAME_M)

$(NAME_M) : $(OBJM) header.h
	(cd printf && make)
	 $(CC) $(CFLAGS) printf/libftprintf.a $(SRCM) -o $(NAME_M)
bonus : $(SRCB) header.h
	(cd printf && make)
	$(CC) $(CFLAGS) printf/libftprintf.a $(SRCB) -o $(NAME_B)
clean :
	(cd printf && make clean)
	rm -f $(OBJM) $(OBJB)

fclean : clean
	(cd printf && make fclean)
	rm -f $(NAME) $(NAME_B)

re : fclean all