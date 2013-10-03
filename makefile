run: compile
	./practica1.out
compile: clean
	clear
	g++ -c NodoAs.cpp -W -Wall -o NodeAS.o
	g++ -c CerraduraEstAS.cpp -W -Wall -o CerraduraEstAS.o
	g++ -c CerraduraPosAS.cpp -W -Wall -o CerraduraPosAS.o
	g++ -c ConcatAS.cpp -W -Wall -o ConcatAS.o
	g++ -c OrAS.cpp -W -Wall  -o OrAS.o
	g++ -c SimboloAS.cpp -W -Wall -o SimboloAS.o
	g++ -c ArbolSintactico.cpp -W -Wall -o ArbolSintactico.o
	g++ -c ExpReg.cpp -W -Wall -o ExpReg.o
	g++ -c main.cpp -W -Wall -o main.o
	g++ -c Nodo.cpp -W -Wall -o Nodo.o
	g++ -c Transicion.cpp -W -Wall -o Transicion.o
	g++ -c NodoAFND.cpp -W -Wall -o NodoAFND.o	
	g++ -c AFND.cpp -W -Wall -o AFND.o
	g++ -c NodoAFD.cpp -W -Wall -o NodoAFD.o
	g++ -c AFD.cpp -W -Wall -o  AFD.o
	g++ *.o -o practica1.out
clean:
	rm -f *.o
	rm -f *.out
