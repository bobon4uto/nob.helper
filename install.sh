#!/bin/bash

set -e

BIN_DIR="/usr/local/bin"
cp ./nobh.sh "$BIN_DIR/nobh" 
chmod +x "$BIN_DIR/nobh"
NOB_TEMPLATE_DIR="/usr/local/share/nobh"
mkdir -p "$NOB_TEMPLATE_DIR"
cp ./nob.c "$NOB_TEMPLATE_DIR/"
cp ./nob.h "$NOB_TEMPLATE_DIR/"
echo "Installation complete:"
echo "	nob template is in $NOB_TEMPLATE_DIR"
echo "	nobh utility is in $BIN_DIR"
