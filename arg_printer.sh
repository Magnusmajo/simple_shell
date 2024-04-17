#!/bin/bash

# Print all arguments except the script name (first argument)
for arg in "${@:1}"; do
    echo "$arg"
done
