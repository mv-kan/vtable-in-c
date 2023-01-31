FLAGS =  -std=c++20 -Werror -Wall -Weffc++ -Wextra -Wsign-conversion -pedantic-errors -fdiagnostics-color=always -g 
FLAGS_NO_SIGN =  -std=c++20 -Werror -Wall -Weffc++ -Wextra -pedantic-errors -fdiagnostics-color=always -g 
# no -Wsign-conversion
FLAGS_C = -std=c17 -Werror -Wall -Wextra  -pedantic-errors -fdiagnostics-color=always -g 
SRC_FILES = $(wildcard ${SRC}/*.c)
ARGS=$()
SRC=.

run:
	@gcc ${FLAGS_C} ${SRC_FILES} -o ${SRC}/main.bin
	${SRC}/main.bin