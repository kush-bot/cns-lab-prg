#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int **matrixMultiply(int **a,int r1,int c1,int **b,int r2,int c2){
	int **resultMatrix;
	int i,j,k,r,c;
	r=r1;c=c2;
	resultMatrix=(int**)malloc(sizeof(int*)*r);
	for(i=0; i<r; i++)
		resultMatrix[i]=(int*)malloc(sizeof(int)*c);
	for(int i=0; i<r; i++){
		for(j=0; j<c; j++){
			resultMatrix[i][j]=0;
			for(k=0; k<c1; k++)
				resultMatrix[i][j]+=a[i][k]*b[k][j];
			}
		}
	return resultMatrix;

}
void plainTextTocipher(char plainText[],int **matrix){
	int **plainTextMatrix,**resultMatrix,len;
	char *cipherText;
	len=strlen(plainText);
	cipherText = (char*)malloc(sizeof(char)*1000);
	
	plainTextMatrix=(int**)malloc(sizeof(int*)*len);
	for(int i=0; i<len; i++)
		plainTextMatrix[i]=(int*)malloc(sizeof(int)*1);
	
	for(int i=0; i<len; i++)
		for(int j=0; j<1; j++)
			plainTextMatrix[i][j]=plainText[i]-'a';
	
	resultMatrix=matrixMultiply(matrix,len,len,plainTextMatrix,len,1);
	
	for(int i=0; i<len; i++)
		for(int j=0; j<1; j++)
			resultMatrix[i][j]%=26;
	
	for(int i=0; i<len; i++)
		for(int j=0; j<1; j++)
			printf("%c",resultMatrix[i][j]+'a');
			

}


void main(){
	int len,**matrix,i,j;
	char plainText[1000];
	printf("enter the plain text :");
	scanf("%s",plainText);
	len=strlen(plainText);
	matrix=(int**)malloc(sizeof(int*)*len);
	for(i=0; i<len; i++)
		matrix[i]=(int*)malloc(sizeof(int)*len);
	printf("enter the %d x %d matrix\n",len,len);
	for(i=0; i<len; i++)
		for(j=0; j<len; j++)
			scanf("%d",&matrix[i][j]);
	plainTextTocipher(plainText,matrix);
}
