NAME = fixed

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp
HEADER = Fixed.hpp

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re