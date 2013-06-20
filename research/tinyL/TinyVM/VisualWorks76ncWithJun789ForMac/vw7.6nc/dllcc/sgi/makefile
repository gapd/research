########################################################################
# File: makefile
#
# Description: DLL and C Connect test suite makefile for SGI IRIX
#
#   Copyright (C) 1999-2006 Cincom Systems, Inc., Santa Clara, California,
#   Georg Heeg, Dortmund Germany.  All Rights Reserved.
########################################################################

CFLAGS=-mips2 -g3

cptst.so: cptst.o cptstcabi.o  makefile
	ld -mips2 -o cptst.so -shared cptst.o cptstcabi.o 

cptst.o: cptst.c cptst.h cptstcabi.h oeAPI.h makefile 
	cc $(CFLAGS) -c cptst.c

cptstcabi.o: cptstcabi.c cptst.h cptstcabi.h oeAPI.h makefile 
	cc $(CFLAGS) -c cptstcabi.c

testcabi.o: testcabi.c cptstcabi.h makefile 
	cc $(CFLAGS) -c testcabi.c

unsafetst.o: cptst.c cptst.h oeAPI.h makefile 
	cc -mips2 -c cptst.c -o unsafetst.o -D OEUNSAFE

unsafetst.so: unsafetst.o makefile
	ld -mips2 unsafetst.o -shared -o unsafetst.so


cptst: testcabi.o cptstcabi.o
	cc $(CFLAGS) -o cptst testcabi.o cptstcabi.o

all: cptst.so cptst
