CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCM = 	mandatory/longest_increasing_subsequence.c mandatory/stack.c \
		mandatory/longest_increasing_subsequence_caller.c mandatory/ft_atoi.c \
		mandatory/ft_split.c mandatory/ft_memmove.c mandatory/ft_memcpy.c \
		mandatory/longest_increasing_subsequence_utils.c mandatory/parsing.c mandatory/stack_methodes.c \
		mandatory/help_functions.c mandatory/stack_methodes_2.c mandatory/stack_methodes_3.c
SRCB =  bonus/ft_atoi_bonus.c bonus/ft_split_bonus.c bonus/ft_memmove_bonus.c bonus/parsing_bonus.c \
		bonus/stack_methodes_bonus.c bonus/stack_methodes_2_bonus.c bonus/stack_methodes_3_bonus.c \
		bonus/bonus.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/extra_bonus.c
OBJM = $(SRCM:.c=.o)
OBJB = $(SRCB:.c=.o)
NAME_M = push_swap
NAME_B = checker

all : $(NAME_M)

$(NAME_M) : $(OBJM) mandatory/push_swap.h
	(cd printf && make)
	 $(CC) $(CFLAGS) printf/libftprintf.a $(SRCM) -o $(NAME_M)

bonus : $(NAME_B)

$(NAME_B) : $(OBJB) bonus/push_swap_bonus.h
	(cd printf && make)
	$(CC) $(CFLAGS) printf/libftprintf.a $(SRCB) -o $(NAME_B)
clean :
	(cd printf && make clean)
	rm -f $(OBJM) $(OBJB)

fclean : clean
	(cd printf && make fclean)
	rm -f $(NAME_M) $(NAME_B)

re : fclean all