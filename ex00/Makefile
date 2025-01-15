.PHONY: all clean re

NAME = zombie
FLAG = -std=c++98

SRCS = \
$(addsuffix .cpp, \
	main \
	newZombie \
	randomChump \
	Zombie \
) \

all: $(NAME)

$(NAME):
	g++ -o $(NAME) $(FLAG) $(SRCS)

clean:
	rm -f $(NAME)

re: clean all
