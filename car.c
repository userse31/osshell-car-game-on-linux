#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resources.h"

//Someone should speedrun this. Hey, maybe you'll even get Dream's level of luck!

#define CLS printf("c");
#define PAUSE printf("Press any key to continue.\n");fflush(stdout);system("read -n 1");

char DO_LEFT_TURN_BUG=0;
char DO_CURE_BLINDNESS=0;
char LEFT_DEPAD=0;

char buffer=0;

char get_keycode(){
	while(1){
		buffer=getchar();
		if(buffer=='s'||buffer=='d'||buffer=='f'){
			return buffer;
		}
	}
}

char anim_center(){
	if(LEFT_DEPAD){
		printf("s is left d is animation f is right\n");
		PAUSE
	}
	printf(CAR_ANIM_CENTER);
	sleep(2);
	CLS
	printf(CAR_ANIM_INBETWEEN);
	sleep(2);
	CLS
	printf(CAR_ANIM_CENTER);
	sleep(2);
	CLS
	printf(CAR_ANIM_INBETWEEN);
	printf("s,d or f\n");
	return get_keycode();
}

char anim_left(){
	CLS
	printf(CAR_ANIM_DRIVE_LEFT);
	sleep(2);
	CLS
	printf(CAR_ANIM_INBETWEEN);
	sleep(2);
	CLS
	printf(CAR_ANIM_DRIVE_LEFT);
	sleep(2);
	CLS
	printf(CAR_ANIM_INBETWEEN);
	printf("s,d or f\n");
	if(DO_LEFT_TURN_BUG){
		get_keycode();
		return 'd';
	}else{
		return get_keycode();
	}
}

char anim_right(){
	CLS
	printf(CAR_ANIM_DRIVE_RIGHT);
	sleep(2);
	CLS
	printf(CAR_ANIM_INBETWEEN);
	sleep(2);
	CLS
	printf(CAR_ANIM_DRIVE_RIGHT);
	sleep(2);
	CLS
	printf(CAR_ANIM_INBETWEEN);
	printf("s,d or f\n");
	return get_keycode();
}

int main(int argc, char *argv[]){
	if(argc>1){
		for(int i=0;i<argc;i++){
			if(!strcmp(argv[i],"--help")){
				printf("Port of the car 'game' from osshell.\nUsage: ./car (options)\n--do-cure-blindness: Enable the colors from the original. (NOT RECOMMENDED)\n--do-left-turn-bug: Enable the bug from the original where the car always centers after turning left.\n--left-depad: Enable the constant printing of 's is left d is animation...' like the original.\n");
				exit(0);
			}
			if(!strcmp(argv[i],"--do-cure-blindness")){
				DO_CURE_BLINDNESS=1;
			}
			if(!strcmp(argv[i],"--do-left-turn-bug")){
				DO_LEFT_TURN_BUG=1;
			}
			if(!strcmp(argv[i],"--left-depad")){
				LEFT_DEPAD=1;
			}
		}
	}
	printf("c");
	if(DO_CURE_BLINDNESS){
		printf(FOREGROUND);
		printf(BACKGROUND);
	}
	fflush(stdout);
	PAUSE
	if(!LEFT_DEPAD){
		printf("s is left d is animation f is right\n");
		PAUSE
	}
	char keycode=anim_center();
	while(1){
		//printf("\n~%c~\n",keycode);
		fflush(stdin);
		switch(keycode){
			case 'd':
				keycode=anim_center();
				break;
			case 's':
				keycode=anim_left();
				break;
			case 'f':
				keycode=anim_right();
				break;
			default:
				printf("FUCK\n");
				printf("\n~%c~\n");
			}		
	}
	/*printf(CAR_ANIM_INBETWEEN);
	printf(CAR_ANIM_CENTER);
	printf(CAR_ANIM_DRIVE_LEFT);
	printf(CAR_ANIM_DRIVE_RIGHT);*/
}
