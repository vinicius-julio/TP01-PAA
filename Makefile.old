# Para executar basta digitar no console make (enter) e depois ./exec (enter)
exec: main.o Labirinto.o Estudante.o ListaCaminhoPercorrido.o
	g++ main.o Labirinto.o Estudante.o ListaCaminhoPercorrido.o -o exec

main.o: main.c
	g++ -c main.c

Labirinto.o: Labirinto.c Labirinto.h
	g++ -c Labirinto.c

Estudante.o: Estudante.c Estudante.h
	g++ -c Estudante.c

ListaCaminhoPercorrido.o: ListaCaminhoPercorrido.c ListaCaminhoPercorrido.h
	g++ -c ListaCaminhoPercorrido.c

clean:
	rm *.o exec 
