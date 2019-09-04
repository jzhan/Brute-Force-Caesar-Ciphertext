#include <stdio.h>
#include <stdint.h>
#include <string.h>

void decrypt(const char *encrypted_message, char *decrypted_message, uint32_t len, uint32_t shift);

int main() {
	char message[1001];
	char encrypted_message[1001];
	char decrypted_message[1001];
	uint32_t len;
	
	printf("Masukkan pesan yang akan didekripsi (MAX: 1000 karakter)\n");
	fgets(encrypted_message, 1000, stdin);

	len = strlen(encrypted_message) - 1;
	encrypted_message[len] = 0;

	for(int i = 1; i < 26; ++i) {
		decrypt(encrypted_message, decrypted_message, len, i);
		printf("%s\n", decrypted_message);
	}
	
	return 0;
}

void decrypt(const char *encrypted_message, char *decrypted_message, uint32_t len, uint32_t shift) {
	for(uint32_t i = 0; i < len; ++i) {
		if(encrypted_message[i] >= 0x41 && encrypted_message[i] <= 0x5A || encrypted_message[i] >= 0x61 && encrypted_message[i] <= 0x7A) {
			decrypted_message[i] = ((encrypted_message[i] <= 0x5A? encrypted_message[i] - 0x41: encrypted_message[i] - 0x61) - shift);
			decrypted_message[i] = (decrypted_message[i] < 0? 26 + decrypted_message[i]: decrypted_message[i]) + 0x41;	
		} else {
			decrypted_message[i] = encrypted_message[i];
		}
	}

	decrypted_message[len] = 0;
}