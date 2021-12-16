#!/bin/sh
../Dominios\ PA/seq-sat-cbp/cbp-roller -o domain.pddl -f problema-1.pddl -O > salida-problema-1.txt
echo Test 1: Completed
../Dominios\ PA/seq-sat-cbp/cbp-roller -o domain.pddl -f problema-2.pddl -O > salida-problema-2.txt
echo Test 2: Completed
../Dominios\ PA/seq-sat-cbp/cbp-roller -o domain.pddl -f problema-3.pddl -O > salida-problema-3.txt
echo Test 3: Completed
../Dominios\ PA/seq-sat-cbp/cbp-roller -o domain.pddl -f problema-4.pddl -O > salida-problema-4.txt
echo Test 4: Completed
../Dominios\ PA/seq-sat-cbp/cbp-roller -o dominioP5.pddl -f problema-5.pddl -O > salida-problema-5.txt
echo Test 5: Completed
../Dominios\ PA/seq-sat-cbp/cbp-roller -o domain.pddl -f problema-6.pddl -O > salida-problema-6.txt
echo Test 6: Completed
../Dominios\ PA/seq-sat-cbp/cbp-roller -o domain.pddl -f problema-7.pddl -O > salida-problema-7.txt
echo Test 7: Completed