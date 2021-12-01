bot.On<GroupMessage>(
	[&](GroupMessage m) {
		string command = m.MessageChain.GetPlainText();
		auto pos = command.find("定数");
		if (pos == std::string::npos || pos != 0) return;
		{
			std::ofstream dingshuO("./dingshu.txt", std::ofstream::out);
			dingshuO << command;
			dingshuO.close();
			system("python3 ./dingshu.py");
			std::ifstream dingshuI("./dingshu.txt", std::ifstream::in);
			string str;
			ostringstream buf;
			char ch;
			while (buf && dingshuI.get(ch)) buf.put(ch);
			bot.SendMessage(m.Sender.Group.GID, MessageChain().Plain(buf.str()));
        }
    });