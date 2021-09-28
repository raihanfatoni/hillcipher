/*
Nama      : Muhammad Raihan Fatoni
NPM       : 140810190034
Nama      : Farhan Maulana Alief
NPM       : 140810190073
Kelas     : A
Deskripsi : Program Hill Cipher Encryption dan Decryption
*/

#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
 
float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];

void Encryption();
void Decryption();
void inputkey();
void inverseMatrix();

int main() {
    mulai:
	string x;
    cout << "~ HILL CIPHER PROGRAM ~ "<<endl;
    cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
	inputkey();
	Encryption();
	Decryption();

    cout<<"Restart the program? (Y/N) ";
    cin>>x;

    if(x == "Y" || x == "y"){
        goto mulai;
    }
    else{
        return 0;
    }
}

void Encryption() {
	int i, j, k;
	
	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
	
	cout << "Encrypted Message : ";
	for(i = 0; i < 3; i++)
		cout<<(char)(fmod(encrypt[i][0], 26) + 97);
 
}

 
void Decryption() {
	int i, j, k;
	inverseMatrix();
	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];

	cout << "Decrypted Message : ";
	for(i = 0; i < 3; i++){
		cout<<(char)(fmod(decrypt[i][0], 26) + 97);
    }
	cout << endl;
    cout << endl;
}
 
void inputkey() {
	int i, j;
	char msg[3];
 
	cout << " Key : ";

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++) {
            cout << "["<<i+1<<","<<j+1<<"] : "; cin >> a[i][j];
			c[i][j] = a[i][j];
		}
	
	cout << "Plaintext : ";
	cin >> msg;
	
	for(i = 0; i < 3; i++)
		mes[i][0] = msg[i] - 97;
}

void inverseMatrix() {
	int i, j, k;
	float p, q;
	
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++) {
			if(i == j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
		
	for(k = 0; k < 3; k++) {
		for(i = 0; i < 3; i++) {
			p = c[i][k];
			q = c[k][k];
				
			for(j = 0; j < 3; j++) {
				if(i != k) {
					c[i][j] = c[i][j]*q - p*c[k][j];
					b[i][j] = b[i][j]*q - p*b[k][j];
				}
			}
		}
	}
	
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			b[i][j] = b[i][j] / c[i][i];
    cout<<endl;
	cout << "Inversed Matrix :  "<<endl;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++){
            cout << "  ";
			cout << b[i][j]; 
        }
		cout << endl;
	}
}
 