CC = g++

OPT = -Wall -pedantic

objets = __PosSys.o __gui__winmain.o __gui__frame.o __mysql.o


#
# Flags pour le compilateur:
#
WXWIDGETS_CFLAGS = `wx-config --cxxflags`

#
# Flags pour l'editeur de liens:
#
WXWIDGETS_LIBS = `wx-config --libs`
MYSQL_LIBS = `mysql_config --libs`

__PosSys :  $(objets)
	$(CC) $(OPT) $(objets) $(WXWIDGETS_LIBS) $(MYSQL_LIBS) -o $@

__PosSys.o: __PosSys.h __gui__winmain.h 
	$(CC) $(OPT) -c __PosSys.cpp $(WXWIDGETS_CFLAGS) 

__gui__winmain.o: __gui__winmain.h __mysql.h
	$(CC) $(OPT) -c __gui__winmain.cpp $(WXWIDGETS_CFLAGS)

#__event.o: __event.h
#	$(CC) $(OPT) -c __event.cpp 
	
__gui__frame.o: __gui__frame.h
	$(CC) $(OPT) -c __gui__frame.cpp $(WXWIDGETS_CFLAGS)
	
__mysql.o:__mysql.h
	$(CC) $(OPT) -c __mysql.cpp 
	

clean:
	rm -f *.o


