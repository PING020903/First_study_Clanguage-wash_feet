#include"head.h"
int main(void)
{
	
	FILE* fp_1 = fopen("尼玛屎了.txt", "r");
	FILE* password = fopen("key.txt", "r");
	
	servicelink myhead = Creat_list_node_service();//初始化头节点
	Read_service(fp_1, myhead);//读取服务
	char admin_temp[256] = { 0 };//输入暂存
	char key[256] = { 0 };//密码暂存
	strcpy(key, Read_key(password));//读取存放密码的文本赋值给key
	char ch = 0;
	
	while (1)
	{
		system("cls");//Linux下终端清屏係"clear",Windows下终端清屏係"cls"即使用power shell打开，但执行的时候本质上是cmd
		top();
		system("pause");//暂停程序，等待用户按任意键继续
		system("cls");
		system("color 0a");//设置终端颜色
		system("title 自助洗脚中心");//设置终端标题
		
		printf("\n客户请输入任意字母，管理员请输入密码(退出请按q):"); 
		scanf("%s", admin_temp);
		if (admin_temp[0] == 'q' && admin_temp[1] == '\0')//检查使用者只按下q
			ch = 'q';
		else
			ch = strcmp(key, admin_temp);//对比管理员密钥
		switch (ch)
		{
		case 'q'://退出
			_fcloseall();//关闭所以文件流，返回被关闭文件流的个数
			system("cls");
			return -1;
			break;
		case 0://管理员
		{
			while (getchar() != '\n');
			admin(fp_1, myhead, password);
			
			break;
		}
		default://客户
		{
			while (getchar() != '\n');
			connection(fp_1, myhead);
			break;
		}
		}
		while (getchar() != '\n');
	}	
	return 0;
}