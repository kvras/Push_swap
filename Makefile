CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCM = longest_increasing_subsequence.c stack.c longest_increasing_subsequence_caller.c ft_atoi.c ft_split.c ft_memmove.c \
		ft_memcpy.c longest_increasing_subsequence_utils.c parsing.c stack_methodes.c help_functions.c stack_methodes_2.c \
		stack_methodes_3.c
SRCB = ft_atoi_bonus.c ft_split_bonus.c ft_memmove_bonus.c parsing_bonus.c stack_methodes_bonus.c \
		stack_methodes_2_bonus.c stack_methodes_3_bonus.c bonus.c get_next_line.c get_next_line_utils.c extra_bonus.c
OBJM = $(SRCM:.c=.o)
OBJB = $(SRCB:.c=.o)
NAME_M = push_swap
NAME_B = checker

all : $(NAME_M)

$(NAME_M) : $(OBJM) header.h
	(cd printf && make)
	 $(CC) $(CFLAGS) printf/libftprintf.a $(SRCM) -o $(NAME_M)
bonus : $(OBJB) header.h
	(cd printf && make)
	$(CC) $(CFLAGS) printf/libftprintf.a $(SRCB) -o $(NAME_B)
clean :
	(cd printf && make clean)
	rm -f $(OBJM) $(OBJB)

fclean : clean
	(cd printf && make fclean)
	rm -f $(NAME_M) $(NAME_B)

re : fclean all