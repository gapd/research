# SccsId is "@(#)solarisx86_64.makefile	62.7"
########################################################################
# File: makefile
# 
# Description: DLL and C Connect test suite makefile for 64-bit VMs on Solaris.
#
#	Copyright (C) 1999-2006 Cincom Systems, Inc.
#	Santa Clara, California.  All Rights Reserved.
########################################################################

## NOTE ## ## NOTE ## ## NOTE ## ## NOTE ## ## NOTE ##
## THIS MUST BE EDITED TO FIT YOUR INSTALATION ##
CBASE = /opt/SUNWspro

CC=${CBASE}/bin/cc

# use -g rather than -g -O for full debugging
COPTION= -mt -g -O -Xa -xlibmieee -D_REENTRANT -xarch=amd64
#COPTION= -mt -g -Xa -xlibmieee -D_REENTRANT -xarch=amd64

# define -DOEUNSAFE and/or -DUNSAFE here if you want to live dangerously (i.e. no tech support)
SAFETY= 
#SAFETY= -DOEUNSAFE -DUNSAFE

CFLAGS= -DVW64=1 $(COPTION) $(SAFETY)

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
