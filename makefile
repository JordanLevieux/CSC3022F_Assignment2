.RECIPEPREFIX +=
CC = g++
CFLAGS = -lm -lrt

PROG = bin/*
OBJS = obj/*

default:
    mkdir -p bin obj
    $(CC) $(CFLAGS) -c src/Driverimage.cpp -o obj/Driverimage
    $(CC) $(CFLAGS) -c src/volimage.cpp -o obj/volimage
    $(CC) $(CFLAGS) obj/Driverimage obj/volimage -o bin/volimage

run:
    bin/volimage

clean:
    rm $(PROG) $(OBJS)


