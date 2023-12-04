#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int shouldswap(char str[], int start,int curr){
	for(int i=start; i<curr; i++){
		if(str[i]==str[curr])
			return 0;
		return 1;
	}
}

void findpermutation(char str[], int index,int n){
	if(index>=n){
		printf("%s\n",str);
	}
	
	for(int i=index; i<n; i++){
		int check=shouldswap(str,index,n);
		if(check){
			char temp = str[index];
			str[index]=str[i];
			str[i]=temp;
			findpermutation(str,index+1,n);
			 temp=str[index];
			str[index]=str[i];
			str[i]=temp;
		}
		}
	}
	
void main(){
	char str[]="ssit";
	int len;
	len=strlen(str);
	findpermutation(str,0,len);
}