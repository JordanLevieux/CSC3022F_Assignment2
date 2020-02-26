.RECIPEPREFIX +=
CC = g++
CFLAGS = -lm -lrt

PROG = bin/*
OBJS = obj/*

default:
    mkdir -p bin obj
    $(CC) $(CFLAGS) -c src/StudentDatabase.cpp -o obj/StudentDatabase
    $(CC) $(CFLAGS) -c src/StudentRecord.cpp -o obj/StudentRecord
    $(CC) $(CFLAGS) obj/StudentDatabase obj/StudentRecord -o bin/StudentDB

run:
    bin/StudentDB

clean:
    rm $(PROG) $(OBJS)


