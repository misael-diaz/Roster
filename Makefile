#!/usr/bin/make
#
# Roster					May 30, 2024
#
# source: Makefile
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

export CXX
export CXXOPT

all: srcs

srcs:
	@$(MAKE) -C src

clean:
	@$(MAKE) -C src clean
