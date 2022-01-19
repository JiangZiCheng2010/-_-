#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#include<windows.h>
#define screen_width 168
#define if_key_down(c) ((GetAsyncKeyState(c)&0x8000)?1:0)
#define maximize ShowWindow(GetForegroundWindow(),SW_MAXIMIZE)
bool sound,hire;
SYSTEMTIME TIME;
#define play_sound if(sound)printf("%c",7);
int user_language;
/*
	0:English
	1:Chinese
	2:American
*/
FILE *fp;
double money,diament,square_kilometre,square_kilometre_before_hire;
void set_color(const int &typeface,const int &back)
{
	WORD color=((back&0x0f)<<4)+(typeface&0x0f);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void repeat_put(const char &c,const int &times)
{
	for(int i=0;i<times;++i)
		putchar(c);
}
void center_type(const char s[],const int &width)
{
	int string_long=strlen(s);
	repeat_put(32,(width-string_long)/2);
	puts(s);
}
void setup()
{
	system("cls");
	switch(user_language)
	{
		case 0:case 2:
		{
			set_color(3,0);
			center_type("Your Language(L)",screen_width);
			set_color(9,0);
			center_type("Mute(M)",screen_width);
			set_color(13,0);
			center_type("Back(B)",screen_width);
			set_color(11,0);
			while(!(if_key_down('L')||if_key_down('M')||if_key_down('B')))
				;
			play_sound;
			if(if_key_down('L'))
			{
				system("cls");
				set_color(1,0);
				center_type("Please choose a country.",screen_width);
				repeat_put('-',screen_width);
				center_type("A.the UK   B.the US   C.China",screen_width);
				while(!(if_key_down('A')||if_key_down('B')||if_key_down('C')))
					;
				play_sound;
				if(if_key_down('A'))
					user_language=0;
				if(if_key_down('B'))
					user_language=2;
				if(if_key_down('C'))
					user_language=1;
			}
			if(if_key_down('M'))
				sound=!sound;
			break;
		}
		case 1:
		{
			set_color(3,0);
			center_type("�������(L)",screen_width);
			set_color(9,0);
			center_type("����(M)",screen_width);
			set_color(13,0);
			center_type("����(B)",screen_width);
			set_color(11,0);
			while(!(if_key_down('L')||if_key_down('M')||if_key_down('B')))
				;
			play_sound;
			if(if_key_down('L'))
			{
				system("cls");
				set_color(1,0);
				center_type("��ѡ��һ�����ҡ�",screen_width);
				repeat_put('-',screen_width);
				center_type("A.�й�   B.Ӣ��   C.����",screen_width);
				while(!(if_key_down('A')||if_key_down('B')||if_key_down('C')))
					;
				play_sound;
				if(if_key_down('A'))
					user_language=1;
				if(if_key_down('B'))
					user_language=0;
				if(if_key_down('C'))
					user_language=2;
				return;
			}
			if(if_key_down('M'))
				sound=!sound;
			break;
		}
	}
}
void start_game()
{
	system("cls");
	switch(user_language)
	{
		case 0:case 2:
		{
		}
		case 1:
		{
			while(1)
			{
			    if(square_kilometre>6e12)
					center_type("����",screen_width);
				else
				    if(square_kilometre>4e10)
						center_type("������",screen_width);
					else
					    if(square_kilometre>5e8)
							center_type("����",screen_width);
						else
						    if(square_kilometre>5e7)
								center_type("С����",screen_width);
							else
							    if(square_kilometre>1e7)
									center_type("��",screen_width);
								else
								    if(square_kilometre>200000)
										center_type("��Ĵ����",screen_width);
									else
									    if(square_kilometre>10000)
											center_type("���С����",screen_width);
										else
										    if(square_kilometre>900)
												center_type("������",screen_width);
											else
											    if(square_kilometre>600)
													center_type("ʡ",screen_width);
												else
												    if(square_kilometre>400)
														center_type("ֱϽ��",screen_width);
													else
													    if(square_kilometre>200)
															center_type("һ�߳���",screen_width);
														else
														    if(square_kilometre>120)
																center_type("���߳���",screen_width);
															else
																if(square_kilometre>60)
																	center_type("���߳���",screen_width);
																else
																    if(square_kilometre>20)
																		center_type("��",screen_width);
																	else
																	    if(square_kilometre>1)
																			center_type("������С��",screen_width);
																		else
																			center_type("С��",screen_width);
				repeat_put('-',screen_width);
				putchar('\n');
				printf("���������");
			    if(square_kilometre>1e25)
					center_type("Լ%.15lfƽ������",square_kilometre/9.6e24);
				else
				    if(square_kilometre>3.24e15)
						center_type("Լ%.6lfƽ�����\n",square_kilometre/3.24e14);
					else
					    if(square_kilometre>=1e13)
							printf("Լ%.5lfƽ������\n",square_kilometre/9e12);
						else
							if(square_kilometre>=10)
								printf("Լ%.3lfƽ��ǧ��\n",square_kilometre);
							else
								if(square_kilometre>=0.1)
									printf("%.2lf����\n",square_kilometre*100);
								else
									if(square_kilometre>=0.001)
										printf("%.1lf��Ķ\n",square_kilometre*10000);
									else
										printf("%.0lfƽ����\n",square_kilometre*1000000);
				printf("�ʲ���%.2lfԪ��Լ%.2lf��Ԫ\n",money,money/6.352);
				printf("��ʯ��%.2lf��\n",diament);
				repeat_put('-',screen_width);
				putchar('\n');
				set_color(5,0);
				center_type("����(1)",screen_width);
				set_color(1,0);
				center_type("�ɿ�(2)",screen_width);
				set_color(9,0);
				center_type("��(3)",screen_width);
				if(money>=500)
				{
					set_color(6,0);
					center_type("�������أ�500��ҡ�500ƽ���ף�(4)",screen_width);
				}
				if(square_kilometre>=0.0015)
				{
					if(!hire)
					{
						set_color(14,0);
						center_type("�������(5)",screen_width);
					}
					else
					{
						set_color(8,0);
						center_type("����(6)",screen_width);
					}
				}
				set_color(4,0);
				center_type("����(0)",screen_width);
				set_color(15,0);
				while(!(if_key_down('1')||if_key_down('2')||if_key_down('3')||if_key_down('4')&&money>=500||if_key_down('5')&&!hire&&square_kilometre>=0.0015||if_key_down('6')&&hire&&square_kilometre>=0.0015||if_key_down('0')))
					;
				play_sound;
				if(if_key_down('1'))
				{
					if(rand()%10<7)
					{
						square_kilometre+=0.000001;
						printf("�ɹ���");
					}
					else
						printf("ʧ�ܣ�");
					Sleep(10);
				}
				if(if_key_down('2'))
				{
					system("cls");
					printf("�ɿ���Ҫ1���ӵ�ʱ�䣬��ȴ�����\n");
					Sleep(5000);
					printf("����󶴡���\n");
					Sleep(5000);
					printf("���ڿ��ɡ���\n");
					Sleep(50000);
					if(rand()%5<4)
					{
						diament+=(rand()%50+35.0)/2000;
						printf("�ɹ���\n");
						if(rand()%100>=96)
						{
							Sleep(100);
							set_color(13,0);
							repeat_put('-',screen_width);
							set_color(15,0);
							center_type("�ɿ���ⷢ�ֱ��䣡",screen_width);
							center_type("��(O)",screen_width);
							while(!if_key_down('O'))
								;
							play_sound;
							set_color(13,0);
							repeat_put('-',screen_width);
							set_color(15,0);
							printf("����");
							set_color(0,15);
							printf("2000");
							set_color(15,0);
							printf("��ң�");
							money+=2000;
							Sleep(3000);
						}
					}
					else
						printf("ʧ�ܣ�\n");
					Sleep(10);
				}
				if(if_key_down('3'))
				{
					system("cls");
					system("color F0");
					printf("����Ҫ����ӵ�ʱ�䣬��ȴ�����\n");
					Sleep(5000);
					printf("���빤�ء���\n");
					Sleep(5000);
					printf("����");
					switch(rand()%3)
					{
						case 0:
						{
							printf("��ש");
							break;
						}
						case 1:
						{
							printf("֯��");
							break;
						}
						case 2:
						{
							printf("����¥");
							break;
						}
					}
					printf("����\n");
					Sleep(20000);
					money+=rand()%300+100;
					printf("�ɹ���\n");
					Sleep(100);
					system("color 0F");
				}
				if(if_key_down('4'))
				{
					system("cls");
					if(rand()%20==0)
					{
						printf("���һ�λ��ۻ��ᣡ\n���˴��˾��ۣ�\n");
						money-=450;
					}
					else
					{
						printf("����ɹ���\n");
						money-=500;
					}
					square_kilometre+=0.0005;
					Sleep(1000);
				}
				if(if_key_down('5'))
				{
					system("cls");
					printf("��ȫ����裬1���Ӻ����⣡��ʱ�䲻�浵��������\n");
					GetLocalTime(&TIME);
					square_kilometre_before_hire=square_kilometre;
					hire=true;
					Sleep(1000);
				}
				if(if_key_down('6'))
				{
					system("cls");
					SYSTEMTIME TIME_temporary;
					GetLocalTime(&TIME_temporary);
					if(TIME.wYear<TIME_temporary.wYear||TIME.wMonth<TIME_temporary.wMonth||TIME.wDay<TIME_temporary.wDay||TIME.wHour<TIME_temporary.wHour||TIME.wMinute<TIME_temporary.wMinute&&TIME.wSecond<=TIME_temporary.wSecond||TIME.wMinute+1<TIME_temporary.wMinute)
					{
						printf("�����⣡\n");
						hire=false;
						money+=square_kilometre_before_hire*(47+rand()%10/0.003);
					}
					else
						printf("ʱ��δ���������ĵȴ�~\n");
					Sleep(1000);
				}
				if(if_key_down('0'))
					break;
				system("cls");
			}
			break;
		}
	}
}
int main()
{
	maximize;
	srand(time(NULL));
	{
		fp=fopen("Archive.arc","r");
		int provisional;
		fscanf(fp,"%lf%lf%lf%d%d",&money,&diament,&square_kilometre,&provisional,&user_language);
		sound=provisional;
	}
	if(square_kilometre==0)
	{
		square_kilometre=0.00005;
		sound=1;
	}
	while(1)
	{
		system("cls");
		switch(user_language)
		{
			case 0:case 2:
			{
				center_type("The Wonderful World",screen_width);
				repeat_put('-',screen_width);
				putchar('\n');
				set_color(3,0);
				center_type("Start(O)",screen_width);
				set_color(9,0);
				center_type("Setup(S)",screen_width);
				set_color(12,0);
				center_type("Close And Archive(C)",screen_width);
				set_color(15,0);
				printf("\n\n\n\n\n\n\nDevelopers:Eric Jiang\n\n\n\n\n");
				while(!(if_key_down('O')||if_key_down('S')||if_key_down('C')))
					;
				play_sound;
				if(if_key_down('C'))
				{
					fclose(fp);
					fp=fopen("Archive.arc","w");
					fprintf(fp,"%.8lf\n%lf\n%lf\n%d\n%d\n",money,diament,square_kilometre,sound,user_language);
					return 0;
				}
				if(if_key_down('S'))
					setup();
				if(if_key_down('O'))
					start_game();
				break;
			}
			case 1:
			{
				center_type("���������",screen_width);
				repeat_put('-',screen_width);
				putchar('\n');
				set_color(3,0);
				center_type("����(O)",screen_width);
				set_color(9,0);
				center_type("����(S)",screen_width);
				set_color(12,0);
				center_type("�˳����浵(C)",screen_width);
				set_color(15,0);
				printf("\n\n\n\n\n\n\n�����ߣ�������\n\n\n\n\n");
				while(!(if_key_down('O')||if_key_down('S')||if_key_down('C')))
					;
				play_sound;
				if(if_key_down('C'))
				{
					fclose(fp);
					fp=fopen("Archive.arc","w");
					fprintf(fp,"%.8lf\n%lf\n%lf\n%d\n%d\n",money,diament,square_kilometre,sound,user_language);
					return 0;
				}
				if(if_key_down('S'))
					setup();
				if(if_key_down('O'))
					start_game();
				break;
			}
		}
	}
	return 0;
}
