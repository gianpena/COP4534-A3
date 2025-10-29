CC = g++
TARGETS = Q1 Q2 Q3
$(TARGETS): Q1.cpp Q2.cpp Q3.cpp
	$(CC) -std=gnu++20 Q1.cpp -o Q1
	$(CC) -std=gnu++20 Q2.cpp -o Q2
	$(CC) -std=gnu++20 Q3.cpp -o Q3

clean:
	rm -f $(TARGETS)

.PHONY: clean