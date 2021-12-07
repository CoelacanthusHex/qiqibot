// 在失去与mah的连接后重连
bot.On<LostConnection>([&](LostConnection e)
	{
		cout << e.ErrorMessage << " (" << e.Code << ")" << endl;
		while (true)
		{
			try
			{
				cout << "尝试连接 mirai-api-http..." << endl;
				bot.Reconnect();
				cout << "与 mirai-api-http 重新建立连接!" << endl;
				break;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			MiraiBot::SleepSeconds(1);
		}
	});
