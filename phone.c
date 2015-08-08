/*
 *
 * Author: RN Alex
 * Example : REC121
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LETTERS (4+1)
#define MAX_KEYS 12

#define KEYID_HASH 10
#define KEYID_STAR 11

typedef struct phone_entry {
	int keyid;
	int active_symbols;
	char symbols[MAX_LETTERS];
}phone_entry;

phone_entry phone[MAX_KEYS]={
	{0,1,{'0'}},
	{1,3,{'.',',','@'}},
	{2,3,{'A','B','C'}},
	{3,3,{'D','E','F'}},
	{4,3,{'G','H','I'}},
	{5,3,{'J','K','L'}},
	{6,3,{'M','N','O'}},
	{7,3,{'P','Q','S'}},
	{8,3,{'T','U','V'}},
	{9,4,{'W','X','Y','Z'}},
	{KEYID_HASH,1,{'#',}},
	{KEYID_STAR,1,{'*',}}};


typedef phone_entry ** key_selection;


void
swap(char *src , char *dst)
{
	char temp;
	temp = *src;
	*src = *dst;
	*dst = temp;
}

void
prepare_selected_keys(char *phone_number, int len, key_selection ks)
{
	int i=0;
	phone_entry *pe = NULL;
	int num;
	assert(phone_number && ks);
	for(i=0;i< len;++i) {
		pe = (phone_entry *)malloc(sizeof(*pe));
		assert(pe);
		switch (phone_number[i]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': num = phone_number[i]-'0';
				  *pe = phone[num];
				  break;
			case '#': num = KEYID_HASH;
				  *pe = phone[num];
				  break;
			case '*': num = KEYID_STAR;
				  *pe = phone[num];
				  break;
			default: 
				  pe->active_symbols = 1;
				  pe->symbols[0]=phone_number[i];

		}
		ks[i]=pe;
	}
}

void
show_digits(phone_entry **pphone, int pl , int pr)
{
	int i;
	printf("\n");
	for(i=0;i<= pr;++i) {
		if(pphone[i]!=NULL){
			printf("%c",pphone[i]->symbols[0]);
		}
	}
}
void
gen_possible_symbols_from_keys(phone_entry **pphone, int pl, int pr)
{
	if (pl > pr ) return;

	if (pphone[pl]!=NULL) {
		int l,r,j;
		l = 0;
		r = pphone[pl]->active_symbols-1;
		for (j=l;j<=r;++j) {
			swap(&pphone[pl]->symbols[l],&pphone[pl]->symbols[j]);                        
			if ((pl+1 <= pr) && pphone[pl+1]!=NULL)gen_possible_symbols_from_keys(pphone,pl+1,pr);
			if (pl == pr) {
				show_digits(pphone,pl,pr);
			}
			swap(&pphone[pl]->symbols[l],&pphone[pl]->symbols[j]);                        

		}

	}
}

int
main(int argc , char **argv)
{
	char sample_phone_number[]="655-654-653";
	phone_entry *selected_keys[MAX_KEYS];
	prepare_selected_keys(sample_phone_number,sizeof(sample_phone_number)-1,selected_keys);
	gen_possible_symbols_from_keys(selected_keys,0,sizeof(sample_phone_number)-2);

}
