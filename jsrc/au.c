/* Copyright 1990-2006, Jsoftware Inc.  All rights reserved.               */
/* Licensed use only. Any other use is in violation of copyright.          */
/*                                                                         */
/* Adverbs: Utilities                                                      */

#include "j.h"


static I jtfdepger(J jt,A w){A*wv;I d=0,k; 
 wv=AAV(w);  
 DO(AN(w), k=fdep(fx(wv[i])); d=MAX(d,k);); 
 R d;
}

#if !USECSTACK
I jtfdep(J jt,A w){A f,g;I d=0,k;V*v;
 RZ(w);
 v=VAV(w);
 if(v->fdep)R v->fdep;  // for speed, use previous value if it has been calculated
 if(f=v->fgh[0]) d=VERB&AT(f)?fdep(f):NOUN&AT(f)&&VGERL&v->flag?fdepger(f):0;
 if(g=v->fgh[1]){k=VERB&AT(g)?fdep(g):NOUN&AT(g)&&VGERR&v->flag?fdepger(g):0; d=MAX(d,k);}
 if(CFORK==v->id){k=fdep(v->fgh[2]); d=MAX(d,k);}
 if(!jt->jerr)v->fdep=(UI4)(1+d);  //Save computed value for next time, but not if error; that would lose the error next time
 R 1+d;
}    /* function depth:  1 + max depth of components */

F1(jtfdepadv){RZ(w); ASSERT(VERB&AT(w),EVDOMAIN); R sc(fdep(w));}
#endif

// jtdf1 and jtdf2 can be called with or without inplace flags since they don't use jt but merely pass it through
DF1(jtdf1){RZ(self); R CALL1(FAV(self)->valencefns[0],  w,self);}
DF2(jtdf2){RZ(self); R CALL2(FAV(self)->valencefns[1],a,w,self);}

DF1(jtdfs1){F1PREFIP;A s=jt->sf,z; RZ(self); z=CALL1IP(FAV(self)->valencefns[0],  w,jt->sf=self); jt->sf=s; RETF(z);}
DF2(jtdfs2){F2PREFIP;
A s=jt->sf,z; 
RZ(self); 
z=CALL2IP(FAV(self)->valencefns[1],a,w,jt->sf=self); jt->sf=s; 
RETF(z);}    
     /* for monads and dyads that can possibly involve $: */

A jtdfss1(J jt, A w, A self, A self0)     {RZ(self); R CALL1(FAV(self)->valencefns[0],  w,self0);}
A jtdfss2(J jt, A a, A w, A self, A self0){RZ(self); R CALL2(FAV(self)->valencefns[1],a,w,self0);}
     // used to treat self as an argument.  Used with routines that don't really use self

F1(jtself1){A z; FDEPINC(d=fdep(jt->sf)); STACKCHKOFL z=df1(  w,jt->sf); FDEPDEC(d); forcetomemory(w); RETF(z);}
F2(jtself2){A z; FDEPINC(d=fdep(jt->sf)); STACKCHKOFL z=df2(a,w,jt->sf); FDEPDEC(d); forcetomemory(w); RETF(z);}

A jtac1(J jt,AF f){R fdef(0,0,VERB, f,0L, 0L,0L,0L, VFLAGNONE, RMAX,RMAX,RMAX);}
A jtac2(J jt,AF f){R fdef(0,0,VERB, 0L,f, 0L,0L,0L, VFLAGNONE, RMAX,RMAX,RMAX);}

F1(jtdomainerr1){ASSERT(0,EVDOMAIN);}
F2(jtdomainerr2){ASSERT(0,EVDOMAIN);}

// create a block for a function (verb/adv/conj).  The meanings of all fields depend on the function executed in f1/f2
// if there has been a previous error this function returns 0
A jtfdef(J jt,I flag2,C id,I t,AF f1,AF f2,A fs,A gs,A hs,I flag,I m,I l,I r){A z;V*v;
 RE(0);
 GAT0(z,INT,(VERBSIZE+SZI-1)>>LGSZI,0); v=FAV(z);  // allocate as fixed size, and as INT to avoid clearing the area, which will be all filled in
 AT(z)=t;  // install actual type
 if(fs)INCORP(fs); if(gs)INCORP(gs); if(hs)INCORP(hs);   // indicate fgh are about to be incorporated
 v->localuse.lclr[0]=v->localuse.lclr[1]=0;  // clear the private field
 v->valencefns[0]    =f1?f1:jtdomainerr1;  /* monad C function */
 v->valencefns[1]    =f2?f2:jtdomainerr2;  /* dyad  C function */
 v->fgh[0]     =fs;                  /* monad            */
 v->fgh[1]     =gs;                  /* dyad             */      
 v->fgh[2]     =hs;                  /* fork right tine or other auxiliary stuff */
 v->flag  =(UI4)flag;
#if !USECSTACK
 v->fdep  =0;                   /* function depth   */
#endif
 v->flag2 = (UI4)flag2;         // more flags
 v->mr    =(RANKT)m;                   /* monadic rank     */
 v->lrr=(RANK2T)((l<<RANKTX)+r);
 v->id    =(C)id;                  /* spelling         */
 R z;
}

B nameless(A w){A f,g,h;C id;V*v;
 if(!w||NOUN&AT(w))R 1;
 v=FAV(w);
 id=v->id; f=v->fgh[0]; g=v->fgh[1]; h=v->fgh[2];
 R !(id==CTILDE&&NAME&AT(f)) && nameless(f) && nameless(g) && (id==CFORK?nameless(h):1);
}

B jtprimitive(J jt,A w){A x=w;V*v;
 RZ(w);
 v=VAV(w);
 if(CTILDE==v->id&&NOUN&AT(v->fgh[0]))RZ(x=fix(w,zeroionei[0]));
 R!VAV(x)->fgh[0];
}    /* 1 iff w is a primitive */


// w is a conj, f C n
// Return 1 if f is of the form <@:g  (or <@g when g has infinite rank)
B jtboxatop(J jt,A w){RZ(w); R 1&boxat(FAV(w)->fgh[0],RMAX,RMAX,RMAX);}

// x is a verb
// Return if verb is of the form <@:g  (or <@g when g has rank >= input rank)
// bit 0 for monad case, bit 1 for dyad
I boxat(A x, I m, I l, I r){C c;V*v;
 if(!x)R 0;
 v=FAV(x); c=v->id;   // x->fgh[0], v->value, c=id of f
 if(!COMPOSE(c))R 0;  // Return if not @ @: & &:
 if(CBOX==ID(v->fgh[0])) {  // if u is <...
   if(c==CATCO) R 3; if(c==CAMPCO) R 1;  // @: is always good, and &: for monad
   I res = 0;
   if(v->fgh[1]&&VERB&AT(v->fgh[1])){
    res |= FAV(v->fgh[1])->mr>=m;    // monad ok if rank big enough  for either @ or &
    res |= (c==CAT)&&lr(v->fgh[1])>=(UI)l&&rr(v->fgh[1])>=(UI)r?2:0;  // dyad for @ only, if rank big enough
   }
   R res;
 }
 R 0; 
}    /* 1 iff w is <@:f or <@f where f has infinite rank */

// w is a verb
// Result has bit 0 set if the verb is [ or ...@[, bit 1 set if ] or ...@]   (or @:)
// The set bit indicates that argument WILL NOT be examined when w is executed
I atoplr(A w){
 if(!w)R 0;
 V *v=FAV(w);     // v->verb info, c=id of w
 C id = v->id;if(v->id==CAT||v->id==CATCO)id = FAV(v->fgh[1])->id;
 switch(id){
  case CLEFT: R JTINPLACEW;   // ...@[  ok to inplace W
  case CRIGHT: R JTINPLACEA;   // ...@]  ok to inplace A
 }
 R 0;   // both args in use
}