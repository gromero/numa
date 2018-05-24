%.o:	%.c
	gcc -g -c $< -o $@ -lnuma

all:	numa.o
	gcc -g numa.o -o numa -lnuma

clean:
	rm -fr numa
	rm -fr *.o
