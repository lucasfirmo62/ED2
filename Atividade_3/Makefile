MAIN=main
AB=ab
ARN=arn

all:
	@echo "compilando"
	clang -c $(AB).c -o $(AB).o
	clang -c $(ARN).c -o $(ARN).o
	clang $(MAIN).c $(AB).o $(ARN).o -o $(MAIN)
	./$(MAIN)
	rm $(MAIN)
	rm *.o