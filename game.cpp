#include<stdio.h>
#include<stdlib.h> // To access Randome function
#include<conio.h>

int height=20,width=20,x,y,fruitX,fruitY,flag,GameEnd,Score;
int tailX[100],tailY[100];
int piece=0;

void makelogic(){
    //this function contain all the logic of the game
    
    int i; //this portion contain logic to increase the length of the snake..
    int prevx,prevy,prev2x,prev2y;
    prevx=tailX[0];
    prevy=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    for ( i=1;i<=piece;i++)
    {
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i]=prevx;
        tailY[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;


    }
        
    //this portion contain logic to increase coordinates of the snake head..
    switch (flag)
    {
    case 1:{
        x--;
        break;
        }
    case 2:{
        x++;
        break;
        }
    case 3:{
        y--;
        break;
        }
    case 4:{
        y++;
        break;
        }
    }
    // X is the height coordinates and Y is the wodth coordinates of snake's head 
    if (x==0 || x==height || y==0 || y==width) // When snake touces the wal, it will end the game
    {
        GameEnd=1;
    }
    if(x==fruitX && y==fruitY){
        label3:
        fruitX=rand()%50;
        if(fruitX==0)
        goto label3;
    
        label4:
        fruitY=rand()%20;
        if(fruitY==0)
        goto label4;
        Score+=10;
        piece++;
    }
    
}

void input(){
    //input from keyboard
    if(kbhit()){
        switch (getch())
        {
            case 'w':{
            flag=1;
            break;
            }
            case 's':{
            flag=2;
            break;
            }
            case 'a':{
            flag=3;
            break;
            }
            case 'd':{
            flag=4;
            break;
            }
        }
    }

}
void setup(){
    //contains snake head and food
    x=height/2;
    y=width/2;

    label1:
    fruitX=rand()%20;
    if(fruitX==0)
    goto label1;
    
    label2:
    fruitY=rand()%20;
    if(fruitY==0)
    goto label2;

    GameEnd=0;
    Score++;
    piece++;


}

void draw(){
    //Box in which complete game takes place
    system("cls");
    int i,j,k,ch;
    for(i=0;i<=height;i++){
        for (j=0;j<=width;j++)
        {
            if (i==0 || i==height || j==0 || j==width)
            {
               printf("*");
            }
            else{
                if(i==x && j==y){
                    printf("0");
                }
                else if (i==fruitX && j==fruitY)
                {
                    printf("@");
                }
                else{
                    ch=0;
                    for (k=0;k<piece;k++)
                    {
                        if (i==tailX[k] && j==tailY[k])
                        {
                            printf("o");
                            ch=1;
                        }
                        
                    }
                    if(ch==0)
                    printf(" ");
                }
            }
            
        
        }
        printf("\n");
    }
    printf("Your score is: %d",Score);
    
}
int main(){
    
    setup();
    
    while(GameEnd != 1)
    {
        input();
        draw();
        makelogic();
    }

}