NAME = longtrip

# directories
INCDIR = includes
SRCDIR = sources
OBJDIR = objects

# sources
SRCS = main.cpp \
	   validation.cpp \
	   get_oneway_list.cpp \
	   find_best_route.cpp \
	   utils.cpp

# objects
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

# flags
BASIC_FLAG = -std=c++17 -O2
WARNING_FLAG = -Wall -Wextra -Werror
INCLUDE_FLAG = -I$(INCDIR)

# rules
all: $(NAME)

$(NAME): $(OBJS)
	g++ $(BASIC_FALG) $(WARNING_FALG) $(OBJS) $(INCLUDE_FLAG) -o $(NAME)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	g++ $(BASIC_FLAG) $(WARNING_FLAG) $(INCLUDE_FLAG) -c $< -o $@

.PHONY: all clean fclean re

