CC	?= gcc
MINGW	?= i686-w64-mingw32-
MINGW_CC	?= $(MINGW)gcc

CFLAGS	= `pkg-config --cflags gtk+-3.0`
LDLIBS	= `pkg-config --libs gtk+-3.0`

MINGW_CFLAGS	= `$(MINGW)pkg-config --cflags gtk+-3.0` -mwindows
MINGW_LDLIBS	= `$(MINGW)pkg-config --libs gtk+-3.0`

WEBKIT_CFLAGS	= `pkg-config --cflags gtk+-3.0 webkit2gtk-4.0`
WEBKIT_LDLIBS	= `pkg-config --libs gtk+-3.0 webkit2gtk-4.0`

ARTIFACT = example-0 example-1 example-2 example-3 example-3-1 example-3-2 \
	   example-webkit glade_test_1 are_you_sure

MINGW_ARTIFACT = mingw_example-0 mingw_example-1 mingw_example-2 mingw_example-3 mingw_example-3-1 mingw_example-3-2 mingw_glade_test_1 mingw_are_you_sure

ICONS = dialog-warning

all: $(ARTIFACT)

mingw: $(MINGW_ARTIFACT)
	cp mingw-copy-deps.bash work/mingw-copy-deps.bash

clean:
	rm -f *.o *.exe *.res *.ico $(ARTIFACT) work/*

## ref1: https://askubuntu.com/questions/867567
## ref2: https://stackoverflow.com/questions/708238
mingw_icon: $(ICONS).png
	convert -resize x48 -gravity center -crop 48x48+0+0 $(ICONS).png -flatten -colors 256 -background transparent $(ICONS).ico
	echo 'id ICON "$(ICONS).ico"' > $(ICONS).rc
	$(MINGW)windres $(ICONS).rc -O coff -o $(ICONS).res

example-0: example-0.c
	$(CC) $(CFLAGS) -o work/$@ $< $(LDLIBS)

example-1: example-1.c
	$(CC) $(CFLAGS) -o work/$@ $< $(LDLIBS)

example-2: example-2.c
	$(CC) $(CFLAGS) -o work/$@ $< $(LDLIBS)

example-3: example-3.c
	$(CC) $(CFLAGS) -o work/$@ $< $(LDLIBS)
	cp builder.ui work/builder.ui

example-3-1: example-3-1.c
	$(CC) $(CFLAGS) -o work/$@ $< $(LDLIBS)
	cp builder.ui work/builder.ui

example-3-2: example-3-2.c
	$(CC) $(CFLAGS) -o work/$@ $< $(LDLIBS)
	cp builder.ui work/builder.ui

example-webkit: example-webkit.c
	$(CC) $(WEBKIT_CFLAGS) -o work/$@ $< $(WEBKIT_LDLIBS)

glade_test_1: glade_test_1.c
	$(CC) $(CFLAGS) -o work/$@ $< $(LDLIBS)
	cp picshower.glade work/picshower.glade
	cp output.png work/output.png

are_you_sure: are_you_sure.c
	$(CC) $(CFLAGS) -o work/$@ $< $(LDLIBS)
	cp are_you_sure.glade work/are_you_sure.glade
	cp dialog-warning.png work/dialog-warning.png

mingw_example-0: example-0.c
	$(MINGW_CC) $(MINGW_CFLAGS) -o work/$@ $< $(MINGW_LDLIBS)

mingw_example-1: example-1.c
	$(MINGW_CC) $(MINGW_CFLAGS) -o work/$@ $< $(MINGW_LDLIBS)

mingw_example-2: example-2.c
	$(MINGW_CC) $(MINGW_CFLAGS) -o work/$@ $< $(MINGW_LDLIBS)

mingw_example-3: example-3.c
	$(MINGW_CC) $(MINGW_CFLAGS) -o work/$@ $< $(MINGW_LDLIBS)
	cp builder.ui work/builder.ui

mingw_example-3-1: example-3-1.c
	$(MINGW_CC) $(MINGW_CFLAGS) -o work/$@ $< $(MINGW_LDLIBS)
	cp builder.ui work/builder.ui

mingw_example-3-2: example-3-2.c
	$(MINGW_CC) $(MINGW_CFLAGS) -o work/$@ $< $(MINGW_LDLIBS)
	cp builder.ui work/builder.ui

mingw_glade_test_1: glade_test_1.c
	$(MINGW_CC) $(MINGW_CFLAGS) -o work/$@ $< $(MINGW_LDLIBS)
	cp picshower.glade work/picshower.glade
	cp output.png work/output.png

mingw_are_you_sure: are_you_sure.c
	$(MINGW_CC) $(MINGW_CFLAGS) -o work/are_you_sure.exe $< dialog-warning.res $(MINGW_LDLIBS)
	cp are_you_sure.glade work/are_you_sure.glade
	cp dialog-warning.png work/dialog-warning.png
