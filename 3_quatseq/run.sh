#!/bin/bash
function run()
{
    echo "Test $1"
    g++ -c quatseq_test.cc -o qtest.o -D TEST_NUM=$1
    g++ quatseq.o qtest.o -o qtest
    ./qtest
}

make debuglevel=2

num=0
run $num
num=101
while [ $num -le 142 ]; do
    run $num
    num=$[num + 1]
done
num=201
while [ $num -le 233 ]; do
    run $num
    num=$[num + 1]
done
num=301
while [ $num -le 304 ]; do
    run $num
    num=$[num + 1]
done
num=401
while [ $num -le 403 ]; do
    run $num
    num=$[num + 1]
done
#101 142
#201 233
#301 304
#401 403
