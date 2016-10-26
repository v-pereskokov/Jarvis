CC = g++

C11 = -std=c++14

BINCLUDE = -I/usr/include

BLIB = -L/usr/lib

LIBS = -lboost_system-mt

LCURL = -lcurl

LPROTOBUF = -lprotobuf

SOURCE = main.cpp

OSOURCE = main.o

CFLAG = -c

all: main
	rm -rf *.o

main: $(OSOURCE)
	$(CC) $(C11) $(BINCLUDE) $(BLIB) $(LIBS) $(OSOURCE) $(LCURL) -o test 

$(OSOURCE):
	$(CC) $(C11) $(CFLAG) $(SOURCE)

run:
	./test

clean:
	rm -rf test
