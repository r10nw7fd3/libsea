ARCH:=x86_64
ARCH_SUPPORTED:=x86_64

ifeq ($(filter $(ARCH),$(ARCH_SUPPORTED)),)
$(error Unsupported architecture $(ARCH))
endif

ASFLAGS:=-mnaked-reg -msyntax=intel
CFLAGS:=-Wall -Wextra -std=c11 -O2 -nostdlib -Iinclude -fno-builtin -fPIC -fvisibility=hidden
LDFLAGS:=-shared -nostdlib -z noexecstack

RUNTIME_SRC:=$(ARCH)/crt0.S $(ARCH)/crti.S $(ARCH)/crtn.S
RUNTIME_OBJ:=$(foreach e,$(RUNTIME_SRC:.S=.o),build/$e)

LIB_SRC:=$(filter-out $(RUNTIME_SRC),$(wildcard $(ARCH)/*.S)) $(wildcard common/*.c)
LIB_OBJ:=$(subst .S,.o,$(LIB_SRC))
LIB_OBJ:=$(subst .c,.o,$(LIB_OBJ))
LIB_OBJ:=$(foreach e,$(LIB_OBJ),build/$e)

_:=$(if $(filter clean,$(MAKECMDGOALS)), \
	$(info rm -rf build include libc.a libc.so test) \
	$(shell rm -rf build include libc.a libc.so test))

all: crt libc.a libc.so

crt: $(RUNTIME_OBJ)

libc.a: $(LIB_OBJ)
	$(AR) crs $@ $(LIB_OBJ)

libc.so: $(LIB_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(LIB_OBJ)

$(RUNTIME_OBJ): | build/$(ARCH)
$(LIB_OBJ): | include build/$(ARCH) build/common

include:
	cp -r common/include .
	cp -r $(ARCH)/include/* include

build/$(ARCH):
	mkdir -p $@

build/common:
	mkdir -p $@

build/$(ARCH)/%.o: $(ARCH)/%.S
	$(AS) $(ASFLAGS) -o $@ $<

build/common/%.o: common/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@true

test: test.c $(RUNTIME_OBJ) libc.a
	$(CC) $(CFLAGS) -fno-stack-protector -z noexecstack -o test -Iinclude build/$(ARCH)/crt0.o build/$(ARCH)/crti.o test.c libc.a build/$(ARCH)/crtn.o

.PHONY: all clean crt
