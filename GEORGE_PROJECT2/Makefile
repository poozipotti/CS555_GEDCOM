NAME = GEDReader
SRC = src/GEDReader.cpp 
IRDIR = ../include
CFLAGS =  -I$(IRDIR)
all: 
	clear
	g++ $(SRC) -o $(NAME) $(CFLAGS)
clean:
	rm -f *.o
fclean:
	rm -f $(NAME)
re: fclean all

debug: fclean
	g++ $(SRC) -o $(NAME) -ggdb $(CFLAGS)
