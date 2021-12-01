//a还是bbot
// 
//在a和b中随机一个选项
//示例：/bot aa还是bb
//建议从“aa”和“bb”中\n选择“aa”呢

bot.On<GroupMessage>(
	[&](GroupMessage m) {
		string command = m.MessageChain.GetPlainText();
		auto id = m.Sender.QQ;
		auto gid = m.Sender.Group.GID;
		auto pos = command.find("/bot");
		auto msg = MessageChain();
		if (pos == std::string::npos || pos != 0) return;
		pos += 5;	//head of choice 1
		auto pos2 = command.find("还是");	//end of choice 1
		if (pos2 == std::string::npos) return;
		string prefix = command.substr(pos, pos2 - pos);//choice 1
		pos2 += 6;	//head of choice 2
		if (command.length() - pos == 0) return;
		string suffix = command.substr(pos2, std::string::npos);//choice 2
		msg = MessageChain().Plain("建议在“" + prefix + "”和“" + suffix + "”中\n选择“" + 
			(rand() % 2 ? prefix : suffix) + "”呢");
		m.QuoteReply(msg);
	});