########################################################################
# File: makefile
# 
# Description: DLLC suite makefile for PowerPC Linux 2.x and up
#
#	Copyright (C) 2002-2006 Cincom Systems, Inc.
#	Santa Clara, California.  All Rights Reserved.
########################################################################

# use -g rather than -g -O for full debugging
#COPTION=-fsigned-char -g -O -Wall -D_REENTRANT -D_LIBC_REENTRANT
COPTION=-fsigned-char -g -Wall -D_REENTRANT -D_LIBC_REENTRANT

# define -DOEUNSAFE and/or -DUNSAFE here if you want to live dangerously (i.e. no tech support)
SAFETY= 
#SAFETY= -DOEUNSAFE -DUNSAFE

CFLAGS= $(COPTION) $(SAFETY)

cptst.so: cptst.c cptstcabi.c
	$(CC) -o cptst.so -shared -static $(CFLAGS) -fpic cptst.c cptstcabi.c

# User Primitive Support

# The name of resultant OE executable
WHO = visualworksUser

# Name(s) of test files
USER = cpint.o cptst.o cptstcabi.o

BASEOBJS = visual.o
LIBS =  -export-dynamic -L/usr/X11R6/lib -lpthread -ldl -lX11 -lm

$(WHO):	$(BASEOBJS) $(USER)
	$(CC) $(CFLAGS) -o $(WHO) $(BASEOBJS) $(USER) $(LIBS)

cptst:  testcabi.c cptstcabi.c
	$(CC) -o cptst $(CFLAGS) testcabi.c cptstcabi.c

$(USER):  userprim.h
userprim.h: up_unsafe.h
up_unsafe.h: unsafe_oops.h
