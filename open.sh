#!/bin/bash

if [[ ${1} == "debug" ]]; then
	echo "DEBUGGER OPEN VERSION"

else
	./project/current.app/Contents/MacOS/current
fi
