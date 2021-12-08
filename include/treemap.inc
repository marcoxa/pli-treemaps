 /* -*- Mode: PL1 -*- */
 /*
  * treemap.inc
  * 
  * Maps implemented as BSTs
  *
  * See COPYING for copyright and licensing information.
  * 
  * Public interface to be %included where needed.  Especially within
  * each 'external' procedure.
  */

 %IF TREEMAPS_LIB_STATUS = 'INCLUDED' %THEN
 % GOTO TREEMAPS_LIB_END;                 /* Skip... */
 
 /*
  * treemap
  */
 DCL 1 TREEMAP BASED(TMPTR),
       2 ID CHAR(80),
       2 ROOT POINTER;
  
 % TREEMAPS_LIB_END: TREEMAPS_LIB_STATUS = 'INCLUDED';
 
 /*
  * end of file -- node.inc
  */
