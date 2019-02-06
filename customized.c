#include<stdio.h>    /*Header file declaration*/
#include<string.h>   /*<string.h> for strcmp();,strlen(); functions use*/
#include<stdlib.h>
#include<time.h>

void easy(char word[])
{
		FILE* fp;
	char word2[20];
	fp=fopen("easy.txt","r");
	int counter=1;
	int num=randomno();
	printf("random no is :%d",num);
    while(!feof(fp))
    {
    	
    	if(counter<num)
    	{
    		fscanf(fp,"%s",word2);
    		strcpy(word,word2);
    		
    		counter++;
    	}else
    	{
    		
    		break;
		}
	}
}
void medium(char word[])
{

	FILE* fp;
	char word2[20];
	fp=fopen("medium.txt","r");
	int counter=1;
	int num=randomno();
	printf("random no is :%d",num);
    while(!feof(fp))
    {
    	
    	if(counter<num)
    	{
    		fscanf(fp,"%s",word2);
    		strcpy(word,word2);
    		
    		counter++;
    	}else
    	{
    		
    		break;
		}
	}
}
void hard(char word[])
{
	FILE* fp;
	char word2[20];
	fp=fopen("hard.txt","r");
	int counter=1;
	int num=randomno();
	printf("random no is :%d",num);
    while(!feof(fp))
    {
    	
    	if(counter<num)
    	{
    		fscanf(fp,"%s",word2);
    		strcpy(word,word2);
    		
    		counter++;
    	}else
    	{
    		
    		break;
		}
	}
}
int randomno()
{
	 int count,norandom;
    
    for(count = 0; count < 6; count ++)
	{
        norandom = rand()+1;
    }
    return norandom%50;
}
int doubleplayer(char namep1[],char namep2[])
{
	int nl;
	printf("you have selected the two player mode\n");
	printf("please enter the name of player 1:\n");
	scanf("%s",namep1);
	printf("please enter the name of player 2:\n");
	scanf("%s",namep2);
	do
	{
		printf("please enter the type :\n");
		printf("there are four variants to this mode\n1.easy\n2.medium\n3.hard\n4.user-supplied\n");
		scanf("%d",&nl);
	}while(nl<1&&nl>4);
		return nl;
	
}
int singleplayer(char namep1[])
{
	int nl;
	printf("please enter your name:\n");
	scanf("%s",namep1);
	printf("you have selected single player mode.\n there are three variants 
		to this mode\n1.easy\n2.medium\n3.hard");
	do
	{
		printf("\nselect your mode:");
		scanf("%d",&nl);
	}while(nl>3&&nl<1);
	return nl;
	
}
void lower_string(char s[]) 
{
   int c = 0;
 
   while (s[c] != '\0') 
   {
      if (s[c] >= 'A' && s[c] <= 'Z') 
	  {
         s[c] = s[c] + 32;
      }
      c++;
   }
}
int playarea(char hangmanword[],char pname[])
{
    char tempWord[100];       /**hangmanWord[] array for the original word and tempWord[] array to get the alphabet from user and compare it with original word**/
    char hangmanOutput[100];                    /**This array will show the remaining blanks and correct inputs**/
    int wrongTry = 6 , matchFound = 0;          /**player will get 5 chance, so we use wrongTry as chance counter**/
                                                /**matchFound to search the alphabet, if the alphabet from user does not exist
                                                in the original word it will remain 0, upon finding the word, matchFound will
                                                be set as 1**/
     char alphabetFromUser;
    int counter = 0 , position = 0, winner, length , i;
    length = strlen(hangmanword);               /**get the length of the word**/
    printf("welcome %s",pname);
    printf("\n\n You will get 5 chances to guess the right word");
    printf("\n\n So help the Man and get...set...GO..!!");
    getchar();

    printf("\n\t||===== ");                 /**show the HANGMAN**/
	printf("\n\t||    | ");
    printf("\n\t||      ");
    printf("\n\t||      ");
    printf("\n\t||      ");
    printf("\n\t||      ");

    printf("\n\n     The word has %d alphabets \n\n",length); 
	getch(); /**tell the user how many alphabets the word has**/
    for( i = 0; i < length ; i++)
    {
        hangmanOutput[i] = '_';
        hangmanOutput[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);        /**Show the Word With n(length of the original word) number of underscores (_)**/
    }
    while(wrongTry != 0)                        /**while loop for exiting the program when no try left**/
    {
    	getch();
        matchFound = 0;
        printf("\n\n   enter any alphabet from a to z and please use small case!!");//AUTOMATIC UPPER CASE CONVERTER
        printf("\n\n\t Enter HERE ==> ");

	    fflush(stdin);//NEW FUNCTION

	    scanf("%c",&alphabetFromUser);            /**get alphabet from user**/
    if(alphabetFromUser < 'a' || alphabetFromUser > 'z') /**In case player gives input other than 'a' to 'z' the console will ask again**/
    {
        system("cls");
        printf("\n\n\t Wrong input TRY AGAIN ");
        matchFound = 2;
    }
    
  //  fflush(stdin);
    if (matchFound != 2)
    {
        for(counter=0;counter<length;counter++)    /**for loop to check whether player input alphabet exists or not in the word**/
	    {
		    if(alphabetFromUser==hangmanword[counter])
		     {
		       matchFound = 1;
                     }//end of if()
            }//end of for()

	   if(matchFound == 0)                      /**in case of wrong guess**/
	    {
     	      printf("\n\t :( You have %d tries left ",--wrongTry);
	          showhangman(wrongTry);
        }//end of if()

	   else
	   {
	     for(counter = 0; counter < length; counter++)
             {
     	         matchFound = 0;
                 if(alphabetFromUser == hangmanword[counter])
	          {
     		     position = counter ;
     		     matchFound = 1;
	          }//end of if
    	      if(matchFound == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == position)
                  	  {
                          hangmanOutput[i] = alphabetFromUser; /**Put the alphabet at right position**/
                      }
                      else if( hangmanOutput[i] >= 'a' && hangmanOutput[i] <= 'z' ) /** If the position already occupied
                                                                                  by same alphabet then no need to
                                                                                  fill again EASY!! and continue */
                      {
                          continue;
                  	  }

                      else
                      {
                          hangmanOutput[i] = '_';            /** Put a blank at not guessed alphabet position **/
                      }
                }
                tempWord[position] = alphabetFromUser;      /**put the alphabet in another char array to check with the original word**/
                tempWord[length] = '\0';                    /**put the NULL character at the end of the temp string**/
                winner = strcmp(tempWord,hangmanword);      /**upon True comparison it will return 0**/

                if(winner == 0)                             /**if the player guessed the whole word right then he/she is the WINNER**/
                {
                	
                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                    printf("\n\n\t The Word was %s ",hangmanword);
                    printf("\n\n\n\n\t\tEASY HUH???\n\n");
                    getchar();
                    
                    return 1;
                }//end of inner if
	       }//end of outer if
	    }//end of for loop
      }//end of else
     }// end of if(matchFound != 2) condition

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",hangmanOutput[i]);                /**Show the original Word With blanks and right Input alphabet**/
      }

    getchar();
    }//end of while loop

      if(wrongTry <= 0)                                 /**if the player can not guess the whole word in 5 chaces**/
      {
          printf("\n\n\t The Word was %s ",hangmanword);
          printf("\n\n\t The man is dead you IDIOT!!!!!");
	      printf("\n\n\t Better luck next!!!");
	      getch();
		  return 0;
      }
}
void showhangman(int choice)                            /**This function show the hangman after each wrong try**/
 {

     switch(choice)
     {

     case 0:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	break;
     case 1:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
     case 2:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 3:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 4:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 5:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
      }//end of switch-case
      return;
 }
void main()
{
	srand(time(NULL));
	char namep1[20],namep2[20];
    char wordp1[100],wordp2[100];  
    int counterp1,counterp2;
	int np,nl,temp;//keeps the track of which mode the user has selected.
    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");   /**Brief description of the game**/
	do
	{
		printf("please select a mode:\n1. one player\n2. two player mode\n");
		scanf("%d",&np);
		
	
		if(np==1)
			nl=singleplayer(namep1);	
		else if (np==2)
			nl=doubleplayer(namep1,namep2);				
	}while(np!=1&&np!=2);
	printf("all words will automatically be in LOWER CASE!");
	getch();
	printf("player details\n");
	if(np==1)
		printf("player name: %s\n",namep1);
	else
	{	
		printf("player 1:%s\n",namep1);
		printf("player 2:%s\n",namep2);
	}
	getch();
	system("cls");                              /**for clearing the screen**/
    
	switch(np)
	{
		case 1:
				
				if(nl==1)
				easy(wordp1);
				else if(nl==2)
				medium(wordp1);
				else 
				hard(wordp1);
				
				counterp1=playarea(wordp1,namep1);
				if(counterp1==1)
				{
					printf("congrats %s for winning the game!",namep1);
				}
				break;
		case 2:
				
				if(nl==1)
				{
					easy(wordp1);
					easy(wordp2);
				}
				else if(nl==2)
				{
					medium(wordp1);
					medium(wordp2);
				}
				else if(nl==3)
				{
					hard(wordp1);
					hard(wordp2);
				}
				else 
				{
					printf("player 1:\tplease enter a word for player 2 and ensure that player 2 is not peeking:\n");
					scanf("%s",wordp2);
					printf("player 2:\tplease enter a word for player 1 and ensure that player 1 is not peeking:\n");
					scanf("%s",wordp1);
				}
				lower_string(wordp1);
				lower_string(wordp2);
				printf("\n\n\nplayer 1's  turn!");
				counterp1=playarea(wordp1,namep1);
				printf("\n\n\nplayer 2's turn!");
				counterp2=playarea(wordp2,namep2);
  				if(counterp1==1&&counterp2==1)
  					printf("\ncongrats %s and %s. you both have won against each other",namep1,namep2);
  				else if(counterp1==1&&counterp2==0)
  					printf("\ncongrats %s. you won against %s.\n Better luck next time %s",namep1,namep2,namep2);
   				else if(counterp1==0&&counterp2==1)
  					printf("\ncongrats %s. you won against %s.\n Better luck next time %s",namep2,namep1,namep1);
  				else
  					printf("\nbetter luck next time %s and %s. you both lose!!!",namep1,namep2);
				  break;
	}
}