MAIN=main
VIDEO=video
RADOMIZADO=radomizado
MEDIANA=mediana

all:
	@echo "compilando"
	clang -c $(VIDEO).c -o $(VIDEO).o 
	clang -c $(RADOMIZADO).c -o $(RADOMIZADO).o
	clang -c $(MEDIANA).c -o $(MEDIANA).o
	clang $(MAIN).c $(VIDEO).o $(RADOMIZADO).o $(MEDIANA).o -o $(MAIN)
	./$(MAIN)
	rm $(MAIN)
	rm *.o