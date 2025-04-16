CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = brain

SRCS = main.cpp WrongCat.cpp WrongAnimal.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re