/*
* 定义：
* 32 位无符号长整型为掩码
*/
bot.On<GroupMessage>(
	[&](GroupMessage m) {
		string command = m.MessageChain.GetPlainText();
		auto gid = m.Sender.Group.GID;
		auto pos = command.find("setmask ");
		if (pos == std::string::npos) return;
		string ss = command.substr(pos + 8, std::string::npos);
		istringstream is(ss);
		is >> mask;
		bot.SendMessage(m.Sender.Group.GID, MessageChain().Plain("mask = " + to_string(mask)));
	});