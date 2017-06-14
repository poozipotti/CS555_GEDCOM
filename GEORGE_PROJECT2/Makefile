NAME = GEDReader
SRC = src/GEDReader.cpp src/birthBeforeDeath.cpp
TEST_SRC =  $(wildcard src/tests/*.cpp) 
IRDIR = ../include
CFLAGS =  -I$(IRDIR)
all: 
	clear
	g++  -std=c++11 $(SRC) src/main.cpp -o $(NAME) $(CFLAGS)
	g++  -std=c++11 $(SRC) $(TEST_SRC) -o $(NAME)_tests $(CFLAGS) -lcppunit
	
clean:
	rm -f *.o
fclean:
	rm -f $(NAME)
re: fclean all

debug: fclean
	g++ $(SRC) -o $(NAME) -ggdb $(CFLAGS)
