CC      := cc
RM      := rm -f

CFLAGS  := -g -Wall -Wextra -Werror

NAME := pipex

COMMON_DEPS := 

COMMON_SOURCES := 

BASE_DEPS := $(COMMON_DEPS)	\
				env_man.h	\
				ft_split.h	\
				pipe_man.h	\
				utils.h		

BASE_SOURCES := $(COMMON_SOURCES)	\
					env_man.c		\
					ft_split.c		\
					pipe_man.c		\
					pipex.c			\
					utils.c


BASE_OBJECTS := $(BASE_SOURCES:.c=.o)

BONUS_NAME := checker

BONUS_DEPS := $(DEPS)	

BONUS_SOURCES :=  $(COMMON_SOURCES)	

BONUS_OBJECTS := $(BONUS_SOURCES:.c=.o)

.PHONY: all bonus clean fclean re exec

all: $(NAME)

$(NAME): $(BASE_OBJECTS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJECTS)

$(BASE_OBJECTS): $(BASE_SOURCES) $(DEPS)

$(BONUS_OBJECTS): $(BONUS_SOURCES) $(BONUS_DEPS)

clean: 
	$(RM) $(BASE_OBJECTS)
	$(RM) $(BONUS_OBJECTS)
	$(RM) *.gch
	$(RM) *.txt

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all
