all: arb_zeta

turing.o: turing.c turing.h parameters.h win_zeta.h inter.h
	gcc -c -Wall turing.c -O2 -finline-functions -fomit-frame-pointer

inter.o: inter.c inter.h parameters.h win_zeta.h
	gcc -c -Wall inter.c -O2 -finline-functions -fomit-frame-pointer

win_zeta.o: win_zeta.c win_zeta.h
	gcc -c -Wall win_zeta.c -O2 -finline-functions -fomit-frame-pointer

arb_zeta.o: arb_zeta.c parameters.h win_zeta.h arb_fft.h inter.h turing.h
	gcc -c -Wall arb_zeta.c -O2 -finline-functions -fomit-frame-pointer

arb_fft.o: arb_fft.c arb_fft.h
	gcc -c -Wall arb_fft.c -O2 -finline-functions -fomit-frame-pointer

arb_zeta: arb_zeta.o arb_fft.o win_zeta.o inter.o turing.o
	gcc -o arb_zeta arb_zeta.o arb_fft.o turing.o inter.o win_zeta.o -larb

clean:
	rm -f arb_zeta *.o