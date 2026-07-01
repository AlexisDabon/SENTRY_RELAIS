struct Balise {
	float frequence;
	int statut_signal;
};

int main () {
	struct Balise ma_balise;
		ma_balise.frequence = 150.0;
		ma_balise.statut_signal = 1;
	
	int code_secret = 1234;
	int echecs = 0;
	int saisis_utilisateur = 0;
	
	while (echecs < 3) {
		printf("taper le code d'accès \n");
		scanf("%d", &saisis_utilisateur);

	if (saisis_utilisateur == code_secret) {
		printf("code correct \n");
		break;
	}
	else { 
		echecs++;
		printf("erreur \n");
	} 
}

	

