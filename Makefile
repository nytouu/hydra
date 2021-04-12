# hydra - a fork of hydra, the dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c hydra.c util.c
OBJ = ${SRC:.c=.o}

all: options hydra

options:
	@echo hydra build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

hydra: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f hydra ${OBJ} hydra-${VERSION}.tar.gz

dist: clean
	mkdir -p hydra-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		hydra.1 drw.h util.h ${SRC} hydra.png transient.c hydra-${VERSION}
	tar -cf hydra-${VERSION}.tar hydra-${VERSION}
	gzip hydra-${VERSION}.tar
	rm -rf hydra-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f hydra ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/hydra
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < hydra.1 > ${DESTDIR}${MANPREFIX}/man1/hydra.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/hydra.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/hydra\
		${DESTDIR}${MANPREFIX}/man1/hydra.1

.PHONY: all options clean dist install uninstall
