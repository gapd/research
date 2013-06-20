########################################################################
# File: makefile
# 
# Description: DLLCC test suite makefile for 64-bit x86-64 on Linux 2.x and up
#
#	Copyright (C) 2004-2006 Cincom Systems, Inc.
#	Santa Clara, California.  All Rights Reserved.
########################################################################

# use -g rather than -g -O for full debugging
COPTION=-m64 -mieee-fp -fsigned-char -g -O2 -Wall -D_REENTRANT -D_LIBC_REENTRANT
#COPTION=-m64 -mieee-fp -fsigned-char -g -Wall -D_REENTRANT -D_LIBC_REENTRANT

# define -DOEUNSAFE and/or -DUNSAFE here if you want to live dangerously (i.e. no tech support)
SAFETY= 
#SAFETY= -DOEUNSAFE -DUNSAFE

CFLAGS= -DVW64=1 $(COPTION) $(SAFETY)

cptst.so: cptst.c cptstcabi.c
	$(CC) -c $(CFLAGS) -fpic cptst.c cptstcabi.c
	ld -o cptst.so -shared cptst.o cptstcabi.o

# User Primitive Support

# The name of resultant OE executable
WHO = visualworksUser

# Name(s) of test files
USER = cpint.o cptst.o

BASEOBJS = visual.o
LIBS =  -export-dynamic -L/usr/X11R6/lib -lpthread -ldl -lX11 -lm

$(WHO):	$(BASEOBJS) $(USER)
	$(CC) $(CFLAGS) -o $(WHO) $(BASEOBJS) $(USER) $(LIBS)

cptst:	testcabi.c cptstcabi.c
	$(CC) -o cptst $(CFLAGS) testcabi.c cptstcabi.c

$(USER):  userprim.h
userprim.h: up_unsafe.h
up_unsafe.h: unsafe_oops.h
