# qiqibot

## 概述

一款简陋的音游 bot，基于 mirai 与 mirai-cpp 开发。

欢迎使用 QiQiBot Ver0.0.1 Beta

本机器人能提供关于 maimai 的运势、查歌、b40 查分等功能

功能介绍：

  * 【今日运势】或【求签】：抽取今天的运势事件、推荐歌曲等
  * 【/bot \[...\]\[...\]什么】：抽一个吃/喝/玩的东西，可以【今天吃什么】，也可以【迪拉熊今天喝什么】
  * 【/bot 迫害XX】：让机器人开始迫害某人
  * 【/bot \<A\>还是\<B\>】：在A和B中选一个，选择困难症福音
  * 【maimai什么歌封面是我老婆】：随机一首歌的封面做你老婆
  * 【定数查歌 \<定数\>】或【定数查歌 \<定数上限\> \<定数下限\>】：查询定数对应的乐曲
  * 【随机\[dx/标准\]\[绿/黄/红/紫/白\]<难度>】：随机一首指定条件的乐曲
  * 【b40】：查分器，用法为“b40【空格】用户名”，如果绑定了QQ的话，只输入“b40”即可。绑定地址：https://www.diving-fish.com/maimaidx/prober/"

其中部分功能由 @Diving-Fish 等开发，仅仅是做了代码移植。

## 使用说明

使用能正常工作的 IDE 如 Visual Studio 2019 / 2022 进行编译。对于 Linux 用户，建议使用 WSL 进行编译。工程采用 `cmake` 工具链进行编译。

使用前请将项目目录下的 `py` 文件夹下的所有文件复制到与编译出的可执行文件相同的目录下。同样的，您也需要将[qiqibot-resources](https://github.com/GekkaSaori/qiqibot-resources)一并置于可执行文件目录下。

初次使用今日运势模块时，可能会需要一些时间下载资源文件，请耐心等待。

## TODO

- [ ] 【查歌 \<乐曲标题的一部分\>】或【查歌 \[绿/黄/红/紫/白\] \<歌曲编号\>】：查询乐曲信息或谱面信息
- [ ] 【XX是什么歌】：查询别名对应的乐曲
- [ ] 【分数线 \<绿/黄/红/紫/白\> \<歌曲编号\> \<分数线\>】：展示歌曲的分数线
