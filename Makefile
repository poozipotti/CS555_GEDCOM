NAME = GEDReader
SRC = src/GEDReader.cpp src/birthBeforeDeath.cpp src/Date.cpp src/main.cpp src/tests/DateTest.cpp src/tests/BirthBeforeDeathTest.cpp
IRDIR = ../include
CFLAGS =  -I$(IRDIR)
all: 
	clear
	g++  -std=c++11 $(SRC) -o $(NAME) $(CFLAGS) -lcppunit
	
clean:
	rm -f *.o
fclean:
	rm -f $(NAME)
re: fclean all

debug: fclean
	g++ -std=c++11 $(SRC) -o $(NAME) -ggdb $(CFLAGS) -lcppunit
