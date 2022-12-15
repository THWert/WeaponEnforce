#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <conio.h>

#define MAX_LEVEL 20

using namespace std;

int main()
{
	string name[MAX_LEVEL] = { "나뭇가지","나무젓가락","단검" ,"목검" ,"철검" ,"양날검" ,"롱 소드" ,"광선검" ,"불타는 쌍검" ,"빙결의 창" ,
					"악마의 낫" ,"빛의 그레이트 소드" ,"엑스칼리버" ,"레바테인" ,"마왕의 블랙 라이트 소드" ,"궁극의 썬더 대거" ,"마지막 대지의 스틸" ,
					"초월신의 명도","미지의 사이버 레이저 소드","파멸한 어둠의 다크 소드" };

	int level = 0; //레벨
	int ticket = 5; //초기 강화 가능 횟수

	int plusticket = 1; //추가로 얻을 강화 가능 횟수

	int percent = 100; //초기 확률

	int mypercent; //내 확률

	int number; //1, 2, 3중에 입력

	srand((int)time(NULL));

	cout << "★☆★☆★☆★☆★☆★☆" << endl;
	cout << "☆                    ★" << endl;
	cout << "★   무기 강화 게임   ☆" << endl;
	cout << "☆                    ★" << endl;
	cout << "★☆★☆★☆★☆★☆★☆" << endl;

	Sleep(2000);

	while (true)
	{
		system("cls");

		cout << "현재 강화 레벨 : +" << level << " (+15 이상부터 강화에 실패할 경우 무기가 파괴됩니다.)" << endl;
		cout << "강화 성공 확률 : " << percent << "%" << endl;
		cout << "강화 가능 횟수 : " << ticket << endl;

		cout << endl;

		cout << "이름 : " << name[level] << endl;
		cout << ">>>팔게 될 경우 " << plusticket << "회의 강화 가능 횟수를 얻습니다.<<<" << endl;

		cout << endl;

		cout << "강화를 하거나 무기를 파시겠습니까? " << endl;
		cout << "1 : 강화 하기" << endl;
		cout << "2 : 현재 무기 팔기" << endl;
		cout << "3 : 게임 종료" << endl << endl;
		cout << "입력 : ";
		cin >> number;

		switch (number)
		{
		case 1:
		{
			if (ticket > 0)
			{
				system("cls");

				cout << "강화 중..." << endl;

				Sleep(1500);

				mypercent = rand() % 100;

				if (mypercent <= percent)
				{
					system("cls");

					cout << "강화 성공!" << endl;
					percent -= 5;
					level++;
					plusticket += 2;
					ticket--;

					Sleep(1000);
				}
				else
				{
					system("cls");

					cout << "강화 실패!" << endl;
					ticket--;

					Sleep(1000);

					if (level >= MAX_LEVEL - 5)
					{
						cout << "무기가 파괴되었습니다." << endl;
						level = 0;
						percent = 100;
						plusticket = 1;

						Sleep(1000);
					}
				}

				if (level == MAX_LEVEL - 1)
				{
					cout << "이름 : " << name[level] << endl;
					cout << "게임 클리어!" << endl;
					cout << "축하드립니다." << endl << endl;
					cout << "게임을 종료합니다." << endl;

					Sleep(2000);
					exit(0);
				}
			}
			else
			{
				system("cls");
				cout << "강화 가능 횟수 부족" << endl;
				Sleep(1000);
				break;
			}
			break;
		case 2:
		{
			system("cls");

			cout << "현재의 무기를 팔고 강화 가능 횟수를 얻습니다." << endl;
			ticket += plusticket;
			level = 0;
			percent = 100;
			plusticket = 1;

			Sleep(2000);
			break;
		}
		case 3:
			system("cls");

			cout << "게임을 종료합니다." << endl;

			Sleep(2000);
			exit(0);
		}
		
		default:
		
			system("cls");

			cout << "잘못 입력하였습니다." << endl;
			Sleep(1000);
			break;
		}
	}
	return 0;
}