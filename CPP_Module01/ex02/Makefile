NAME = hi_this_is_brain

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = main.cpp

OBJS = $(SRCs:.cpp=.o)


all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
