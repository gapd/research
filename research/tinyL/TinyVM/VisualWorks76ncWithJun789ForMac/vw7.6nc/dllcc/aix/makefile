########################################################################
# File: makefile
# 
# Description: DLL and C Connect test suite makefile for AIX 5.x
#
#	Copyright (C) 1999-2006 Cincom Systems, Inc., Santa Clara, California, 
#   Georg Heeg, Dortmund Germany.  All Rights Reserved.
#
########################################################################

COPTS=-q32 -O -g
LINKOPTS=-bM:SRE -G -bexpall -bnoentry -lc

CC=/usr/vac/bin/cc
LD=/usr/ccs/bin/ld

cptst.so: cptst.h cptst.c cptstcabi.c oeAPI.h makefile
	$(CC) -c $(COPTS) cptst.c cptstcabi.c
	$(LD) -o cptst.so cptst.o cptstcabi.o $(LINKOPTS)

# User Primitive Support

# The name of resultant OE executable
WHO = visualworksUser

# Name(s) of test files
USER = cpint.o cptst.o cptstcabi.o

BASEOBJS=visual.o
LIBS=-lm -lX11 -lld -lbsd -lpthreads -bexpall -brtl

$(WHO):	$(BASEOBJS) $(USER)
	$(CC) $(COPTS) -c cptst.c
	$(CC) $(COPTS) -o $(WHO) $(BASEOBJS) $(USER) $(LIBS)

cptst: testcabi.c cptstcabi.c
	$(CC) -o cptst $(COPTS) testcabi.c cptstcabi.c -lm

$(USER): userprim.h oeAPI.h
userprim.h: up_unsafe.h
up_unsafe.h: unsafe_oops.h
