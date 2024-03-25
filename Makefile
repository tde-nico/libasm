#####   COLORS   #####

END				= \033[0m

GREY			= \033[30m
RED				= \033[31m
GREEN			= \033[32m
YELLOW			= \033[33m
BLUE			= \033[34m
PURPLE			= \033[35m
CYAN			= \033[36m

HIGH_RED		= \033[91m

#####   INFO   #####

NAME			= tester
NAME_BONUS		= tester_bonus
LIBASM			= libasm/libasm.a

#####   COMMANDS   #####

CC				= gcc
CFLAGS			= -Werror -Wall -Wextra -g

MD				= mkdir -p
RM				= rm -rf


#####   RESOURCES   #####

SRC_DIR			= srcs
INC_DIR			= includes
OBJ_DIR			= objs

SRC_SUB_DIRS	= $(SRC_DIR)
INC_SUB_DIRS	= $(shell find $(INC_DIR) -type d)
OBJ_SUB_DIRS	= $(SRC_SUB_DIRS:$(SRC_DIR)%=$(OBJ_DIR)%)

INCS			= $(foreach DIR, $(INC_SUB_DIRS), $(wildcard $(DIR)/*.h))

SRCS			= $(SRC_DIR)/checker.c
OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_BONUS		= $(SRC_DIR)/checker_bonus.c
OBJS_BONUS		= $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


#####   BASE RULES   #####

all: $(NAME)
bonus: $(NAME) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_SUB_DIRS) $(OBJS_BONUS) $(LIBASM)
	@ $(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBASM) -o $@
	@ echo "$(GREEN)[+] $(NAME_BONUS)$(END)"

$(NAME): $(OBJ_SUB_DIRS) $(OBJS) $(LIBASM)
	@ $(CC) $(CFLAGS) $(OBJS) $(LIBASM) -o $@
	@ echo "$(GREEN)[+] $(NAME)$(END)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCS)
	@ $(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@ echo "$(BLUE)[+] $@$(END)"

$(OBJ_SUB_DIRS):
	@ $(MD) $(OBJ_SUB_DIRS)
	@ echo "$(PURPLE)[+] $(SRC_DIR) -> $(OBJ_DIR) $(END)"

$(LIBASM):
	@ make -s -C libasm

clean:
	@ make -s -C libasm clean
	@ $(RM) $(OBJ_DIR)
	@ echo "$(YELLOW)[+] $(OBJ_DIR)$(END)"

fclean: clean
	@ make -s -C libasm fclean
	@ $(RM) $(NAME) $(NAME_BONUS)
	@ echo "$(YELLOW)[+] $(NAME)$(END)"

re: fclean all



#####   EXTRA RULES   #####

test: all
	@ ./$(NAME)

run: test
rrun: fclean test

val: all
	valgrind --leak-check=full ./$(NAME)
var: val



#####   PHONY   #####

.PHONY: all clean fclean re bonus test run rrun val var