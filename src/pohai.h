//迫害bot
//示例：/bot 迫害xx
//示例：/bot 迫害Zn

map<string, vector<string>> pohai; // Key: people vector<string>: filename

try
{
	system("ls ./pohai > pohailist.txt");
	std::ifstream ls2("./pohailist.txt", std::ifstream::in);
	string s2;
	while (getline(ls2, s2)) {
		string people = s2.substr(0, s2.find("-"));
		if (people == s2) continue;
		pohai[people].push_back(s2);
	}
	ls2.close();
	assert(pohai.size());
	// 如果未读到数据，存在未定义行为
}
catch (const std::exception& ex)
{
	cout << ex.what();
}

bot.On<GroupMessage>(
	[&](GroupMessage m) {
		string command = m.MessageChain.GetPlainText();
		auto id = m.Sender.QQ;
		auto gid = m.Sender.Group.GID;
		auto pos = command.find("/bot 迫害");
		if (pos == std::string::npos || pos != 0) return; //不是迫害
		pos += 11; //指针到“bot 迫害”后
		// /bot 迫害Zn
		if (pos == command.length()) return;
		string p = command.substr(pos, std::string::npos);
		if (!pohai[p].size()) return;
		int r = rand() % pohai[p].size();
		string fname = "./pohai/" + pohai[p][r];
		GroupImage img = bot.UploadGroupImage(fname);
		MessageChain msg = MessageChain().Image(img);
		bot.SendMessage(gid, msg);
	});