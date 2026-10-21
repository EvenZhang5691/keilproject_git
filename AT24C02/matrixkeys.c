#include "matrixkeys.h"

unsigned int matrixkeys(void)
{
    static unsigned int last_tick = 0;
    static unsigned int stable_key = 0;
	static unsigned int candidate_key =0;
    static unsigned char key_cnt[16]={0};
	unsigned char i;
    unsigned int key = 0;
	unsigned char valid=1;

    if (sys_tick - last_tick < 5)
        return stable_key;

    last_tick = sys_tick;
    P1 = 0xFF;

    P1_3 = 0;
    if (!P1_7) key |= (1U << 0);   // S1
    if (!P1_6) key |= (1U << 4);   // S5
    if (!P1_5) key |= (1U << 8);   // S9
    if (!P1_4) key |= (1U << 12);  // S13
    P1=0xFF;

    P1_2 = 0;
    if (!P1_7) key |= (1U << 1);   // S2
    if (!P1_6) key |= (1U << 5);   // S6
    if (!P1_5) key |= (1U << 9);   // S10
    if (!P1_4) key |= (1U << 13);  // S14
    P1=0xFF;

    P1_1 = 0;
    if (!P1_7) key |= (1U << 2);   // S3
    if (!P1_6) key |= (1U << 6);   // S7
    if (!P1_5) key |= (1U << 10);  // S11
    if (!P1_4) key |= (1U << 14);  // S15
    P1=0xFF;

    P1_0 = 0;
    if (!P1_7) key |= (1U << 3);   // S4
    if (!P1_6) key |= (1U << 7);   // S8
    if (!P1_5) key |= (1U << 11);  // S12
    if (!P1_4) key |= (1U << 15);  // S16
    P1=0xFF;

	for(i=0;i<16;i++){
		if(key &(1u << i)){
			if(key_cnt[i]<5) {key_cnt[i]++; valid=0;} //Ïû¶¶
		
			else candidate_key |=(1u << i);
			
		}
		else{
			if(key_cnt[i]>0) {key_cnt[i]--; valid=0;}
				
			else candidate_key &= ~(1u << i);
		
		}
	}
	if(valid) stable_key = candidate_key;
	return stable_key;
 
 
}


unsigned int num_matrixkeys(void)
{
    static unsigned int last_tick = 0;
    static unsigned int stable_key = 0;
    static unsigned int candidate = 0;
    unsigned int key = 0;

    if ((unsigned int)(sys_tick - last_tick) < 10)
        return stable_key;

    last_tick = sys_tick;
    P1 = 0xFF;

    P1_3 = 0;
    if (!P1_7) key = 1;   // S1
    if (!P1_6) key = 5;   // S5
    if (!P1_5) key = 9;   // S9
    if (!P1_4) key = 13;  // S13
    P1_3 = 1;

    P1_2 = 0;
    if (!P1_7) key = 2;   // S2
    if (!P1_6) key = 6;   // S6
    if (!P1_5) key = 10;   // S10
    if (!P1_4) key = 14;  // S14
    P1_2 = 1;

    P1_1 = 0;
    if (!P1_7) key = 3;   // S3
    if (!P1_6) key = 7;   // S7
    if (!P1_5) key = 11;  // S11
    if (!P1_4) key = 15;  // S15
    P1_1 = 1;

    P1_0 = 0;
    if (!P1_7) key = 4;   // S4
    if (!P1_6) key = 8;   // S8
    if (!P1_5) key = 12;  // S12
    if (!P1_4) key = 16;  // S16
    P1_0 = 1;

    if (key == candidate)
        stable_key = key;
    else
        candidate = key;

    return stable_key;
}