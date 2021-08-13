MAIN=main
ARN=arn
LST=lista

all:
	@echo "compilando"
	clang -c $(LST).c -o $(LST).o
	clang -c $(ARN).c -o $(ARN).o
	clang $(MAIN).c $(LST).o $(ARN).o -o $(MAIN)
	./$(MAIN)
	rm $(MAIN)
	rm *.o