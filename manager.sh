#!/bin/bash

if [ -f "main.c" ]; then
	echo "accès autorisé";
else
	echo "fichier introuvable";
	exit 1;
fi
