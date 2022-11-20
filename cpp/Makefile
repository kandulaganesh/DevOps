
# Compiler
CC = g++

# Flags
FLAGS = -g -Wall -std=c++11

#Libraries
LIB = -pthread

#Header files
INCLUDE = -L.

APP_NAME = mybin

OBJECT_FILES = Consumer.o Producer.o multi_thread.o

.PHONY: all
all: $(OBJECT_FILES)
	$(CC) $(FLAGS) $(OBJECT_FILES) -o $(APP_NAME) $(LIB)

%.o: %.cc
	$(CC) -c $< $(FLAGS) $(LIB) $(INCLUDE)

.PHONY: clean
clean:
	rm -f *.o $(APP_NAME) bin/*

.PHONY: test
test: $(APP_NAME)
	timeout 5 ./$(APP_NAME) || true

mybin: all

.PHONY: install
install: mybin
	@if [ -d bin ]; \
	 then \
	 mv $(APP_NAME) bin/.; \
	else \
	 echo "bin directory not found"; \
	 exit 1; \
	fi

# How to Compile the code
help:
	@echo -e "use \"make\" comamnd to generate binary. \nuse \"make clean\" to delete object and binaries.\nuse \"make test\" to test the binary."

