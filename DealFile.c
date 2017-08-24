#include "DealFile.h"

int writeFile(Year *year, FILE *pFile) {

	Project *project = NULL;
	Person *person = NULL;

	//ȷ���ļ�ָ���Ƿ�ΪNULL
	if(pFile == NULL) {
		printf("file pointer wrong!");
		return 0;
	}

	//����ȼƻ��е�������Ϣд���ļ���
	//(��Ϊ��ͬ�ı������Կո�Ϊ�ֽ�,����,Ӧ�����Ƚ����е��ַ�������Ԥ����:���ո�ת�����»���)
	fprintf(pFile, "{\n");
	while(year != NULL) {
		fprintf(pFile, "{%s %f %s %d %d %d %d %d\n", year->yearNum, year->yearMoney, year->yearHostPerson,
			year->applyProjectNum, year->actProjectNum, year->endProjectNum, year->startTime, year->endTime);

		project = year->project;

		while(project != NULL) {
			fprintf(pFile, "{%s %s %f %d %d %d %d %s %s %d %s\n", project->projectNum, project->projectName,
				project->projectMoney, project->personNum, project->projectStartTime, project->projectEndTime,
				project->rank, project->projectHostPerson, project->projectHostPersonTel, project->achiveType,
				project->achiveName);

			person = project->person;

			while(person != NULL) {
				fprintf(pFile, "{%s %s %d %d %s %s %s %s %s %d\n", person->personID, person->personName,
					person->age, person->personType, person->major, person->classRoom, person->skill,
					person->task, person->tel, person->personRank);
				fprintf(pFile, "}\n");
				person = person->nextPerson;
			}
			fprintf(pFile, "}\n");
			project = project->nextProject;
		}
		fprintf(pFile, "}\n");
		year = year->nextYear;
	}
	fprintf(pFile, "}");
	return 1;
}

int readFile(Year *year, FILE *pFile) {

	Year *nextYear = NULL;
	Project *project = NULL, *nextProject = NULL;
	Person *person = NULL, *nextPerson = NULL;
	char endMarkPerson[4], endMarkProject[4], endMarkYear[4];
	int endMarkNum = 0, endWord = 0;

	fgetc(pFile);
	fgetc(pFile);
	while(fscanf(pFile, "{%s %f %s %d %d %d %d %d\n", year->yearNum, &year->yearMoney, year->yearHostPerson,
		&year->applyProjectNum, &year->actProjectNum, &year->endProjectNum, &year->startTime, &year->endTime) != EOF) {

		project = mallocProject(project);/*Ϊproject����ͷָ��*/
		year->project = project;
		while(fscanf(pFile, "{%s %s %f %d %d %d %d %s %s %d %s\n", project->projectNum, project->projectName,
			&project->projectMoney, &project->personNum, &project->projectStartTime, &project->projectEndTime,
			&project->rank, project->projectHostPerson, project->projectHostPersonTel, &project->achiveType,
			project->achiveName) != EOF) {

			person = mallocPerson(person);/*Ϊperson����ͷָ��*/
			project->person = person;
			while(fscanf(pFile, "{%s %s %d %d %s %s %s %s %s %d\n", person->personID, person->personName,
				&person->age, &person->personType, person->major, person->classRoom, person->skill,
				person->task, person->tel, &person->personRank) != EOF) {
				endWord = fgetc(pFile);
				if(endWord == '}')/*��ȡ����һ��'}', ��ζ�����person�������Ѿ�������*/
					endMarkNum++;

				fgetc(pFile);
				endWord = fgetc(pFile);
				if(endWord == '}') {/*��ȡ���ڶ���'}', ��ζ�����е�person�������Ѿ�������, ͬʱҲ��ζ�����project�������Ѿ�������*/
					person->nextPerson = NULL;
					endMarkNum++;
					break;
				}
				else if(endWord == '{') {/*��ȡ��һ��'{', ��ʼ������һ��person������*/
					nextPerson = mallocPerson(nextPerson);
					person->nextPerson = nextPerson;
					person = nextPerson;
					fseek(pFile, -1, SEEK_CUR);/*����ȡ�ļ���λ�÷���һλ, */
					endMarkNum = 0;
					continue;
				}
			}
			//����Ҫ�úÿ���һ��....
			fgetc(pFile);
			endWord = fgetc(pFile);
			if(endWord == '}') {/*��ζ�����year�Ѿ�������*/
				project->nextProject = NULL;
				endMarkNum++;
				break;
			}
			else if(endWord == '{') {/*��ȡ���ڶ���'{', ��ʼ������һ��project������*/
				nextProject = mallocProject(nextProject);
				project->nextProject = nextProject;
				project = nextProject;
				fseek(pFile, -1, SEEK_CUR);
				endMarkNum = 0;
				continue;
			}
		}
		fgetc(pFile);
		endWord = fgetc(pFile);
		if(endWord == '}') {/*��ȡ��������'}", ���е�year�������*/
			year->nextYear = NULL;
			endMarkNum++;
			break;
		}
		else if(endWord == '{') { /*��ʼ������һ����ݵ���Ϣ*/
			nextYear = mallocYear(nextYear);
			year->nextYear = nextYear;
			year = nextYear;
			fseek(pFile, -1, SEEK_CUR);
			continue;
		}

	}
	return 1;
}
