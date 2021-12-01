vector<string> memeslist;

try
{
	system("ls ./memes > filelist.txt");
	std::ifstream ls("./filelist.txt", std::ifstream::in);
	string s;
	while (getline(ls, s)) memeslist.push_back(s);
	ls.close();
	assert(memeslist.size());
	// 如果未读到数据，存在未定义行为
}
catch (const std::exception& ex)
{
	cout << ex.what();
}

//随机表情包
bot.On<GroupMessage>(
	[&](GroupMessage m) {
		auto gid = m.Sender.Group.GID;
		Cyan::MessageChain mc = m.MessageChain;
		if (m.AtMe() && (mc.GetPlainText() == " " || mc.GetPlainText() == ""))
		{
			string fn = "./memes/" + memeslist[rand() % memeslist.size()];
			GroupImage img = bot.UploadGroupImage(fn);
			MessageChain msg = MessageChain().Image(img);
			bot.SendMessage(gid, msg);
		}
		return;
	});