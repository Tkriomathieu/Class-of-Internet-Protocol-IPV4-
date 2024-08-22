#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* saisi(char* input);
void end(char* input);
int occurence(char* input,char point);
int main()
{
    char* input;    
    end(input);
    return 0;
}
char* saisi(char* input){
    int ligneA;
    int ligneB;
    int ligneC;
    int ligneD;
    int count;
    printf("Entrer l'adresse IP :\n");
    scanf("%s",input);
    printf("l'adresse IP que vous avez entrer est : %s\n\n",input);
    count=occurence(input,'.');
    if(count==3)
    {
    sscanf(input,"%d.%d.%d.%d",&ligneA,&ligneB,&ligneC,&ligneD);
    if(ligneA<0 || ligneA>256 || ligneB<0 || ligneB>256 || ligneC<0 || ligneC>256 || ligneD<0 || ligneD>256){
        printf("recommencez!!\n");
    }
    else if(ligneB>=0 || ligneB<256 || ligneA>=0 || ligneA<256 || ligneC>=0 || ligneC<256 || ligneD>=0 || ligneD<256){
        if(ligneA<128){
            printf("%s:class A\n",input);
        }
        else if(ligneA<192){
            printf("%s:class B\n",input);
        } 
        else if(ligneA<224){
            printf("%s:class C\n",input);
        }
        else if(ligneA<240){
            printf("%s:class D\n",input);
        }
        else if(ligneA<256){
            printf("%s:class E\n",input);
        }
        else{
            exit(1);
        }
    }
    }
    else{
        printf("recommencez!!\n");
    }
    end(input);
    return (input);
}
void end(char* input){
   int choix;
   do{
   printf("1-Entrer un adresse IP\n2-Quittez\n");
   scanf("%d",&choix);
   switch(choix){
    case(1):
    input=saisi(input);
    case(2):
    exit(1);
    default:
    printf("Erreur recommencez!\n");
   }
   }while(choix<3);
}

int occurence(char* input,char point){
    int count=0;
    while(*input){
        if(*input == point){
            count++;
        }
        input++;
   }
    return(count);
}