ifdef x64
CFLAGS= /WX /W3 /O2 /GS /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /MT
FLAGS= /DLL /NOLOGO /MACHINE:X64 /SUBSYSTEM:WINDOWS,5.02
else
CFLAGS= /WX /W3 /Ot /Oy- /GS /D _USING_V110_SDK71_ /D _CRT_SECURE_NO_WARNINGS /M
FLAGS= /DLL /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS,5.01
endif

.SUFFIXES: .o

OBJS=  ../../jsrc/tsdll.o

DEF= ../../makevs/tsdll/tsdll.def

ifndef LD
LD=link
endif

%.o: %.c
	$(CC) $(CFLAGS) /Fo$@ /c $<

ifdef x64
TARGET= tsdll.dll
else
TARGET= tsdll32.dll
endif

$(TARGET) : $(OBJS)
	$(LD) /NOLOGO /DEF:$(DEF) $(FLAGS) /out:$@ $(OBJS)

jddll.res : $(RCS)
	$(RC) /L 0x409 /D _USING_V110_SDK71_ -R -FO$@ $(RCS)

all: $(TARGET)

clean:
	rm -f *.lib *.exp *.res $(OBJS)

.PHONY: all clean
