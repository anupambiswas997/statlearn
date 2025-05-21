CC=g++

all: stat

stat: src/stat.cpp
	$(CC) stat.cpp -o $@

clean:
	rm -rf stat
