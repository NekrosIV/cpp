NAME := test
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS_DIR := ./src
OBJS_DIR := ./objs

HEADERS := ./include
FILES := main.cpp \
			Weapon.cpp \
			HumanB.cpp \
			HumanA.cpp 
	

SRCS := $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(addprefix $(OBJS_DIR)/, $(FILES:.cpp=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(HEADERS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
