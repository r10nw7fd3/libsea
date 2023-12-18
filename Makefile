ARCH:=x86_64
ARCH_SUPPORTED:=x86_64

ifeq ($(filter $(ARCH),$(ARCH_SUPPORTED)),)
$(error Unsupported architecture $(ARCH))
endif

ASFLAGS:=-mnaked-reg -msyntax=intel
CFLAGS:=-Wall -Wextra -std=c11 -O2 -nostdlib -Iinclude
LDFLAGS:=-shared -nostdlib -z noexecstack

RUNTIME_SRC:=arch/$(ARCH)/crt0.S arch/$(ARCH)/crti.S arch/$(ARCH)/crtn.S
RUNTIME_OBJ:=$(subst arch/,build/arch/,$(RUNTIME_SRC:.S=.o))

LIB_SRC:=$(filter-out $(RUNTIME_SRC),$(wildcard arch/$(ARCH)/*.S)) $(wildcard portable/*.c)
LIB_OBJ:=$(subst .S,.o,$(LIB_SRC))
LIB_OBJ:=$(subst .c,.o,$(LIB_OBJ))
LIB_OBJ:=$(subst arch/,build/arch/,$(LIB_OBJ))
LIB_OBJ:=$(subst portable/,build/portable/,$(LIB_OBJ))

all: crt libc.a libc.so

crt: $(RUNTIME_OBJ)

libc.a: $(LIB_OBJ)
	$(AR) crs $@ $(LIB_OBJ)

libc.so: $(LIB_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(LIB_OBJ)

$(RUNTIME_OBJ): | build/arch/$(ARCH)
$(LIB_OBJ): | build/arch/$(ARCH) build/portable

build/arch/$(ARCH):
	mkdir -p $@

build/portable:
	mkdir -p $@

build/arch/$(ARCH)/%.o: arch/$(ARCH)/%.S
	$(AS) $(ASFLAGS) -o $@ $<

build/portable/%.o: portable/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf build libc.a libc.so test

test: test.c $(RUNTIME_OBJ) libc.a
	$(CC) $(CFLAGS) -z noexecstack -o test -Iinclude build/arch/$(ARCH)/crt0.o build/arch/$(ARCH)/crti.o test.c libc.a build/arch/$(ARCH)/crtn.o

.PHONY: all clean crt
