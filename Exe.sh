#!/bin/bash

EXECUTABLE="bin/SOTW"

if [ -f "$EXECUTABLE" ]; then    
    ./$EXECUTABLE
else
    echo "Error: $EXECUTABLE Not Found."
fi