NAME=Violence
CC=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98
SRCS=main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS=$(SRCS:.cpp=.o)
HEADERS=Weapon.hpp HumanA.hpp HumanB.hpp

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