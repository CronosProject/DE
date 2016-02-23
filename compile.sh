#!/bin/bash

gcc -I includes/ main.c src/*.c src/network/*.c src/utils/*.c -o test