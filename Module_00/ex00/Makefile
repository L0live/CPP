NAME=megaphone
CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRCS=magaphone.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) -o $@
	@echo "\n\nCPP builded"

%.o: %.cpp
	@$(CPP) $(FLAGS) -c $<
	@echo -n '.....'

clean:
	@rm -f $(OBJS)
	@echo "All objects clean"

fclean: clean
	@rm -f $(NAME)
	@echo "And the executable too"

re: fclean all

.PHONY: all fclean clean re