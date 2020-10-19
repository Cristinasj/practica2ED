CCFLAGS = -std=c++11 -g

imag: imagen.o imag.o imagenES.o
	g++ $(CCFLAGS) -o $@ $^ -I.

negativo: negativo.o imagenES.o
	g++ $(CCFLAGS) -o negativo negativo.o imagenES.o

imagenES.o: imagenES.cpp imagenES.h
	g++ $(CCFLAGS) -c -o imagenES.o -I. imagenES.cpp

imagen.o: imagen.cpp imagen.h
	g++ $(CCFLAGS) -c -o imagen.o -I. $<

imag.o: imag.cpp imagen.o imagenES.o
	g++ $(CCFLAGS) -c -o $@ $<


clean:
	@rm *.o 2>/dev/null || true
