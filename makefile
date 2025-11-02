CC = g++

all: Q1 Q2 Q3

Q1: Q1.cpp
	$(CC) -std=gnu++20 Q1.cpp -o Q1

Q2: Q2.cpp
	$(CC) -std=gnu++20 Q2.cpp -o Q2

Q3: Q3.cpp
	$(CC) -std=gnu++20 Q3.cpp -o Q3

clean:
	rm -f Q1 Q2 Q3

.PHONY: clean all