MAIN=main
BB=buscaBinaria
IP=implementacao

all:
	@echo "compilando"
	clang -c $(BB).c -o $(BB).o
	clang -c $(IP).c -o $(IP).o
	clang $(MAIN).c $(BB).o $(IP).o -o $(MAIN)
	./$(MAIN)
	rm $(MAIN)
	rm *.o