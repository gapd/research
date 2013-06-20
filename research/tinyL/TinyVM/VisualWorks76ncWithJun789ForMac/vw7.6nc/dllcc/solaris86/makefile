# SccsId is "@(#)solaris86.makefile	62.7"
########################################################################
# File: makefile
# 
# Description: DLL and C Connect test suite makefile for Solaris 10 i386
#
#	Copyright (C) 2005-2006 Cincom Systems, Inc.
#	Santa Clara, California.  All Rights Reserved.
########################################################################

## NOTE ## ## NOTE ## ## NOTE ## ## NOTE ## ## NOTE ##
## THIS MUST BE EDITED TO FIT YOUR INSTALATION ##
CBASE = /opt/SUNWspro

CC=${CBASE}/bin/cc

# use -g rather than -g -O for full debugging
COPTION= -mt -g -xarch=generic -xO1 -Xa -xlibmieee -D_REENTRANT
#COPTION= -mt -g -Xa -xlibmieee -D_REENTRANT

# define -DOEUNSAFE and/or -DUNSAFE here if you want to live dangerously (i.e. no tech support)
SAFETY= 
#SAFETY= -DOEUNSAFE -DUNSAFE

CFLAGS= $(COPTION) $(SAFETY)

cptst.so: cptst.c cptstcabi.c
	$(CC) -c $(CFLAGS) -K pic cptst.c cptstcabi.c
	ld -o cptst.so -G cptst.o cptstcabi.o

# User Primitive Support

# The name of resultant OE executable
WHO = visualworksUser

# Name(s) of test files
USER = cpint.o cptst.o cptstcabi.o

BASEOBJS = visual.o
THREADLIBS = -lpthread -lposix4 -lthread
LIBS =  -L/usr/openwin/lib $(THREADLIBS) -lsocket -lnsl -ldl -lX11 -lm

$(WHO):	$(BASEOBJS) $(USER)
	$(CC) $(CFLAGS) -o $(WHO) $(BASEOBJS) $(USER) $(LIBS)

cptst:	testcabi.c cptstcabi.c
	$(CC) $(CFLAGS) -o cptst testcabi.c cptstcabi.c -lm

$(USER):  userprim.h
userprim.h: up_unsafe.h
up_unsafe.h: unsafe_oops.h
