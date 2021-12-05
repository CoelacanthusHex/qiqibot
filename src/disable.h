/*
* 定义：
* 32 位无符号长整型为掩码
*/
bot.On<GroupMessage>(
	[&](GroupMessage m) {
		string command = m.MessageChain.GetPlainText();
		auto gid = m.Sender.Group.GID;
		auto pos = command.find("setmask ");
		auto pos2 = command.find("/open ");
		auto pos3 = command.find("/close ");
		auto pos4 = command.find("/function query");
		if (pos4 != std::string::npos) {
			auto msg = MessageChain();
			msg.Add(PlainMessage("bot各功能开关状态：\n"));
			for (auto it = cscu.begin(); it != cscu.end(); ++it)
				msg.Add(PlainMessage(it->first + "：" + ((mask & it->second) ? "开\n" : "关\n")));
			msg.Add(PlainMessage("报告结束"));
			bot.SendMessage(gid, msg);
			return;
		}
		if (pos == std::string::npos && pos2 == std::string::npos 
			&& pos3 == std::string::npos) return;
		if (pos != std::string::npos) {
			string ss = command.substr(pos + 8, std::string::npos);
			istringstream is(ss);
			is >> mask;
			bot.SendMessage(gid, MessageChain().Plain("mask = " + to_string(mask)));
			return;
		}
		string ss; bool open = pos2 != std::string::npos;
		if (pos2 != std::string::npos) ss = command.substr(pos2 + 6, std::string::npos);
		else ss = command.substr(pos2 + 8, std::string::npos);
		for (auto it = cscu.begin(); it != cscu.end(); ++it)
			if (it->first == ss) mask = open ? (mask | it->second) : (mask & ~(it->second));
		bot.SendMessage(gid, MessageChain().Plain("mask = " + to_string(mask)));
	});