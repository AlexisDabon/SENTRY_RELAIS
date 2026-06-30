struct Balise {
	float frequence;
	int statut_signal;
};

int main () {
	struct Balise ma_balise;
		ma_balise.frequence = 433.5;
		ma_balise.statut_signal = 1;
	
	int code_secret = 1234;
	int echecs = 0;
	int saisis_utilisateur = 0;

