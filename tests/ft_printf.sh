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

# Run tests and capture output
cd printfTester
output=$(make m 2>&1)

# Parse results
categories=("c" "s" "p" "d" "i" "u" "x" "X" "%" "mix")
total_ok=0
total_ko=0
failed_cats=""

for cat in "${categories[@]}"; do
    line=$(echo "$output" | grep -A1 "category: $cat" | tail -1)
    ok=$(echo "$line" | grep -o "OK" | wc -l)
    ko=$(echo "$line" | grep -o "KO" | wc -l)
    total_ok=$((total_ok + ok))
    total_ko=$((total_ko + ko))
    [[ $ko -gt 0 ]] && failed_cats="$failed_cats $cat($ko)"
done

total=$((total_ok + total_ko))
pct=$((total_ok * 100 / total))

# Display result
if [[ $total_ko -eq 0 ]]; then
    echo "✓ ft_printf: $total_ok/$total (100%)"
    cd ..
    rm -rf printfTester
    make fclean > /dev/null 2>&1
else
    echo "✗ ft_printf: $total_ok/$total ($pct%) | Failed:$failed_cats"
fi
