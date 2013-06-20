/************************************************************************
 * File: cptst.h
 *
 * Description: DLL and C Connect test suite interface header.
 *
 *	Copyright (C) 1999-2007 Cincom Systems, Inc.
 *	Santa Clara, California.  All Rights Reserved.
 ************************************************************************/

/*
 * If we're on a Windows platform define the Callback entry points
 * and DLL entry points appropriately using Microsoft type qualifiers.
 * On non-Windows machines simply define the qualifiers as no-ops.
 */
#if defined(_WINDLL)
# define CALLBACKENTRY _far PASCAL
# define DLLENTRY _export _far PASCAL
#elif defined(WIN32)
# define CALLBACKENTRY _cdecl
# define DLLENTRY _stdcall
# define _far
#elif defined(WIN32SFAR)
# define CALLBACKENTRY _far
# define DLLENTRY _far _export
# define int short
#else
# define CALLBACKENTRY
# define DLLENTRY
# define _far
#endif

#ifndef MACENTRY
# define MACENTRY
#endif

#ifndef MACCALLBACKENTRY
# define MACCALLBACKENTRY
#endif

#include "cptstcabi.h"

extern char globalChar;
extern unsigned char unsignedChar;
extern short globalShort;
extern unsigned short unsignedShort;
extern int globalInt;
extern unsigned int unsignedInt;
extern long globalLong;
extern unsigned long unsignedLong;
extern float globalFloat;
extern double globalDouble;
extern CharStruct globalCharStruct;
extern BigStruct globalBigStruct;

#ifndef UPNOTSUPPORTED

MACENTRY upHandle DLLENTRY
TstSendBackKeepFailure(upHandle, upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendBackMany(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendBack0(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendBack1(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendBack2(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendBack3(upHandle, upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendcBackMany(upHandle, char _far *, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendcBack0(upHandle, char _far *);

MACENTRY upHandle DLLENTRY
TstSendcBack1(upHandle, char _far *, upHandle);

MACENTRY upHandle DLLENTRY
TstSendcBack2(upHandle, char _far *, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendcBack3(upHandle, char _far *, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendBack0IfFailNoReturn(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendBack0IfFailReturnFalse(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstSendBack0ReturnKeptReceiver(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTbool(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTchar(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTfloat(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTint(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCbool(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCchar(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCfloat(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCint(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPbasicAt(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPbasicAtPut(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPbyteAt(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPbyteAtPut(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPcopyCtoSTintArray(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPcopyCtoSTbytes(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPcopyCtoSTfloatArray(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPcopyCtoSTstring(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPcopySTtoCbytes(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPcopySTtoCfloatArray(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPcopySTtoCintArray(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPcopySTtoCstring(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPfloatAt(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPintegerAt(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPfloatAtPut(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPindexVarSize(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPinstVarAt(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPinstVarAtPut(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPinstVarSize(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPintegerAtPut(upHandle, upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisArrayOfFloat(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisArrayOfInteger(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisBoolean(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisByteArray(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisCharacter(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisFloat(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisInteger(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisString(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisByteLike(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPnil(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPnestedReturn(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPreturnNil(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPreturnTrue(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPreturnHandle(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPreturnFalse(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPerrorHandler(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPregHandleAt(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisImmediate(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPallocRegSlot(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPregHandleAtPut(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPallocFs(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPallocVs(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPclassType(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPsignalSem(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPMyPollHandler(void);

MACENTRY upHandle DLLENTRY
TstExternalUPpostInt(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisKindOf(upHandle, upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTdouble(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCdouble(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPisDouble(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPclass(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalSumByteArray(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalZeroArray(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPdoubleAt(upHandle, upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeCharacter(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeInteger(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeString(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeByteArray(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeArrayOfInteger(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeArrayOfFloat(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeBoolean(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeByteLike(upHandle);

MACENTRY upHandle DLLENTRY
TstExternalTstExternalUPlongRun(upHandle);


#endif /* ifndef UPNOTSUPPORTED */


#ifndef OENOTSUPPORTED

MACENTRY OEoop DLLENTRY
oeTstSendBackKeepFailure(
	OEoop oReceiver,
	OEoop oSelector,
	OEoop oArgs,
	OEoop oKeep,
	OEoop oFailure);

MACENTRY OEoop DLLENTRY
oeTstSendBackMany(
	OEoop oReceiver,
	OEoop oSelector,
	OEoop oArgs);

MACENTRY OEoop DLLENTRY
oeTstSendBack0(OEoop oReceiver, OEoop oSelector);

MACENTRY OEoop DLLENTRY
oeTstSendBack1(OEoop oReceiver, OEoop oSelector, OEoop oArg1);

MACENTRY OEoop DLLENTRY
oeTstSendBack2(OEoop oReceiver, OEoop oSelector, OEoop oArg1, OEoop oArg2);

MACENTRY OEoop DLLENTRY
oeTstSendBack3(OEoop oReceiver, OEoop oSelector, OEoop oArg1, OEoop oArg2, OEoop oArg3);

MACENTRY OEoop DLLENTRY
oeTstSendcBackMany(
	OEoop oReceiver,
	char *szSelector,
	OEoop oArg1,
	OEoop oArg2);

MACENTRY OEoop DLLENTRY
oeTstSendcBack0(OEoop oReceiver, char *selector);

MACENTRY OEoop DLLENTRY
oeTstSendcBack1(OEoop oReceiver, char *selector, OEoop oArg1);

MACENTRY OEoop DLLENTRY
oeTstSendcBack2(OEoop oReceiver, char *selector, OEoop oArg1, OEoop oArg2);

MACENTRY OEoop DLLENTRY
oeTstSendcBack3(OEoop oReceiver, char *selector, OEoop oArg1, OEoop oArg2, OEoop oArg3);

MACENTRY OEoop DLLENTRY
oeTstSendBack0IfFailNoReturn(OEoop oReceiver, OEoop oSelector);

MACENTRY OEoop DLLENTRY
oeTstSendBack0IfFailReturnFalse(OEoop oReceiver, OEoop oSelector);

MACENTRY OEoop DLLENTRY
oeTstSendBack0ReturnKeptReceiver(OEoop oReceiver, OEoop oSelector);

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEbool(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEchar(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEfloat(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEint(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCbool(OEoop rcvr, OEoop aBoolOop);

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCchar(OEoop rcvr, OEoop aCharOop);

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCfloat(OEoop rcvr, OEoop aFloatOop);

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCint(OEoop rcvr, OEoop anIntOop);

MACENTRY OEoop DLLENTRY
oeTstExternalBasicAt(OEoop rcvr, OEoop arrayOEoop, OEoop indexOop);

MACENTRY OEoop DLLENTRY
oeTstExternalBasicAtPut(OEoop rcvr, OEoop arrayOEoop,
						OEoop indexOop, OEoop OEoopToBePut);

MACENTRY OEoop DLLENTRY
oeTstExternalByteAt(OEoop rcvr, OEoop argOop, OEoop indexOop);

MACENTRY OEoop DLLENTRY
oeTstExternalByteAtPut(OEoop rcvr,OEoop argOop, OEoop indexOop, OEoop byteOop);

MACENTRY OEoop DLLENTRY
oeTstExternalCopyCtoOEintArray(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop);

MACENTRY OEoop DLLENTRY
oeTstExternalCopyCtoOEbytes(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop);

MACENTRY OEoop DLLENTRY
oeTstExternalCopyCtoOEfloatArray(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop);

MACENTRY OEoop DLLENTRY
oeTstExternalCopyCtoOEstring(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop);

MACENTRY OEoop DLLENTRY
oeTstExternalCopyOEtoCbytes(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop);

MACENTRY OEoop DLLENTRY
oeTstExternalCopyOEtoCfloatArray(OEoop rcvr, OEoop argOop, OEoop aCountOop,
								 OEoop startingAtOop);

MACENTRY OEoop DLLENTRY
oeTstExternalCopyOEtoCintArray(OEoop rcvr, OEoop argOop, OEoop aCountOop,
								OEoop startingAtOop);
MACENTRY OEoop DLLENTRY
oeTstExternalCopyOEtoCstring(OEoop rcvr, OEoop argOop, OEoop aCountOop,
								OEoop startingAtOop);

MACENTRY OEoop DLLENTRY
oeTstExternalFloatAt(OEoop rcvr, OEoop argOop, OEoop indexOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIntegerAt(OEoop rcvr, OEoop argOop, OEoop indexOop);

MACENTRY OEoop DLLENTRY
oeTstExternalFloatAtPut(OEoop rcvr, OEoop argOop, OEoop indexOop, OEoop aFloatOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIndexVarSize(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalInstVarAt(OEoop rcvr, OEoop argOop, OEoop indexOop);

MACENTRY OEoop DLLENTRY
oeTstExternalInstVarAtPut(OEoop rcvr, OEoop argOop, OEoop indexOop, OEoop OEoopToBePut);

MACENTRY OEoop DLLENTRY
oeTstExternalInstVarSize(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIntegerAtPut(OEoop rcvr, OEoop argOop, OEoop indexOop, OEoop anIntOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsArrayOfFloat(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsArrayOfInteger(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsBoolean(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsByteArray(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsCharacter(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsFloat(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsInteger(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsString(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsByteLike(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalNil(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstreturn(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalReturnFalse(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstExternalReturnHandle(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalNestedReturn(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalReturnNil(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstExternalReturnTrue(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstExternalRegHandleAt(OEoop rcvr, OEoop indexOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsImmediate(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalAllocRegSlot(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstExternalRegHandleAtPut(OEoop rcvr, OEoop indexOop, OEoop valOop);

MACENTRY OEoop DLLENTRY
oeTstExternalAllocFs(OEoop rcvr, OEoop cls);

MACENTRY OEoop DLLENTRY
oeTstExternalAllocVs(OEoop rcvr, OEoop cls, OEoop szOop);

MACENTRY OEoop DLLENTRY
oeTstExternalClassType(OEoop rcvr, OEoop cls);

MACENTRY OEoop DLLENTRY
oeTstExternalSignalSem(OEoop rcvr, OEoop sem);

void OEENTRY
oeTstExternalMyPollHandler(void);

MACENTRY OEoop DLLENTRY
oeTstExternalPostInt(OEoop rcvr, OEoop sem);

MACENTRY OEoop DLLENTRY
oeTstExternalIsKindOf(OEoop rcvr, OEoop inst, OEoop cls);

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEdouble(OEoop rcvr);

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCdouble(OEoop rcvr,OEoop aDoubleOop);

MACENTRY OEoop DLLENTRY
oeTstExternalIsDouble(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalClass(OEoop rcvr, OEoop argOop);

MACENTRY OEoop DLLENTRY
oeTstExternalSumByteArray(OEoop rcvr, OEoop baOop);

MACENTRY OEoop DLLENTRY
oeTstExternalZeroArray(OEoop rcvr, register OEoop aOop);

MACENTRY OEoop DLLENTRY
oeTstExternalDoubleAt(OEoop oeArray, OEoop indexOop);

MACENTRY OEoop DLLENTRY
oeTstExternalLongRun(OEoop oeObject);

#endif
