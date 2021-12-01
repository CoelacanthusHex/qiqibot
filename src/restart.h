bot.On<GroupMessage>(
	[&](GroupMessage m) {
		string command = m.MessageChain.GetPlainText();
		if (command == "/update")
		{
			pros.clear();
			cons.clear();
			memeslist.clear();
			eatwhat.clear();
			pohai.clear();
			lastUpdate.clear();
			try
			{
				std::ifstream eat("./eatwhat.txt", std::ifstream::in);
				string s, s2;
				while (eat >> s >> s2) eatwhat[s].push_back(s2);
				eat.close();
				assert(eatwhat.size());
				// 如果未读到数据，存在未定义行为
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
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
			/*try
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
		}
	});
