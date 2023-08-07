/*
 * main.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Esraa sherif
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include <util/delay.h>
#define F_CPU		8000000UL
void smile(void);
void openEye(void);
void halfOpenEye(void);
void closeEye(void);
void blink(void);
void openMouth(void);
void halfOpenMouth(void);
void closeMoth(void);
void talk(void);
void talks(void);
u8 face1[] = {
		0b11111,
		0b10000,
		0b10000,
		0b10000,
		0b10000,
		0b10011,
		0b10011,
		0b10011
};
u8 face2[] = {
		0b11111,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000
};
u8 face3[] = {
		0b11111,
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b11001,
		0b11001,
		0b11001
};
u8 face4[] = {
		0b10000,
		0b10000,
		0b10010,
		0b10001,
		0b10000,
		0b10000,
		0b10000,
		0b11111
};
u8 face5[] = {
		0b00000,
		0b00000,
		0b00000,
		0b11111,
		0b00000,
		0b00000,
		0b00000,
		0b11111
};
u8 face6[] = {
		0b00001,
		0b00001,
		0b01001,
		0b10001,
		0b00001,
		0b00001,
		0b00001,
		0b11111
};

u8 eyecloseL[]={
		0b11111,
		0b10000,
		0b10000,
		0b10000,
		0b10000,
		0b10000,
		0b10000,
		0b10011

};
u8 eyecloseR[]={
		0b11111,
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b11001


};

u8 eyehalfL[]={
		0b11111,
		0b10000,
		0b10000,
		0b10000,
		0b10000,
		0b10000,
		0b10011,
		0b10011

};
u8 eyehalfR[]={
		0b11111,
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b11001,
		0b11001


};
u8 D1[] = {
		0b10000,
		0b10000,
		0b10011,
		0b10001,
		0b10000,
		0b10000,
		0b10000,
		0b11111
};
u8 D2[] = {
		0b00000,
		0b00000,
		0b11111,
		0b00000,
		0b11111,
		0b00000,
		0b00000,
		0b11111
};
u8 D3[] = {
		0b00001,
		0b00001,
		0b11001,
		0b10001,
		0b00001,
		0b00001,
		0b00001,
		0b11111
};
u8 c1[] = {
		0b10000,
		0b10000,
		0b10000,
		0b10001,
		0b10000,
		0b10000,
		0b10000,
		0b11111
};
u8 c2[] = {
		0b00000,
		0b00000,
		0b00000,
		0b11111,
		0b00000,
		0b00000,
		0b00000,
		0b11111
};
u8 c3[] = {
		0b00001,
		0b00001,
		0b00001,
		0b10001,
		0b00001,
		0b00001,
		0b00001,
		0b11111
};
u8 tri1[8] = {
		0b00000,
		0b10000,
		0b11000,
		0b11100,
		0b11110,
		0b11111,
		0b00000,
		0b00000
};
u8 tri2[8] = {
		0b00000,
		0b00001,
		0b00011,
		0b00111,
		0b01111,
		0b11111,
		0b00000,
		0b00000
};
u8 sq[8] = {
		0b11111,
		0b11111,
		0b11111,
		0b11111,
		0b00000,
		0b00000,
		0b00000,
		0b00000
};
int main(void)
{
	CLCD_voidInit();

	smile();
	_delay_us(200);
	talks();
	_delay_us(200);

	CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_5);
	CLCD_voidSendString((u8*)"Hello space ");
	CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_5);
	CLCD_voidSendString((u8*)"visitor ! ");
	_delay_ms(500);
	smile();
	int f=0;
	while(1){
		smile();
		blink();
		_delay_us(200);
		talk();
		_delay_us(200);
		if(f==0){
			CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_5);
			CLCD_voidSendString((u8*)"Welcome to  ");
			CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_5);
			CLCD_voidSendString((u8*)"FlatLand !");

			_delay_ms(1500);
			CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
			++f;
		}else if(f==1){
			CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_5);
			CLCD_voidSendString((u8*)"You can meet");
			CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_5);
			CLCD_voidSendString((u8*)"all 2D shape");
			_delay_ms(1500);
			CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
			++f;
		}else if(f==2){
			CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_5);
			CLCD_voidSendString((u8*)"Triangle ");
			CLCD_voidSendExtraChar(6 , tri1 , CLCD_ROW_2 , CLCD_COL_10);
			CLCD_voidSendExtraChar(7 , tri2 , CLCD_ROW_2 , CLCD_COL_9);
			_delay_ms(1500);
			CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
			++f;
		}else if(f==3){
			CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_5);
			CLCD_voidSendString((u8*)"Square,like");
			CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_5);
			CLCD_voidSendString((u8*)"me!");
			CLCD_voidSendExtraChar(6 , sq, CLCD_ROW_2 , CLCD_COL_13);
			_delay_ms(1500);
			CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
			++f;
		}else if(f==4){
			CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_5);
			CLCD_voidSendString((u8*)"And so on ! ");
			_delay_ms(1500);
			CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
			++f;}else if(f==5){
				CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_5);
				CLCD_voidSendString((u8*)"Enjoy your ");
				CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_5);
				CLCD_voidSendString((u8*)"time, bye!");
				_delay_ms(1500);
				CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
				++f;}else if(f==6){
					smile();
					for(u8 i = 1 ; i <=16 ; i++)
					{
						CLCD_voidSendExtraChar(1 , face6, CLCD_ROW_2 , 2+i);
						CLCD_voidSendExtraChar(2 , face3, CLCD_ROW_1 , 2+i);
						_delay_us(1000);
						CLCD_voidSendExtraChar(3 , face5 , CLCD_ROW_2 , 1i);
						CLCD_voidSendExtraChar(4 , face2 , CLCD_ROW_1 , 1+i);
						_delay_us(1000);
						CLCD_voidSendExtraChar(5 , face1 , CLCD_ROW_1 , i);
						CLCD_voidSendExtraChar(6 , face4 , CLCD_ROW_2 , i);
						_delay_us(1000);


						CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
						++f;}
					CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
					break;
				}

		smile();
		blink();
		_delay_us(1000);


	}

while(1);
	return 0 ;
}

void smile(void){
	CLCD_voidSendExtraChar(0 , face1 , CLCD_ROW_1 , CLCD_COL_1);
	CLCD_voidSendExtraChar(1 , face2 , CLCD_ROW_1 , CLCD_COL_2);
	CLCD_voidSendExtraChar(2 , face3 , CLCD_ROW_1 , CLCD_COL_3);

	CLCD_voidSendExtraChar(3 , face4 , CLCD_ROW_2 , CLCD_COL_1);
	CLCD_voidSendExtraChar(4 , face5 , CLCD_ROW_2 , CLCD_COL_2);
	CLCD_voidSendExtraChar(5 , face6 , CLCD_ROW_2 , CLCD_COL_3);}
void openEye(void){
	CLCD_voidSendExtraChar(0 , face1 , CLCD_ROW_1 , CLCD_COL_1);
	CLCD_voidSendExtraChar(1 , face2 , CLCD_ROW_1 , CLCD_COL_2);
	CLCD_voidSendExtraChar(2 , face3 , CLCD_ROW_1 , CLCD_COL_3);
}
void blink(void){
	openEye();
	_delay_ms(1000);
	halfOpenEye();
	_delay_ms(150);
	closeEye();
	_delay_ms(100);
	halfOpenEye();
	_delay_ms(150);
}
void closeEye(void){
	CLCD_voidSendExtraChar(0 , eyecloseL , CLCD_ROW_1 , CLCD_COL_1);
	CLCD_voidSendExtraChar(1 , face2 , CLCD_ROW_1 , CLCD_COL_2);
	CLCD_voidSendExtraChar(2 , eyecloseR , CLCD_ROW_1 , CLCD_COL_3);

}
void halfOpenEye(void){
	CLCD_voidSendExtraChar(0 , eyehalfL , CLCD_ROW_1 , CLCD_COL_1);
	CLCD_voidSendExtraChar(1 , face2 , CLCD_ROW_1 , CLCD_COL_2);
	CLCD_voidSendExtraChar(2 , eyehalfR , CLCD_ROW_1 , CLCD_COL_3);

}
void openMouth(void){
	CLCD_voidSendExtraChar(3 , D1 , CLCD_ROW_2 , CLCD_COL_1);
	CLCD_voidSendExtraChar(4 , D2 , CLCD_ROW_2 , CLCD_COL_2);
	CLCD_voidSendExtraChar(5 , D3, CLCD_ROW_2 , CLCD_COL_3);
}
void halfOpenMouth(void){
	CLCD_voidSendExtraChar(3 , face4 , CLCD_ROW_2 , CLCD_COL_1);
	CLCD_voidSendExtraChar(4 , face5 , CLCD_ROW_2 , CLCD_COL_2);
	CLCD_voidSendExtraChar(5 , face6 , CLCD_ROW_2 , CLCD_COL_3);
}
void closeMoth(void){
	CLCD_voidSendExtraChar(3 , c1 , CLCD_ROW_2 , CLCD_COL_1);
	CLCD_voidSendExtraChar(4 , c2 , CLCD_ROW_2 , CLCD_COL_2);
	CLCD_voidSendExtraChar(5 , c3, CLCD_ROW_2 , CLCD_COL_3);}
void talks(void){
	closeMoth();
	_delay_ms(500);
	halfOpenMouth();
	_delay_ms(1000);
	openMouth();
	_delay_ms(1000);
}
void talk(void){
	halfOpenMouth();
	_delay_ms(150);
	openMouth();
	_delay_ms(200);
}
