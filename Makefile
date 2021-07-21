NAME		= lgcollector.a
PREFIX_MSG 	= "[LIB-GCOLLECTOR]"
SRCS 		= anchor.c free.c hash.c \
			malloc.c methods.c utils.c

TEST_SRCS 	= tests/basic_tests.c tests/free_tests.c \
			tests/main.c  tests/malloc_tests.c tests/utils.c

HASHTABLE_DIR = ../hashtable
HASHTABLE_BIN = $(HASHTABLE_DIR)/lhashtable.a

CC		= clang
LINKER	= ar -rcs

SRCS_DIR	 = srcs
OBJS_DIR	 = objs
INCLUDES_DIR = includes
OBJS		 = $(addprefix objs/, $(SRCS:.c=.o))

NAME_TEST	= tests_bin

CFLAGS		= -Wall -Wextra -Werror -O3 -fPIE
CSANITIZE	= -g -fsanitize=address
PRINTER		= printf

RM			= /bin/rm -f

CMP_MSG		= "$(PREFIX_MSG)[\\033[33m\+\\033[0m]"
INF_MSG		= "$(PREFIX_MSG)[\\033[37mINF\\033[0m]"
SCS_MSG		= "$(PREFIX_MSG)[\\033[32mSUC\\033[0m]"
ERR_MSG		= "$(PREFIX_MSG)[\\033[31m!\\033[0m]"

objs/%.o	: srcs/%.c
			@	mkdir -p $(dir $@)
			@	$(PRINTER) "$(CMP_MSG) Compiling $<\n"
			@	$(CC) $(CFLAGS) -c $< -o $@

all		:	$(NAME)

$(NAME)	: $(OBJS)
ifeq ("$(wildcard $(HASHTABLE_DIR))", "")
	@	$(PRINTER) "$(ERR_MSG) Unable to find HASHTABLE_DIR.\n"
	@	git clone https://github.com/c3b5aw/c_hashtable.git $(HASHTABLE_DIR)
endif
ifeq ("$(wildcard $(HASHTABLE_BIN))", "")
	@	$(PRINTER) "$(ERR_MSG) Unable to find HASHTABLE_BIN.\n"
	@	$(MAKE) -sC $(HASHTABLE_DIR)
endif
	@	$(LINKER) $(NAME) $(OBJS) $(HASHTABLE_BIN)
	@	$(PRINTER) "$(SCS_MSG) $(NAME) @ built !\n"

re		:	fclean all

fclean	:	clean
		@	$(PRINTER) "$(INF_MSG) Deleting bins...\n"
		@	$(RM) $(NAME)
		@	$(RM) $(NAME_TEST)

clean	:
		@	$(PRINTER) "$(INF_MSG) Deleting assets...\n"
		@	$(RM) -r $(OBJS_DIR)

tests	: re
		@	$(CC) $(CFLAGS) $(TEST_SRCS) -I includes $(NAME) $(HASHTABLE_BIN) -o $(NAME_TEST)
		@	./tests/tester.sh

.PHONY	:	fclean clean re all tests