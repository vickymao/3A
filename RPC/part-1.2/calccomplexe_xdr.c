/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calccomplexe.h"

bool_t
xdr_complexe (XDR *xdrs, complexe *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->pentiere))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->pimaginaire))
		 return FALSE;
	return TRUE;
}
