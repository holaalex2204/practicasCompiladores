run: compile
	./practica1.out
compile: clean
	clear
	g++ -c NodoAS.cpp -W -Wall -o NodeAS.o -g3
	g++ -c CerraduraEstAS.cpp -W -Wall -o CerraduraEstAS.o -g3
	g++ -c CerraduraPosAS.cpp -W -Wall -o CerraduraPosAS.o -g3
	g++ -c ConcatAS.cpp -W -Wall -o ConcatAS.o -g3
	g++ -c OrAS.cpp -W -Wall  -o OrAS.o -g3
	g++ -c SimboloAS.cpp -W -Wall -o SimboloAS.o -g3
	g++ -c ArbolSintactico.cpp -W -Wall -o ArbolSintactico.o -g3
	g++ -c ExpReg.cpp -W -Wall -o ExpReg.o -g3
	g++ -c main.cpp -W -Wall -o main.o -g3
	g++ -c Nodo.cpp -W -Wall -o Nodo.o -g3
	g++ -c Transicion.cpp -W -Wall -o Transicion.o -g3
	g++ -c NodoAFND.cpp -W -Wall -o NodoAFND.o	-g3
	g++ -c AFND.cpp -W -Wall -o AFND.o -g3
	g++ -c NodoAFD.cpp -W -Wall -o NodoAFD.o -g3
	g++ -c AFD.cpp -W -Wall -o  AFD.o -g3
	g++ *.o -o practica1.out -g3
clean:
	rm -f *.o
	rm -f *.out
