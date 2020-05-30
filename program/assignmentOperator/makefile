Tool=g++
objects=main.o assignmentOperator.o
all:main.o assignmentOperator.o
	$(Tool) -o all $(objects) -std=c++11
main.o:main.cpp assignmentOperator.h
	$(Tool) -c main.cpp -std=c++11
assignmentOperator.o:assignmentOperator.cpp assignmentOperator.h
	$(Tool) -c assignmentOperator.cpp -std=c++11

clean:
	rm all $(objects)

