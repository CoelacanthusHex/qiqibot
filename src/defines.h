// bot 的定义
MiraiBot bot;
SessionOptions opts;
opts.BotQQ = 3560532039_qq;				// 请修改为你的机器人QQ
opts.HttpHostname = "localhost";		// 请修改为和 mirai-api-http 配置文件一致
opts.WebSocketHostname = "localhost";	// 同上
opts.HttpPort = 21021;					// 同上
opts.WebSocketPort = 21021;				// 同上
opts.VerifyKey = "1234567890";			// 同上
// 常量的定义
srand(unsigned(time(NULL)));
