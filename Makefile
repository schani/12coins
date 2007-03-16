coins : coins.c
	gcc -o coins coins.c

clean :
	rm -f *~ coins

dist :
	rm -rf 12coins
	mkdir 12coins
	cp Makefile README COPYING coins.c 12coins/
	tar -zcvf 12coins.tar.gz 12coins
	rm -rf 12coins
