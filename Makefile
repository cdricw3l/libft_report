#https://www.gnu.org/software/make/manual/html_node/Options-Summary.html
CC = cc
GFLAGS = -Wall -Wextra -Werror
PARENT_DIR = $(shell dirname $(shell pwd))
NAME = libft_dirty_report
SRCS = ${wildcard *.c}
LIB = -L../. -lft
OBJETS_SRCS = ${SRCS:.c=.o}

%.o:%.c
	@${CC} ${GFLAGS} -c $^ -o $@

MANDATORY= 	ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr \
			ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
			ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
			ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap \
			

UTILS = utils.c

# get the target name: $@ -> exemple make ft_strjoin $@ = ft_strjoin
$(MANDATORY):
	@make -C $(PARENT_DIR)
	@$(CC) $(GFLAGS)  $@_assert.c $(UTILS) $(LIB) -o $(NAME)
	@./$(NAME) && rm -f $(NAME)


#whithout argument make call the first target
${NAME}: lib ${OBJETS_SRCS}  
ifeq (${shell uname} , Darwin)
	${CC} ${GFLAGS} ${OBJETS_SRCS} ${LIB} -lbsd  -o ${NAME}
	${shell export MallocStackLogging=1}
	@leaks -list  --atExit -- ./${NAME}
else
	${CC} ${GFLAGS} ${OBJETS_SRCS} ${LIB} -lbsd  -o ${NAME}
	@valgrind --child-silent-after-fork=yes --leak-check=full --show-leak-kinds=all -s ./${NAME}
endif
	rm -f *.o

lib:
	@make -C ${PARENT_DIR}

clean:
	@rm -f ${OBJETS_SRCS}
	@make clean -C ${PARENT_DIR}

fclean: clean
	@rm -f ${NAME}
	@make fclean -C ${PARENT_DIR}

COM="libft_report"
git:
	git add .
	git commit -m $(COM)
	git push origin $(shell git branch --show-current)

.PHONY: ${NAME} lib clean fclean