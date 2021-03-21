LEVELDB_DIR=/home/sharonf/workspace/leveldb
IDIR=$(LEVELDB_DIR)/include

LDIR=-L$(LEVELDB_DIR)/build
LIBS=-lleveldb

CXXFILES=hello_leveldb.cpp
CXXFLAGS=-o -I$(IDIR) $(LDIR)
 
CXX=g++



OBJFILES:=$(CXXFILES:%.cpp=%.o) 
LDFLAGS=-static $(LDIR) $(LIBS)


.PHONY: all
# all: hello_leveldb

# hello_leveldb: hello_leveldb.cpp
# 	g++ -o  hello_leveldb $(INC) hello_leveldb.cpp

all:$(OBJFILES)
	$(CXX) $(OBJFILES) -o hello_leveldb


# $(CXXFILES) $(CXXFLAGS) 
$(OBJFILES):$(CXXFILES)
	# $(CXX) $(INC) $(CXXFLAGS) $(CXXFILES)  $(LDFLAGS)
	$(CXX)  $(CXXFLAGS) $@ $< 	

.PHONY: clean
clean: 
	rm -rf hello_leveldb *.O
