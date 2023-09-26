CC = g++
CFLAGS = -Wall -g

main.exe: main.o linkedList.o
	$(CC) $(CFLAGS) -o main.exe main.o linkedList.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

admissions.o: linkedList.cpp 
	$(CC) $(CFLAGS) -c linkedList.cpp

clean:
	rm -f *o main.exe *gch