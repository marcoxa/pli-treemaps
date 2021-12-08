 /* -*- Mode: PL1 -*- */
 /*
  * treemapi.inc
  * 
  * Maps implemented as BSTs
  *
  * See COPYING for copyright and licensing information.
  * 
  * Library macro setup.
  * The API is such these macro variables contain the status of the
  * treemaps files inclusions.
  * 
  * This file should be included only ONCE in each external procedure
  * that is compiled separately.
  *
  * Each variable can be 'DECLARED' (the initial state) or, FTTB,
  * 'INCLUDED', indicating that the library declarations have been
  * 'inluded' in the code.
  *
  * The variables are one for each "data structure declaration" and
  * for each "PRocedure INterface".  Plus a useful "information" macro
  *  variable.
  *
  * To use, therefore you need to do, in sequence, in each external
  * procedure:
  *
  *      %INCLUDE TREEMAPS(TMAPI);
  *      ...
  *      %INCLUDE TREEMAPS(TMNODES);
  * or
  *      %INCLUDE TREEMAPS(TMAPI);
  *      ...
  *      %INCLUDE TREEMAPS(TREEMAP);
  *
  * The above being an example.  The NODES member (assuming you have
  * the TREEMAPS DDNAME in your JCL) will have the proprocessor
  * variables available.
  *
  * Of course, this is for PL/I (F); with XINCLUDE of later PL/I
  * incarnations the above becomes less useful.
  *
  * Note also that the setup is a bit iffy, given - always in PL/I (F) -
  * the lack of PACKAGEs and the impossibility of (1) having
  * "declarations" shared among external procedures and (2) the
  * impossibility of checkling whther a preprocessor variable exists at
  * all.
  */
 
 %DECLARE TREEMAPS_PREFIX CHARACTER;
 % TREEMAPS_PREFIX = 'TM';
 
 %DECLARE TREEMAPS_LIB_STATUS CHARACTER;
 % TREEMAPS_LIB_STATUS = 'DECLARED';
 
 %DECLARE TREEMAPS_TM_STATUS CHARACTER;
 % TREEMAPS_TM_STATUS = 'DECLARED';
 
 %DECLARE TREEMAPS_PRIN_LIB_STATUS CHARACTER;
 % TREEMAPS_PRIN_LIB_STATUS = 'DECLARED';
 
 %DECLARE TREEMAPS_NODE_LIB_STATUS CHARACTER;
 % TREEMAPS_NODE_LIB_STATUS = 'DECLARED';
 
 /*
  * end of file -- treemapi.inc
  */
