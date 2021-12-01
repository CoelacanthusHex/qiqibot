//今天吃什么bot
// 
//随机一个今天吃什么的内容
//示例：/bot 吃什么
//建议吃烧烤
//示例：/bot Zn吃什么
//建议Zn喝东方树叶
//示例：/bot Zn明天吃什么
//建议Zn明天喝西北风

unordered_map<string, vector<string>> eatwhat;

try
{
	std::ifstream eat("./eatwhat.txt", std::ifstream::in);
	string s, s2;
	while (getline(eat, s)) {
		string sa = s.substr(0, 3);
		string sb = s.substr(4, std::string::npos);
		eatwhat[sa].push_back(sb);
	}
	eat.close();
	assert(eatwhat.size());
	// 如果未读到数据，存在未定义行为
}
catch (const std::exception& ex)
{
	cout << ex.what();
}

/*vector<string> medcine;

try
{
	std::ifstream med("./medcine.txt", std::ifstream::in);
	string s;
	while (getline(med, s)) medcine.push_back(s);
	med.close();
	assert(medcine.size());
	// 如果未读到数据，存在未定义行为
}
catch (const std::exception& ex)
{
	cout << ex.what();
}*/

bot.On<GroupMessage>(
	[&](GroupMessage m) {
		string command = m.MessageChain.GetPlainText();
		auto id = m.Sender.QQ;
		auto gid = m.Sender.Group.GID;
		auto pos = command.find("/bot");
		auto msg = MessageChain();
		if (pos == std::string::npos || pos != 0) return;
		pos += 5;
		auto pos2 = command.find("什么");
		if (pos2 == std::string::npos) return;
		string prefix = command.substr(pos, pos2 - pos);
		string dot = prefix;
		dot.erase(dot.begin(), dot.end() - 3);
		if (eatwhat.find(dot) == eatwhat.end()) {
			msg = MessageChain().Plain("不存在这种做法，联系管理员加一点吧！");
			m.QuoteReply(msg);
			return;
		}
		auto pos3 = command.find("什么药");
		//if (pos3 == std::string::npos) {
			int r = rand() % eatwhat[dot].size();
			msg = MessageChain().Plain("建议" + prefix + (eatwhat[dot])[r]);
			m.QuoteReply(msg);
		/*}
		else {
			int r = rand() % medcine.size();
			msg = MessageChain().Plain("建议吃" + medcine[r] + "。消息仅供娱乐，不作为任何医学建议！");
			m.QuoteReply(msg);
		}*/
	});