# TREEMAPS in PL/I

Marco Antoniotti

Copyright (c) 2021 Marco Antoniotti
See file COPYING for licensing information


## Description

This "library" is an exercise to acquire passing knowledge of **PL/I**.
The library implements a *persistent* version of a standard Binary
Search Tree ADT; no balancing.  As such, it is a library that would
require a proper garbage collector to work well; as it stands, it will
leak as a coulander.  Nevertheless, playing around with `BASED`
variables and `AREA`s offers some tantalizing suggestions about how to
write some cleaning up code; also, rememeber that **PL/I** has `TASK`
available.

### Motivations

The exercise is a standard one that I use in class.  The idea is to
write something not particularly trivial, with the goal of showing
*how* you arrange some code in a "library" with clean interfaces
etc. etc.

The exercise (which took quite some time) was meant for me to learn
**PL/I (F)**, as it is available under **MVS 3.8j** (cfr.,
[TK4-](http://wotho.ethz.ch/tk4-/)) and **MTS** (cfr.,
[MTS](http://www.try-mts.com)).  This is not the latest and greatest
**PL/I** compiler available; the *Enterprise* version from IBM is a different
beast altogether
(cfr.,
[IBM PL/I for z/OS](https://www.ibm.com/products/pli-compiler-zos);
**PL/I (F)** is '70s technolgy.  Yet, it allows you to to very
sophisticated things.  Studying **PL/I**  made me realize how many of the
"modern" features we expect from a programming language ecosystem were
actually already present in it 50 years ago, at the time of this
writing.

### Library Structure

More modern **PL/I** compilers introduced several features meant to
better modularize code.  **PL/I** *is meant* to be compiled
separately; alas, in its early incarnation it did require a all
encopassing `procedure top options(main)` where everything should be
"contained".  This does not work well if you are accustomed to
**C/C++** multiple include's and its distinction between declaartions
and definitions.  More recent **PL/I** compilers have adopted things
like `package`s, but they are not available in **PL/I**.

**C/C++** programmers are accustomed to play the by now standard trick
of writing

    #ifndef _FOO_INTERFACE_H
    #define _FOO_INTERFACE_H
       ...
    #endif
    
in their header files.  This accomplishes the intended results.

In **PL/I** you have (you already had) a rather sophisticted
*preprocessor*, which is capable of defining rather complex macros.
Not what you get if you love parenthes (*no* language comes close yet,
not even [Julia](https://julialang.org/),
especially if you don't care to get ... dirty), but quite
sophisticated indeed.  The problem is that there seem to be no way
(in **PL/I (F)**) to check whether a macro variable has already been
`DECLARE`d or not.  This prevents the standard **C/C++** trick and
forces you to have a file, pardon, dataset where you `%DECLARE` all
your macro variables before using them.

Having find ut all of this the hard way, I came up with the following
organization.  The names used are for UN*X, or Windows filesystems.

* `tmapi.inc` dataset (or file -- whatever).  
  Contains the macro declarations.
* `treemap.inc` dataset.  
  Contains the the *tree map* structure; the public API functions
  operate on these structures.
* `tmnodes.inc` dataset.  
  Contains the tree *node* structure; these are not meant to be seen
  or used outside the library.
* `tmprin.inc` dataset.  
  Contains the declarations of the API `ENTRY`'s that the client
  program should use.
  
A client program (e.g., the `tmtest.pl1` code) will start like

    USETM: PROC OPTIONS(MAIN);
    
    %INCLUDE DDTM(TMAPI);
    %INCLUDE DDTM(TMPRIN);
    
    ...
    
    DCL SOME_TREEMAP POINTER;
    
    ...
    
    SOME_TREEMAP = TMNEWTM('Test Tree Map');  /* TMNEWTM is the "constructor" */
    
    ...
    
    END USETM;
    
where `DDTM` is a "*ddname*" in the JCL (in **MVS**) that you use to
compile the library and run the test.

The code for the library is in the dataset `treemaps.pli`, which, as
you can see in the code, uses the batch compiler invocation by means
of the `*PROCESS`directive.  Most likely a normal **MVS** or **z/OS**
setup would have all functions in separate datasets and then combined
in a single load module, but in this way the JCL is easier.


### **MVS** (and **z/OS**) Setup

Because of limitation of the **PL/I (F)** compiler it is best to keep
the "include" files in a separate dataset, say
``HLQ.TREEMAP.PLI.INCLUDE``, while keeping the code in another one,
say ``HLQ.TREEMAP.PLI``; your choice.


### Test Program and JCL

The library contains a test program `tmtest.pl1` which shows how the
library can be used.


## Some Random Things Learned along the Way...

While working on the exercise, I learned several things (or better,
idiosyncrasies) of the **PL/I (F)** compiler.  Here is an incomplete
list.

* You need to use a lot of variables; it is unclear why certain
  expressions do not do what you would normally expect 50 years after
  the compile was written; time's a bitch.  That is, sometime some
  errors disappear if you set a variable to an expression value and
  then pass the variable to a function or subroutine.

* Conversion rules are very complex; it is still unclear to me when to
  use `DECIMAL` or `BINARY` numbers.  They mix, but often in
  surprising ways.
  
* Output (and input) is quite complex.  Even apparently "simple"
  things in `PUT EDIT` statements come back to bite you with
  initially unintelligible 2000 "cond codes".  The main thing I
  learned -- it worked for me, it may be wrong -- is that if you use a
  `DO ... TO` construct, you need to have the correct
  repeated number of format directives.
  
* There is no apparent way to check whether a macro variable has been
  `%DECLARED`.
  
* You need to make sure that a declaration of all names (especially
  functions and subroutines) used within a block is visible.
  
Of course there are many other ones.

### ... and, in fact, here they are...

After having worked on the first iteration of the code, I was told, by
the kind (and patient) folks on the
[pl1f-and-mvs38j](https://groups.io/g/pl1f-and-mvs38j) group, that
there is *another* way to achieve nice modularity within a **single**
procedure, by leveraging the `ENTRY` *statement*.  It took a while,
interpreting the reasons why the **PL/I (F)** compiler and the loader
were not cooperating, but eventually I succeded.  Hence you now have a
`tmpkg.pl1` code that implements the *procedure-as-package* idiom. It
works like a charm and I'd say it is the way to go because it solves
many of the other problems that the setup with many pre-processor
files actually raise.
  
  
## Where to Get Help

Mosty on the Mainframe groups.  Especially on the
[pl1f-and-mvs38j](https://groups.io/g/pl1f-and-mvs38j)
[groups.io](https://groups.io) group.  Links to the relevant documents
for the **PL/I (F)** compiler can be found there.


## A Note on Forking

Of course you are free to fork the project subject to the current
licensing scheme.  However, before you do so, I ask you to consider
plain old "cooperation" by asking me to become a developer.
It helps keeping the entropy level at an acceptable level.

Enjoy

Marco Antoniotti 2021-12-21
