CXX=clang++
CFLAGS = -g -Wall -Wextra 
SRCS= Demo.cpp
SRCSTEST = tests/tests.cpp 
TARGETDEMO = bin/demo.out
TARGETTEST = bin/test.out

all: demo test

demo: $(TARGETDEMO)

test: $(TARGETTEST)

$(TARGETDEMO): $(SRCS)
	$(CXX) $(CFLAGS) -o $@ $^

$(TARGETTEST): $(SRCSTEST)
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -rf bin/*