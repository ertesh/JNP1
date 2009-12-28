#!/bin/bash
cp maptel.h testy/
plik=$1
echo $plik

#make
#gcc -c $plik -o klient.o
#g++ maptel.o klient.o -o klient
#./klient


make debuglevel=2
gcc -c $plik -o klient.o
g++ maptel.o klient.o -o klient
./klient

rm testy/maptel.h
