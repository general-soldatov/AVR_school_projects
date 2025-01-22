
/*
 * BCD.h
 *
 * Created: 17.01.2025 20:53:06
 *  Author: GS
 */ 


/*
 * BCD.h
 *
 * Created: 17.01.2025 20:32:12
 *  Author: GS
 */ 

#ifndef HEADER_BCD
#define HEADER_BCD

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6

#define ZERO (1 << A)|(1 << B)|(1 << C)|(1 << D)|(1 << E)|(1 << F)
#define ONE (1 << B)|(1 << C)
#define TWO (1 << A)|(1 << B)|(1 << G)|(1 << E)|(1 << D)
#define THREE (1 << A)|(1 << B)|(1 << G)|(1 << C)|(1 << D)
#define FOUR (1 << B)|(1 << F)|(1 << G)|(1 << C)
#define FIVE (1 << A)|(1 << F)|(1 << G)|(1 << C)|(1 << D)
#define SIX (1 << A)|(1 << F)|(1 << E)|(1 << D)|(1 << C)|(1 << G)
#define SEVEN (1 << A)|(1 << B)|(1 << C)
#define EIGHT (1 << A)|(1 << B)|(1 << C)|(1 << D)|(1 << E)|(1 << F)|(1 << G)
#define NINE (1 << A)|(1 << B)|(1 << C)|(1 << D)|(1 << F)|(1 << G)
#endif



