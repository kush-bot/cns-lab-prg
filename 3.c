#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int i,j,len,count,code[100][100],rails;
	char str[100];
	printf("enter the plain text:\n");
	gets(str);
	len=strlen(str);
	printf("enter the number of rails : \n");
	scanf("%d",&rails);
	for(int i=0; i<rails; i++)
	{
		for(int j=0; j<len; j++){
			code[i][j]=0;
		}
	}
	count=0;
	j=0;
	while(j<len)
	{
		if(count%2==0)
		{
			for(i=0; i<rails; i++)
			{
				code[i][j]=(int)str[j];
				j++;
			}
		}
		else{
			for(i=rails-2; i>0; i--){
				code[i][j] = (int)str[j];
				j++;
			}
		}
		count++;
	}
	printf("encrypted message:\n");
	for(i=0; i<rails; i++)
		for(j=0; j<len; j++)
			if(code[i][j]!=0){
				printf("%c",code[i][j]);
}
	printf("after decryption :\n");
	count=0;
	j=0;
	while(j<len)
	{
		if(count%2==0)
		{
			for(i=0; i<rails; i++)
			if(code[i][j]!=0)
			{
				printf("%c",code[i][j]);
				j++;
			}
		}else{
			for(i=rails-2; i>0; i--){
			if(code[i][j]!=0)
			{
				printf("%c",code[i][j]);
				j++;
			}
		}
		count++;
	}
}
		
	

}