default: keywords keywords2

CFLAGS = -x c -g -std=c99 -pedantic-errors

keywords: keywords.o getch.o

keywords2: keywords2.o getch.o

kw: kw.o getch.o

clean:
	rm -f *~ *.exe *.o *.stackdump
