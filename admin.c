#include"head.h"
//管理员
int admin(FILE* fp, servicelink myhead, FILE* password)
{
	if (fp == NULL || password == NULL)
	{
		perror("文件打开失败！！！\n");
		return -1;
	}
	while (1)
	{
		system("cls");//Linux下终端清屏係"clear",Windows下终端清屏係"cls"即使用power shell打开，但执行的时候本质上是cmd
		char ch = 0;		
		printf("\n\n管理员模式\n");
		printf("\n按s进入服务管理\n按k查看且修改密码\n按q退出：");

		scanf("%c", &ch);
		
		switch (ch)//管理员权限
		{
		case 'q':
		{
			return -1;
			break;
		}
		case 's':
		{
			while (getchar() != '\n');
			service_manage(myhead, fp);
			Display_Service(myhead, SHOW_MODE);
			break;
		}
		case 'k':
		{
			printf("现在密码是："); 
			char key[256] = { 0 };
			strcpy(key, Read_key(password));
			printf("%s\n", key);
			Change_key(password);
			break;
		}
		default:
			break;
		}
		while (getchar() != '\n');//当选择分支结束后再去除空格，否则会有bug(此bug让我心力憔悴)
	}
	return 0;
}