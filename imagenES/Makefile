CCFLAGS = -std=c++11

imag: imagen.o imag.o imagenES.o
	g++ $(CCFLAGS) -g -o $@ $^ -I.

negativo: negativo.o imagenES.o
	g++ $(CCFLAGS) -g -o negativo negativo.o imagenES.o

imagenES.o: imagenES.cpp imagenES.h
	g++ $(CCFLAGS) -g -c -o imagenES.o -I. imagenES.cpp

imagen.o: imagen.cpp imagen.h
	g++ $(CCFLAGS) -g -c -o imagen.o -I. $<

imag.o: imag.cpp imagen.o imagenES.o
	g++ $(CCFLAGS) -g -c -o $@ $<


clean:
	@rm *.o 2>/dev/null || true
