NAME		=	span
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC			=	main.cpp\
				Span.cpp
OBJ			=	$(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) span_file vector_file

re: fclean all

.PHONY: all clean fclean re