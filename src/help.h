//help文件
bot.On<GroupMessage>(
	[&](GroupMessage m) {
		string command = m.MessageChain.GetPlainText();
		if (command == "help")
		{
			repeatTime.clear();
			bot.SendMessage(
				m.Sender.Group.GID,
				MessageChain().Plain("欢迎使用QiQiBot Ver0.0.1 Beta\n")
							  .Plain("本机器人能提供关于maimai的运势、查歌、b40查分等功能\n")
							  .Plain("功能介绍：\n")
							  //.Plain("* 复读机：复读机：复读机：三条消息就会复读\n")
							  .Plain("* 【今日运势】或【求签】：抽取今天的运势事件、推荐歌曲等\n")
							  .Plain("* 【/bot [...][...]什么】：抽一个吃/喝/玩的东西，可以【今天吃什么】，"
										"也可以【迪拉熊今天喝什么】\n")
							  .Plain("* 【/bot 迫害XX】：让机器人开始迫害某人\n")
							  .Plain("* 【/bot <A>还是<B>】：在A和B中选一个，选择困难症福音\n")
							  .Plain("* 【maimai什么歌封面是我老婆】：随机一首歌的封面做你老婆\n")
							  .Plain("* 【定数查歌 <定数>】或【定数查歌 <定数上限> <定数下限>】：查询定数对应的乐曲\n")
							  .Plain("* 【随机[dx/标准][绿/黄/红/紫/白]<难度>】：随机一首指定条件的乐曲\n")
							  .Plain("* 【查歌 <乐曲标题的一部分>】或【查歌 [绿/黄/红/紫/白] <歌曲编号>】:查询乐曲信息或谱面信息\n")
							  .Plain("* 【XX是什么歌】：查询别名对应的乐曲\n")
							  .Plain("* 【分数线 <绿/黄/红/紫/白> <歌曲编号> <分数线>】：展示歌曲的分数线\n")
							  .Plain("* 【b40】：查分器，用法为“b40【空格】用户名”\n")
							  .Plain("如果绑定了QQ的话，只输入“b40”即可\n")
							  .Plain("绑定地址：https://www.diving-fish.com/maimaidx/prober/")
			);
			repeatTime.clear();
		}
	});
