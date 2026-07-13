#include <stdio.h>

struct Balise {
	float frequence;
	int statut_signal;
	};
	
	typedef struct {
		char data_brut [64];
		char data_chiffres [64];
		unsigned char clefs_dynamiques;
	} Payload;
	
	void appliquer_crypto(Payload *p) {
		int i = 0;

		while (p -> data_brut[i] != '\0' && i < 64) {
			p -> data_chiffres[i] = p -> data_brut[i] ^ p -> clefs_dynamiques;
			i ++;
		}
		if (i < 64) {
			p -> data_chiffres[i] = '\0';
		}
	}

int main () {
	struct Balise ma_balise;
		ma_balise.frequence = 150.0;
		ma_balise.statut_signal = 1;
	
	int code_secret = 1234;
	int echecs = 0;
	int saisis_utilisateur = 0;
	int choix = 0;
	int c;

	while (echecs < 3) {
		printf("taper le code d'accès \n");
		if (scanf("%d", &saisis_utilisateur) != 1) {
		printf("saisis invalide : tapez des chiffres \n");
		while ((c = getchar()) != '\n' && c != EOF);
		echecs++;
		continue;
	}
		if (saisis_utilisateur == code_secret) {
		printf("code correct \n");
		break;
		}

		else {
		echecs++;
		printf("erreur \n");
		}
	}

		if (echecs == 3) {
		return 10;
	}

	printf("Access \n");
	
	printf("frequence : %.2f \n", ma_balise.frequence);
	printf("statut_signal : %d \n", ma_balise.statut_signal);

	printf("1.modifier frequence : \n");
	printf("2.Deconnexion \n");
	printf("choix : \n");
	scanf("%d", &choix);

	switch (choix) {

		case 1 :
		printf("entrez la nouvelle frequence : \n");
		scanf("%f", &ma_balise.frequence);

		if (ma_balise.frequence < 100.0 || ma_balise.frequence > 500.0) {
		printf("interuption du programme \n");
		ma_balise.statut_signal = 0;
		return 20;
		}

		printf("nouvelle frequence : %.2f \n", ma_balise.frequence);
		break;

		case 2 :
		printf("Deconnexion \n");
		return 0;

		default :
		printf("choix invalide \n");
		break;

	}

return 0;

}
		

