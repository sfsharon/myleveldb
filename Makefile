.PHONY: all
all: hello_leveldb

hello_leveldb: hello_leveldb.cpp
	g++ -o hello_leveldb hello_leveldb.cpp

.PHONY: clean
clean: 
	rm -rf hello_leveldb 
