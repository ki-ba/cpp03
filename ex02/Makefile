NAME = fragtrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
INC = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
DEP = $(addprefix $(OBJ_DIR), $(INC:%.hpp=%.d))

OBJ_DIR = .obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))

.PHONY = all re clean fclean

all : $(NAME)

clean :
	 rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean
	$(MAKE) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)
