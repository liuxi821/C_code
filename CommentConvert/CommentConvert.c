#define _CRT_SECURE_NO_WARNINGS 1
#include"CommentConvert.h"

void DoNulState(FILE*pfIn, FILE*pfOut, enum STATE* s)
{
	int first = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case'/':
	{
			   int second = fgetc(pfIn);
			   switch (second)
			   {
			   case'/'://  '//'为C++状态，直接输出
			   {
						   
						   fputc(first, pfOut);
						   fputc(second, pfOut);
						   *s = CPP_STATE;
			   }
				   break;
			   case'*':
			   {
						  
						  fputc(first, pfOut);
						  fputc('/', pfOut);  //把'/*'转换为'//',C状态 需转换
						  *s = C_STATE;
			   }
				   break;
			   default:
				   fputc(first, pfOut);
				   fputc(second, pfOut);
				   break;
			   }
	}
		break;
	case EOF:
		//fputc(first, pfOut);
		*s = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}
void DoCState(FILE*pfIn, FILE*pfOut, enum STATE* s)
{
	int first = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case'*':
	{
			   int second = fgetc(pfIn);
			   switch (second)
			   {
			   case'/':
			   {
						  int third = fgetc(pfIn);
						  if (third == '\n')
						  {
							  fputc(third, pfOut);
						  }
						  else
						  {
							  fputc('\n', pfOut);
							  ungetc(third, pfIn);//   遇到'*/'时 与前面的‘/*’作用注释其中的内容，
							   // 而如果'*/'后不是‘\n’则需要加上换行
						  }
						  *s = NUL_STATE;
			   }
				   break;
			   case '*':
			   {
						   //int third = getc(pfIn);
						   fputc(first, pfOut);  //fputc ： 送一个字符到一个流中
						   ungetc(second, pfIn);//ungetc： 把一个字符退回到输入流中
			   }                                 //防止多个'*'连用时'*/'中的*被提前读取
				   break;
			   default:
				   fputc(first, pfOut);
				   fputc(second, pfOut);
				   break;
			   }
	}
		break;
	case '\n':
	{
				 fputc(first, pfOut);
				 fputc('/', pfOut);
				 fputc('/', pfOut);
	}
		break;
	case EOF:
		*s = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}
void DoCppState(FILE*pfIn, FILE*pfOut, enum STATE* s)
{
	int first = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case'\n':
	{
				fputc(first, pfOut);
				*s = NUL_STATE;
	}
		break;
	case EOF:
		*s = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}
