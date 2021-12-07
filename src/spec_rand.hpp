bot.On<GroupMessage>(
	[&](GroupMessage m) {
		if ((mask & SPEC_RAND) == 0) return;
		string command = m.MessageChain.GetPlainText();
		auto pos = command.find("随机");
		if (pos == std::string::npos || pos != 0) return;
		{
			std::ofstream speco("./spec_rand.txt", std::ofstream::out);
			speco << command;
			speco.close();
			system("python3 ./spec_rand.py");
			std::ifstream speci("./spec_rand.txt", std::ifstream::in);
			string str;
			getline(speci, str);
			auto msg = MessageChain().Plain(str);
			getline(speci, str);
			GroupImage img;
			string fn = "./static/mai/cover/" + str;
			try {
				img = bot.UploadGroupImage(fn + ".jpg");
			}
			catch (...) {
				try {
					img = bot.UploadGroupImage(fn + ".png");
				}
				catch (...) {
					img = bot.UploadGroupImage("./static/mai/cover/1000.png");
				}
			}
			msg.Add(ImageMessage(img));
			getline(speci, str);
			msg.Add(PlainMessage("\n" + str));
			bot.SendMessage(m.Sender.Group.GID, msg);
			speci.close();
        }
    });