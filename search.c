#include<stdio.h>
#include<stdlib.h>

char filename[]="lotto.txt";
void search(int,int,int,int,int,int);
int linecount(char[]);
int counter(int,int,int,int,int,int,int);

int main(){
    int no1,no2,no3,no4,no5,no6;

    printf("Enter 6 Combination number to search: ");
    scanf("%d %d %d %d %d %d",&no1,&no2,&no3,&no4,&no5,&no6);

    search(no1,no2,no3,no4,no5,no6);

}
void search(int no1,int no2,int no3,int no4,int no5,int no6){
    FILE * finput;
    int i;
    char month[5];
    char day[5];
    char year[10];
    char id[15];
    char outlet_name[100];
    char r1[5],r2[5],r3[5],r4[5],r5[5],r6[5];
    int total6=0,total5=0,total4=0,total3=0; //for counting of winners

    finput = fopen(filename,"r");

    for (i = 0; i <= linecount(filename); i++) {

        int count=0;

        fscanf(finput, "%s %s %s %s %s %s %s %s %s", month,day,year,r1,r2,r3,r4,r5,r6); //get from files
        int a1 = atoi(r1);
        int a2 = atoi(r2);
        int a3 = atoi(r3);
        int a4 = atoi(r4);
        int a5 = atoi(r5);
        int a6 = atoi(r6);

        count +=counter(a1,no1,no2,no3,no4,no5,no6);
        count +=counter(a2,no1,no2,no3,no4,no5,no6);
        count +=counter(a3,no1,no2,no3,no4,no5,no6);
        count +=counter(a4,no1,no2,no3,no4,no5,no6);
        count +=counter(a5,no1,no2,no3,no4,no5,no6);
        count +=counter(a6,no1,no2,no3,no4,no5,no6);

        if(count==6){
            total6+=1;
        }
    }

    if (total6!=0){
        printf("\nThe combination you had search is already been picked: %d times.",total6);
    }
    else{
        printf("\nThe combination is not found.");
    }

    fclose(finput);
}
int linecount(char filename[]){
    FILE *fp;
	int count = 0; // Line counter (result)
	char c; // To store a character read from file
	fp = fopen(filename, "r");
	// Check if file exists
	if (fp == NULL)
	{
		printf("Could not open file %s", filename);
		return 0;
	}

	// Extract characters from file and store in character c
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') // Increment count if this character is newline
			count = count + 1;

	// Close the file
	fclose(fp);
return count;
}
int counter(int r1,int no1,int no2,int no3,int no4,int no5,int no6){
    int count = 0;
    if(r1 == no1|| r1 == no2 || r1 == no3 || r1 == no4 || r1 == no5 || r1==no6){
        count+=1;
    }
        return count;
}
