#!/bin/bash

cont=1

for LINEA in `cat prueba.txt`
do

    NOMBRE=`echo $LINEA | cut -d " " -f2`
 
    echo "$cont: $NOMBRE"
    cont=$((cont + 1))
done