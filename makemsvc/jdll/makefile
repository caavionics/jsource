ifdef DEBUG

ifdef x64
ifdef JAVX2
CFLAGS= /FS /Zi /D _JDLL /DC_AVX=1 /D C_AVX2=1 /arch:AVX2 /DC_NA=0 /WX /W3 /O2 /GS /Zc:strictStrings /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /MT
else
ifdef JAVX
CFLAGS= /FS /Zi /D _JDLL /DC_AVX=1 /arch:AVX /DC_NA=0 /WX /W3 /O2 /GS /Zc:strictStrings /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /MT
else
CFLAGS= /FS /Zi /D _JDLL /DC_NA=0 /WX /W3 /O2 /GS /Zc:strictStrings /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /MT
endif
endif
FLAGS= /DEBUG /DLL /NOLOGO /MACHINE:X64 /SUBSYSTEM:WINDOWS,5.02
ASMFLAGS= /Cx
else
CFLAGS= /FS /Zi /D _JDLL /WX /W3 /Ot /Oy- /GS /Zc:strictStrings /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /MT
FLAGS= /DEBUG /DLL /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS,5.01
ASMFLAGS= /Cx /coff
endif

else

ifdef x64
ifdef JAVX2
CFLAGS= /D _JDLL /DC_AVX=1 /D C_AVX2=1 /arch:AVX2 /DC_NA=0 /WX /W3 /O2 /GS /Zc:strictStrings /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /MT
else
ifdef JAVX
CFLAGS= /D _JDLL /DC_AVX=1 /arch:AVX /DC_NA=0 /WX /W3 /O2 /GS /Zc:strictStrings /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /MT
else
CFLAGS= /D _JDLL /DC_NA=0 /WX /W3 /O2 /GS /Zc:strictStrings /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /MT
endif
endif
FLAGS= /DLL /NOLOGO /MACHINE:X64 /SUBSYSTEM:WINDOWS,5.02
ASMFLAGS= /Cx
else
# /Og fail g310r
# /Oy crash ]^:_"1[0
CFLAGS= /D _JDLL /WX /W3 /Ot /Oy- /GS /Zc:strictStrings /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /MT
FLAGS= /DLL /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS,5.01
ASMFLAGS= /Cx /coff
endif

endif

.SUFFIXES: .o

OBJS=  \
 ../../jsrc/a.o \
 ../../jsrc/ab.o \
 ../../jsrc/aes-c.o \
 ../../jsrc/aes-ni.o \
 ../../jsrc/aes-sse2.o \
 ../../jsrc/af.o \
 ../../jsrc/ai.o \
 ../../jsrc/am.o \
 ../../jsrc/am1.o \
 ../../jsrc/amn.o \
 ../../jsrc/ao.o \
 ../../jsrc/ap.o \
 ../../jsrc/ar.o \
 ../../jsrc/as.o \
 ../../jsrc/au.o \
 ../../jsrc/blis/gemm_c-ref.o \
 ../../jsrc/blis/gemm_int-aarch64.o \
 ../../jsrc/blis/gemm_int-avx.o \
 ../../jsrc/blis/gemm_int-fma.o \
 ../../jsrc/blis/gemm_int-sse2.o \
 ../../jsrc/blis/gemm_vec-ref.o \
 ../../jsrc/c.o \
 ../../jsrc/ca.o \
 ../../jsrc/cc.o \
 ../../jsrc/cd.o \
 ../../jsrc/cf.o \
 ../../jsrc/cg.o \
 ../../jsrc/ch.o \
 ../../jsrc/cip.o \
 ../../jsrc/cl.o \
 ../../jsrc/cp.o \
 ../../jsrc/cpdtsp.o \
 ../../jsrc/cpuinfo.o \
 ../../jsrc/cr.o \
 ../../jsrc/crs.o \
 ../../jsrc/ct.o \
 ../../jsrc/cu.o \
 ../../jsrc/cv.o \
 ../../jsrc/cx.o \
 ../../jsrc/d.o \
 ../../jsrc/dc.o \
 ../../jsrc/dss.o \
 ../../jsrc/dstop.o \
 ../../jsrc/dsusp.o \
 ../../jsrc/dtoa.o \
 ../../jsrc/f.o \
 ../../jsrc/f2.o \
 ../../jsrc/fbu.o \
 ../../jsrc/gemm.o \
 ../../jsrc/i.o \
 ../../jsrc/io.o \
 ../../jsrc/j.o \
 ../../dllsrc/jdll.o \
 ../../dllsrc/jdllcomx.o \
 ../../jsrc/jdlllic.o \
 ../../jsrc/k.o \
 ../../jsrc/m.o \
 ../../jsrc/mbx.o \
 ../../jsrc/p.o \
 ../../jsrc/pv.o \
 ../../jsrc/px.o \
 ../../jsrc/r.o \
 ../../jsrc/rl.o \
 ../../jsrc/rt.o \
 ../../jsrc/s.o \
 ../../jsrc/sc.o \
 ../../jsrc/sl.o \
 ../../jsrc/sn.o \
 ../../jsrc/t.o \
 ../../jsrc/u.o \
 ../../jsrc/v.o \
 ../../jsrc/v0.o \
 ../../jsrc/v1.o \
 ../../jsrc/v2.o \
 ../../jsrc/va1.o \
 ../../jsrc/va1ss.o \
 ../../jsrc/va2.o \
 ../../jsrc/va2s.o \
 ../../jsrc/va2ss.o \
 ../../jsrc/vamultsp.o \
 ../../jsrc/vb.o \
 ../../jsrc/vbang.o \
 ../../jsrc/vbit.o \
 ../../jsrc/vcant.o \
 ../../jsrc/vcat.o \
 ../../jsrc/vcatsp.o \
 ../../jsrc/vchar.o \
 ../../jsrc/vcomp.o \
 ../../jsrc/vcompsc.o \
 ../../jsrc/vd.o \
 ../../jsrc/vdx.o \
 ../../jsrc/ve.o \
 ../../jsrc/vf.o \
 ../../jsrc/vfft.o \
 ../../jsrc/vfrom.o \
 ../../jsrc/vfromsp.o \
 ../../jsrc/vg.o \
 ../../jsrc/vgauss.o \
 ../../jsrc/vgcomp.o \
 ../../jsrc/vgranking.o \
 ../../jsrc/vgsort.o \
 ../../jsrc/vgsp.o \
 ../../jsrc/vi.o \
 ../../jsrc/viavx.o \
 ../../jsrc/viix.o \
 ../../jsrc/visp.o \
 ../../jsrc/vm.o \
 ../../jsrc/vo.o \
 ../../jsrc/vp.o \
 ../../jsrc/vq.o \
 ../../jsrc/vrand.o \
 ../../jsrc/vrep.o \
 ../../jsrc/vs.o \
 ../../jsrc/vsb.o \
 ../../jsrc/vt.o \
 ../../jsrc/vu.o \
 ../../jsrc/vx.o \
 ../../jsrc/vz.o \
 ../../jsrc/w.o \
 ../../jsrc/wc.o \
 ../../jsrc/wn.o \
 ../../jsrc/ws.o \
 ../../jsrc/x.o \
 ../../jsrc/x15.o \
 ../../jsrc/xa.o \
 ../../jsrc/xaes.o \
 ../../jsrc/xb.o \
 ../../jsrc/xc.o \
 ../../jsrc/xcrc.o \
 ../../jsrc/xd.o \
 ../../jsrc/xf.o \
 ../../jsrc/xfmt.o \
 ../../jsrc/xh.o \
 ../../jsrc/xi.o \
 ../../jsrc/xl.o \
 ../../jsrc/xo.o \
 ../../jsrc/xs.o \
 ../../jsrc/xsha.o \
 ../../jsrc/xt.o \
 ../../jsrc/xu.o \
 ../../jsrc/openssl/sha/keccak1600.o \
 ../../jsrc/openssl/sha/md4_dgst.o \
 ../../jsrc/openssl/sha/md4_one.o \
 ../../jsrc/openssl/sha/md5_dgst.o \
 ../../jsrc/openssl/sha/md5_one.o \
 ../../jsrc/openssl/sha/openssl-util.o \
 ../../jsrc/openssl/sha/sha1_one.o \
 ../../jsrc/openssl/sha/sha256.o \
 ../../jsrc/openssl/sha/sha3.o \
 ../../jsrc/openssl/sha/sha512.o

ifdef NO_SHA_ASM
CFLAGS1= /D NO_SHA_ASM
else
ifdef x64
OBJS_ASM= \
 ../../openssl-asm/keccak1600-x86_64-nasm.o \
 ../../openssl-asm/sha1-x86_64-nasm.o \
 ../../openssl-asm/sha256-x86_64-nasm.o \
 ../../openssl-asm/sha512-x86_64-nasm.o
else
OBJS_ASM= \
 ../../openssl-asm/keccak1600-mmx-nasm.o \
 ../../openssl-asm/sha1-586-nasm.o \
 ../../openssl-asm/sha256-586-nasm.o \
 ../../openssl-asm/sha512-586-nasm.o
endif
endif

DEF= ../../dllsrc/jdll.def
RCS= ../../dllsrc/jdll.rc

ifndef LD
LD=link
endif

%.o: %.c
	$(CC) $(CFLAGS) $(CFLAGS1) /Fo$@ /c $<

%.o: %.cpp
	$(CC) $(CFLAGS) /Fo$@ /c $<

%.o: %.asm
	$(ML) $(ASMFLAGS) /Fo$@ /c $<

ifdef x64
ifdef JAVX2
TARGET= javx2.dll
else
ifdef JAVX
TARGET= javx.dll
else
TARGET= j.dll
endif
endif
else
TARGET= j32.dll
endif

$(TARGET) : $(OBJS) $(SRC_ASM) $(OBJS_ASM) $(ASM) jdll.res
	$(LD) /NOLOGO /DEF:$(DEF) $(FLAGS) /out:$@ $(OBJS) $(SRC_ASM) $(OBJS_ASM) $(ASM) jdll.res ole32.lib advapi32.lib oleaut32.lib

jdll.res : $(RCS)
	$(RC) /L 0x409 /D _USING_V110_SDK71_ -R -FO$@ $(RCS)

all: $(TARGET)

clean:
	rm -f *.lib *.exp *.res *.ilk *.pdb $(OBJS) $(SRC_ASM)

.PHONY: all clean
