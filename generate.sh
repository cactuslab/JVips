#!/bin/bash -eu
# Generate code from currently installed vips
# MAKE SURE IT'S THE SAME VERSION YOU'RE BUILDING

rm -f src/main/java/com/criteo/vips/enums/*
rm -f src/main/java/com/criteo/vips/options/*

(
	cd script/generate
	pnpm install
	pnpm start
)

cp -rf src/generate/* src/main/
