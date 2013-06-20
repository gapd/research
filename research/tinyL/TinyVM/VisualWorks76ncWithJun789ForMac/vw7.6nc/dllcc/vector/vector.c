/*
 * 32-bit float Vector Arithmetic Functions for use via
 * VisualWorks DLL & C Connect.
 *
 * Written by David Leibs & Eliot Miranda. February 1998
 *
 * You are free to use this code for any purpose without restriction.
 * Neither the authors nor Cincom Systems Inc. will accept any liability
 * resulting from the use of this code.
 */

#include <math.h>

#include "oeAPI.h"
#include "vector.h"

#define getByteSize(o,s) (oeIndexVarSize(o,&(s)), (s))

OEoop
vectorMultiplyByScalar(OEoop v1, float s, OEoop result)
{
	register float *vin1;
	register float *vans;
	         long   szin;
             long   sztmp;

	if (!oeIsByteLike(v1)
     || !oeIsByteLike(result))
        oeFail(OEerrorWrongClass);
	getByteSize(v1,szin);
	if (getByteSize(result,sztmp) != szin)
        oeFail(OEerrorObjectTooSmall);

	vin1 = (float *)oeOopDataPtr(v1);
	vans = (float *)oeOopDataPtr(result);
    while ((szin -= sizeof(float)) >= 0)
		*vans++ = *vin1++ * s;

    return result;
}

OEoop
vectorDivideByScalar(OEoop v1, float s, OEoop result)
{
	register float *vin1;
	register float *vans;
	         long   szin;
             long   sztmp;

	if (!oeIsByteLike(v1)
	 || !oeIsByteLike(result))
        oeFail(OEerrorWrongClass);
	getByteSize(v1,szin);
	if (getByteSize(result,sztmp) != szin)
        oeFail(OEerrorObjectTooSmall);

	vin1 = (float *)oeOopDataPtr(v1);
	vans = (float *)oeOopDataPtr(result);
	while ((szin -= sizeof(float)) >= 0)
		*vans++ = *vin1++ / s;

    return result;
}

OEoop
vectorAdd(OEoop v1, OEoop v2, OEoop result)
{
	register float *vin1;
	register float *vin2;
	register float *vans;
	         long   szin;
             long   sztmp;

	if (!oeIsByteLike(v1)
	 || !oeIsByteLike(v2)
	 || !oeIsByteLike(result))
        oeFail(OEerrorWrongClass);
	getByteSize(v1,szin);
	if (getByteSize(v2,sztmp) != szin
     || getByteSize(result,sztmp) != szin)
        oeFail(OEerrorObjectTooSmall);

	vin1 = (float *)oeOopDataPtr(v1);
	vin2 = (float *)oeOopDataPtr(v2);
	vans = (float *)oeOopDataPtr(result);
	while ((szin -= sizeof(float)) >= 0)
		*vans++ = *vin1++ + *vin2++;

    return result;
}

OEoop
vectorMinus(OEoop v1, OEoop v2, OEoop result)
{
	register float *vin1;
	register float *vin2;
	register float *vans;
	         long   szin;
             long   sztmp;

	if (!oeIsByteLike(v1)
	 || !oeIsByteLike(v2)
	 || !oeIsByteLike(result))
        oeFail(OEerrorWrongClass);
	getByteSize(v1,szin);
	if (getByteSize(v2,sztmp) != szin
     || getByteSize(result,sztmp) != szin)
        oeFail(OEerrorObjectTooSmall);

	vin1 = (float *)oeOopDataPtr(v1);
	vin2 = (float *)oeOopDataPtr(v2);
	vans = (float *)oeOopDataPtr(result);
	while ((szin -= sizeof(float)) >= 0)
		*vans++ = *vin1++ - *vin2++;

    return result;
}

float
vectorDotProduct(OEoop v1, OEoop v2)
{
	register double ta = 0.0;
	register float *vin1;
	register float *vin2;
	         long   szin;
             long   sztmp;

	if (!oeIsByteLike(v1)
	 || !oeIsByteLike(v2))
        oeFail(OEerrorWrongClass);
	getByteSize(v1,szin);
	if (getByteSize(v2,sztmp) != szin)
        oeFail(OEerrorObjectTooSmall);

	vin1 = (float *)oeOopDataPtr(v1);
	vin2 = (float *)oeOopDataPtr(v2);
	while ((szin -= sizeof(float)) >= 0)
		ta += *vin1++ * *vin2++;

	return ta;
}

float
vectorMagnitude(OEoop v)
{
	register float *vin;
	         long   szin;
             long   sztmp;
	register double ta = 0.0;

	if (!oeIsByteLike(v))
        oeFail(OEerrorWrongClass);

	getByteSize(v,szin);
	vin = (float *)oeOopDataPtr(v);
	while ((szin -= sizeof(float)) >= 0) {
		register float temp = *vin++;
		ta += temp * temp;
	}

	return sqrt(ta);
}

OEoop
vectorNormal(OEoop v, OEoop result)
{
	register float *vin;
	register float *vans;
	         long   szin;
             long   sztmp;
	register double ans = 0.0;

	if (!oeIsByteLike(v)
	 || !oeIsByteLike(result))
        oeFail(OEerrorWrongClass);
	getByteSize(v,szin);
	if (getByteSize(result,sztmp) != szin)
        oeFail(OEerrorObjectTooSmall);

	vin = (float *)oeOopDataPtr(v);
	vans = (float *)oeOopDataPtr(result);
	while ((szin -= sizeof(float)) >= 0) {
		register float temp = *vin++;
		ans += temp * temp;
	}
	ans = sqrt(ans);
	if (ans == 0.0)
        oeFail(OEerrorSrange);

	getByteSize(v,szin);
	vin = (float *)oeOopDataPtr(v);
	while ((szin -= sizeof(float)) >= 0)
		*vans++ = *vin++ / ans;

    return result;
}

OEoop
vectorNegate(OEoop in, OEoop out)
{
	register float *vin;
	register float *vout;
	         long   szin;
             long   sztmp;

	if (!oeIsByteLike(in)
	 || !oeIsByteLike(out))
        oeFail(OEerrorWrongClass);
	getByteSize(in,szin);
	if (getByteSize(out,sztmp) != szin)
        oeFail(OEerrorObjectTooSmall);

	vin  = (float *)oeOopDataPtr(in);
	vout = (float *)oeOopDataPtr(out);
	while ((szin -= sizeof(float)) >= 0)
		*vout++ = -*vin++;

    return out;
}

OEoop
vectorRound(OEoop in, OEoop out)
{
	register float *vin;
	register float *vout;
	         long   szin;
             long   sztmp;

	if (!oeIsByteLike(in)
	 || !oeIsByteLike(out))
        oeFail(OEerrorWrongClass);
	getByteSize(in,szin);
	if (getByteSize(out,sztmp) != szin)
        oeFail(OEerrorObjectTooSmall);

	vin  = (float *)oeOopDataPtr(in);
	vout = (float *)oeOopDataPtr(out);
	while ((szin -= sizeof(float)) >= 0) {
        register float tv = *vin++;
        *vout++ = tv >= 0.0 ? floor(tv + 0.5f) : ceil(tv - 0.5);
    }

    return out;
}

OEoop
vectorCrossProduct(OEoop vecin1, OEoop vecin2, OEoop vecOut)
{
	register float *vin1;
	register float *vin2;
	register float *vout;
             long   sztmp;

	if (!oeIsByteLike(vecin1)
	 || !oeIsByteLike(vecin2)
	 || !oeIsByteLike(vecOut))
        oeFail(OEerrorWrongClass);
	if (getByteSize(vecin1,sztmp) != (3 * sizeof(float))
	 || getByteSize(vecin2,sztmp) != (3 * sizeof(float))
	 || getByteSize(vecOut,sztmp) != (3 * sizeof(float)))
        oeFail(OEerrorArgCheckFailed);

	vin1 = (float *)oeOopDataPtr(vecin1);
	vin2 = (float *)oeOopDataPtr(vecin2);
	vout = (float *)oeOopDataPtr(vecOut);

	vout[0] = (vin1[1] * vin2[2]) - (vin1[2] * vin2[1]);
	vout[1] = (vin1[2] * vin2[0]) - (vin1[0] * vin2[2]);
	vout[2] = (vin1[0] * vin2[1]) - (vin1[1] * vin2[0]);

    return vecOut;
}

OEoop
vectorCrossProductNormal(OEoop vecin1, OEoop vecin2, OEoop vecOut)
{
	register float *vin1;
	register float *vin2;
	register float *vout;
             long   sztmp;
	         double x, y, z, l;

	if (!oeIsByteLike(vecin1)
	 || !oeIsByteLike(vecin2)
	 || !oeIsByteLike(vecOut))
        oeFail(OEerrorWrongClass);
	if (getByteSize(vecin1,sztmp) != (3 * sizeof(float))
	 || getByteSize(vecin2,sztmp) != (3 * sizeof(float))
	 || getByteSize(vecOut,sztmp) != (3 * sizeof(float)))
        oeFail(OEerrorArgCheckFailed);

	vin1 = (float *)oeOopDataPtr(vecin1);
	vin2 = (float *)oeOopDataPtr(vecin2);
	vout = (float *)oeOopDataPtr(vecOut);

	x = vin1[1] * vin2[2] - vin1[2] * vin2[1];
	y = vin1[2] * vin2[0] - vin1[0] * vin2[2];
	z = vin1[0] * vin2[1] - vin1[1] * vin2[0];
	l = sqrt(x*x + y*y + z*z);
	if (l == 0.0f)
        oeFail(OEerrorSrange);
	vout[0] = x / l;
	vout[1] = y / l;
	vout[2] = z / l;

    return vecOut;
}
