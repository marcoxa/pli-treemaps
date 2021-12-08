 /* -*- Mode: PL1 -*- */
 /*
  * tmprin.inc
  * 
  * Maps implemented as BSTs.
  *
  * See COPYING for copyright and licensing information.
  * 
  * Tree Maps PRocedure INterface.
  * Public interface to be %included where needed.  Especially within
  * each 'external' procedure.
  */

 %IF TREEMAPS_PRIN_LIB_STATUS = 'INCLUDED' %THEN
 % GOTO TREEMAPS_PRIN_LIB_END;  /* Skip... */
 
 /*
  * Interface.
  *
  * Notes:
  * All entries return pointers to treemaps in AREA treemaps.
  */
 DCL TMNEWTM ENTRY (CHAR(80))
             RETURNS (POINTER);
 
 DCL TMINSER ENTRY (POINTER, FIXED BINARY (15), CHAR(80))
             RETURNS (POINTER);
 
 DCL TMSRCH  ENTRY (POINTER, FIXED BINARY (15), CHAR(80))
             RETURNS (BIT(1));

 DCL TMPRNT  ENTRY (POINTER); /* Prints on SYSPRINT */
 
 % TREEMAPS_PRIN_LIB_END: TREEMAPS_PRIN_LIB_STATUS = 'INCLUDED';

 /*
  * end of file -- node.inc
  */
