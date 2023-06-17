#include"head.h"
//客户
int connection(FILE* fp, servicelink myhead)
{
	//Display_Service(myhead, SHOW_MODE);
	while (1)
	{
		system("cls");//Linux下终端清屏係"clear",Windows下终端清屏係"cls"即使用power shell打开，但执行的时候本质上是cmd
		int ch = 0;
		time_t timep;
		time(&timep); //存入time_t类型的timep
		printf("\n\n客户模式\n");
		printf("按s显示所有服务\n按c选择服务编号\n按q退出：");
		
		scanf("%c", &ch);
		
		switch (ch)//客户权限
		{
		case 'q':
		{
			fclose(fp);
			return -1;
		}
		case 's':
		{
			printf("/*\n");
			Display_Service(myhead, SHOW_MODE);
			printf("*/\n按Enter返回");
			getchar();
			break;
		}
		case 'c':
		{
			system("cls");
			Display_Service(myhead, SHOW_MODE);
			printf("请选择您的服务：");
			while (getchar() != '\n');
			servicelink temp = Display_Service(myhead, FIND_MODE);
			if (temp == NULL)
			{
				printf("\n\n欢迎下次光临！！！\n(按任意键退出)");
				getchar();
				break;
			}
			Save_history(temp);
			printf("您的号码：%s", ctime(&timep));
			printf("\n\n欢迎下次光临！！！\n(再次按下回车确认)");
			getchar();
			break;
		}
		default:
			break;
		}
		while (getchar() != '\n');//当选择分支结束后再去除空格，否则会有bug(此bug让我找得心力憔悴)
	}
	return 0;
}