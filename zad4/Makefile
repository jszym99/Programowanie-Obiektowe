#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: obroty_3D
	./obroty_3D

#obroty_3D: obj obj/main.o obj/Prostokat.o obj/Macierz.o obj/Wektor.o\
	g++ -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor.o\
                        obj/Macierz.o obj/Prostokat.o -lpthread

obroty_3D: obj obj/main.o obj/Wektor.o\

	g++ -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor.o -lpthread

obj:
	mkdir obj

#obj/Dr2D_gnuplot_api.o: inc/Dr2D_gnuplot_api.hh inc/Draw2D_api_interface.hh src/Dr2D_gnuplot_api.cpp\
	g++ -c ${CXXFLAGS} -o obj/Dr2D_gnuplot_api.o src/Dr2D_gnuplot_api.cpp

#obj/main.o: src/main.cpp inc/Prostokat.hh inc/Macierz.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/main.o: src/main.cpp inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

#obj/Prostokat.o: src/Prostokat.cpp inc/Prostokat.hh\
	g++ -c ${CXXFLAGS} -o obj/Prostokat.o src/Prostokat.cpp

#obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh \
	g++ -c ${CXXFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor.o src/Wektor.cpp

clean:
	rm -f obj/*.o obroty_3D