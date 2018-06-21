#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void filez();
void converter(char letters[],int count[]);

int main(int argc, char** argv) {
	char stopper[2];
	filez();
	fgets(stopper,sizeof(2),stdin);
	return 0;
}

void converter(char letters[],int count[]) {
	int i;
	int j;
	int contain;
	int highest=0;
	int lowest=0;
	char rletters[26] = {'e','t','a','n','i','o','s','r','h','d','c','l','m','p','u','w','f','g','z','j','v','b','y','k','q','x'};
	char temp[26];
	char assign[1];
	FILE * fop;
	char read;
	
	for (j = 0 ; j < 26; j++) {
		for (i = 0 ; i < 26; i++) {
			if (count[i]<count[i+1]) {
				contain =count[i];
				count[i] = count[i+1];
				count[i+1] = contain;	
				assign[1] = letters[i];
				letters[i] = letters[i+1];
				letters[i+1] = assign[1];
			}
		}
	}
	printf("\n");
	for (i = 0 ; i < 26;i++) {
		temp[i] = rletters[i];
		temp[0] = 'e';
		printf("%c: %c\t",letters[i],temp[i]);
	}
	printf("\n");
	fop = fopen("q1a.txt","r");
	while ((read = fgetc(fop)) != EOF) {
		for (i = 0 ; i < 26;i++) {
			if (read == letters[i]) {
				printf("%c",temp[i]);
			}
		}
		j++;
		if (j >80) {
			printf("\n");
			j=0;
		}
	}
}


void filez() {
	char read;
	int i;
	int j;
	int count[26];
	FILE * fop;
	char letters[26];
	bool found =false;
	
	for (i =0;i<sizeof(letters);i++) {
		letters[i] ='0';
		count[i]=0;
	}
	fop = fopen("q1a.txt","r");
	while ((read = fgetc(fop)) != EOF) {
		for (i=0; i < sizeof(letters);i++) {
			if (read != letters[i] && i==25) {
				for (j =0 ; j <sizeof(letters);j++) {
					if (letters[j]=='0'){
						letters[j] = read;
						count[j]+=1;
						found =true;
						break;
					}
					if (found ==true) {
						break;
					}
				}
			} else if (read == letters[i]){
				found =true;
				count[i]+=1;
			}
			if (found ==true) {
				found =false;
				break;
			}
		}
	}
	printf("printing the whole array:\n");
	for (i=0;i<sizeof(letters);i++) {
		printf("%i letter: %c freq: %i\n",i+1,letters[i],count[i]);
	}
	fclose(fop);
	converter(letters,count);
}