# Microsoft Visual C++ generated build script - Do not modify
# Makefile for 16-bit test suite DLL on Windows 95/3.1

PROJ = CPTST16
DEBUG = 1
PROGTYPE = 1
CALLER =
ARGS =
DLLS =
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = C:\CPOK20\MAKE\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG =
CPPCREATEPCHFLAG =
CUSEPCHFLAG =
CPPUSEPCHFLAG =
FIRSTC = CPTST.C
FIRSTCPP =
RC = rc
CFLAGS_D_WDLL = /nologo /f- /G2 /Zp8 /W3 /Zi /ALw /Od /D "UPNOTSUPPORTED" /D "_DEBUG" /D "OENOTSUPPORTED" /FR /GD /Fd"CPTST16.PDB"  /D /D
CFLAGS_R_WDLL = /nologo /W3 /ALw /O1 /D "NDEBUG" /FR /GD
LFLAGS_D_WDLL = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:61440 /CO /NOE /ALIGN:16 /MAP:FULL
LFLAGS_R_WDLL = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:61440 /NOE /ALIGN:16 /MAP:FULL
LIBS_D_WDLL = oldnames libw commdlg shell olecli olesvr ldllcew
LIBS_R_WDLL = oldnames libw commdlg shell olecli olesvr ldllcew
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS =
DEFFILE = CPTST16.DEF
OBJS_EXT =
LIBS_EXT =
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WDLL)
LFLAGS = $(LFLAGS_D_WDLL)
LIBS = $(LIBS_D_WDLL)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WDLL)
LFLAGS = $(LFLAGS_R_WDLL)
LIBS = $(LIBS_R_WDLL)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = CPTST16.SBR


CPTST_DEP = oeAPI.h \
			userprim.h \
			up_defs.h \
			cptst.h


all:	$(PROJ).DLL $(PROJ).BSC

CPTST.OBJ:	CPTST.C $(CPTST_DEP)
	$(CC) $(CFLAGS) $(CCREATEPCHFLAG) /c CPTST.C


$(PROJ).DLL::	CPTST.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
CPTST.OBJ +
$(OBJS_EXT)
$(PROJ).DLL
$(MAPFILE)
C:\MSVC\LIB\+
C:\MSVC\MFC\LIB\+
C:\WIN32S\UT\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) $@
	implib /nowep $(PROJ).LIB $(PROJ).DLL


run: $(PROJ).DLL
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
