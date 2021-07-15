MAIN=main
AB=ab


all:
	@echo "compilando"
	clang -c $(AB).c -o $(AB).o
	clang $(MAIN).c $(AB).o -o $(MAIN)
	./$(MAIN)
	rm $(MAIN)
	rm *.o