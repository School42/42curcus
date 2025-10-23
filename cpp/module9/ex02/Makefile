CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

explain:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -D EXPLANATION=1" re

.PHONY: all clean fclean re explain