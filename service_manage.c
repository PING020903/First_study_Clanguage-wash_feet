#include"head.h"
int service_manage(servicelink myhead, FILE* fp)
{
	char ch = 0;
	while (1)
	{
		system("cls");//Linux下终端清屏係"clear",Windows下终端清屏係"cls"即使用power shell打开，但执行的时候本质上是cmd
		printf("\n\n服务管理模式(管理员)：\n");
		printf("按s显示所有服务\n按a增加一项服务\n按d删除选择的服务\n按c更改选择的服务\n按q退出：");
		scanf("%c", &ch);
		switch (ch)
		{
		case 'q':
		{
			fclose(fp);
			//先关闭，重新用 截零更改 模式打开
			fp = fopen("尼玛屎了.txt", "w+");
			Save_file_service(fp, myhead);
			fclose(fp);
			return -1;
			break;
		}
		case 'd'://删除、遍历(服务)
		{
			while (getchar() != '\n');
			Display_Service(myhead, SHOW_MODE);
			Dele_Service(myhead);
			break;
		}
		case 's'://遍历(服务)
		{
			printf("/*\n");
			Display_Service(myhead, SHOW_MODE);
			printf("*/\n按Enter返回");
			getchar();
			break;
		}
		case 'c'://更改节点数据(服务)
		{
			while (getchar() != '\n');
			Display_Service(myhead, SHOW_MODE);
			Change_Service(myhead);
			break;
		}
		case 'a'://增加数据节点(服务)
		{
			while (getchar() != '\n');
			Tail_Add_Node_Service(myhead);
			//Display_Service(myhead, SHOW_MODE);
		}
		default:
			break;
		}
		while (getchar() != '\n');
	}	

	return 0;
}