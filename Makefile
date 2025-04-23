NAME = longtrip

# directories
INCDIR = includes
SRCDIR = sources
OBJDIR = objects

# sources
SRCS = main.c 

# objects
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# flags
WFLAG = -Wall -Wextra -Werror
IFLAG = -I$(INCDIR)

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(WFALG) $(OBJS) $(IFLAG) -o $(NAME)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(WFLAG) $(IFLAG) -c $< -o $@

.PHONY: all clean fclean re
