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
unsigned mask	=	0b11111111111111111111111111111111u;
#define	AORB		0b00000000000000000000000000000001u
#define	B40			0b00000000000000000000000000000010u
#define	DINGSHU		0b00000000000000000000000000000100u
#define	EATWHAT		0b00000000000000000000000000001000u
#define	LUCK		0b00000000000000000000000000010000u
#define MEMES		0b00000000000000000000000000100000u
#define POHAI		0b00000000000000000000000001000000u
#define SPEC_RAND	0b00000000000000000000000010000000u
#define WIFE		0b00000000000000000000000100000000u