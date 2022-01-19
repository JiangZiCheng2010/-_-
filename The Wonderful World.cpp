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
			center_type("你的语言(L)",screen_width);
			set_color(9,0);
			center_type("静音(M)",screen_width);
			set_color(13,0);
			center_type("返回(B)",screen_width);
			set_color(11,0);
			while(!(if_key_down('L')||if_key_down('M')||if_key_down('B')))
				;
			play_sound;
			if(if_key_down('L'))
			{
				system("cls");
				set_color(1,0);
				center_type("请选择一个国家。",screen_width);
				repeat_put('-',screen_width);
				center_type("A.中国   B.英国   C.美国",screen_width);
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
					center_type("恒星",screen_width);
				else
				    if(square_kilometre>4e10)
						center_type("巨行星",screen_width);
					else
					    if(square_kilometre>5e8)
							center_type("行星",screen_width);
						else
						    if(square_kilometre>5e7)
								center_type("小行星",screen_width);
							else
							    if(square_kilometre>1e7)
									center_type("洲",screen_width);
								else
								    if(square_kilometre>200000)
										center_type("你的大国家",screen_width);
									else
									    if(square_kilometre>10000)
											center_type("你的小国家",screen_width);
										else
										    if(square_kilometre>900)
												center_type("自治区",screen_width);
											else
											    if(square_kilometre>600)
													center_type("省",screen_width);
												else
												    if(square_kilometre>400)
														center_type("直辖市",screen_width);
													else
													    if(square_kilometre>200)
															center_type("一线城市",screen_width);
														else
														    if(square_kilometre>120)
																center_type("二线城市",screen_width);
															else
																if(square_kilometre>60)
																	center_type("三线城市",screen_width);
																else
																    if(square_kilometre>20)
																		center_type("县",screen_width);
																	else
																	    if(square_kilometre>1)
																			center_type("美丽的小镇",screen_width);
																		else
																			center_type("小区",screen_width);
				repeat_put('-',screen_width);
				putchar('\n');
				printf("土地面积：");
			    if(square_kilometre>1e25)
					center_type("约%.15lf平方光年",square_kilometre/9.6e24);
				else
				    if(square_kilometre>3.24e15)
						center_type("约%.6lf平方光分\n",square_kilometre/3.24e14);
					else
					    if(square_kilometre>=1e13)
							printf("约%.5lf平方光秒\n",square_kilometre/9e12);
						else
							if(square_kilometre>=10)
								printf("约%.3lf平方千米\n",square_kilometre);
							else
								if(square_kilometre>=0.1)
									printf("%.2lf公顷\n",square_kilometre*100);
								else
									if(square_kilometre>=0.001)
										printf("%.1lf公亩\n",square_kilometre*10000);
									else
										printf("%.0lf平方米\n",square_kilometre*1000000);
				printf("资产：%.2lf元，约%.2lf美元\n",money,money/6.352);
				printf("钻石：%.2lf个\n",diament);
				repeat_put('-',screen_width);
				putchar('\n');
				set_color(5,0);
				center_type("开垦(1)",screen_width);
				set_color(1,0);
				center_type("采矿(2)",screen_width);
				set_color(9,0);
				center_type("打工(3)",screen_width);
				if(money>=500)
				{
					set_color(6,0);
					center_type("购买土地（500金币→500平方米）(4)",screen_width);
				}
				if(square_kilometre>=0.0015)
				{
					if(!hire)
					{
						set_color(14,0);
						center_type("租借土地(5)",screen_width);
					}
					else
					{
						set_color(8,0);
						center_type("收租(6)",screen_width);
					}
				}
				set_color(4,0);
				center_type("返回(0)",screen_width);
				set_color(15,0);
				while(!(if_key_down('1')||if_key_down('2')||if_key_down('3')||if_key_down('4')&&money>=500||if_key_down('5')&&!hire&&square_kilometre>=0.0015||if_key_down('6')&&hire&&square_kilometre>=0.0015||if_key_down('0')))
					;
				play_sound;
				if(if_key_down('1'))
				{
					if(rand()%10<7)
					{
						square_kilometre+=0.000001;
						printf("成功！");
					}
					else
						printf("失败！");
					Sleep(10);
				}
				if(if_key_down('2'))
				{
					system("cls");
					printf("采矿需要1分钟的时间，请等待……\n");
					Sleep(5000);
					printf("进入矿洞……\n");
					Sleep(5000);
					printf("正在开采……\n");
					Sleep(50000);
					if(rand()%5<4)
					{
						diament+=(rand()%50+35.0)/2000;
						printf("成功！\n");
						if(rand()%100>=96)
						{
							Sleep(100);
							set_color(13,0);
							repeat_put('-',screen_width);
							set_color(15,0);
							center_type("采矿额外发现宝箱！",screen_width);
							center_type("打开(O)",screen_width);
							while(!if_key_down('O'))
								;
							play_sound;
							set_color(13,0);
							repeat_put('-',screen_width);
							set_color(15,0);
							printf("发现");
							set_color(0,15);
							printf("2000");
							set_color(15,0);
							printf("金币！");
							money+=2000;
							Sleep(3000);
						}
					}
					else
						printf("失败！\n");
					Sleep(10);
				}
				if(if_key_down('3'))
				{
					system("cls");
					system("color F0");
					printf("打工需要半分钟的时间，请等待……\n");
					Sleep(5000);
					printf("进入工地……\n");
					Sleep(5000);
					printf("正在");
					switch(rand()%3)
					{
						case 0:
						{
							printf("搬砖");
							break;
						}
						case 1:
						{
							printf("织布");
							break;
						}
						case 2:
						{
							printf("建高楼");
							break;
						}
					}
					printf("……\n");
					Sleep(20000);
					money+=rand()%300+100;
					printf("成功！\n");
					Sleep(100);
					system("color 0F");
				}
				if(if_key_down('4'))
				{
					system("cls");
					if(rand()%20==0)
					{
						printf("获得一次还价机会！\n商人打了九折！\n");
						money-=450;
					}
					else
					{
						printf("购买成功！\n");
						money-=500;
					}
					square_kilometre+=0.0005;
					Sleep(1000);
				}
				if(if_key_down('5'))
				{
					system("cls");
					printf("已全部租借，1分钟后收租！（时间不存档！！！）\n");
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
						printf("已收租！\n");
						hire=false;
						money+=square_kilometre_before_hire*(47+rand()%10/0.003);
					}
					else
						printf("时间未到，请耐心等待~\n");
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
				center_type("奇妙的世界",screen_width);
				repeat_put('-',screen_width);
				putchar('\n');
				set_color(3,0);
				center_type("进入(O)",screen_width);
				set_color(9,0);
				center_type("设置(S)",screen_width);
				set_color(12,0);
				center_type("退出并存档(C)",screen_width);
				set_color(15,0);
				printf("\n\n\n\n\n\n\n开发者：江梓成\n\n\n\n\n");
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
