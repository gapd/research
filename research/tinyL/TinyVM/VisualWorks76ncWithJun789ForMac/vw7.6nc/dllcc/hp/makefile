########################################################################
# File: makefile
# 
# Description: DLL and C Connect test suite makefile for HPPA.
#
#	Copyright (C) 1999-2006 Cincom Systems, Inc.
#	Santa Clara, California.  All Rights Reserved.
########################################################################

# use -g rather than -O for debugging
#COPTION= -O -Aa +e +DA2.0
COPTION= -g -Aa +e +DA2.0

# define -DOEUNSAFE and/or -DUNSAFE here if you want to live dangerously (i.e. no tech support)
SAFETY=
#SAFETY=-DOEUNSAFE -DUNSAFE

CFLAGS = $(COPTION) $(SAFETY)

cptst.sl: cptst.c cptstcabi.c
	$(CC) $(CFLAGS) +z -c cptst.c cptstcabi.c
	ld -o cptst.sl -b cptst.o cptstcabi.o

# User Primitive Support

# The name of resultant OE executable
WHO = visualworksUser

# Name(s) of test files
USER = cpint.o cptst.o

BASEOBJS = visual.o
LIBS =  -lm -ldld -L/usr/lib/X11R5 -L/usr/lib/X11R5 -lX11

$(WHO):	$(BASEOBJS) $(USER)
	$(CC) $(CFLAGS) -c cptst.c
	$(CC) $(CFLAGS) -o $(WHO) $(BASEOBJS) $(USER) $(LIBS)
	chatr -B immediate -B nonfatal +s enable $(WHO)

cptst:  testcabi.c cptstcabi.c
	$(CC) -o cptst $(CFLAGS) testcabi.c cptstcabi.c -lm

$(USER):  userprim.h oeAPI.h
userprim.h: up_unsafe.h
up_unsafe.h: unsafe_oops.h
