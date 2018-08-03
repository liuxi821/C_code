#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#include<stdio.h>
#include <stdlib.h>

enum STATE
{
	END_STATE,
	NUL_STATE,
	C_STATE,
	CPP_STATE
};

void DoNulState(FILE*pfIn, FILE*pfOut, enum STATE* s);
void DoCState(FILE*pfIn, FILE*pfOut, enum STATE* s);
void DoCppState(FILE*pfIn, FILE*pfOut, enum STATE* s);



#endif //__COMMENT_CONVERT_H__
