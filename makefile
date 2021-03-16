menu_executable: menu.o studentlist.o
	g++ -g -o menu menu.o studentlist.o
	chmod 755 menu

menu.o: menu.cpp studentlist.h
	g++ -g -c menu.cpp
    
studentlist.o: studentlist.cpp studentlist.h
	g++ -g -c studentlist.cpp    

clean:
	rm -f *.o