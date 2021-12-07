// 注意: 本项目的所有源文件都必须是 UTF-8 编码

#include <iostream>
#include <map>
#include <mirai.h>
#include <fstream>
#include "myheader.h"
using namespace std;
using namespace Cyan;

int main(int argc, char* argv[])
{
#if defined(WIN32) || defined(_WIN32)
	// 切换代码页，让 CMD 可以显示 UTF-8 字符
	system("chcp 65001");
#endif

	#include "defines.h"

	while (true)
	{
		try
		{
			cout << "尝试与 mirai-api-http 建立连接..." << endl;
			bot.Connect(opts);
			break;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
		MiraiBot::SleepSeconds(1);
	}
	cout << "Bot Working..." << endl;

	#include "lostConnect.h"

	#include "disable.h"

	#include "recall.h"

	#include "luck.h"

	#include "help.h"

	#include "b40.h"

	#include "eatwhat.h"

	#include "memes.h"

	#include "aorb.h"

	#include "pohai.h"

	#include "wife.h"

	#include "dingshu.h"

	#include "spec_rand.h"

	#include "restart.h"

	char ch;
	while ((ch = getchar()) != 'q');
	bot.Disconnect();
	return 0;
}
