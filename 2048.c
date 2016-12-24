/*___________________________________________________________________________
  Program :			  2048 Game
  ---------------------------------------------------------------------------

  Team    : 1. Arushi Mehta
	  : 2. Janil Malhara
	  : 3. Manasi Pandya
	  : 4. Rohit Mehta
*/

#include<stdio.h>
#include<conio.h>
//For random function
#include<stdlib.h>
#include<graphics.h>
void Random(void);
void Print(void);
void Win(void);
void GameOver(void);

int a[4][4];
int  i ,l[4][4] , q ,z, w , con = 1 , g, k, pos , pos1 , t , j , temp , choice , flag =0 ,c[4][4] , no = 0 , score = 0 , undoscore , game,r,ch,x,y,value;
char cha[20];

int main()
{

	     int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	 //Initialize blank space by 0
		clrscr();
		printf("\n");
		for (g = 0 ; g<4 ; g++)
		{
			for(k = 0; k<4 ; k++)
			{
				a[g][k] =0  ;

			}
		}
		for (g = 1 ; g<3 ; g++)    //To generate '2' at two random position
		{
			Random();
		}
		Print();
		//Not including undo option for first step
		undoscore = score;

	do
	{
		undoscore = score;
	     //To copy matrix 'a' to 'c'
	     //This will help us for undo option
	      for( i=0 ; i<4 ; i++)
	     {
			for(j=0 ; j<4 ; j++)
			{
				c[i][j] = a[i][j];
			}
	     }

	      Win();   // If 2048 generate at any position

	      GameOver(); //If their are no steps left

	     undoscore = score;
	     if(con == 1 )
	     {
		  ch = getch();
		  // 117 = ascii value of u for UNDO
		  if(ch == 117)
				choice = 5;
		  else if(ch != 65) //65 = ascii value of A for EXIT
		  {
			  ch = getch();
			  if(ch == 75) 	         //  Left
			  {
				 choice = 2;
			  }
			  if(ch == 72) 		  //  Up
			  {
				 choice = 4;
			  }
			  if(ch == 77) 		  //  Right
			  {
				  choice = 1;
			  }
			  if(ch == 80) 		   //  Down
			  {
				  choice = 3;
			  }
		   }
			else
			exit (0);                  //To exit
	    }

	if(choice == 1)
	{
		no = 0;
	      //To sort all the values to right and 0 to left
	      for( i=0 ; i<4 ; i++)
	     {
			for(q=3 ; q>=0 ; q--)
			{
				if(a[i][q]== 0)
				{
					//pos : to keep position of 0(i.e.,space)
					pos =q;
					for(w=q; w>=0 ; w--)
					{
						//pos1 : to keep position of the element
						if(a[i][w]!=0)
						{
							pos1 = w;
							//flag : To show an element is present or not with the help of 0 and 1
							flag = 1;
							break;
						}
						flag = 0;
					}
					// If element is present swap it with space(i.e., 0)
					if(flag == 1)
					{
						no = 1;
						temp = a[i][pos];
						a[i][pos] = a[i][pos1];
						a[i][pos1] = temp;
					}
				}
			}
	     }
	     for( t = 0 ; t<4 ; t++)   //To calculate
	     {
			for( i=3 ; i>0 ; i--)
			{
				if(a[t][i]!=0 )      //So that it will not sort two '0'
				{
				if(a[t][i]==a[t][i-1])
				{
					no = 1;      //This will help in generating random values
					score = score + a[t][i] + a[t][i-1];
					a[t][i] = a[t][i]+a[t][i-1];
					a[t][i-1] = 0;
					i= i-1;
				}
				}
			}
	     }

	     for( i=0 ; i<4 ; i++)   //Again sorting
	     {
			for(q=3 ; q>=0 ; q--)
			{

				if(a[i][q]== 0)
				{
					pos =q;
					for(w=q; w>=0 ; w--)
					{
						if(a[i][w]!=0)
						{
							pos1 = w;
							flag =1;
							break;
						}
						flag = 0;
					}
					if(flag == 1)
					{
						no  = 1;
						temp = a[i][pos];
						a[i][pos] = a[i][pos1];
						a[i][pos1] = temp;
					}
				}
			}
	     }

	       if(no == 1)
	       {
			Random();
	       }

	 }                                   //end of If choice == 1
	 if(choice == 2)
	{
		no = 0;
	      for( i=3 ; i>=0 ; i--)
	     {
			for(q=0 ; q<=3 ; q++)
			{
				if(a[i][q]== 0)
				{
					pos =q;
					for(w=q; w<=3 ; w++)
					{
						if(a[i][w]!=0)
						{
							pos1 = w;
							flag = 1;
							break;
						}
						flag = 0;
					}
					if(flag == 1)
					{
						no =1;
						temp = a[i][pos];
						a[i][pos] = a[i][pos1];
						a[i][pos1] = temp;
					}
				}
			}
	     }

	     for( t = 0 ; t<4 ; t++)
	     {
			for( i=0 ; i<=3 ; i++)
			{
				if(a[t][i]!=0 )
				{
				if(a[t][i]==a[t][i+1])
				{
					no  = 1;
					score = score + a[t][i] + a[t][i+1];
					a[t][i] = a[t][i]+a[t][i+1];
					a[t][i+1] = 0;
					i= i+1;
				}
				}
			}
	     }

	     for( i=3 ; i>=0 ; i--)
	     {
			for(q=0 ; q<=3 ; q++)
			{

				if(a[i][q]== 0)
				{
					pos =q;
					for(w=q; w<=3 ; w++)
					{
						if(a[i][w]!=0)
						{
							pos1 = w;
							flag =1;
							break;
						}
						flag = 0;
					}
					if(flag == 1)
					{
						no  = 1;
						temp = a[i][pos];
						a[i][pos] = a[i][pos1];
						a[i][pos1] = temp;
					}
				}
			}
	     }

	       if( no==1)
	       {
			Random();
	       }

	 }                               //end of if (choise == 2)
	 //If user want to do shift down
	if(choice == 3)
	{
		no = 0;
	      for( i=0 ; i<4 ; i++)
	     {
			for(q=3 ; q>=0 ; q--)
			{
				if(a[q][i]== 0)
				{
					pos =q;
					for(w=q; w>=0 ; w--)
					{
						if(a[w][i]!=0)
						{
							pos1 = w;
							flag = 1;
							break;
						}
						flag = 0;
					}
					if(flag == 1)
					{
						no = 1;
						temp = a[pos][i];
						a[pos][i] = a[pos1][i];
						a[pos1][i] = temp;
					}
				}
			}
	     }

	      for( t = 0 ; t<4 ; t++)
	     {
			for( i=3 ; i>=0 ; i--)
			{
				if(a[i][t]!=0)
				{
				if(a[i][t]==a[i-1][t])
				{
					no  = 1;
					score = score + a[i][t] + a[i-1][t];
					a[i][t] = a[i][t]+a[i-1][t];
					a[i-1][t] = 0;
					i= i-1;
				}
				}
			}
	     }


	     for( i=0 ; i<4 ; i++)
	     {
			for(q=3 ; q>=0 ; q--)
			{

				if(a[q][i]== 0)
				{
					pos =q;
					for(w=q; w>=0 ; w--)
					{
						if(a[w][i]!=0)
						{
							pos1 = w;
							flag =1;
							break;
						}
						flag = 0;
					}
					if(flag == 1)
					{
						no  = 1;
						temp = a[pos][i];
						a[pos][i] = a[pos1][i];
						a[pos1][i] = temp;
					}
				}
			}
	     }
	     if(no ==1)
	     {
		Random();
	     }
	 }                               //end of if (choise == 3)
	//If user want to do shift up
	if(choice == 4)
	{
		no = 0;
	      for( i=0 ; i<4 ; i++)
	     {
			for(q=0 ; q<4 ; q++)
			{
				if(a[q][i]== 0)
				{
					pos =q;
					for(w=q; w<4 ; w++)
					{
						if(a[w][i]!=0)
						{
							pos1 = w;
							flag = 1;
							break;
						}
						flag = 0;
					}
					if(flag == 1)
					{
						no = 1;
						temp = a[pos][i];
						a[pos][i] = a[pos1][i];
						a[pos1][i] = temp;
					}
				}
			}
	     }

	     for( t = 0 ; t<4 ; t++)
	     {
			for( i=0 ; i<=3 ; i++)
			{
				if(a[i][t]!=0)
				{
				if(a[i][t]==a[i+1][t])
				{
					no  = 1;
					score = score + a[i][t] + a[i+1][t];
					a[i][t] = a[i][t]+a[i+1][t];
					a[i+1][t] = 0;
					i= i+1;
				}
				}
			}
	     }

	     for( i=0 ; i<4 ; i++)
	     {
			for(q=0 ; q<4 ; q++)
			{

				if(a[q][i]== 0)
				{
					pos =q;
					for(w=q; w<4 ; w++)
					{
						if(a[w][i]!=0)
						{
							pos1 = w;
							flag =1;
							break;
						}
						flag = 0;
					}
					if(flag == 1)
					{
						no  = 1;
						temp = a[pos][i];
						a[pos][i] = a[pos1][i];
						a[pos1][i] = temp;
					}
				}
			}
	     }

	     if(no == 1)
	     {
		Random();
	     }
	 }                               //end of if (choise == 4)

	 con = 0;  //If undo not take place in earlier step
	 if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
	 {
		clrscr();
		Print();
		  ch = getch();
		  if(ch == 117)
		  choice = 5;
		  else if(ch != 65)
		  {
			  ch = getch();
			  if(ch == 75)
			  {
				  choice = 2;
			  }
			  if(ch == 72)
			  {
				  choice = 4;
			  }
			  if(ch == 77)
			  {
				  choice = 1;
			  }
			  if(ch == 80)
			  {
				  choice = 3;
			  }
		   }
		   else
			exit (0);

	 }
	 if(choice == 5)
	{
			clrscr();
			con = 1;  //If undo take place , so that it will no take input 2 time
			score = score - (score - undoscore); // To subtract score
			 for( i=0 ; i<4 ; i++)
			 {
				for(j=0 ; j<4 ; j++)
				{
					a[i][j] = c[i][j];
				}
			}
			Print();
	}

	}while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
		closegraph();
		return 0;

}



void Random(void)
{
	for(k = 1; k>0 ; k++)
	{
		i = rand()%4;
		j = rand()%4;
		if(a[i][j] == 0)
		{
			a[i][j] = 2;
			no = 0;
			break;
		}
	}
}

void Print(void)
{
	setcolor(1);
		printf("\n\n\t Score : %d",score);
		printf("\tUNDO: u\tEXIT : A");
     y = 115;
	for(i=0;i<4;i++)
	{

		x = 115;
			for( j=0 ; j<4 ;j++)
			{
				value = a[i][j];
				gotoxy(x,y);

				if(a[i][j]==0)
				cprintf("");
				else
				{
				if(a[i][j]==2)
					setcolor(0);
				if(a[i][j]==4)
					setcolor(1);
				if(a[i][j]==8)
					setcolor(2);
				if(a[i][j]==16)
					setcolor(3);
				if(a[i][j]==32)
					setcolor(4);
				if(a[i][j]==64)
					setcolor(5);
				if(a[i][j]==128)
					setcolor(6);
				if(a[i][j]==256)
					setcolor(8);
				if(a[i][j]==512)
					setcolor(9);
				if(a[i][j]==1024)
					setcolor(10);
				if(a[i][j]==2048)
					setcolor(11);
				sprintf(cha,"%d",value);
				outtextxy(x,y,cha);
				}

				x = x+60;
			}
		y =y+60;
	}
    setcolor(0);
  line(100, 100, 100, 340);
   line(160, 100, 160, 340);
   line(220, 100, 220, 340);
   line(280, 100, 280, 340);
   line(340, 100, 340, 340);

   line(100, 160, 340, 160);
   line(100, 220, 340, 220);
   line(100, 340, 340,340);
    line(100, 280, 340, 280);
   line(100, 100, 340, 100);

}

void Win(void)
{
for( i=0 ; i<4 ; i++)
	     {
			for(j=0 ; j<4 ; j++)
			{
				if(a[i][j] ==2048)
				{
					printf("\n\n\n\t\t YOU WON!!!!!!!!");
					getch();
					exit (0);
				}
			}
	     }
}

void GameOver(void)
{
	game = 0;
	     for( i=0 ; i<4 ; i++)
	     {
			for(j=0 ; j<4 ; j++)
			{
				if(a[i][j] ==0)
				{
					game = 1;
					z=1;
					break;
				}
			}
	     }
	     for( i=0 ; i<4 ; i++)
	     {
			for(j=0 ; j<4 ; j++)
			{
				l[i][j] = a[i][j];
			}
	     }
	     if(game == 0)
	     {
		z = 0;
		 for( t = 0 ; t<4 ; t++)
		     {
			for( i=3 ; i>0 ; i--)
			{
				if(l[t][i]==l[t][i-1])
				{
					z =1;
					l[t][i] = l[t][i]+l[t][i-1];
					l[t][i-1] = 0;
					i= i-1;
				}
			}
		  }

	     for( t = 0 ; t<4 ; t++)
	     {
			for( i=0 ; i<=3 ; i++)
			{
				if(l[t][i]==l[t][i+1])
				{
					z =1;
					l[t][i] = l[t][i]+l[t][i+1];
					l[t][i+1] = 0;
					i= i+1;
				}
			}
	     }

	      for( t = 0 ; t<4 ; t++)
	     {
			for( i=3 ; i>=0 ; i--)
			{
				if(l[i][t]==l[i-1][t])
				{
					z =1;
					l[i][t] = l[i][t]+l[i-1][t];
					l[i-1][t] = 0;
					i= i-1;
				}
			}
	     }

	     for( t = 0 ; t<4 ; t++)
	     {
			for( i=0 ; i<=3 ; i++)
			{
				if(a[i][t]==a[i+1][t])
				{
					z = 1;
					l[i][t] = l[i][t]+l[i+1][t];
					l[i+1][t] = 0;
					i= i+1;
				}
			}
	     }
	    }
	       if(z == 0)
	       {
		setcolor(0);
		printf(" \n\n\t\t  GAME OVER");
		getch();
		exit (0);
		}
}


