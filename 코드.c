//�������
#include <stdio.h>
#include<Windows.h>
#include <string.h>
//����
#define MENU_X 15
#define MENU_Y 30
#define Up 0
#define Down 1
#define Submit 2
//������Ȯ��
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
//�޴�â
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
			case 1:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); printf("��"); break;
			case 2:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); printf("��"); break;
			case 3:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); printf("��"); break;
			case 4:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); printf("��"); break;
			case 5:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); printf("��"); break;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		}
		
		
		
		puts("");

	}
}//���۸޴�
//gotoxy
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
//���۹�ư
int Start() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	int x = 15;
	int y = 17;

	gotoxy(x - 2, y);
	printf("> �� �� �� �� �� ��");
	gotoxy(x + 1, y+ 1);
	printf("�� �� ��  �� ��");
	gotoxy(x, y +2);
	printf("      �� ��     ");
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
//����ȭ��
void infoDraw() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	system("cls");
	printf("\n\n");
	printf("                            \n");
	printf("      ������ؿ� �����ܢ�   \n");
	printf("                            \n");
	printf("         ����������Ʈ       \n");
	printf("                            \n");
	printf("        ������:�ֿ���       \n");
	printf("                            \n");

	while (1) {
		if (KeyControler() == Submit) {
		
			break;
		}
	}
}
//����
void cooking() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	char cookInput[30];
	
	system("cls");
	printf("������������\n");
	printf("��     �丮�ϱ�     ��\n");
	printf("������������\n");
	printf("��     ����/���    ��\n");
	printf("������������\n");
	printf("�Է� :");
	while (1) 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	
		gets(cookInput);
		
			if (strcmp(cookInput,"����") == 0 || strcmp(cookInput, "���� ") == 0) {
		
					levelone();
				
			}
			else if (strcmp(cookInput,"���") == 0 || strcmp(cookInput, "��� ") == 0) {
				system("cls");
				
				main();
				return 0;
			
			}
			else {
				printf("�ٽ��Է��ϼ���");
				continue;
			}
		
	
	}
	
}	       
//level1
int levelone() {
	char foodInput[100];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	system("cls");
	printf("���������������\n");
	printf("��̼�:������ġ�� �������\n");
	printf("���������������\n");
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("���������������\n");
	printf("��        ������        ��\n");
	printf("���������������\n");
	printf("��      ������ ���� ��    ��\n");
	printf("��------------------------��\n");
	printf("��      �Դ� ���� ġ��    ��\n");
	printf("��------------------------��\n");
	printf("��      �ž��� �����     ��\n");
	printf("���������������\n");
	
	Sleep(2500);
	system("cls");
	printf("���������������\n");
	printf("�� ù��° ��� �Է��ϱ�   ��\n");
	printf("��                        ��\n");
	printf("���������������\n");
	gotoxy(3, 2);
	gets(foodInput);
	if (strcmp(foodInput, "������ ���� ��") == 0 || strcmp(foodInput, "������ ���� �� ") == 0) {
		system("cls");
		printf("���������������\n");
		printf("�� �ι�° ��� �Է��ϱ�   ��\n");
		printf("��                        ��\n");
		printf("���������������\n");
		gotoxy(3, 2);
		gets(foodInput);

		if (strcmp(foodInput, "�Դ� ���� ġ��") == 0 || strcmp(foodInput, "�Դ� ���� ġ�� ") == 0) {
			system("cls");
			printf("���������������\n");
			printf("�� ����° ��� �Է��ϱ�   ��\n");
			printf("��                        ��\n");
			printf("���������������\n");
			gotoxy(3, 2);
			gets(foodInput);
			if (strcmp(foodInput, "�ž��� �����") == 0 || strcmp(foodInput, "�ž��� ����� ") == 0) {
				system("cls");
				printf("���������������\n");
				printf("��       �����Դϴ�!      ��\n");
				printf("��                        ��\n");
				printf("���������������\n");
				Sleep(2000);
			
				leveltwo();
			}
			else {
				gotoxy(3, 6);
				printf("�����ϼ̽��ϴ�.");
				Sleep(500);
				cooking();
			}
		}
		else {
			gotoxy(3, 6); 
			printf("�����ϼ̽��ϴ�.");
			Sleep(500);
			cooking();
		}

	}
	else {
		gotoxy(3, 6);
		printf("�����ϼ̽��ϴ�.");
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
	printf("���������������\n");
	printf("��̼�:����� ������    ��\n");
	printf("���������������\n");
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("���������������\n");
	printf("��        ������        ��\n");
	printf("���������������\n");
	printf("��    ������ ���� ����    ��\n");
	printf("��------------------------��\n");
	printf("��     ö�� ������ ��     ��\n");
	printf("��------------------------��\n");
	printf("��      �ļۼ� ���Ź     ��\n");
	printf("���������������\n");

	Sleep(2500);
	system("cls");
	printf("���������������\n");
	printf("�� ù��° ��� �Է��ϱ�   ��\n");
	printf("��                        ��\n");
	printf("���������������\n");
	gotoxy(3, 2);
	gets(foodInput);
	if (strcmp(foodInput, "������ ���� ����") == 0 || strcmp(foodInput, "������ ���� ���� ") == 0) {
		system("cls");
		printf("���������������\n");
		printf("�� �ι�° ��� �Է��ϱ�   ��\n");
		printf("��                        ��\n");
		printf("���������������\n");
		gotoxy(3, 2);
		gets(foodInput);

		if (strcmp(foodInput, "ö�� ������ ��") == 0 || strcmp(foodInput, "ö�� ������ �� ") == 0) {
			system("cls");
			printf("���������������\n");
			printf("�� ����° ��� �Է��ϱ�   ��\n");
			printf("��                        ��\n");
			printf("���������������\n");
			gotoxy(3, 2);
			gets(foodInput);
			if (strcmp(foodInput, "�ļۼ� ���Ź") == 0 || strcmp(foodInput, "�ļۼ� ���Ź ") == 0) {
				system("cls");
				printf("���������������\n");
				printf("��       �����Դϴ�!      ��\n");
				printf("��                        ��\n");
				printf("���������������\n");
				Sleep(2000);
				system("cls");
				main();
			}
			else {
				gotoxy(3, 6);
				printf("�����ϼ̽��ϴ�.");
				Sleep(500);
				cooking();
			}
		}
		else {
			gotoxy(3, 6);
			printf("�����ϼ̽��ϴ�.");
			Sleep(500);
			cooking();
		}

	}
	else {
		gotoxy(3, 6);
		printf("�����ϼ̽��ϴ�.");
		Sleep(500);
		cooking();
	}
	system("cls");


}
//����
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