#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: obroty_2D
	./obroty_2D

obroty_2D: obj obj/main.o obj/Prostokat.o obj/Macierz2x2.o obj/Wektor2D.o\
           obj/Dr2D_gnuplot_api.o
	g++ -Wall -pedantic -std=c++0x -o obroty_2D obj/main.o obj/Wektor2D.o\
                        obj/Macierz2x2.o obj/Prostokat.o obj/Dr2D_gnuplot_api.o -lpthread

obj:
	mkdir obj

obj/Dr2D_gnuplot_api.o: inc/Dr2D_gnuplot_api.hh inc/Draw2D_api_interface.hh src/Dr2D_gnuplot_api.cpp
	g++ -c ${CXXFLAGS} -o obj/Dr2D_gnuplot_api.o src/Dr2D_gnuplot_api.cpp

obj/main.o: src/main.cpp inc/Prostokat.hh inc/Macierz2x2.hh inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostokat.o: src/Prostokat.cpp inc/Prostokat.hh
	g++ -c ${CXXFLAGS} -o obj/Prostokat.o src/Prostokat.cpp

obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hh 
	g++ -c ${CXXFLAGS} -o obj/Macierz2x2.o src/Macierz2x2.cpp

obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor2D.o src/Wektor2D.cpp

clean:
	rm -f obj/*.o obroty_2D