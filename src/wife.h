//maimai什么歌封面是我老婆
bot.On<GroupMessage>(
	[&](GroupMessage m) {
		if ((mask & WIFE) == 0) return;
		string command = m.MessageChain.GetPlainText();
		if (command == "maimai什么歌封面是我老婆")
		{
			system("python3 ./wife.py");
			std::ifstream wife("./wifeResult.txt", std::ifstream::in);
			string st;
			getline(wife, st);
			auto msg = MessageChain().Plain(st);
			getline(wife, st);
			GroupImage img;
			string fn = "./static/mai/cover/" + st;
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
			getline(wife, st);
			msg.Add(PlainMessage("\n" + st));
			bot.SendMessage(m.Sender.Group.GID, msg);
			wife.close();
		}
	});
