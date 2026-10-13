CC = gcc
CXX = g++

CFLAGS = -O2  -fno-tree-vectorize -fno-unroll-loops -g -Wall -Wextra -Werror -pedantic -std=gnu99

CXXFLAGS = -O2  -fno-tree-vectorize -fno-unroll-loops -g -Wall -Wextra -Werror -pedantic -std=c++17

LDFLAGS = -lbenchmark -lpthread

TARGET_BENCH = bench_runner
TARGET_PROF = profile_runner

OBJS_BENCH = suml0.o BM.o
OBJS_PROF = suml0.o main.o


all: $(TARGET_BENCH) $(TARGET_PROF)

$(TARGET_BENCH): $(OBJS_BENCH)
	$(CXX) $(OBJS_BENCH) -o $(TARGET_BENCH) $(LDFLAGS)

$(TARGET_PROF): $(OBJS_PROF)
	$(CC) $(OBJS_PROF) -o $(TARGET_PROF)

suml0.o: suml0.c suml0.h
	$(CC) $(CFLAGS) -c suml0.c -o suml0.o

BM.o: BM.cpp suml0.h
	$(CXX) $(CXXFLAGS) -c BM.cpp -o BM.o

main.o: main.c suml0.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f *.o $(TARGET_BENCH) $(TARGET_PROF)


runB: $(TARGET_BENCH)
	./$(TARGET_BENCH)


runP: $(TARGET_PROF)
	./$(TARGET_PROF)

.PHONY: all clean run
