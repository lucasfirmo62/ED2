MAIN=main

LABIRINTO=labirinto

all:
	@echo "compilando..."
	gcc -c $(LABIRINTO).c -o $(LABIRINTO).o
	gcc $(MAIN).c $(LABIRINTO).o -o $(MAIN)
	./$(MAIN)
	rm *.o
	rm $(MAIN)