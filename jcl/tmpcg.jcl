//TMTSTCG6 JOB (PLITEST),
//             'TREEMAPS CG TEST',
//             CLASS=A,
//             MSGCLASS=H,
//             MSGLEVEL=(1,1),
//             NOTIFY=MARCOXA
//********************************************************************
//*
//* NAME: MARCOXA.NEWPROJ.PLI.TMTEST(TMCG)
//* ORIGINAL NAME: SYS2.JCLLIB(TESTPL1)
//*
//* DESCRIPTION: Treemaps Library Compile and Go Test
//*
//* This is the version with the 'package-like' single procedure.
//*
//* Note the requirements for the included code from the TREEMAPS
//* DDNAME.
//*
//********************************************************************
//*
//* Compiling, separately, the library and its test.
//*
//CMPTMLIB    EXEC PL1LFC,PARM.PL1L='MACRO'
//PL1L.SYSLIN DD UNIT=SYSDA
//PL1L.SYSIN  DD DSN=MARCOXA.NEWPROJ.PLI.TREEMAPS(TMPKG),DISP=SHR
//TREEMAPS    DD DSN=MARCOXA.NEWPROJ.PLI.INCL,DISP=SHR
//*
//* Compile, separately, the treemap test program.
//*
//CMPTMTST    EXEC PL1LFCG,PARM.PL1L='MACRO'
//PL1L.SYSLIN DD UNIT=SYSDA
//PL1L.SYSIN  DD DSN=MARCOXA.NEWPROJ.PLI.TREEMAPS(TMTEST),DISP=SHR
//TREEMAPS    DD DSN=MARCOXA.NEWPROJ.PLI.INCL,DISP=SHR
//GO.SYSLIN   DD DSN=*.CMPTMLIB.PL1L.SYSLIN,DISP=MOD
//GO.SYSPRINT DD SYSOUT=*
//
