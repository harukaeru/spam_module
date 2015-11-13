CFLAGS=$$(pkg-config --cflags python3)
LIBS=$$(pkg-config --libs python3)

spam.so: spam.o
	gcc --shared spam.o $(LIBS) -o spam.so
spam.o:
	gcc -c spam.c $(CFLAGS) -o spam.o
pointer:
	gcc pointer.c -o pointer
clean:
	rm -rf spam.so spam.o pointer
