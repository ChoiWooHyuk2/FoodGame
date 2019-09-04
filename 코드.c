//헤더파일
#include <stdio.h>
#include<Windows.h>
#include <string.h>
//선언
#define MENU_X 15
#define MENU_Y 30
#define Up 0
#define Down 1
#define Submit 2
//움직임확인
int KeyControler() {
	char InputKey = getch();



	
    if (InputKey == 72|| InputKey == 'W'|| InputKey == 'w') {
		return Up;
	}
	else 	if (InputKey == 80 || InputKey == 's'|| InputKey == 'S') {
		return Down;
	}
	else 	if (InputKey == 13) {
		return Submit;
	}
}
//메뉴창
int Menu() {

	int menu[MENU_X][MENU_Y] =
	{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,3,3,3,2,2,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,2,2,3,2,2,2,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,2,5,2,2,5,5,5,2,2,5,2,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,1,5,5,5,5,5,5,5,5,5,1,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,4,4,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},




	};
	
	for (int i = 0; i < MENU_X; i++) {
		for (int j = 0; j < MENU_Y; j++) {
			switch (menu[i][j])
			{
			case 0:printf("  "); break;
			case 1:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); printf("■"); break;
			case 2:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); printf("■"); break;
			case 3:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); printf("■"); break;
			case 4:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); printf("■"); break;
			case 5:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); printf("■"); break;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		}
		
		
		
		puts("");

	}
}//시작메뉴
//gotoxy
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
//시작버튼
int Start() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	int x = 15;
	int y = 17;

	gotoxy(x - 2, y);
	printf("> 요 리 게 임 하 기");
	gotoxy(x + 1, y+ 1);
	printf("제 작 자  정 보");
	gotoxy(x, y +2);
	printf("      종 료     ");
	while (1) {
		int n = KeyControler();
		switch (n) {
		case Up: if (y > 17) {
			gotoxy(x - 2, y);
			printf(" ");
			gotoxy(x - 2, --y);
			printf(">");
		}
				 break;
		case Down: if (y < 19) {
			gotoxy(x - 2, y);
			printf(" ");
			gotoxy(x - 2, ++y);
			printf(">");
		}
				 break;
		case Submit: {

			return y - 17;

		}
		}
		
	
	}
}
//정보화면
void infoDraw() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	system("cls");
	printf("\n\n");
	printf("                            \n");
	printf("      ♥사랑해요 정현쌤♥   \n");
	printf("                            \n");
	printf("         프밍프로젝트       \n");
	printf("                            \n");
	printf("        개발자:최우혁       \n");
	printf("                            \n");

	while (1) {
		if (KeyControler() == Submit) {
		
			break;
		}
	}
}
//게임
void cooking() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	char cookInput[30];
	
	system("cls");
	printf("■■■■■■■■■■■\n");
	printf("■     요리하기     ■\n");
	printf("■■■■■■■■■■■\n");
	printf("■     시작/취소    ■\n");
	printf("■■■■■■■■■■■\n");
	printf("입력 :");
	while (1) 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	
		gets(cookInput);
		
			if (strcmp(cookInput,"시작") == 0 || strcmp(cookInput, "시작 ") == 0) {
		
					levelone();
				
			}
			else if (strcmp(cookInput,"취소") == 0 || strcmp(cookInput, "취소 ") == 0) {
				system("cls");
				
				main();
				return 0;
			
			}
			else {
				printf("다시입력하세요");
				continue;
			}
		
	
	}
	
}	       
//level1
int levelone() {
	char foodInput[100];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	system("cls");
	printf("■■■■■■■■■■■■■■\n");
	printf("■미션:샌드위치를 만들어라■\n");
	printf("■■■■■■■■■■■■■■\n");
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("■■■■■■■■■■■■■■\n");
	printf("■        재료공개        ■\n");
	printf("■■■■■■■■■■■■■■\n");
	printf("■      옆으로 썰은 햄    ■\n");
	printf("■------------------------■\n");
	printf("■      먹다 남은 치즈    ■\n");
	printf("■------------------------■\n");
	printf("■      씽씽한 양상추     ■\n");
	printf("■■■■■■■■■■■■■■\n");
	
	Sleep(2500);
	system("cls");
	printf("■■■■■■■■■■■■■■\n");
	printf("■ 첫번째 재료 입력하기   ■\n");
	printf("■                        ■\n");
	printf("■■■■■■■■■■■■■■\n");
	gotoxy(3, 2);
	gets(foodInput);
	if (strcmp(foodInput, "옆으로 썰은 햄") == 0 || strcmp(foodInput, "옆으로 썰은 햄 ") == 0) {
		system("cls");
		printf("■■■■■■■■■■■■■■\n");
		printf("■ 두번째 재료 입력하기   ■\n");
		printf("■                        ■\n");
		printf("■■■■■■■■■■■■■■\n");
		gotoxy(3, 2);
		gets(foodInput);

		if (strcmp(foodInput, "먹다 남은 치즈") == 0 || strcmp(foodInput, "먹다 남은 치즈 ") == 0) {
			system("cls");
			printf("■■■■■■■■■■■■■■\n");
			printf("■ 세번째 재료 입력하기   ■\n");
			printf("■                        ■\n");
			printf("■■■■■■■■■■■■■■\n");
			gotoxy(3, 2);
			gets(foodInput);
			if (strcmp(foodInput, "씽씽한 양상추") == 0 || strcmp(foodInput, "씽씽한 양상추 ") == 0) {
				system("cls");
				printf("■■■■■■■■■■■■■■\n");
				printf("■       정답입니다!      ■\n");
				printf("■                        ■\n");
				printf("■■■■■■■■■■■■■■\n");
				Sleep(2000);
			
				leveltwo();
			}
			else {
				gotoxy(3, 6);
				printf("실패하셨습니다.");
				Sleep(500);
				cooking();
			}
		}
		else {
			gotoxy(3, 6); 
			printf("실패하셨습니다.");
			Sleep(500);
			cooking();
		}

	}
	else {
		gotoxy(3, 6);
		printf("실패하셨습니다.");
		Sleep(500);
		cooking();
	}
	system("cls");

}
//level2
int leveltwo() {
	char foodInput[20];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	system("cls");
	printf("■■■■■■■■■■■■■■\n");
	printf("■미션:라면을 만들어라    ■\n");
	printf("■■■■■■■■■■■■■■\n");
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("■■■■■■■■■■■■■■\n");
	printf("■        재료공개        ■\n");
	printf("■■■■■■■■■■■■■■\n");
	printf("■    마법의 가루 스프    ■\n");
	printf("■------------------------■\n");
	printf("■     철분 가득한 물     ■\n");
	printf("■------------------------■\n");
	printf("■      파송송 계란탁     ■\n");
	printf("■■■■■■■■■■■■■■\n");

	Sleep(2500);
	system("cls");
	printf("■■■■■■■■■■■■■■\n");
	printf("■ 첫번째 재료 입력하기   ■\n");
	printf("■                        ■\n");
	printf("■■■■■■■■■■■■■■\n");
	gotoxy(3, 2);
	gets(foodInput);
	if (strcmp(foodInput, "마법의 가루 스프") == 0 || strcmp(foodInput, "마법의 가루 스프 ") == 0) {
		system("cls");
		printf("■■■■■■■■■■■■■■\n");
		printf("■ 두번째 재료 입력하기   ■\n");
		printf("■                        ■\n");
		printf("■■■■■■■■■■■■■■\n");
		gotoxy(3, 2);
		gets(foodInput);

		if (strcmp(foodInput, "철분 가득한 물") == 0 || strcmp(foodInput, "철분 가득한 물 ") == 0) {
			system("cls");
			printf("■■■■■■■■■■■■■■\n");
			printf("■ 세번째 재료 입력하기   ■\n");
			printf("■                        ■\n");
			printf("■■■■■■■■■■■■■■\n");
			gotoxy(3, 2);
			gets(foodInput);
			if (strcmp(foodInput, "파송송 계란탁") == 0 || strcmp(foodInput, "파송송 계란탁 ") == 0) {
				system("cls");
				printf("■■■■■■■■■■■■■■\n");
				printf("■       정답입니다!      ■\n");
				printf("■                        ■\n");
				printf("■■■■■■■■■■■■■■\n");
				Sleep(2000);
				system("cls");
				main();
			}
			else {
				gotoxy(3, 6);
				printf("실패하셨습니다.");
				Sleep(500);
				cooking();
			}
		}
		else {
			gotoxy(3, 6);
			printf("실패하셨습니다.");
			Sleep(500);
			cooking();
		}

	}
	else {
		gotoxy(3, 6);
		printf("실패하셨습니다.");
		Sleep(500);
		cooking();
	}
	system("cls");


}
//메인
int main() {
	
	
	while (1)
	{
		
		Menu();
	
	
		int MenuCode = Start();
		if (MenuCode == 0) {
			cooking();
		}
		else if (MenuCode == 1) {
			infoDraw();
		}
		else if (MenuCode == 2) {
			
			break;
		}
		
		system("cls");
		
	
	}	
	exit(1);

}