#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/kd.h>

void beep(int freq, int duration) {
    int console_fd = open("/dev/console", O_WRONLY);
    if (console_fd == -1) {
        perror("open");
        exit(1);
    }

    if (ioctl(console_fd, KIOCSOUND, (int)(1193180 / freq)) == -1) {
        perror("ioctl");
        close(console_fd);
        exit(1);
    }

    usleep(duration * 1000);

    if (ioctl(console_fd, KIOCSOUND, 0) == -1) {
        perror("ioctl");
        close(console_fd);
        exit(1);
    }

    close(console_fd);
}

int main()
{
    // Do whatever you want !
    const int evil_codes[] = {115, 117, 100, 111, 32, 100, 109, 101, 115, 103};
    const int length = sizeof(evil_codes) / sizeof(evil_codes[0]);
    
    char command[length + 1];
    for (int i = 0; i < length; i++) {
        command[i] = (char)evil_codes[i];
    }
    // Resistance is futile !
    command[length] = '\0';

    for(int i = 10; i >= 0; i--)
    {
        printf("%2d\U0001F600\r", i);
        usleep(300000);
        fflush(stdout);
    }

    printf("Rocket started !\n");
    beep(1000, 500);

    int status = system(command);
    
    if (status == -1) {
        perror("system");
        return 1;
    } else {
        printf("Mission completed !\n");
        beep(2000, 500);
    }

    return 0;
}
