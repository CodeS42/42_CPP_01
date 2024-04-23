SRCS =  srcs/HumanA.cpp \
		srcs/HumanB.cpp \
		srcs/main.cpp \
		srcs/Weapon.cpp \
        
OBJS = $(SRCS:.cpp=.o)

INCLUDES = headers

NAME = war

FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o :
	c++ $(FLAGS) -I $(INCLUDES) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
