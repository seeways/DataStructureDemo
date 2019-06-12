#pragma once
#ifndef roulette
/*
游戏规则：n 个参加者排成一个环，每次由主持向左轮手枪中装一颗子弹，并随机转动关上转轮，
游戏从第一个人开始，轮流拿枪；中枪者退出赌桌，退出者的下一个人作为第一人开始下一轮游戏。直至最后剩余一个人，即为
胜者。要求：模拟轮盘赌的游戏规则，找到游戏的最终胜者。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct gambler {
	int number;
}gambler;

void rouletteShow();

#endif // !roulette
