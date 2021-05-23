#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

__start__: sterowanie_dronem
	./sterowanie_dronem

sterowanie_dronem: obj obj/main.o obj/Macierz.o obj/Wektor.o obj/Prostopadloscian.o obj/Dr3D_gnuplot_api.o obj/Graniastoslup.o obj/Dron.o obj/UkladW.o obj/Powierzchnia.o obj/Scena.o obj/Wzgorze.o obj/Plaskowyz.o\

	g++ -Wall -pedantic -std=c++0x -o sterowanie_dronem obj/main.o obj/Wektor.o obj/Dron.o obj/UkladW.o obj/Powierzchnia.o obj/Scena.o obj/Wzgorze.o obj/Plaskowyz.o\
                        obj/Macierz.o obj/Prostopadloscian.o obj/Dr3D_gnuplot_api.o obj/Graniastoslup.o -lpthread
obj:
	mkdir obj

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
	g++ -c ${CXXFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp -lpthread

obj/main.o: src/main.cpp inc/Wektor.hh inc/Macierz.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Graniastoslup.o: src/Graniastoslup.cpp inc/Graniastoslup.hh
	g++ -c ${CXXFLAGS} -o obj/Graniastoslup.o src/Graniastoslup.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh 
	g++ -c ${CXXFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh
	g++ -c ${CXXFLAGS} -o obj/Dron.o src/Dron.cpp

obj/UkladW.o: src/UkladW.cpp inc/UkladW.hh
	g++ -c ${CXXFLAGS} -o obj/UkladW.o src/UkladW.cpp

obj/Powierzchnia.o: src/Powierzchnia.cpp inc/Powierzchnia.hh
	g++ -c ${CXXFLAGS} -o obj/Powierzchnia.o src/Powierzchnia.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Wzgorze.o: src/Wzgorze.cpp inc/Wzgorze.hh
	g++ -c ${CXXFLAGS} -o obj/Wzgorze.o src/Wzgorze.cpp

obj/Plaskowyz.o: src/Plaskowyz.cpp inc/Plaskowyz.hh
	g++ -c ${CXXFLAGS} -o obj/Plaskowyz.o src/Plaskowyz.cpp

clean:
	rm -f obj/*.o sterowanie_dronem