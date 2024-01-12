TARGET=

obj_file=$(TARGET).o
compile=$(TARGET).cpp

CC=gcc

compile:
    $(CC) $(compile) -o $(obj_file) -lstdc++
    ./$(obj_file)

.PHONY: clean all

clean:
    rm -f *.o

push:
    git add .
    git add Makefile
    git commit -a -m "mama"
    git push