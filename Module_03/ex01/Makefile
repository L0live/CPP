NAME=ScavTrap
CC=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98
SRCS=main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS=$(SRCS:.cpp=.o)
HEADERS=ClapTrap.hpp ScavTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re