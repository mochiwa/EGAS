CC := g++
TARGET := libSQLParser.a
INCLUDE_PROJECT_DIR= ../../include/SQLParser

SRCEXT := cpp
CFLAGS := -g -Wall
INC := -I include


main:	*.cpp
	$(CC) $(INC) $(CGLAFS) -o main *.cpp
	rm *.o

main-full:	main-lib
	@echo "-->move the lib into ./lib dir"
	@mv libSQLParser.a ../
	@echo "-->make the SQLParser dir for includes into ./include"
	@mkdir -p $(INCLUDE_PROJECT_DIR)
	@echo "-->Copy every .h into ./include/SQLParser/"
	@cp -Rd include/* $(INCLUDE_PROJECT_DIR)

main-lib:	*.cpp
	@echo "-->Make main-lib of SQLParser"
	@$(CC) $(INC) -c *.cpp
	@ar rcs $(TARGET) *.o
	@rm *.o


