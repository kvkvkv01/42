#!/bin/bash

# Check if we're in the right directory
if [[ ! -f "Makefile" ]] && [[ ! -f "libftprintf.a" ]]; then
    echo "Error: Run this script from your ft_printf directory"
    exit 1
fi

# Compile project
[[ -f "Makefile" ]] && make > /dev/null 2>&1

# Clone tester
rm -rf printfTester
git clone --quiet https://github.com/Tripouille/printfTester.git 2>/dev/null || exit 1

# Run tests
cd printfTester && make m
