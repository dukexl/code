objects = main.o singleton.o
CC = g++
Env = '-std=c++11'
all:$(objects)
	$(CC) -o all $(objects) $(Env)

main.o:singleton.h
singlton.o:singleton.h


.PHONY:clean
clean:
	rm all $(objects)

