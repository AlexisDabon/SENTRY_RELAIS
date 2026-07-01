#!/bin/bash

if [ -f "main.c" ]; then
	echo "accès autorisé"
	gcc -Wall -Wextra main.c -o programme_balise

	if [ $? -ne 0 ]; then
		echo "Echec compilation"
		exit 1
	fi
	
	clear

	./programme_balise

else
	echo "fichier introuvable"
	exit 1
fi


