NAME = claptrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -std=c++98
SRC = main.cpp ClapTrap.cpp
INC = ClapTrap.hpp

OBJ_DIR = .obj/
SRC_DIR = src/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))
DEP = $(OBJ:%.o=%.d)


.PHONY = all re clean fclean

all : $(NAME)

clean :
	 rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean
	$(MAKE) all

-include $(DEP)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : %.cpp $(INC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
