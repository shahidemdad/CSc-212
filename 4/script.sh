set ff=unix
#!bin/bash

make

echo "$(./exam)" | cat > result.txt

rm *.o
