#!/usr/bin/make
#
# Rosters					May 30, 2024
#
# source: src/roster/Makefile
# author: @misael-diaz
#
# Synopsis:
# Defines the Makefile for building the program with GNU make.
#
# Copyright (c) 2024 Misael Díaz-Maldonado
# This file is released under the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#

include make-inc

all: $(ROSTER_BIN)

$(ROSTER_BIN): $(ROSTER_OBJ)
	$(CXX) $(CXXOPT) $(ROSTER_OBJ) -o $(ROSTER_BIN)

$(ROSTER_OBJ): $(HEADERS) $(ROSTER_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(ROSTER_CXX) -o $(ROSTER_OBJ)

clean:
	/bin/rm -f *.obj *.bin
