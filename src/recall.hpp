// 复读模块
map<GID_t, bool> recallGroup;
map<string, int> repeatTime;
// 复读开关
bot.On<GroupMessage>(
	[&](GroupMessage m)
	{
		try
		{
			string plain = m.MessageChain.GetPlainText();
			if (plain == "/recall-machine enabled")
			{
				recallGroup[m.Sender.Group.GID] = true;
				m.Reply(MessageChain().Plain("开始复读"));
			}
			if (plain == "/recall-machine disabled")
			{
				recallGroup[m.Sender.Group.GID] = false;
				m.Reply(MessageChain().Plain("停止复读"));
			}
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	});

bot.On<GroupMessage>(
	[&](GroupMessage m)
	{
		if (recallGroup.find(m.Sender.Group.GID) == recallGroup.end() || recallGroup[m.Sender.Group.GID] == false)
			return;
		try
		{
			string plain = m.MessageChain.GetPlainText();
			if (repeatTime.empty())
				repeatTime.insert(std::make_pair(plain, 1));
			else
			{
				if (repeatTime.find(plain) == repeatTime.end())
				{
					repeatTime.clear();
					repeatTime[plain]++;
				}
				else
				{
					repeatTime[plain]++;
					if (repeatTime[plain] == 3)
						bot.SendMessage(m.Sender.Group.GID, m.MessageChain);
				}
			}
		}
		catch (std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	});
