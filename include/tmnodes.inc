 /* -*- Mode: PL1 -*- */
 /*
  * node.inc
  * 
  * Maps implemented as BSTs
  *
  * See COPYING for copyright and licensing information.
  * 
  * Public interface to be %included where needed.  Especially within
  * each 'external' procedure.
  */

 %IF TREEMAPS_NODE_LIB_STATUS = 'INCLUDED' %THEN
 % GOTO TREEMAPS_NODE_LIB_END;                 /* Skip... */
 %ELSE
 
 /*
  * node
  */
 DCL 1 NODE BASED(NPTR),
       2 KEY FIXED BIN (15),
       2 CONTENT CHAR(80),
       2 LEFT  POINTER,
       2 RIGHT POINTER;
 
 % TREEMAPS_NODE_LIB_END: TREEMAPS_NODE_LIB_STATUS = 'INCLUDED';

 /*
  * end of file -- node.inc
  */
