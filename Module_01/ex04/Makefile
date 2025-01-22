NAME=Replace
CC=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)
	rm -f *.replace

re: fclean all

.PHONY: all fclean clean re