########################################################################
# File: makefile
# 
# Description: DLL and C Connect test suite makefile for MacOS X x86.
#
#	Copyright (C) 2006 Cincom Systems, Inc., Santa Clara, California,
#	Georg Heeg, Dortmund Germany.  All Rights Reserved.
########################################################################

COPTS=-g

# Edit the following if Debugging is not needed
DEBUGOPTS=
LINKOPTS=-dynamic -bundle -flat_namespace -undefined suppress
IMPORTOPTS=
SRC = 

CC= cc
LD= ld

cptst.so: cptst-i386.so cptst-ppc.so
	lipo -create cptst-i386.so cptst-ppc.so -output cptst.so

cptst-i386.so: cptst-i386.o cptstcabi-i386.o
	$(LD) -arch i386 -o cptst-i386.so cptst-i386.o cptstcabi-i386.o $(LINKOPTS) $(IMPORTOPTS)

cptst-i386.o: cptst.h cptst.c oeAPI.h makefile
	$(CC) -arch i386 $(COPTS) $(DEBUGOPTS) -c cptst.c -o cptst-i386.o 

cptstcabi-i386.o: cptst.h cptstcabi.c oeAPI.h makefile
	$(CC) -arch i386 $(COPTS) $(DEBUGOPTS) -c cptstcabi.c -o cptstcabi-i386.o

cptst-ppc.so: cptst-ppc.o cptstcabi-ppc.o
	$(LD) -arch ppc -o cptst-ppc.so cptst-ppc.o cptstcabi-ppc.o $(LINKOPTS) $(IMPORTOPTS)

cptst-ppc.o: cptst.h cptst.c oeAPI.h makefile
	$(CC) -arch ppc $(COPTS) $(DEBUGOPTS) -c cptst.c -o cptst-ppc.o 

cptstcabi-ppc.o: cptst.h cptstcabi.c oeAPI.h makefile
	$(CC) -arch ppc $(COPTS) $(DEBUGOPTS) -c cptstcabi.c -o cptstcabi-ppc.o

cptst: cptst-i386 cptst-ppc
	lipo -create cptst-i386 cptst-ppc -output cptst

cptst-i386: testcabi.c cptstcabi.c makefile
	$(CC) -arch i386 -o cptst-i386 $(COPTS) $(DEBUGOPTS) testcabi.c cptstcabi.c 

cptst-ppc: testcabi.c cptstcabi.c makefile
	$(CC) -arch ppc -o cptst-ppc $(COPTS) $(DEBUGOPTS) testcabi.c cptstcabi.c 


