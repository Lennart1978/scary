#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main()
{
    int r;
    srand(time(NULL));
    printf(ANSI_COLOR_RED);
    printf("\nReady for flashing BIOS ...\n");
    sleep(1);

    for(int i = 0; i < 100; i++)
    {       
        int color = rand() % 6; 
                
        switch(color) {
            case 0:
                printf(ANSI_COLOR_RED);
                break;
            case 1:
                printf(ANSI_COLOR_GREEN);
                break;
            case 2:
                printf(ANSI_COLOR_YELLOW);
                break;
            case 3:
                printf(ANSI_COLOR_BLUE);
                break;
            case 4:
                printf(ANSI_COLOR_MAGENTA);
                break;
            case 5:
                printf(ANSI_COLOR_CYAN);
                break;
            default:
                break;
        }
        
        for(int j = 0; j < 1000; j++)
        {
            
            if(j % 100 == 0)
                printf("\n");
            
            r = rand() % 256;
            printf("%c",r); 
            fflush(stdout);
        }
        
        printf(ANSI_COLOR_RESET);
        printf("\r");
        fflush(stdout);

        usleep(50000);
    }
    printf(ANSI_COLOR_RESET);
    printf("\n\n");
    printf("\nSuccessfully flashed BIOS with NULL ! enjoy ;-)\n");
    return 0;
}
