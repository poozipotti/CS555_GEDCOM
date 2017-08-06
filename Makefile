NAME = GEDReader
SRC = src/Individual.cpp src/MarriageBeforeDeath.cpp src/tooOld.cpp src/MarriageBeforeDivorce.cpp src/Family.cpp src/GEDData.cpp src/GEDWriter.cpp src/birthBeforeDeath.cpp src/Date.cpp src/uniqueID.cpp src/GenderRole.cpp src/DatesBeforeToday.cpp src/main.cpp src/tests/genderRoleTest.cpp src/tests/DateTest.cpp src/tests/BirthBeforeDeathTest.cpp src/tests/isDeadTest.cpp src/tests/uniqueIDTest.cpp
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
