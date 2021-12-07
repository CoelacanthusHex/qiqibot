// 注意: 本项目的所有源文件都必须是 UTF-8 编码

#include <iostream>
#include <map>
#include <mirai.hpp>
#include <fstream>
#include "myheader.hpp"
using namespace std;
using namespace Cyan;

int main(int argc, char* argv[])
{
#if defined(WIN32) || defined(_WIN32)
	// 切换代码页，让 CMD 可以显示 UTF-8 字符
	system("chcp 65001");
#endif

	#include "defines.hpp"

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

	#include "lostConnect.hpp"

	#include "disable.hpp"

	#include "recall.hpp"

	#include "luck.hpp"

	#include "help.hpp"

	#include "b40.hpp"

	#include "eatwhat.hpp"

	#include "memes.hpp"

	#include "aorb.hpp"

	#include "pohai.hpp"

	#include "wife.hpp"

	#include "dingshu.hpp"

	#include "spec_rand.hpp"

	#include "restart.hpp"

	char ch;
	while ((ch = getchar()) != 'q');
	bot.Disconnect();
	return 0;
}