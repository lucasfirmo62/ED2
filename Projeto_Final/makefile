MAIN=main
ADC=adicional
ARN=arn
LST=lista

all:
	@echo "compilando"
	clang -c $(LST).c -o $(LST).o
	clang -c $(ARN).c -o $(ARN).o
	clang -c $(ADC).c -o $(ADC).o
	clang $(MAIN).c $(LST).o $(ARN).o $(ADC).o -o $(MAIN)

remove:
	rm $(MAIN)
	rm *.o