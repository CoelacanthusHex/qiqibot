// 今日运势模块
vector<string> pros;
vector<string> cons;
try
{
	std::ifstream pro("./proLuck.txt", std::ifstream::in);
	string s;
	while (getline(pro, s)) pros.push_back(s);
	pro.close();
	std::ifstream con("./conLuck.txt", std::ifstream::in);
	while (getline(con, s)) cons.push_back(s);
	con.close();
	assert(pros.size());
	assert(cons.size());
	// 如果未读到数据，存在未定义行为
}
catch (const std::exception& ex)
{
	cout << ex.what();
}
map<QQ_t, pair<time_t, MessageChain_t>> lastUpdate;
string gPos[] = { "东", "西", "南", "北", "东南", "东北", "西南", "西北","仰着打", "趴着玩", "别玩，会打着打着来电话"};
string mPos[] = { "1P", "2P" };
string autres[] = { "观众席", "等待区", "机器里当迪拉熊", "对面的吴丽芳", "旁边的e舞"};
string game[] = { "啤酒烧烤", "邦邦", "偶像大师", "maimai 鸡盘", "maimai 茶盘", "maimai 球盘", "maimai DX",
				  "maimai DX 最新最热", "maimai DX 斯普莱士", "maimai DX 油腻拔丝", "Cytus", "Cytus Ⅱ",
				  "CHUNITHM", "O.N.G.E.K.I.", "东方弹幕神楽", "Mush Dash", "Arcaea", "Phigros", 
				  "太鼓达人", "华卡音舞", "吴丽芳", "Beatmania IIDX", "SOUND VOTEX", "GROOVE COASTER",
				  "jubeat", "nostalgia", "Pop\'n music", "头文字 D", "湾岸", "Deemo", "VOEZ", "maimai 旧框" };
bot.On<GroupMessage>(
	[&](GroupMessage m) {
		string command = m.MessageChain.GetPlainText();
		if (command == "求签" || command == "今日运势")
		{
			repeatTime.clear();
			auto id = m.Sender.QQ;
			auto gid = m.Sender.Group.GID;
			auto now = time(NULL);
			struct tm tm_t;  localtime_s(&tm_t, &now);
			auto day = tm_t.tm_mday;
			if (lastUpdate.find(id) != lastUpdate.end() && lastUpdate[id].first == day) {
				auto msg = lastUpdate[id].second;
				bot.SendMessage(gid, msg);
				return;
			}
			int rPros = rand() % pros.size();
			int rCons = rand() % cons.size();
			while (rPros == rCons)
			{
				rPros = rand() % pros.size();
				rCons = rand() % cons.size();
			}
			int luck = rand() % 100;
			auto msg = MessageChain().At(id).Plain(" 的今日运势：\n宜：")
					.Plain(pros[rPros])
					.Plain("\n忌：")
					.Plain(cons[rCons])
					.Plain("\n今日人品值：")
					.Plain(to_string(luck));
			if (luck == 0) msg.Add(PlainMessage("\n出门小心丢东西"));
			else if (luck == 100) msg.Add(PlainMessage("\n出门在外能捡钱"));
			if (rand() >= 9. / 10 * RAND_MAX)
				msg = MessageChain().At(id).Plain("今日运势：\n万事皆宜");
			else if (rand() >= 9. / 10 * RAND_MAX)
				msg = MessageChain().At(id).Plain("今日运势：\n诸事不宜");
			msg.Add(PlainMessage("\n移动端黄金位：" + gPos[rand() % 11]));
			msg.Add(PlainMessage("\nmaimai 黄金位：" + (rand() % 3 == 2 ? autres[rand() % 5] : mPos[rand() % 2])));
			msg.Add(PlainMessage("\n今日推荐音游：" + game[rand() % 32]));
			system("python3 ./suggestions.py");
			std::ifstream fSong("./result.txt", std::ifstream::in);
			string song;
			getline(fSong, song);
			msg.Add(PlainMessage("\n\n今日推荐歌曲：" + song));
			fSong >> song;
			msg.Add(PlainMessage("\n所属流派：" + song));
			fSong >> song;
			msg.Add(PlainMessage("\n难度：" + song + " "));
			fSong >> song;
			msg.Add(PlainMessage(song));
			fSong >> song;
			msg.Add(PlainMessage("\n谱师：" + song + "\n"));
			fSong >> song;
			GroupImage img;
			string fn = "./static/mai/cover/" + song;
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
			fSong.close();
			if (lastUpdate.find(id) == lastUpdate.end()) lastUpdate[id] = make_pair(day, msg);
			else
			{
				lastUpdate[id].first = day;
				lastUpdate[id].second = msg;
			}
			bot.SendMessage(gid, msg);
			repeatTime.clear();
		}
	});
