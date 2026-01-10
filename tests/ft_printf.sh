#!/bin/bash

# Check if we're in the right directory
if [[ ! -f "Makefile" ]] && [[ ! -f "libftprintf.a" ]]; then
    echo "Error: Run this script from your ft_printf directory"
    exit 1
fi

# Spinner function
spinner() {
    local pid=$1
    local msg=$2
    local frames=("⠋" "⠙" "⠹" "⠸" "⠼" "⠴" "⠦" "⠧" "⠇" "⠏")
    local i=0
    while kill -0 $pid 2>/dev/null; do
        printf "\r\033[36m${frames[$i]}\033[0m $msg"
        i=$(( (i + 1) % ${#frames[@]} ))
        sleep 0.08
    done
    printf "\r\033[K"
}

# Compile project
if [[ -f "Makefile" ]]; then
    make > /dev/null 2>&1 &
    spinner $! "Compiling..."
fi

# Clone tester
rm -rf printfTester
git clone --quiet https://github.com/Tripouille/printfTester.git 2>/dev/null &
spinner $! "Cloning tester..."

# Run tests and capture output
cd printfTester
make m > /tmp/printf_test_output.txt 2>&1 &
spinner $! "Running tests..."

output=$(cat /tmp/printf_test_output.txt)
rm -f /tmp/printf_test_output.txt

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
    echo -e "\033[32m✓\033[0m ft_printf: $total_ok/$total (100%)"
    cd ..
    rm -rf printfTester
    make fclean > /dev/null 2>&1
else
    echo -e "\033[31m✗\033[0m ft_printf: $total_ok/$total ($pct%) | Failed:$failed_cats"
fi
