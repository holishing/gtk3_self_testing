#!/bin/sh

/usr/bin/gcc -Wall -g -o test_glade_01 test.c `pkg-config --cflags --libs gtk+-3.0`
