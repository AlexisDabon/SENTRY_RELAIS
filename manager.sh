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
	code_retour=$?

	case $code_retour in
	
	0)
		echo "fermeture de session"
	;;
	
	10)
		echo "alerte secu : terminal verouillé après trois échec"
	;;

	20)
		echo "anomalie fréquence signal"
	;;
	
	esac

else
	echo "fichier introuvable"
	exit 1
fi


