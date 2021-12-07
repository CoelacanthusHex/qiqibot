// b40 模块
bot.On<GroupMessage>(
	[&](GroupMessage m) {
		if ((mask & B40) == 0) return;
		string command = m.MessageChain.GetPlainText();
		auto gid = m.Sender.Group.GID;
		auto id = m.Sender.QQ;
		auto pos = command.find("b40");
		if (pos == std::string::npos || pos != 0) return;
		else {
			repeatTime.clear();
			std::ofstream b40o("./b40", std::ofstream::out);
			b40o << command;
			if (command.find(" ") == std::string::npos)
				b40o << " " << id;
			b40o.close();
			int result = system("python3 ./maimai_best_40.py ");
			auto msg = MessageChain();
			if (result != 0)
				msg = MessageChain().Plain("没有找到你的查分器信息,请尝试使用“b40【空格】用户名”"
					"或者绑定QQ号。详情请使用“help”指令");
			else {
				GroupImage img = bot.UploadGroupImage("./pic.png");
				msg = MessageChain().Image(img);
			}
			bot.SendMessage(gid, msg);
		}
	});
