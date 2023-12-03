#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int height = 20, width = 50 , x, y , fruitx , fruity ,flag = 0 , Game_End,Score,piece,tailx[100],taily[100],ch,again=1;
void boundary();
void setup();
void input();
void logic();
struct user {
   char user[100];
   int score;
};
int main()
{   
	FILE *fptr;
    char name[100];
    int n,i;
    struct user player[n];
    struct user* ptr =0;
    printf("Enter the number of users: \n");
    scanf("%d",&n);
    ptr = (struct user*)calloc(n,sizeof(struct user));
    int d;
	printf("Enter the level of difficulty you want : \nPress :\n1 for Easy\n2 for Hard\n");
	scanf("%d",&d);
   if(d == 1)
   {
   	 for(i=0;i<n;i++)
    {
	
	printf("Enter the user Name: \n");
	scanf("%s",name);
	strcpy(player[i].user,name);
	setup();
	boundary();
	printf("Use W A S D keys\n");
	if(i>=1)
	{
		flag = 0;	
	}
    while(Game_End!=0)
    {
    input();
    logic();
	boundary();
	}
	player[i].score=Score;
	fptr = fopen("score.txt","a");
	fprintf(fptr,"Name : %s , Score = %d\n",player[i].user,player[i].score);
	Score = 0;
	fclose(fptr);
	system("cls");	
    }
	
   }
   else if(d==2)
   {
   	height = 18 , width = 24;
   	 for(i=0;i<n;i++)
	{
	printf("Enter the user Name: \n");
	scanf("%s",name);
	strcpy(player[i].user,name);
	setup();
	boundary();
	printf("Use W A S D keys");
	if(i>=1)
	{

		flag = 0;
		
	}
	
	
	    while(Game_End!=0)
    {
    input();
    logic();
	boundary();
	}
	player[i].score=Score;
	fptr = fopen("score.txt","a");
	fprintf(fptr,"Name : %s , Score = %d\n",player[i].user,player[i].score);
	Score = 0;
	fclose(fptr);
	system("cls");	
}
}
   for(i=0;i<n;i++)
	{
		printf("Name : %s Score : %d \n",player[i].user,player[i].score);
	}

	printf("Thank You!");
	return 0;	
}
void boundary()
{    
    system("cls"); //clear screen
	int i ,j ,k; 
	for(i=0 ; i<height ; i++)
	{
	for(j=0;j<width;j++)
	{
		if( i==0||j==0||i==height-1||j==width-1)
		{
		printf("#");
		}	
		else{
			if(i==x && j==y)
			{
				printf("0");
			}
			else if(i==fruitx && j==fruity)
			{
				printf("@");
			}
			else
			{
			        ch =0;
			        if(again)
					for( k =1 ;k<=piece ; k++)
					 {
                	if(i == tailx[k] && j  == taily[k])
				 	{
                    printf("o");
                    ch=1;
                	}
                	
                	}
                	if(ch!=1)
					printf(" ");	
		}
	}
}
	printf("\n");
}
}
void setup()
{
	x = height / 2 ; 
	y = width / 2 ; 
	
	label1:
	fruitx = 1 + rand() % (height-2);
	if(fruitx == 0 )
	{
		goto label1;	
	}
	
		label2:
	fruity = 1+ rand() % (width-2);
	if(fruity == 0 )
	{
		goto label2;	
	}
	Game_End=1;
	Score = 0 ;
}


void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'w' : 
			{
				flag = 1 ;
				break ; 
			}
				case 'a' : 
			{
				flag = 2 ;
				break ; 
			}
				case 's' : 
			{
				flag = 3 ;
				break ; 
			}
				case 'd' : 
			{
				flag = 4 ;
				break ; 
			}
		}
	}
	
}


void logic()
{
	int i;
	int prevx,prevy,prev2x,prev2y;
	prevx = tailx[0];
	prevy = taily[0];
	tailx[0]=x;
	taily[0]=y;
	for( i = 0 ; i <= piece ; i++) 
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i]= prevx;
		taily[i] = prevy;
		prevx = prev2x;
        prevy = prev2y;
	}
	switch(flag)
	{
	    	case 1 :
	    		
				x--;
				break;
		
			case 2 :
				y--;
				break;
			case 3 :
				x++;
				break;
			case 4 :
				y++;
				break;
	}
	
	if(x==0 || y==0 || x == height - 1|| y== width-1)
	{
	Game_End = 0;
	x = height / 2 ; 
	y = width / 2 ;
	piece = 0 ;
	again = 0;
	}
	if(x==fruitx && y == fruity)
	{   
	label3:
	fruitx = 1 + rand() % (height-2);
	if(fruitx == 0 )
	{
		goto label3;	
	}
	
	label4:
	fruity = 1 + rand() % (width-2);
	if(fruity == 0 )
	{
		goto label4;	
	}
	again++;
	piece++;
	Score++;
	}
	
}