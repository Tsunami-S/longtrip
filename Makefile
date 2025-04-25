NAME = longtrip

# directories
INCLUDE_DIR = includes
SRC_DIR = sources
OBJ_DIR = objects

# sources
SRCS = main.cpp \
	   validation.cpp \
	   get_oneway_list.cpp \
	   find_best_route.cpp \
	   utils.cpp

# objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# flags
BASIC_FLAG = -std=c++17 -O2
WARNING_FLAG = -Wall -Wextra -Werror
INCLUDE_FLAG = -I$(INCLUDE_DIR)

# command
CXX = g++
RM = rm -rf

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(BASIC_FLAG) $(WARNING_FLAG) $(OBJS) $(INCLUDE_FLAG) -o $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX)  $(BASIC_FLAG) $(WARNING_FLAG) $(INCLUDE_FLAG) -c $< -o $@

.PHONY: all clean fclean re

