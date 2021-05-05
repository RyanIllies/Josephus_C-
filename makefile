# Ryan Illies
# CSIS 352 - Asmt #7
# Makefile - prog7



CC = g++ 


OBJECTS = main.o 


LFLAGS = 


CFLAGS =  


EXE = prog7


$(EXE):		$(OBJECTS) 
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS) 

main.o:		main.cpp person.h circularqueue.h
		$(CC) $(CFLAGS) -c main.cpp 



clean:
		rm -rf $(EXE) $(OBJECTS) 



test:		$(EXE)
		./$(EXE) < testinput.txt

