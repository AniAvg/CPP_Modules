CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)


all: a.out

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

a.out: $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re
