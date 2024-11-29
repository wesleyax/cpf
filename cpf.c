#include <stdio.h>
#include <string.h>


char check (char slave[11]){
	int cpf[11];
	int i;
	int x = 10;
	int digit1 = 0;
	int digit2 = 0;
	
	for(i=0; i<=10; i++){
		cpf[i] = slave[i] - '0'; //Converting char in int
	}

	for(i=0;i<9;i++){
		digit1 += cpf[i] * x;
		x--;
	}
	
	digit1 = 11 - (digit1 % 11);
	
	if (digit1 >= 10){
		digit1 = 0;
	}
	
	x = 11;
	
	for(i=0;i<10;i++){
		digit2 += cpf[i] * x;
		x--;
	}
	digit2 = 11 - (digit2 % 11);
	
	if (digit2 >= 10){
		digit2 = 0;
	}
	
	if(cpf[9]==digit1 && cpf[10]==digit2){
		printf("\nCorrect");
	} else {
		printf("\nIncorrect");
	}
}

char create (char slave[9]){
	int cpf[10];
	int i;
	int x = 10;
	int digit1 = 0;
	int digit2 = 0;
	
	for(i=0; i<=8; i++){
		cpf[i] = slave[i] - '0'; //Converting char in int
	}
	
	for(i=0;i<9;i++){
		digit1 += cpf[i] * x;
		x--;
	}
	
	digit1 = 11 - (digit1 % 11);
	
	if (digit1 >= 10){
		digit1 = 0;
	}
	
	cpf[9] = digit1;
	
	x = 11;
	
	for(i=0;i<10;i++){
		digit2 += cpf[i] * x;
		x--;
	}
	
	digit2 = 11 - (digit2 % 11);
	
	if (digit2 >= 10){
		digit2 = 0;
	}
	
	printf("The verification digit is: %d%d\n",digit1,digit2);
}
int main(int argc, char *argv[]) {
	
	int option = 0;
	char cpfCheck[11];
	char cpfCreate[9];

	while(option != 1 && option != 2){
		printf("1 - To check the verification digit\n");
		printf("2 - To create the verification digit\n");
		printf("Option: ");
		scanf("%d",&option);
		if(option != 1 && option != 2){
			system("cls");
			printf("\n\\--------Incorrect value--------//\n\n");
		}
	}
	system("cls");
	
	if(option == 2){
		while(strlen(cpfCreate)!=9){
			printf("Write the first 9 characters of the CPF: ");
			scanf("%s",&cpfCreate);
			if(strlen(cpfCreate)!=9){
				system("cls");
				printf("\n\\--------Incorrect value--------//\n\n");
			}
		}   	
		create(cpfCreate);
	}else{
		while(strlen(cpfCheck)!=11){
			printf("Write your CPF: ");
			scanf("%s",&cpfCheck);
			if(strlen(cpfCheck)!=11){
				system("cls");
				printf("\n\\--------Incorrect value--------//\n\n");
			}
		}
		check(cpfCheck);
	}	
}
