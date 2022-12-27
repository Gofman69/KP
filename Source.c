#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

typedef struct rally
{
	int zhrebi;
	char name[20];
	int ochki;
	int hours[4];
	int minutes[4];
	float seconds[4];
	int place;
	float cash;
};

struct rally zero();
struct rally ok();
int time_s();
void SP();

void main() 
{
	setlocale(LC_ALL, "rus");
	char fname_2[20];
	char text[5] = ".txt";
	char name[20];
	char cash[20];
	FILE* file;
	int count, n, selection, selection_2, end;
	struct rally build[100];
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	n = 0;
	end = 0;
	printf("������� ���-�� ����������� ��������: ");
	scanf_s("%d", &n);
	for (int k = 0; k < n; k++) 
	{
		build[k] = ok(build[k], k);
	}
	while (1)
	{
		count = 0;

		
			int seconds_int;
			for (int i = 0; i < n; i++)
			{
			build[i].hours[3] = build[i].hours[0] + build[i].hours[1] + build[i].hours[2];
			build[i].minutes[3] = build[i].minutes[0] + build[i].minutes[1] + build[i].minutes[2];
			build[i].seconds[3] = build[i].seconds[0] + build[i].seconds[1] + build[i].seconds[2];
			
			seconds_int = build[i].seconds[3];
			

			if (seconds_int > 60)
			{
				for (; seconds_int > 60; seconds_int -= 60) 
				{
					build[i].seconds[3] -= 60;
					build[i].minutes[3] += 1;
				}
			}
			if (build[i].minutes[3] > 60)
			{
				for (; build[i].minutes[3] > 60; build[i].minutes[3] -= 60)
				{				
					build[i].hours[3] += 1;
				}
			}
			
		    }
			
		system("cls");
		SP(build, n);
		printf("��������� ����������� ������.\n");
		printf("�������� ���� �� �������������� �������:\n");
		printf("1. �������� �������.\n2. �������� �������������� ��������.\n3. ��������� ���������� �������� �� �����.\n4. ��������� ���� � ������������ �������.\n5. �������� �������������� �������.\n6. �������� ������������ ����� ������. \n7. �������� ����������� ����� ������\n8. �������� ������� ����� ������.\n9. �����\n");
		printf("������� ��������: ");
		scanf_s("%d", &selection);
		system("cls");
		switch (selection) 
		{
		case 1: 
		{
			printf("\n");
			printf("|%6s|%17s|%12s|%12s|%12s|%12s|%12s|%12s|\n", "������", "������", "1-�����", "2-�����", "3-�����", "���-�� �����", "����� �����", "�����");
			
			for (int i = 0; i < n; i++) 
			{
				printf("|%5d|", build[i].zhrebi);
				printf("|%16s|", build[i].name);
				printf("|%3d:%2d:%4.1f|", build[i].hours[0], build[i].minutes[0], build[i].seconds[0]);
				printf("|%3d:%2d:%4.1f|", build[i].hours[1], build[i].minutes[1], build[i].seconds[1]);
				printf("|%3d:%2d:%4.1f|", build[i].hours[2], build[i].minutes[2], build[i].seconds[2]);
				printf("|%11d|", n - i);
				printf("|%3d:%2d:%4.1f|", build[i].hours[3], build[i].minutes[3], build[i].seconds[3]);
				printf("|%12d|", i + 1);
				printf("\n");
				build[i].ochki = n - i;
				build[i].place = i + 1;
			}
			printf("\n");
			printf("\n\n");
			printf("���������� ���������?\n1) ���\n2) ��\n");
			printf("������� �������: ");
			scanf_s("%d", &end);
			printf("\n\n");
			system("cls");
			break;
		}
		case 2: 
		{
			printf("������� �����������:\n");
			printf("1. �������� ��� �������.\n2. �������� ����� ������� ������ �������.\n3. �������� ����� ������� ������ �������.\n4. �������� ����� �������� ������ �������.\n");
			printf("������� �������: ");
			scanf_s("%d", &selection_2);
			system("cls");
			printf("������� ����� �������: ");
			scanf_s("%d", &selection);
			printf("\n");
			system("cls");
			switch (selection_2)
			{
			case 1:
			{				
				for (int i_2 = 0; i_2 < n; i_2++)
				{
					if (selection == build[i_2].zhrebi)
					{
						printf("������� ��� �������: ");
						scanf("%s", build[i_2].name);
						system("cls");
					}					
				}
				
				break;
			}
			case 2:
			{
				printf("������� �������: ");
				scanf_s("%f", &build[(selection - 1)].seconds[0]);
				printf("\n");
				printf("������� ������: ");
				scanf_s("%d", &build[(selection - 1)].minutes[0]);
				printf("\n");
				printf("������� ����: ");
				scanf_s("%d", &build[(selection - 1)].hours[0]);
				printf("\n");
				system("cls");
				break;
			}
			case 3:
			{
				printf("������� �������: ");
				scanf_s("%f", &build[(selection - 1)].seconds[1]);
				printf("\n");
				printf("������� ������: ");
				scanf_s("%d", &build[(selection - 1)].minutes[1]);
				printf("\n");
				printf("������� ����: ");
				scanf_s("%d", &build[(selection - 1)].hours[1]);
				printf("\n");
				system("cls");
				break;
			}
			case 4:
			{
				printf("������� �������: ");
				scanf_s("%f", &build[(selection - 1)].seconds[2]);
				printf("\n");
				printf("������� ������: ");
				scanf_s("%d", &build[(selection - 1)].minutes[2]);
				printf("\n");
				printf("������� ����: ");
				scanf_s("%d", &build[(selection - 1)].hours[2]);
				printf("\n");
				system("cls");
				break;
			}
			}
			break;
		}
		case 3:
		{
			printf("������� �������� �����, � �������� ������ ��������� ����������: ");
			scanf("%s", fname_2);
			strcat(fname_2, text);
			file = fopen(fname_2, "r");
			while (fscanf(file, "%s%d%d%d%f%d%d%f%d%d%f", name, &(build[count].zhrebi), &(build[count].hours[0]), &(build[count].minutes[0]), &(build[count].seconds[0]), &(build[count].hours[1]), &(build[count].minutes[1]), &(build[count].seconds[1]), &(build[count].hours[2]), &(build[count].minutes[2]), &(build[count].seconds[2])) != EOF)
			{
				printf("%s %d %d %d %.2f %d %d %.2f %d %d %.2f\n", build[count].name, (build[count].zhrebi), (build[count].hours[0]), (build[count].minutes[0]), (build[count].seconds[0]), (build[count].hours[1]), (build[count].minutes[1]), (build[count].seconds[1]), (build[count].hours[2]), (build[count].minutes[2]), (build[count].seconds[2]));
				count++;
			}
			n = count;
			fclose(file);
			break;
		}
		case 4:
		{
			printf("������� �������� �����: ");
			scanf("%s", fname_2);
			strcat(fname_2, text);
			file = fopen(fname_2, "w");
			for (int i = 0; i < n; i++)
			{
				fprintf(file, "%s %d %d %d %.2f %d %d %.2f %d %d %.2f\n", build[i].name, (build[i].zhrebi), (build[i].hours[0]), (build[i].minutes[0]), (build[i].seconds[0]), (build[i].hours[1]), (build[i].minutes[1]), (build[i].seconds[1]), (build[i].hours[2]), (build[i].minutes[2]), (build[i].seconds[2]));
			}
			fclose(file);
			break;
		}
		case 5:
		{
			int sel;
			printf("���������� ��������.\n");
			printf("������� ����� �������, �������� ������ ������ ����������: \n");
			scanf_s("%d", &sel);
			system("cls");
			for (int i_i = 0; i_i < n; i_i++)
			{
				if (sel == build[i_i].zhrebi)
				{
					printf("|%6s|%17s|%12s|%12s|%12s|%12s|%12s|%12s|\n", "������", "������", "1-�����", "2-�����", "3-�����", "���-�� �����", "����� �����", "�����");
					printf("|%5d|", build[i_i].zhrebi);
					printf("|%16s|", build[i_i].name);
					printf("|%3d:%2d:%4.1f|", build[i_i].hours[0], build[i_i].minutes[0], build[i_i].seconds[0]);
					printf("|%3d:%2d:%4.1f|", build[i_i].hours[1], build[i_i].minutes[1], build[i_i].seconds[1]);
					printf("|%3d:%2d:%4.1f|", build[i_i].hours[2], build[i_i].minutes[2], build[i_i].seconds[2]);
					printf("|%11d|", build[i_i].ochki);
					printf("|%3d:%2d:%4.1f|", build[i_i].hours[3], build[i_i].minutes[3], build[i_i].seconds[3]);
					printf("|%12d|", build[i_i].place);
					printf("\n\n\n");
					printf("���������� ���������?\n1) ���\n2) ��\n");
					printf("������� �������: ");
					scanf_s("%d", &end);
					system("cls");
					
				}
				
			}
			break;
				
		}
		case 6:
		{
			char *nm[20];
			int sel2, max_m = 0, max_h = 0, i = 0;
			float time_int = 0, max_s = 0;
			printf("������� ����� ������.\n");
			scanf_s("%d", &sel2);
			system("cls");
			for (; i < n; i++)
			{
				time_int = build[i].hours[sel2 - 1] * 3600 + build[i].minutes[sel2 - 1] * 60 + build[i].seconds[sel2 - 1];
				if (time_int > max_s)
				{
					max_s = time_int;
					*nm = build[i].name;
				}
			}
			for (; max_s >= 60; max_s -= 60)
			{
				max_m += 1;
			}
			for (; max_m > 59; max_m -= 60)
			{
				max_h += 1;
			}
			printf("������������ ����� ������: %3d:%2d:%4.1f\t\t\t��� �������: %10s", max_h,max_m,max_s, *nm);
			printf("\n");
			printf("���������� ���������?\n1) ���\n2) ��\n");
			printf("������� �������: ");
			scanf_s("%d", &end);
			system("cls");
			break;
		}
		case 7:
		{
			char* nm1[20];
			int sel21, min_m = 0, min_h = 0;
			float time_int = 0, min_s = 150000;
			printf("������� ����� ������.\n");
			scanf_s("%d", &sel21);
			system("cls");
			for (int i = 0; i < n; i++)
			{
				time_int = build[i].hours[sel21 - 1] * 3600 + build[i].minutes[sel21 - 1] * 60 + build[i].seconds[sel21 - 1];
				if (time_int < min_s)
				{
					min_s = time_int;
					*nm1 = build[i].name;
				}
			}
			for (; min_s >= 60; min_s -= 60)
			{
				min_m += 1;
			}
			for (; min_m > 59; min_m -= 60)
			{
				min_h += 1;
			}
			printf("����������� ����� ������: %3d:%2d:%4.1f\t\t\t��� �������: %10s", min_h, min_m, min_s, *nm1);
			printf("\n");
			printf("���������� ���������?\n1) ���\n2) ��\n");
			printf("������� �������: ");
			scanf_s("%d", &end);
			system("cls");
			break;
		}
		case 8:
		{
			char* sn[20];
			int h1=0, m1=0, sss, ll=0, h11=0, m11=0;
			float timesss;
			printf("������� ����� �������: ");
			printf("\n");
			scanf_s("%d", &sss);
			for (; ll < n; ll++)
			{
				if (sss == build[ll].zhrebi)
				{
					*sn = build[ll].name;
					timesss = ((build[ll].hours[3] * 3600 + build[ll].minutes[3] * 60 + build[ll].seconds[3]) / 3);
					for (; timesss >= 60; timesss -= 60)
					{
						m11 += 1;
					}
					for (; m11 >= 60; m11 -= 60)
					{
						h11 += 1;
					}
				}
			}
			
			
			printf("������� ����� �������: %3d:%2d:%4.1f\t\t\t��� �������: %10s\n\n\n", h11, m11, timesss, *sn);
			printf("���������� ���������?\n1) ���\n2) ��\n");
			printf("������� �������: ");
			scanf_s("%d", &end);
			system("cls");
			break;
		}
		case 9:
		{
			printf("��������� ���������.\n\n");
			end = 1;
			break;
		}
		default:
		{
			printf("����������� ������� �������.");
			printf("\n\n");
			printf("���������� ���������?\n1) ���\n2) ��\n");
			printf("������� �������: ");
			scanf_s("%d", &end);
			system("cls");
			break;
		}
		}
		if (end == 1) 
		{
			break;
		}
	}
	return 0;



}



struct rally ok(struct rally array, int j)
{
	char fn[1000] = "   ";
	strcpy(array.name, fn);
	array.zhrebi = j + 1;
	
	for (int i = 0; i < 4; i++)
	{
		array.seconds[i] = 0 + rand() % 60;
		array.minutes[i] = 0 + rand() % 60;
		array.hours[i] = 0 + rand() % 4;
	}
	array.ochki = 0;
	return array;
}

int time_s(struct rally array)
{
	array.cash = (array.hours[3] * 60 * 60) + (array.minutes[3] * 60) + array.seconds[3];
	return array.cash;
}

void SP(struct rally build[], int N)
{
	struct rally tmp;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (time_s(build[j]) > time_s(build[j + 1]))
			{
				tmp = build[j];
				build[j] = build[j + 1];
				build[j + 1] = tmp;
			}
		}
	}

	return build;
}

