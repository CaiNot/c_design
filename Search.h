#include "Content.h"
#ifndef SEARCH_H_ //∑¿÷π÷ÿ∏¥±‡“Î
#define SEARCH_H_

struct yearGet {
	Year *year;
	struct yearGet *nextYearGet;
};

struct projectGet {
	Year *year;
	Project *project;
	struct projectGet *nextProjectGet;
};

struct personGet {
	Year *year;
	Project *project;
	Person *person;
	struct personGet *nextPersonGet;
};

typedef struct yearGet YearGet;
typedef struct projectGet ProjectGet;
typedef struct personGet PersonGet;

YearGet* searchByYearNum(char *yearNum, Year *year);

YearGet* searchByYearMoney(float low, float high, Year *year);

YearGet* searchByYearActProject(int low, int high, Year *year);

ProjectGet* searchByProjectName(char *projectName, Year *year);

ProjectGet* searchByProjectAchiveName(char *achiveName, Year *year);

ProjectGet* searchByProjectMoney(float low, float high, Year *year);

ProjectGet* searchByProjectRank(int rank, Year *year);

ProjectGet* searchByProjectAchiveType(int achiveType, Year *year);

PersonGet* searchByPersonName(char *personName, Year *year);

PersonGet* searchByPersonMajor(char *major, Year *year);

PersonGet* searchByPersonSkill(char *skill, Year *year);

PersonGet* searchByPersonTask(char *task, Year *year);

#endif