#!/bin/bash
# +----------------------------------------------------------------------------+
# | MM6DTest v0.1 * Tester program for MM6D remote controlled switching device |
# | Copyright (C) 2021 Pozsar Zsolt <pozsar.zsolt@szerafingomba.hu>            |
# | build.sh                                                                   |
# | Builder script for linux                                                   |
# +----------------------------------------------------------------------------+

wmake -e -f Makefile.linux $1
