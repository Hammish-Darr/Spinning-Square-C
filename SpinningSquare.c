#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main() {
    printf("\x1b[2J");
    int width = 50;
    int height = 20;
    char size[width*height];
    memset(size, '.', sizeof(size));


    double Speed = 0.002;

    int rndx;
    int rndy;

    int rect1[] = {-10, 5};
    int rect2[] = {10, -5};

    double pointArr[(abs(rect1[0])+abs(rect2[0]))*(abs(rect1[1]) + abs(rect2[1]))][2];
    int count1 = 0;

    for (int ex = -abs(rect1[0]); ex<=abs(rect2[0]); ex ++){
        for (int ey = -abs(rect1[1]); ey<=abs(rect2[1]); ey ++){


            pointArr[count1][0] = ex;
            pointArr[count1][1] = ey;
            count1 ++;


        }
    }


    while(1){
        memset(size, ' ', sizeof(size));
        
        printf("\x1b[H");
        printf("\033[?25l");
        
        for(int i = 0; i<=(abs(rect1[0])+abs(rect2[0]))*(abs(rect1[1]) + abs(rect2[1])); i++){
            pointArr[i][0] = (pointArr[i][0]*cos(Speed)-pointArr[i][1]*sin(Speed));
            pointArr[i][1] = (pointArr[i][0]*sin(Speed)+pointArr[i][1]*cos(Speed));
        }


        for(int ey = -(height/2); ey<=height/2; ey++){
            for(int ex = -(width/2); ex<=width/2; ex++){

                
                for(int i = 0; i<=(abs(rect1[0])+abs(rect2[0]))*(abs(rect1[1]) + abs(rect2[1])); i++){
                    rndx = (int) round(pointArr[i][0]);
                    rndy = (int) round(pointArr[i][1]);
                    
                    if(rndx == ex && rndy == ey) {
                        size[((width*height+width)/2)+ex-(ey*width)] = '@';
                    }
                }

            }
                
        }
        for(int x = 0; x <= (sizeof(size) / (sizeof(char)))-1; x++){
            if (size[x] == ' ' || size[x] == '@'){
            putchar(size[x]);
            }
            else{
                putchar(' ');
            }

            if((x+1)%width == 0){
                putchar('\n');
            }
        }
        printf("\033[?25h");
        

    }
    return 0;
}
