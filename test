#!/bin/bash

test_two=(
	"1 2"
	"2 1"
)
test_three=(
	"1 2 3"
	"1 3 2"
	"2 1 3"
	"2 3 1"
	"3 1 2"
	"3 2 1"
)
test_four=(
	"1 2 3 4"
	"1 2 4 3"
	"1 3 2 4"
	"1 3 4 2"
	"1 4 2 3"
	"1 4 3 2"
	"2 1 3 4"
	"2 1 4 3"
	"2 3 1 4"
	"2 3 4 1"
	"2 4 1 3"
	"2 4 3 1"
	"3 1 2 4"
	"3 1 4 2"
	"3 2 1 4"
	"3 2 4 1"
	"3 4 1 2"
	"3 4 2 1"
	"4 1 2 3"
	"4 1 3 2"
	"4 2 1 3"
	"4 2 3 1"
	"4 3 1 2"
	"4 3 2 1"
)
test_five=(
	"1 2 3 4 5"
	"1 2 3 5 4"
	"1 2 4 3 5"
	"1 2 4 5 3"
	"1 2 5 3 4"
	"1 2 5 4 3"
	"1 3 2 4 5"
	"1 3 2 5 4"
	"1 3 4 2 5"
	"1 3 4 5 2"
	"1 3 5 2 4"
	"1 3 5 4 2"
	"1 4 2 3 5"
	"1 4 2 5 3"
	"1 4 3 2 5"
	"1 4 3 5 2"
	"1 4 5 2 3"
	"1 4 5 3 2"
	"1 5 2 3 4"
	"1 5 2 4 3"
	"1 5 3 2 4"
	"1 5 3 4 2"
	"1 5 4 2 3"
	"1 5 4 3 2"
	"2 1 3 4 5"
	"2 1 3 5 4"
	"2 1 4 3 5"
	"2 1 4 5 3"
	"2 1 5 3 4"
	"2 1 5 4 3"
	"2 3 1 4 5"
	"2 3 1 5 4"
	"2 3 4 1 5"
	"2 3 4 5 1"
	"2 3 5 1 4"
	"2 3 5 4 1"
	"2 4 1 3 5"
	"2 4 1 5 3"
	"2 4 3 1 5"
	"2 4 3 5 1"
	"2 4 5 1 3"
	"2 4 5 3 1"
	"2 5 1 3 4"
	"2 5 1 4 3"
	"2 5 3 1 4"
	"2 5 3 4 1"
	"2 5 4 1 3"
	"2 5 4 3 1"
	"3 1 2 4 5"
	"3 1 2 5 4"
	"3 1 4 2 5"
	"3 1 4 5 2"
	"3 1 5 2 4"
	"3 1 5 4 2"
	"3 2 1 4 5"
	"3 2 1 5 4"
	"3 2 4 1 5"
	"3 2 4 5 1"
	"3 2 5 1 4"
	"3 2 5 4 1"
	"3 4 1 2 5"
	"3 4 1 5 2"
	"3 4 2 1 5"
	"3 4 2 5 1"
	"3 4 5 1 2"
	"3 4 5 2 1"
	"3 5 1 2 4"
	"3 5 1 4 2"
	"3 5 2 1 4"
	"3 5 2 4 1"
	"3 5 4 1 2"
	"3 5 4 2 1"
	"4 1 2 3 5"
	"4 1 2 5 3"
	"4 1 3 2 5"
	"4 1 3 5 2"
	"4 1 5 2 3"
	"4 1 5 3 2"
	"4 2 1 3 5"
	"4 2 1 5 3"
	"4 2 3 1 5"
	"4 2 3 5 1"
	"4 2 5 1 3"
	"4 2 5 3 1"
	"4 3 1 2 5"
	"4 3 1 5 2"
	"4 3 2 1 5"
	"4 3 2 5 1"
	"4 3 5 1 2"
	"4 3 5 2 1"
	"4 5 1 2 3"
	"4 5 1 3 2"
	"4 5 2 1 3"
	"4 5 2 3 1"
	"4 5 3 1 2"
	"4 5 3 2 1"
	"5 1 2 3 4"
	"5 1 2 4 3"
	"5 1 3 2 4"
	"5 1 3 4 2"
	"5 1 4 2 3"
	"5 1 4 3 2"
	"5 2 1 3 4"
	"5 2 1 4 3"
	"5 2 3 1 4"
	"5 2 3 4 1"
	"5 2 4 1 3"
	"5 2 4 3 1"
	"5 3 1 2 4"
	"5 3 1 4 2"
	"5 3 2 1 4"
	"5 3 2 4 1"
	"5 3 4 1 2"
	"5 3 4 2 1"
	"5 4 1 2 3"
	"5 4 1 3 2"
	"5 4 2 1 3"
	"5 4 2 3 1"
	"5 4 3 1 2"
	"5 4 3 2 1"
)
	# ./push_swap "1 2" | wc -l
	# ./push_swap "1 2" | ./checker_linux "1 2"
	# ./push_swap "2 1" | wc -l
	# ./push_swap "2 1" | ./checker_linux "2 1"

echo "[-] compiling..."
make re  >/dev/null 2>&1
echo "[-] testing 2..."
for str in "${test_two[@]}"; do
	OP_NB=$(./push_swap $str | wc -l)
	IS_OK=$(./push_swap $str | ./checker_linux $str)
	if [[ $IS_OK = "OK" ]]
	then
		echo "[+] $IS_OK - $str - $OP_NB"
	else
		echo "[!] $IS_OK - $str - $OP_NB"
	fi
done

echo "[-] testing 3..."
for str in "${test_three[@]}"; do
	OP_NB=$(./push_swap $str | wc -l)
	IS_OK=$(./push_swap $str | ./checker_linux $str)
	if [[ $IS_OK = "OK" ]]
	then
		echo "[+] $IS_OK - $str - $OP_NB"
	else
		echo "[!] $IS_OK - $str - $OP_NB"
	fi
done

echo "[-] testing 4..."
for str in "${test_four[@]}"; do
	OP_NB=$(./push_swap $str | wc -l)
	IS_OK=$(./push_swap $str | ./checker_linux $str)
	if [[ $IS_OK = "OK" ]]
	then
		echo "[+] $IS_OK - $str - $OP_NB"
	else
		echo "[!] $IS_OK - $str - $OP_NB"
	fi
done

echo "[-] testing 5..."
for str in "${test_five[@]}"; do
	OP_NB=$(./push_swap $str | wc -l)
	IS_OK=$(./push_swap $str | ./checker_linux $str)
	if [[ $IS_OK = "OK" ]]
	then
		echo "[+] $IS_OK - $str - $OP_NB"
	else
		echo "[!] $IS_OK - $str - $OP_NB"
	fi
done
