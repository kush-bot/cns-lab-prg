#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main(){
	char plain[100],cipher[100];
	int key,len;
	printf("enter the plain text :");
	scanf("%s",plain);
	printf("enter the key :");
	scanf("%d",&key);
	len=strlen(plain);
	printf("encrypted message : ");
	for(int i=0; i<len; i++){
		cipher[i]=plain[i]+key;
		if(isupper(plain[i]) && (cipher[i]>'Z'))
			cipher[i]=cipher[i]-26;
		if(islower(plain[i]) && (cipher[i]>'z'))
			cipher[i]=cipher[i]-26;
			printf("%c",cipher[i]);
	}
	printf("\nafter decryption: ");
	for(int i=0; i<len; i++){
		plain[i]=cipher[i]-key;
		if(isupper(cipher[i]) && (plain[i]<'A'))
			plain[i]=plain[i]+26;
		if(islower(cipher[i]) && (plain[i]<'a'))
			plain[i]=plain[i]+26;
			printf("%c",plain[i]);
	}
		
}
