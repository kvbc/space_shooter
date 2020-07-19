#pragma once
#include "core.h"
#include "cmd.h"


#define OPTIONS 10

#define OP_FPS 0
#define OP_BSIZE_X 1
#define OP_BSIZE_Y 2
#define OP_PHEALTH 3
#define OP_PDAMAGE 4
#define OP_PSPEED 5
#define OP_ENEMIES 6
#define OP_EHEALTH 7
#define OP_EDAMAGE 8
#define OP_BACK 9

#define IS_BACK  OP_BACK ==
#define NOT_BACK OP_BACK !=


typedef int COption;
typedef const int Option;
typedef const unsigned int UOption;

COption Cvalue(const std::pair<int, std::vector<unsigned int>> &option);
Option& value(const std::pair<int, std::vector<unsigned int>> &option);
UOption& Uvalue(const std::pair<int, std::vector<unsigned int>> &option);

typedef std::vector<
	std::pair<int, std::vector<unsigned int>>
> Options;


const Options* const DEFAULT_OPTIONS = new Options {
	{8, {10, 20, 30, 60, 120, 240, 360, 480, 560, 640, 720, 840, 960, 1000}},
	{0, {90, 100, 110, 120, 130, 140, 150, 160}},
	{0, {25, 30, 35, 40}},
	{2, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}},
	{0, {1, 2, 3, 4, 5}},
	{1, {1, 2, 3, 4, 5}},
	{4, {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10, 11, 12, 13, 14, 15}},
	{9, {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10, 15, 20, 25}},
	{0, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}}
};