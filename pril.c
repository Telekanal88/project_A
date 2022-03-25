#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
 
#define PI 3.14159265 //число Пи  
 
//Считает количество действий для переменной k 
int count_action(char str[], char str_check[],int len){ 
	count_action(char str[], char str_check[],int len){ 
 		int k=0, i, j; 
 		for(i=0; i<len; i++){
	   		for(j=0; j<11; j++){ 
 	 	    	if (str[i]==str_check[j]) 
 	 	    		k++; 
 	 		} 
    	} 
	return k; 
	} 
 
  
//ищет позиции всех действий в строке для массива n[i] 
int position_action(char str[], char str_check[],int len, int n[]){  	
	int l=1, i, j; 
 	for(i=0; i<len; i++){  	 	
		for(j=0; j<11; j++){
	  		if (str[i]==str_check[j]){ 
 	 	    n[l]=i; 
 	 	 	l++; 
 	 	 	} 
 	 	} 
    } 
} 
  
//переводим строчные цифры в вещественные 
double convert(char s, double *A,double *B,double *C,double *D){
  	double m=0;  	
	switch(s){  	 	
		case '1':
			m=1;  	 	 	
			break;  	 	
		case '2':
			m=2;  	 	 	
			break;  	 	
		case '3':
			m=3;
			break; 
		case '4':
			m=4;  	
			break; 
		case '5':
			m=5;  	 	
			break;  	
		case '6':
			m=6;  	 	
			break; 
		case '7':
			m=7;  	 	 	
			break;  	 	
		case '8':
			m=8;  	 	 	
			break;  	 	
		case '9':
			m=9;  	 	 	
			break;  	 	
		case 'A':
			m=*A;  	 	 	
			break;  	 	
		case 'B':
			m=*B;  	 	 	
			break;  	 	
		case 'C':
			m=*C;  	 	 	
			break;  	 	
		case 'D':
			m=*D;  	 	 	
			break; 
 	} 
 	return m; 
} 
 
//Получаем число из куска строки 
double get_number(char* str, int n0, int n1,double* A,double* B,double* C,double* D){
	double G=0; char o; int h=0; double t; int S=n1; int V=0; int P=0; 
//S - переменная для поиска; V - проверка на наличие "."; P - позиция "."; 
//Смотрим, является ли число переменной A B C D или ищем в нём "." 

	while(S>n0){  	 	
		if (str[S]=='.') 
 	 		V=1;
		P=S; 
 	 	S--; 
 	} 
 	//теперь, если V=1, то число - десятичная дробь. Тогда: 
 	if (V==1){ 
 	 	S=P+1; //так как S в будущем не используется, мы можем использовать её снова  	 	while(P>n0){ 
 	 	o=str[P-1]; 
 	 	t=convert(o,A,B,C,D);
		G+=(t*pow(10,h)); 
 	 	h++;
 	 	P--; 
 	} 
	h=-1; 
	while(S<n1){ 
	 	o=str[S]; 
	 	t=convert(o,A,B,C,D); 
		G+=(t*pow(10,h));
		h--; 
	 	S++; 
	} 
	return G; 
} 
//если V=0, то число - целое. Тогда: 
if (V==0){ 
	while(n1>n0){ 
	 	o=str[n1-1]; 
 	 	t=convert(o,A,B,C,D);
		G+=(t*pow(10,h)); 
 	 	h++; 
 	 	n1=n1-1; 
 	} 
 	return G; 
} 
} 
 
//Сдвигает все элементы массивов arr и act на 1 влево 
void move_massive(double* arr, char* act, int a, int k){ 
 	//a- с какого элемента сдвигать;  	
	 int m=a; int n=a;  	
	 for(m;m<(k+1);m++) arr[m]=arr[m+1];  	
	 for(n;n<(k+1);n++) act[n]=act[n+1]; 
}  
void move_massive_brackets(double* arr, char* act, int a, int k){ 
 	//a- с какого элемента сдвигать;  	
	 int m=a+1; int n=a;  	
	 for(m;m<(k+1);m++) arr[m]=arr[m+1];  	
	 for(n;n<(k+1);n++) act[n]=act[n+1]; 
} 
 
//Совершение Калькулятором конкретного действия над переменными 
void action(double* arr,char* act,int k, int i, int j, char A){ 
 	//i - откуда считать 
 	//j - до куда считать 
 	//A - Action, производимое действие 
while (i<j){ 
 	if(act[i]==A){ 
 	 	switch(A){
		    case '+':
				arr[i+1]+=arr[i]; 
 	 	 	    move_massive(arr,act,i,k);
				break;  	 	 	 	
			case '-': arr[i+1]=arr[i]-arr[i+1]; 
 	 	 		move_massive(arr,act,i,k); 
				break;  	 	 	 	
			case '*':
				arr[i+1]=arr[i]*arr[i+1]; 
 	 	 		move_massive(arr,act,i,k); 
				break;  	 	 	 	
			case '/': if((arr[i+1]<0.0000001&&  
          		arr[i+1]>0)||(arr[i+1]==0)){ 
					printf("Can`t be devided by 0!\n"); 
 	 	 	 	} 
				arr[i+1]=arr[i]/arr[i+1];
				move_massive(arr,act,i,k);
				break;  	 	 	
			case 'l': arr[i+1]=log(arr[i+1]);  	 	
          		move_massive(arr,act,i,k); 
				break; 
			case 'o':
				arr[i+1]=cos(arr[i+1]*PI/180); 
	            move_massive(arr,act,i,k); 
				break;  	 	 	
			case 'i':
				arr[i+1]=sin(arr[i+1]*PI/180); 
	 	 		move_massive(arr,act,i,k); 
				break;  	
			case 'a': 
				arr[i+1]=tan(arr[i+1]*PI/180); 
 	 	 		move_massive(arr,act,i,k);  	 	 	 	 
				break;  	 	 	 	
			case '^': 
				arr[i+1]=pow(arr[i],arr[i+1]); 
 	 	 		move_massive(arr,act,i,k);  	 	 	 	 	
				break; 
 	 	}
	} 
 	i++;
} 
} 
 
//Совершает действия в "правильном" порядке 
void do_actions(double* arr,char* act, int k, int ni, int nj){ 
 	int i; 
 	for(i=0;i<k;i++){
	   	action(arr,act,k,ni,nj,'l');  	 	
		action(arr,act,k,ni,nj,'a');
  	 	action(arr,act,k,ni,nj,'i');  	 	
		action(arr,act,k,ni,nj,'o');  	 	
		action(arr,act,k,ni,nj,'^');  	 	
		action(arr,act,k,ni,nj,'/');  	 	
		action(arr,act,k,ni,nj,'*');  	 	
		action(arr,act,k,ni,nj,'-');  	 	
		action(arr,act,k,ni,nj,'+'); 
 	} 
} 
  
//поиск скобок (рекурсивный) 
void brackets(double* arr, char* act, int l, int k){ 
 	//l - с какого элемента ведётся поиск, изначально - 0 
 	//k - длина массива act(кол-во действий) 
 	int j=0; 
 	for(l;l<k;l++){
	   	if(act[l]=='('){
		    brackets(arr,act,l+1,k);
			move_massive(arr,act,l,k); 
 	 	 	for(j=l;j<(k+1);j++){ 
 	 	 	 	if(act[j]==')'){ 
 	 	 	 		do_actions(arr,act,k,l,j); 
 	 	 	 		move_massive_brackets(arr,act,j-1,k); 
 	 	 	 	} 
 	 	 	} 
 	 	} 
 	} 
}  
int main(){
	double A, B, C, D;
	char string[128];
	int check; 
	printf("Supported functions list:\n"); 
	printf("+ - * / sin cos tan ln ^ ()\n");
	printf("Do you want to use variables?\n");
	printf("yes - 1   no - 0\n");
	scanf("%d",&check);  	
	if (check==1){
		printf("\nSupported variables list:\n");
		printf("A B C D\n");
		printf("Enter your variables:\n");
		printf("A=");
		scanf("%lf",&A);
		printf("B=");
		scanf("%lf",&B);
		printf("C=");
		scanf("%lf",&C);
		printf("D="); 
 	 	scanf("%lf",&D); 
 	} 
 	printf("\nEnter your example: "); 
 	scanf("%s",&string); 
 	printf("\n"); 
 	//Получили строку - собираем массивы  	
	int len=0;  
    while  (string[len]!='\0') len++; //len - длина массива  	
	char action[]={'+','-','*','/','^','o','i','a','l','(',')'};  	
	int k=count_action(string,action,len);  	
	double arr[k+1];//числа в строке  	
	char act[k];//действия в строке 
 	int i;
	int n[k+2];//номера действий в строке  	
	position_action(string,action,len,n); //заполняем массив с номерами действий 
 	n[0]=0; 
 	n[k+1]=len;//последний элемент этого массива - конец строки;  	
	arr[0]=0; 
 	for(i=0;i<(k+1);i++){
	   	arr[i]=get_number(string,n[i],n[i+1],&A,&B,&C,&D); 
 	 	act[i]=string[n[i+1]]; 
 	} 
 	printf("\n");
	brackets(arr,act,0,k);
	do_actions(arr,act,k,0,k);
	printf("Result:%lf\n",arr[0]); 
 	system("pause"); 
} 
