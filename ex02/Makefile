CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET   = program
SRC      = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ      = $(SRC:.cpp=.o)

all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re
