
PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin
CFLAGS = -Wall -Werror -Wsign-compare

ifdef DEBUG
CFLAGS += -O0
else
CFLAGS += -O2
endif

all: mktokens

%.o: %.c
	gcc -g -c -o $@ $< $(CFLAGS)

mktokens: mktokens.o
	gcc -g -o $@ $^ -lgmp $(CFLAGS)

install: mktokens
	install -d $(BINDIR)
	install -m 755 mktokens $(BINDIR)

.PHONY: clean
clean:
	-rm *.o mktokens
