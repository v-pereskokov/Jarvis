CC = g++
C11 = -std=c++14
BINCLUDE = -I/opt/local/include
BLIB = -L/opt/local/lib
LBOOST = -lboost_system
LCURL = -lcurl
SOURCE = Tests/test.cpp
OSOURCE = test.o
CFLAG = -c

all: main
	rm -rf *.o
main: $(OSOURCE)
	$(CC) $(C11) $(LBOOST) $(BINCLUDE) $(BLIB) $(OSOURCE) $(LCURL) -o build/test 
$(OSOURCE):
	$(CC) $(C11) $(CFLAG) $(SOURCE)
run:
	test
clean:
	rm -rf test
