#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//converts char to integer value
/*
int convertCI(char c){
	return c - '0';
}*/

//This program implements the RabinKarp Algorithm for string searching.
//
int main(int argc, char *argv[]){
	
	char fromText[130] = "";
	char input[130] = "";
	char pattern[130] = "";
	int i = 0;
	int j = 0;
	//int q = argv[1];
	int q = 13;
	int patternLength = 0;
	int flag = 0;
	int rkArr[64] = { 0 };
	FILE *fpread, fpwrite;
	int patternq = 0;
	//fpread = fopen(argv[2], "r");
	fpread = fopen("inputall.txt", "r");
	//fpwrite = fopen("output.txt", "w");
	int n = 0;
	int x = 1;
	int shift = -1;
	if(fpread != NULL){
		
		while(fgets(fromText, sizeof(fromText), fpread) != NULL){
			
			int length = strlen(fromText);
			if(fromText[length - 1] == '\n') 
				fromText[length - 1] = '\0';
			
			printf("String #%d: %s\n", x, fromText);
			//get text and pattern
			
			for(i = 0; i < length; i++){
				
				if(fromText[i] != '.'){
					
					if(flag){
						
						
						strncat(pattern, &fromText[i], 1);
						patternq = patternq + (int)fromText[i];
						
					}
					
					else{
						strncat(input, &fromText[i], 1);
						//kArr[i] = convertCI(fromText[i]);
						
					}
					 
				}
				
				
				else if(fromText[i] == '.')
					flag = 1;
				
			}
			
			patternq = patternq % q;
			flag = 0;
			for(i = 0; i < strlen(input); i++){
				
				if(strlen(input) - i < strlen(pattern)){ 
					//printf("\n%d", i);
					break;
				}
					
				for(j = 0; j < strlen(pattern); j++){
					
					rkArr[i] = rkArr[i] + (int)input[i + j]; //basically adding everything within pattern's size
					//printf("%d %d\n", j, (int)input[i+j]);
				}
				//printf("\n");
				rkArr[i] = rkArr[i] % q; //for hashing
				
				//printf("mod: %d \n", rkArr[i]);
				//printf("pattern: %d \n", patternq);
				n++;
				
			}
			//this part is the comparison
			for(i = 0; i < n; i++){
				
				if(rkArr[i] == patternq){
					
					for(j = 0; j < strlen(pattern); j++){
												
						if(input[i + j] == pattern[j]){
						
							flag = 1;
						}
						else{
							flag = 0;
							break;
						}
						
					}
					
				}
				if(flag){
					
					flag = 0;
					printf("Pattern occurs with shift %d\n", i);
					shift = 1;
				}
				
			}
			if(shift == -1){
				printf("Invalid shift\n");
			}
			//variable reset for next loop
			printf("\n");
			i = 0;
			memset(input, 0, sizeof(input));
			memset(pattern, 0, sizeof(pattern));
			flag = 0;
			shift = -1;
			patternq = 0;
			memset(rkArr, 0, sizeof(rkArr));
			x++;
			n = 0;
		}
	}
	
	fclose(fpread);
	
	
	return 0;
}
