/************************************************************************
 * File: cptst.c
 *
 * Description: The DLL and C Connect test suite source code.
 *
 *	Copyright (C) 1999-2007 Cincom Systems, Inc.
 *	Santa Clara, California.  All Rights Reserved.
 ************************************************************************/

#include <stdlib.h>
#include <memory.h>
#include <string.h>

#include "userprim.h"
#include "oeAPI.h"
#include "cptst.h"

char globalChar;
unsigned char unsignedChar;
short globalShort;
unsigned short unsignedShort;
int globalInt;
unsigned int unsignedInt;
long globalLong;
unsigned long unsignedLong;
float globalFloat;
double globalDouble;
CharStruct globalCharStruct;
BigStruct globalBigStruct;

#ifndef UPNOTSUPPORTED

MACENTRY upHandle DLLENTRY
TstSendBackKeepFailure(
	upHandle oReceiver,
	upHandle oSelector,
	upHandle oArgs,
	upHandle oKeep,
	upHandle oFailure)
{
	return UPSendMessage1(
			oReceiver,
			oSelector,
			oArgs,
			&oKeep,
			oFailure);
}

MACENTRY upHandle DLLENTRY
TstSendBackMany(upHandle oReceiver, upHandle oSelector, upHandle oArgs)
{
	return UPSendMessageMany(
			oReceiver,
			oSelector,
			oArgs,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendBack0(upHandle oReceiver, upHandle oSelector)
{
	return UPSendMessage0(
			oReceiver,
			oSelector,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendBack1(upHandle oReceiver, upHandle oSelector, upHandle oArg1)
{
	return UPSendMessage1(
			oReceiver,
			oSelector,
			oArg1,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendBack2(upHandle oReceiver, upHandle oSelector, upHandle oArg1, upHandle oArg2)
{
	return UPSendMessage2(
			oReceiver,
			oSelector,
			oArg1, oArg2,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendBack3(upHandle oReceiver, upHandle oSelector, upHandle oArg1, upHandle oArg2, upHandle oArg3)
{
	return UPSendMessage3(
			oReceiver,
			oSelector,
			oArg1, oArg2, oArg3,
			(upHandle *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendcBackMany(
	upHandle oReceiver,
	char _far *szSelector,
	upHandle oArg1,
	upHandle oArg2)
{
	upHandle argArray[2];

	argArray[0] = oArg1;
	argArray[1] = oArg2;
	return UPCSendMessageMany(
			oReceiver,
			szSelector,
			argArray,
			2,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendcBack0(upHandle oReceiver, char _far *selector)
{
	return UPCSendMessage0(
			oReceiver,
			selector,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendcBack1(upHandle oReceiver, char _far *selector, upHandle oArg1)
{
	return UPCSendMessage1(
			oReceiver,
			selector,
			oArg1,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendcBack2(upHandle oReceiver, char _far *selector, upHandle oArg1, upHandle oArg2)
{
	return UPCSendMessage2(
			oReceiver,
			selector,
			oArg1, oArg2,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendcBack3(upHandle oReceiver, char _far *selector, upHandle oArg1, upHandle oArg2, upHandle oArg3)
{
	return UPCSendMessage3(
			oReceiver,
			selector,
			oArg1, oArg2, oArg3,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendBack0IfFailNoReturn(upHandle oReceiver, upHandle oSelector)
{
	return UPSendMessage0(
			oReceiver,
			oSelector,
			(upHandle _far *) 0,
			(upHandle) 0);
}

MACENTRY upHandle DLLENTRY
TstSendBack0IfFailReturnFalse(upHandle oReceiver, upHandle oSelector)
{
	return UPSendMessage0(
			oReceiver,
			oSelector,
			(upHandle _far *) 0,
			UPCtoSTbool(0));
}

MACENTRY upHandle DLLENTRY
TstSendBack0ReturnKeptReceiver(upHandle oReceiver, upHandle oSelector)
{
	upHandle keep[1];
	keep[0] = oReceiver;
	UPSendMessage0(
			oReceiver,
			oSelector,
			keep,
			(upHandle) 0);
	return keep[0];
}

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTbool(upHandle rcvr)
{
	return(UPCtoSTbool(TRUE));
}

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTchar(upHandle rcvr)
{
	return(UPCtoSTchar('c'));
}

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTfloat(upHandle rcvr)
{
	return(UPCtoSTfloat(3.14f));
}

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTint(upHandle rcvr)
{
	return(UPCtoSTint((upInt)42));
}

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCbool(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool((upBool)(UPSTtoCbool(arg))));
}

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCchar(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTchar(UPSTtoCchar(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCfloat(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTfloat(UPSTtoCfloat(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCint(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTint(UPSTtoCint(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPbasicAt(upHandle rcvr, upHandle arrayUpHandle, upHandle index)
{
	return(UPbasicAt(arrayUpHandle, UPSTtoCint(index)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPbasicAtPut(upHandle rcvr, upHandle arrayUpHandle,
                        upHandle index, upHandle upHandleToBePut)
{
	upHandle old;

	old = UPbasicAt(arrayUpHandle, (int)UPSTtoCint(index));
	UPbasicAtPut(arrayUpHandle, (int)UPSTtoCint(index), upHandleToBePut);
	return(old);
}

MACENTRY upHandle DLLENTRY
TstExternalUPbyteAt(upHandle rcvr, upHandle arg, upHandle index)
{
	return(UPCtoSTint((upInt)UPbyteAt(arg, UPSTtoCint(index))));
}

MACENTRY upHandle DLLENTRY
TstExternalUPbyteAtPut(upHandle rcvr, upHandle arg, upHandle index,
                       upHandle aUpByte)
{
	upInt i;
	upInt old;

	i = UPSTtoCint(index);
	old = UPbyteAt(arg, i);
	UPbyteAtPut(arg, i, (upByte)UPSTtoCint(aUpByte));
	return(UPCtoSTint(old));
}

MACENTRY upHandle DLLENTRY
TstExternalUPcopyCtoSTintArray(upHandle rcvr, upHandle arg,
                               upHandle aCount, upHandle startingAt)
{
	static upInt aUpIntPointer[3] = {1, 2, 3};
	return(UPCtoSTint(UPcopyCtoSTintArray(arg, aUpIntPointer,
												  UPSTtoCint(aCount),
												  UPSTtoCint(startingAt))));
}

MACENTRY upHandle DLLENTRY
TstExternalUPcopyCtoSTbytes(upHandle rcvr, upHandle arg,
                            upHandle aCount, upHandle startingAt)
{
	static upByte aUpBytes[3] = {0xff, 2, 0xfd};
	return(UPCtoSTint(UPcopyCtoSTbytes(arg, aUpBytes,
											   UPSTtoCint(aCount),
											   UPSTtoCint(startingAt))));
}

MACENTRY upHandle DLLENTRY
TstExternalUPcopyCtoSTfloatArray(upHandle rcvr, upHandle arg,
                                 upHandle aCount, upHandle startingAt)
{
	static upFloat aUpFloatPointer[3] = {-1.0f, 2.0f, -3.0f};
	return(UPCtoSTint(UPcopyCtoSTfloatArray(arg, aUpFloatPointer,
													UPSTtoCint(aCount),
													UPSTtoCint(startingAt))));
}

MACENTRY upHandle DLLENTRY
TstExternalUPcopyCtoSTstring(upHandle rcvr, upHandle arg,
                             upHandle aCount, upHandle startingAt)
{
	return(UPCtoSTint(UPcopyCtoSTstring(arg, "abc",
												UPSTtoCint(aCount),
												UPSTtoCint(startingAt))));
}

MACENTRY upHandle DLLENTRY
TstExternalUPcopySTtoCbytes(upHandle rcvr, upHandle arg,
                            upHandle aCount, upHandle startingAt)
{
	char aUpBytes[20];
	static upByte proto[6] = { 2, 2, 2, 2, 2, 2};
	upHandle myBA;

	memset(aUpBytes, 0, 20);
	memcpy(aUpBytes, (char *)proto, sizeof(proto));
	UPcopySTtoCbytes(arg,
						(upByte _far *)&aUpBytes[UPSTtoCint(startingAt)-1],
						UPSTtoCint(aCount) ,1L);
	myBA = UPallocByteArray((upByte)0, (upInt)sizeof(proto));
	UPcopyCtoSTbytes(myBA, (upByte _far *)aUpBytes, (upInt)sizeof(proto), 1L);
	return(myBA);
}

MACENTRY upHandle DLLENTRY
TstExternalUPcopySTtoCfloatArray(upHandle rcvr, upHandle arg,
                                 upHandle aCount, upHandle startingAt)
{
	upFloat aUpFloats[20];
	static upFloat proto[6] = { 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f};
	int sz;
	upHandle myA;

	memcpy((char *)aUpFloats, (char *)proto, sizeof(proto));
	UPcopySTtoCfloatArray(arg,
							&aUpFloats[UPSTtoCint(startingAt) - 1],
							UPSTtoCint(aCount),1L);
	sz = sizeof(proto) / sizeof(upFloat);
	myA = UPallocArray(UPCtoSTfloat(0.0f), (upInt)sz);
	UPcopyCtoSTfloatArray(myA, aUpFloats, (upInt)sz, 1L);
	return(myA);
}

MACENTRY upHandle DLLENTRY
TstExternalUPcopySTtoCintArray(upHandle rcvr, upHandle arg,
                               upHandle aCount, upHandle startingAt)
{
	upInt aUpInts[20];
	static upInt proto[6] = { 2, 2, 2, 2, 2, 2};
	upHandle myA;
	int sz;

	memcpy( (char *)aUpInts, (char *)proto, sizeof(proto));
	UPcopySTtoCintArray(arg,
						&aUpInts[UPSTtoCint(startingAt) - 1],
						UPSTtoCint(aCount),1L);
	sz = sizeof(proto) / sizeof(upInt);
	myA = UPallocArray(UPCtoSTint(0L), (upInt)sz);
	UPcopyCtoSTintArray(myA, aUpInts, (upInt)sz, 1L);
	return(myA);
}

MACENTRY upHandle DLLENTRY
TstExternalUPcopySTtoCstring(upHandle rcvr, upHandle arg,
                             upHandle aCount, upHandle startingAt)
{
	upHandle myA;
	char aUpString[20];

	strcpy(aUpString, "bbbbbb");
	UPcopySTtoCstring(arg, &aUpString[UPSTtoCint(startingAt) - 1],
					  UPSTtoCint(aCount),1L);
	myA = UPallocString(' ', (upInt)strlen(aUpString));
	UPcopyCtoSTstring(myA, aUpString, (upInt)strlen(aUpString), 1L);
	return(myA);
}


MACENTRY upHandle DLLENTRY
TstExternalUPfloatAt(upHandle rcvr, upHandle arg, upHandle index)
{
	return(UPCtoSTfloat(UPfloatAt(arg, (int)UPSTtoCint(index))));
}
MACENTRY
upHandle DLLENTRY
TstExternalUPintegerAt(upHandle rcvr, upHandle arg, upHandle index)
{
	return(UPCtoSTint(UPintegerAt(arg, (int)UPSTtoCint(index))));
}

MACENTRY upHandle DLLENTRY
TstExternalUPfloatAtPut(upHandle rcvr, upHandle arg, upHandle index,
                        upHandle aFloat)
{
	upInt i;
	upHandle old;

	i = (int)UPSTtoCint(index);
	old = UPbasicAt(arg, i);
	UPfloatAtPut(arg, i, UPSTtoCfloat(aFloat));
	return(old);
}

MACENTRY upHandle DLLENTRY
TstExternalUPindexVarSize(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTint(UPindexVarSize(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPinstVarAt(upHandle rcvr, upHandle arg, upHandle index)
{
	return(UPinstVarAt(arg, UPSTtoCint(index)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPinstVarAtPut(upHandle rcvr, upHandle arg, upHandle index,
                          upHandle upHandleToBePut)
{
	upHandle old;

	old = UPinstVarAt(arg, (int)UPSTtoCint(index));
	UPinstVarAtPut(arg, (int)UPSTtoCint(index), upHandleToBePut);
	return(old);
}

MACENTRY upHandle DLLENTRY
TstExternalUPinstVarSize(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTint(UPinstVarSize(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPintegerAtPut(upHandle rcvr, upHandle arg, upHandle index,
                          upHandle aUpInt)
{
	upInt i;
	upHandle old;

	i = UPSTtoCint(index);
	old = UPbasicAt(arg, i);
	UPintegerAtPut(arg, i, UPSTtoCint(aUpInt));
	return(old);
}

MACENTRY upHandle DLLENTRY
TstExternalUPisArrayOfFloat(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisArrayOfFloat(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPisArrayOfInteger(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisArrayOfInteger(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPisBoolean(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisBoolean(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPisByteArray(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisByteArray(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPisCharacter(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisCharacter(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPisFloat(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisFloat(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPisInteger(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisInteger(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPisString(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisString(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPisByteLike(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisByteLike(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPnil(upHandle rcvr)
{
	return(UPnil());
}

MACENTRY upHandle DLLENTRY
Tstreturn(upHandle rcvr, upHandle arg)
{
	return(arg);
}

MACENTRY upHandle DLLENTRY
TstExternalUPreturnFalse(upHandle rcvr)
{
	UPreturnFalse();
	/* not reached */
	return (upHandle) 0;
}

MACENTRY upHandle DLLENTRY
TstExternalUPreturnHandle(upHandle rcvr, upHandle arg)
{
	UPreturnHandle(arg);
	/* not reached */
	return (upHandle) 0;
}

MACENTRY upHandle _far
nest3(upHandle arg1)
{
	UPreturnHandle(arg1);
	/* NOTREACHED */
	return (upHandle) 0;
}

MACENTRY upHandle _far
nest2(upHandle arg)
{
	return nest3(arg);
}

MACENTRY upHandle _far
nest1(upHandle arg)
{
	return nest2(arg);
}

MACENTRY upHandle DLLENTRY
TstExternalUPnestedReturn(upHandle rcvr, upHandle arg)
{
	return nest1(arg);
}

MACENTRY upHandle DLLENTRY
TstExternalUPreturnNil(upHandle rcvr)
{
	UPreturnNil();
	/* not reached */
	return (upHandle) 0;
}

MACENTRY upHandle DLLENTRY
TstExternalUPreturnTrue(upHandle rcvr)
{
	UPreturnTrue();
	/* not reached */
	return (upHandle) 0;
}

MACENTRY void DLLENTRY
myHandler(upInt code)
{
	UPinstallErrorHandler((upFunct)0);	/* remove handler */
	UPreturnHandle(UPCtoSTint(100));
}

MACENTRY upHandle DLLENTRY
TstExternalUPerrorHandler(upHandle rcvr)
{
	upHandle junk;

	UPinstallErrorHandler((upFunct)myHandler);
	junk = UPallocArray(UPCtoSTint(0), 2); /* two elements */
	UPfloatAtPut(junk, 10L, 1.0f);		/* this should fail*/
	return(UPCtoSTint(101));	/* shouldn't get here */
}

MACENTRY upHandle DLLENTRY
TstExternalUPregHandleAt(upHandle rcvr, upHandle indx)
{
	return(UPregisteredHandleAt(UPSTtoCint(indx)));
}


MACENTRY upHandle DLLENTRY
TstExternalUPisImmediate(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisImmediate(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPallocRegSlot(upHandle rcvr)
{
	return(UPCtoSTint(UPallocRegistrySlot()));
}

MACENTRY upHandle DLLENTRY
TstExternalUPregHandleAtPut(upHandle rcvr, upHandle indx, upHandle val)
{
	UPregisteredHandleAtPut(UPSTtoCint(indx), val);
	return(UPregisteredHandleAt(UPSTtoCint(indx)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPallocFs(upHandle rcvr, upHandle cls)
{
	return(UPallocFsObject(cls));
}

MACENTRY upHandle DLLENTRY
TstExternalUPallocVs(upHandle rcvr, upHandle cls, upHandle sz)
{
	return(UPallocVsObject(cls, UPSTtoCint(sz)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPclassType(upHandle rcvr, upHandle cls)
{
	return(UPCtoSTint(UPclassType(cls)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPsignalSem(upHandle rcvr, upHandle sem)
{
	UPsignalSemaphore(sem);
	return(sem);
}

static upInt mySlot = -1;

MACENTRY void DLLENTRY
TstExternalMyPollHandler()
{
	if(mySlot > 0) {
		UPsignalSemaphore(UPregisteredHandleAt(mySlot));
		UPregisteredHandleAtPut(mySlot, UPnil());
	}
	UPinstallPollHandler((upFunct)0);
}

MACENTRY upHandle DLLENTRY
TstExternalUPpostInt(upHandle rcvr, upHandle sem)
{
	mySlot = UPallocRegistrySlot();
	UPregisteredHandleAtPut(mySlot, sem);
	UPinstallPollHandler((upFunct)TstExternalMyPollHandler);
	UPpostInterrupt();
	return(rcvr);
}

MACENTRY upHandle DLLENTRY
TstExternalUPisKindOf(upHandle rcvr, upHandle inst, upHandle cls)
{
	return(UPCtoSTbool(UPisKindOf(inst, cls)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPCtoSTdouble(upHandle rcvr)
{
	return(UPCtoSTdouble(3.14));
}

MACENTRY upHandle DLLENTRY
TstExternalUPSTtoCdouble(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTdouble(UPSTtoCdouble(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPisDouble(upHandle rcvr, upHandle arg)
{
	return(UPCtoSTbool(UPisDouble(arg)));
}

MACENTRY upHandle DLLENTRY
TstExternalUPclass(upHandle rcvr, upHandle arg)
{
	return(UPclass(arg));
}

MACENTRY upHandle DLLENTRY
TstExternalSumByteArray(upHandle rcvr, register upHandle ba)
{
	register int sz, i;
	register int sum = 0;

	if(!UPisByteArray(ba))
		UPfail(UPEwrongClass);
	sz = UPindexVarSize(ba);
	for(i = 1; i <= sz; i++) {
		sum += UPbyteAt(ba, i);
	}
	return(UPCtoSTint(sum));
}

MACENTRY upHandle DLLENTRY
TstExternalZeroArray(upHandle rcvr, register upHandle a)
{
	register int sz, i;
	register upHandle zero = UPCtoSTint(0);

	if(UPclass(a) != UPregisteredHandleAt(arrayClassX))
		UPfail(UPEwrongClass);
	sz = UPindexVarSize(a);
	for(i = 1; i <= sz; i++) {
		UPbasicAtPut(a, i, zero);
	}
	return(rcvr);
}

MACENTRY upHandle DLLENTRY
TstExternalUPdoubleAt(upHandle upArray, upHandle upIndex)
{
	double aDouble;
	aDouble = UPdoubleAt(upArray, UPSTtoCint(upIndex));
	return UPCtoSTdouble(aDouble);
}

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeCharacter(upHandle upCharacter)
{
	UPmustBeCharacter(upCharacter);
	return upCharacter;
}

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeInteger(upHandle upInteger)
{
	UPmustBeInteger(upInteger);
	return upInteger;
}

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeString(upHandle upString)
{
	UPmustBeString(upString);
	return upString;
}

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeByteArray(upHandle upByteArray)
{
	UPmustBeByteArray(upByteArray);
	return upByteArray;
}

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeArrayOfInteger(upHandle upArray)
{
	UPmustBeArrayOfInteger(upArray);
	return upArray;
}

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeArrayOfFloat(upHandle upArray)
{
	UPmustBeArrayOfFloat(upArray);
	return upArray;
}

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeBoolean(upHandle upBoolean)
{
	UPmustBeBoolean(upBoolean);
	return upBoolean;
}

MACENTRY upHandle DLLENTRY
TstExternalUPmustBeByteLike(upHandle upObject)
{
	UPmustBeByteLike(upObject);
	return upObject;
}

MACENTRY upHandle DLLENTRY
TstExternalUPlongRun(upHandle upObject)
{
	UPstartLongPrimitive(1);
	UPfinishLongPrimitive();
	return upObject;
}

#endif /* ifndef UPNOTSUPPORTED */

#ifndef OENOTSUPPORTED

MACENTRY OEoop DLLENTRY
oeTstSendBackKeepFailure(
	OEoop oReceiver,
	OEoop oSelector,
	OEoop oArgs,
	OEoop oKeep,
	OEoop oFailure)
{
	return oeSendMessage1(
			oReceiver,
			oSelector,
			oArgs,
			&oKeep,
			oFailure);
}

MACENTRY OEoop DLLENTRY
oeTstSendBackMany(
	OEoop oReceiver,
	OEoop oSelector,
	OEoop oArgs)
{
	return oeSendMessageMany(
			oReceiver,
			oSelector,
			oArgs,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendBack0(OEoop oReceiver, OEoop oSelector)
{
	return oeSendMessage0(
			oReceiver,
			oSelector,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendBack1(OEoop oReceiver, OEoop oSelector, OEoop oArg1)
{
	return oeSendMessage1(
			oReceiver,
			oSelector,
			oArg1,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendBack2(OEoop oReceiver, OEoop oSelector, OEoop oArg1, OEoop oArg2)
{
	return oeSendMessage2(
			oReceiver,
			oSelector,
			oArg1, oArg2,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendBack3(OEoop oReceiver, OEoop oSelector, OEoop oArg1, OEoop oArg2, OEoop oArg3)
{
	return oeSendMessage3(
			oReceiver,
			oSelector,
			oArg1, oArg2, oArg3,
			(OEoop *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendcBackMany(
	OEoop oReceiver,
	char _far *szSelector,
	OEoop oArg1,
	OEoop oArg2)
{
	OEoop argArray[2];

	argArray[0] = oArg1;
	argArray[1] = oArg2;
	return oeCSendMessageMany(
			oReceiver,
			szSelector,
			argArray,
			2,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendcBack0(OEoop oReceiver, char _far *selector)
{
	return oeCSendMessage0(
			oReceiver,
			selector,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendcBack1(OEoop oReceiver, char _far *selector, OEoop oArg1)
{
	return oeCSendMessage1(
			oReceiver,
			selector,
			oArg1,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendcBack2(OEoop oReceiver, char _far *selector, OEoop oArg1, OEoop oArg2)
{
	return oeCSendMessage2(
			oReceiver,
			selector,
			oArg1, oArg2,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendcBack3(OEoop oReceiver, char _far *selector, OEoop oArg1, OEoop oArg2, OEoop oArg3)
{
	return oeCSendMessage3(
			oReceiver,
			selector,
			oArg1, oArg2, oArg3,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendBack0IfFailNoReturn(OEoop oReceiver, OEoop oSelector)
{
	return oeSendMessage0(
			oReceiver,
			oSelector,
			(OEoop _far *) 0,
			(OEoop) 0);
}

MACENTRY OEoop DLLENTRY
oeTstSendBack0IfFailReturnFalse(OEoop oReceiver, OEoop oSelector)
{
	return oeSendMessage0(
			oReceiver,
			oSelector,
			(OEoop _far *) 0,
			oeCtoOEbool(0));
}

MACENTRY OEoop DLLENTRY
oeTstSendBack0ReturnKeptReceiver(OEoop oReceiver, OEoop oSelector)
{
	OEoop keep[1];
	keep[0] = oReceiver;
	oeSendMessage0(
			oReceiver,
			oSelector,
			keep,
			(OEoop) 0);
	return keep[0];
}

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEbool(OEoop rcvr)
{
	return(oeCtoOEbool(TRUE));
}

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEchar(OEoop rcvr)
{
	return(oeCtoOEchar('c'));
}

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEfloat(OEoop rcvr)
{
	return(oeCtoOEfloat(3.14f));
}

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEint(OEoop rcvr)
{
	return(oeCtoOEint((OEint)42));
}

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCbool(OEoop rcvr, OEoop aBoolOop)
{
	OEbool	aBool;
	OEoop	errOop;

	errOop = oeOEToCbool(aBoolOop, &aBool);
	return (oeCtoOEbool(aBool));
}

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCchar(OEoop rcvr, OEoop aCharOop)
{
	OEchar	aChar;
	OEoop	errOop;

	errOop = oeOEToCchar(aCharOop, &aChar);
	return (oeCtoOEchar(aChar));
}

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCfloat(OEoop rcvr, OEoop aFloatOop)
{
	OEfloat	aFloat;
	OEoop errOop;

	errOop = oeOEToCfloat(aFloatOop, &aFloat);
	return (oeCtoOEfloat(aFloat));
}

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCint(OEoop rcvr, OEoop anIntOop)
{
	OEint	anInt;
	OEoop	errOop;

	errOop = oeOEToCint(anIntOop, &anInt);
	return (oeCtoOEint(anInt));
}

MACENTRY OEoop DLLENTRY
oeTstExternalBasicAt(OEoop rcvr, OEoop arrayOEoop, OEoop indexOop)
{
	OEint	index;
	OEoop	errOop;

	errOop = oeOEToCint(indexOop, &index);
	return oeBasicAt(arrayOEoop, index);
}

MACENTRY OEoop DLLENTRY
oeTstExternalBasicAtPut(OEoop rcvr, OEoop arrayOEoop,
						OEoop indexOop, OEoop OEoopToBePut)
{
	OEoop oldOop;
	OEint	index;
	OEoop	errOop;

	errOop = oeOEToCint(indexOop, &index);
	oldOop = oeBasicAt(arrayOEoop, index);
	oeBasicAtPut(arrayOEoop, index, OEoopToBePut);
	return oldOop;
}

MACENTRY OEoop DLLENTRY
oeTstExternalByteAt(OEoop rcvr, OEoop argOop, OEoop indexOop)
{
	OEbyte	aByte;
	OEint	index;
	OEoop	errOop;

	errOop = oeOEToCint(indexOop, &index);
	errOop = oeByteAt(argOop, index, &aByte);
	return (oeCtoOEint(aByte));
}

MACENTRY OEoop DLLENTRY
oeTstExternalByteAtPut(OEoop rcvr,OEoop argOop, OEoop indexOop, OEoop byteOop)
{
	OEint index;
	OEint  aByte;
	OEbyte oldByte;
	OEoop	errOop;

	errOop = oeOEToCint(indexOop, &index);
	errOop = oeByteAt(argOop, index, &oldByte);
	errOop = oeOEToCint(byteOop, &aByte);
	oeByteAtPut(argOop, index, (OEbyte) aByte);
	return (oeCtoOEint(oldByte));
}

MACENTRY OEoop DLLENTRY
oeTstExternalCopyCtoOEintArray(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop)
{
	static OEint aOEintPointer[3] = {1, 2, 3};
	OEoop errOop;
	OEint	aCount, startingAt, anInt;

	errOop = oeOEToCint(aCountOop, &aCount);
	errOop = oeOEToCint(startingAtOop, &startingAt);
	errOop = oeCopyCtoOEintArray(argOop, aOEintPointer,aCount,startingAt, &anInt);
	return (oeCtoOEint(anInt));
}

MACENTRY OEoop DLLENTRY
oeTstExternalCopyCtoOEbytes(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop)
{
	static OEbyte aOEbytes[3] = {0xff, 2, 0xfd};
	OEoop errOop;
	OEint	aCount, startingAt, anInt;

	errOop = oeOEToCint(aCountOop, &aCount);
	errOop = oeOEToCint(startingAtOop, &startingAt);
	errOop = oeCopyCtoOEbytes(argOop, aOEbytes,aCount,startingAt, &anInt);
	return (oeCtoOEint(anInt));
}

MACENTRY OEoop DLLENTRY
oeTstExternalCopyCtoOEfloatArray(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop)
{
	static OEfloat aOEfloatPointer[3] = {-1.0f, 2.0f, -3.0f};
	OEoop errOop;
	OEint	aCount, startingAt, anInt;

	errOop = oeOEToCint(aCountOop, &aCount);
	errOop = oeOEToCint(startingAtOop, &startingAt);
	errOop = oeCopyCtoOEfloatArray(argOop, aOEfloatPointer,aCount,startingAt, &anInt);
	return (oeCtoOEint(anInt));
}

MACENTRY OEoop DLLENTRY
oeTstExternalCopyCtoOEstring(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop)
{
	OEoop errOop;
	OEint	aCount, startingAt, anInt;

	errOop = oeOEToCint(aCountOop, &aCount);
	errOop = oeOEToCint(startingAtOop, &startingAt);
	errOop = oeCopyCtoOEstring(argOop, "abc",aCount,startingAt, &anInt);
	return (oeCtoOEint(anInt));
}

MACENTRY OEoop DLLENTRY
oeTstExternalCopyOEtoCbytes(OEoop rcvr, OEoop argOop, OEoop aCountOop, OEoop startingAtOop)
{
	char aOEbytes[20];
	static OEbyte proto[6] = { 2, 2, 2, 2, 2, 2};
	OEoop myBA;
	OEoop errOop;
	OEint	aCount, startingAt, anInt;

	errOop = oeOEToCint(aCountOop, &aCount);
	errOop = oeOEToCint(startingAtOop, &startingAt);

	memset(aOEbytes, 0, 20);
	memcpy(aOEbytes, (char *)proto, sizeof(proto));
	errOop = oeCopyOEtoCbytes(argOop, (OEbyte *)&aOEbytes[startingAt - 1],
					 aCount ,1L, &anInt);
	myBA = oeAllocByteArray((OEbyte)0, (OEint)sizeof(proto));
	errOop = oeCopyCtoOEbytes(myBA, (OEbyte *)aOEbytes, (OEint)sizeof(proto), 1L, &anInt);
	return (myBA);
}

MACENTRY OEoop DLLENTRY
oeTstExternalCopyOEtoCfloatArray(OEoop rcvr, OEoop argOop, OEoop aCountOop,
								 OEoop startingAtOop)
{
	OEfloat aOEfloats[20];
	static OEfloat proto[6] = { 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f};
	int sz;
	OEoop myA;
	OEoop errOop;
	OEint	aCount, startingAt, anInt;

	errOop = oeOEToCint(aCountOop, &aCount);
	errOop = oeOEToCint(startingAtOop, &startingAt);

	memcpy((char *)aOEfloats, (char *)proto, sizeof(proto));
	errOop = oeCopyOEtoCfloatArray(argOop, &aOEfloats[startingAt - 1],
						  aCount,1L, &anInt);
	sz = sizeof(proto) / sizeof(float);
	myA = oeAllocArray(oeCtoOEfloat(0.0f), (OEint)sz);
	errOop = oeCopyCtoOEfloatArray(myA, aOEfloats, (OEint)sz, 1L, &anInt);
	return (myA);
}

MACENTRY OEoop DLLENTRY
oeTstExternalCopyOEtoCintArray(OEoop rcvr, OEoop argOop, OEoop aCountOop,
								OEoop startingAtOop)
{
	OEint aOEints[20];
	static OEint proto[6] = { 2, 2, 2, 2, 2, 2};
	OEoop myA;
	int sz;
	OEoop errOop;
	OEint	aCount, startingAt, anInt;

	errOop = oeOEToCint(aCountOop, &aCount);
	errOop = oeOEToCint(startingAtOop, &startingAt);

	memcpy( (char *)aOEints, (char *)proto, sizeof(proto));
	errOop = oeCopyOEtoCintArray(argOop, &aOEints[startingAt - 1],
						aCount,1L, &anInt);
	sz = sizeof(proto) / sizeof(OEint);
	myA = oeAllocArray(oeCtoOEint(0L), (OEint)sz);
	errOop = oeCopyCtoOEintArray(myA, aOEints, (OEint)sz, 1L, &anInt);
	return (myA);
}

MACENTRY OEoop DLLENTRY
oeTstExternalCopyOEtoCstring(OEoop rcvr, OEoop argOop, OEoop aCountOop,
								OEoop startingAtOop)
{
	OEoop myA;
	char aUpString[20];
	OEoop errOop;
	OEint	aCount, startingAt, anInt;

	errOop = oeOEToCint(aCountOop, &aCount);
	errOop = oeOEToCint(startingAtOop, &startingAt);

	strcpy(aUpString, "bbbbbb");
	oeCopyOEtoCstring(argOop, &aUpString[startingAt - 1], aCount,1L, &anInt);
	myA = oeAllocString(' ', (OEint)strlen(aUpString));
	errOop = oeCopyCtoOEstring(myA, aUpString, (OEint)strlen(aUpString), 1L, &anInt);
	return (myA);
}


MACENTRY OEoop DLLENTRY
oeTstExternalFloatAt(OEoop rcvr, OEoop argOop, OEoop indexOop)
{
	OEoop errOop;
	OEint	index;
	OEfloat	aFloat;

	errOop = oeOEToCint(indexOop, &index);
	errOop = oeFloatAt(argOop, index, &aFloat);

	return (oeCtoOEfloat(aFloat));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIntegerAt(OEoop rcvr, OEoop argOop, OEoop indexOop)
{
	OEoop errOop;
	OEint	index, anInt;

	errOop = oeOEToCint(indexOop, &index);
	errOop = oeIntegerAt(argOop, index, &anInt);

	return (oeCtoOEint(anInt));
}

MACENTRY OEoop DLLENTRY
oeTstExternalFloatAtPut(OEoop rcvr, OEoop argOop, OEoop indexOop, OEoop aFloatOop)
{
	OEint index;
	OEoop oldOop;
	OEoop errOop;
	OEfloat aFloat;

	errOop = oeOEToCint(indexOop, &index);
	errOop = oeOEToCfloat(aFloatOop, &aFloat);
	oldOop = oeBasicAt(argOop, index);
	oeFloatAtPut(argOop, index, aFloat);
	return (oldOop);
}

MACENTRY OEoop DLLENTRY
oeTstExternalIndexVarSize(OEoop rcvr, OEoop argOop)
{
	OEint anInt;
	OEoop errOop;

	errOop = oeIndexVarSize(argOop, &anInt);
	return (oeCtoOEint(anInt));
}

MACENTRY OEoop DLLENTRY
oeTstExternalInstVarAt(OEoop rcvr, OEoop argOop, OEoop indexOop)
{
	OEoop errOop;
	OEint index;

	errOop = oeOEToCint(indexOop, &index);
	return (oeInstVarAt(argOop, index));
}

MACENTRY OEoop DLLENTRY
oeTstExternalInstVarAtPut(OEoop rcvr, OEoop argOop, OEoop indexOop, OEoop OEoopToBePut)
{
	OEoop oldOop;
	OEoop errOop;
	OEint index;

	errOop = oeOEToCint(indexOop, &index);
	oldOop = oeInstVarAt(argOop, index);
	oeInstVarAtPut(argOop, index, OEoopToBePut);
	return (oldOop);
}

MACENTRY OEoop DLLENTRY
oeTstExternalInstVarSize(OEoop rcvr, OEoop argOop)
{
	OEint anInt;
	OEoop errOop;

	errOop = oeInstVarSize(argOop, &anInt);
	return (oeCtoOEint(anInt));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIntegerAtPut(OEoop rcvr, OEoop argOop, OEoop indexOop, OEoop anIntOop)
{
	OEint index, anInt;
	OEoop oldOop;
	OEoop errOop;

	errOop = oeOEToCint(indexOop, &index);
	errOop = oeOEToCint(anIntOop, &anInt);
	oldOop = oeBasicAt(argOop, index);
	oeIntegerAtPut(argOop, index, anInt);
	return (oldOop);
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsArrayOfFloat(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsArrayOfFloat(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsArrayOfInteger(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsArrayOfInteger(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsBoolean(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsBoolean(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsByteArray(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsByteArray(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsCharacter(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsCharacter(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsFloat(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsFloat(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsInteger(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsInteger(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsString(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsString(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsByteLike(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsByteLike(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalNil(OEoop rcvr)
{
	return (oeNil());
}

MACENTRY OEoop DLLENTRY
oeTstreturn(OEoop rcvr, OEoop argOop)
{
	return (argOop);
}

MACENTRY OEoop DLLENTRY
oeTstExternalReturnFalse(OEoop rcvr)
{
	return oeFalse();
}

MACENTRY OEoop DLLENTRY
oeTstExternalReturnHandle(OEoop rcvr, OEoop argOop)
{
	return argOop;
}

MACENTRY OEoop _far
oeNest3(OEoop arg1)
{
	return arg1;
}

MACENTRY OEoop _far
oeNest2(OEoop argOop)
{
	return oeNest3(argOop);
}

MACENTRY OEoop _far
oeNest1(OEoop argOop)
{
	return oeNest2(argOop);
}

MACENTRY OEoop DLLENTRY
oeTstExternalNestedReturn(OEoop rcvr, OEoop argOop)
{
	return nest1(argOop);
}

MACENTRY OEoop DLLENTRY
oeTstExternalReturnNil(OEoop rcvr)
{
	return oeNil();
}

MACENTRY OEoop DLLENTRY
oeTstExternalReturnTrue(OEoop rcvr)
{
	return oeTrue();
}

MACENTRY OEoop DLLENTRY
oeTstExternalRegHandleAt(OEoop rcvr, OEoop indexOop)
{
	OEoop errOop;
	OEint index;

	errOop = oeOEToCint(indexOop, &index);
	return (oeRegisteredHandleAt(index));
}


MACENTRY OEoop DLLENTRY
oeTstExternalIsImmediate(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsImmediate(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalAllocRegSlot(OEoop rcvr)
{
	return (oeCtoOEint(oeAllocRegistrySlot()));
}

MACENTRY OEoop DLLENTRY
oeTstExternalRegHandleAtPut(OEoop rcvr, OEoop indexOop, OEoop valOop)
{
	OEoop errOop;
	OEint index;

	errOop = oeOEToCint(indexOop, &index);
	oeRegisteredHandleAtPut(index, valOop);
	return (oeRegisteredHandleAt(index));
}

MACENTRY OEoop DLLENTRY
oeTstExternalAllocFs(OEoop rcvr, OEoop cls)
{
	return (oeAllocFsObject(cls));
}

MACENTRY OEoop DLLENTRY
oeTstExternalAllocVs(OEoop rcvr, OEoop cls, OEoop szOop)
{
	OEoop errOop;
	OEint sz;

	errOop = oeOEToCint(szOop, &sz);
	return (oeAllocVsObject(cls, sz));
}

MACENTRY OEoop DLLENTRY
oeTstExternalClassType(OEoop rcvr, OEoop cls)
{
	return (oeCtoOEint(oeClassType(cls)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalSignalSem(OEoop rcvr, OEoop sem)
{
	oeSignalSemaphore(sem);
	return(sem);
}

static OEint oeMySlot = -1;

void OEENTRY
oeTstExternalMyPollHandler()
{
	if(oeMySlot > 0) {
		oeSignalSemaphore(oeRegisteredHandleAt(oeMySlot));
		oeRegisteredHandleAtPut(oeMySlot, oeNil());
	}
	oeInstallPollHandler((OEvoidFuncPtr)0);
}

MACENTRY OEoop DLLENTRY
oeTstExternalPostInt(OEoop rcvr, OEoop sem)
{
	oeMySlot = oeAllocRegistrySlot();
	oeRegisteredHandleAtPut(oeMySlot, sem);
	oeInstallPollHandler((OEvoidFuncPtr)oeTstExternalMyPollHandler);
	oePostInterrupt();
	return(rcvr);
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsKindOf(OEoop rcvr, OEoop inst, OEoop cls)
{
	return(oeCtoOEbool(oeIsKindOf(inst, cls)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalCtoOEdouble(OEoop rcvr)
{
	return(oeCtoOEdouble(3.14));
}

MACENTRY OEoop DLLENTRY
oeTstExternalOEtoCdouble(OEoop rcvr,OEoop aDoubleOop)
{
	OEoop errOop;
	OEdouble aDouble;

	errOop = oeOEToCdouble(aDoubleOop, &aDouble);
	return (oeCtoOEdouble(aDouble));
}

MACENTRY OEoop DLLENTRY
oeTstExternalIsDouble(OEoop rcvr, OEoop argOop)
{
	return (oeCtoOEbool(oeIsDouble(argOop)));
}

MACENTRY OEoop DLLENTRY
oeTstExternalClass(OEoop rcvr, OEoop argOop)
{
	return (oeClass(argOop));
}

MACENTRY OEoop DLLENTRY
oeTstExternalSumByteArray(OEoop rcvr, OEoop baOop)
{
	OEint sum = 0;
	OEint sz, i;
	OEbyte temp;
	OEoop errOop;

	if(oeIsByteArray(baOop) == OEFALSE) return OEnonOop;
	errOop = oeIndexVarSize(baOop, &sz);
	if (errOop == OEnonOop) return OEnonOop;
	for(i = 1; i <= sz; i++) {
		oeByteAt(baOop, i, &temp);
		sum += temp;
	}
	return oeCtoOEint(sum);
}

MACENTRY OEoop DLLENTRY
oeTstExternalZeroArray(OEoop rcvr, register OEoop aOop)
{
	register int i;
	register OEoop zero = oeCtoOEint(0);
	OEint sz;
	OEoop errOop;

	if (oeClass(aOop) != oeArrayClass()) return OEnonOop;
	errOop = oeIndexVarSize(aOop, &sz);
	if (errOop == OEnonOop) return OEnonOop;
	for(i = 1; i <= sz; i++) {
		oeBasicAtPut(aOop, i, zero);
	}
	return (rcvr);
}

MACENTRY OEoop DLLENTRY
oeTstExternalDoubleAt(OEoop oeArray, OEoop indexOop)
{
	OEoop errOop;
	OEint	index;
	double aDouble;

	errOop = oeOEToCint(indexOop, &index);

	errOop = oeDoubleAt(oeArray, index, &aDouble);
	return oeCtoOEdouble(aDouble);
}

MACENTRY OEoop DLLENTRY
oeTstExternalLongRun(OEoop oeObject)
{
	oeStartLongComputation(1);
	oeFinishLongComputation();
	return oeObject;
}

#endif
