NAME=RPN
CC=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98 -g
SRCS=main.cpp RPN.cpp
OBJS=$(SRCS:.cpp=.o)
HEADERS=RPN.hpp

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