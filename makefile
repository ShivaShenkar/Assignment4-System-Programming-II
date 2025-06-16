#fikhman2005@gmail.com
CXX=clang++
CFLAGS = -g -Wall -Wextra 
SRCS= Demo.cpp
SRCSTEST = tests/tests.cpp 
TARGETDEMO = bin/demo.out
TARGETTEST = bin/test.out

all: demo test

main: $(TARGETDEMO)

test: $(TARGETTEST)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all $(TARGETDEMO)
	valgrind --leak-check=full --show-leak-kinds=all $(TARGETTEST)

$(TARGETDEMO): $(SRCS)
	$(CXX) $(CFLAGS) -o $@ $^

$(TARGETTEST): $(SRCSTEST)
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -rf bin/*