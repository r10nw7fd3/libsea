ASFLAGS:=-mnaked-reg -msyntax=intel
CFLAGS:=-Wall -Wextra -std=c11 -O2 -nostdlib -Iinclude
LDFLAGS:=-shared -nostdlib -z noexecstack

RUNTIME_SRC:=src/crt0.s src/crti.s src/crtn.s
RUNTIME_OBJ:=$(subst src/,build/,$(RUNTIME_SRC:.s=.o))

LIB_SRC:=$(filter-out $(RUNTIME_SRC),$(wildcard src/*.s)) $(wildcard src/*.c)
LIB_OBJ:=$(subst src/,build/,$(subst .c,.o,$(LIB_SRC:.s=.o)))

all: $(RUNTIME_OBJ) libc.a libc.so

libc.a: $(LIB_OBJ)
	$(AR) crs $@ $(LIB_OBJ)

libc.so: $(LIB_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(LIB_OBJ)

$(RUNTIME_OBJ): | build
$(LIB_OBJ): | build

build:
	mkdir $@

build/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf build libc.a libc.so test

test: test.c $(RUNTIME_OBJ) libc.a
	$(CC) $(CFLAGS) -z noexecstack -o test -Iinclude build/crt0.o build/crti.o test.c libc.a build/crtn.o

.PHONY: all clean
