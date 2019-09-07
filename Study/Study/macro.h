#ifndef _BIT_H_
#define _BIT_H_

typedef struct _bits {
	char b0: 1;
	char b1: 1;
	char b2: 1;
	char b3: 1;
	char b4: 1;
	char b5: 1;
	char b6: 1;
	char b7: 1;
} __attribute__((__packed__)) bits;

#define bit(X, Y) ((*(volatile bits*)&X).b##Y) 

#define sb(X) (1 << (X))
#define cbit(X, Y) X &= ~sb(Y)
#define sbit(X, Y) X |= sb(Y)
#define fbit(X, Y) X ^= sb(Y)
#define out(X, Y, Z) (Z ? sbit(X, Y) : cbit(X, Y))
#define in(X, Y) ((X & sb(Y)) >> Y)

#endif