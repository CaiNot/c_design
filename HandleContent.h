#include "Content.h"

Year *insertYear(Year *yearHead, Year *year);

Project *insertProject(Year *yearNeeded, Project *project);

Person *insertPerson(Project *projectNeeded, Person *person);

Year *deleteYear(Year *yearHead, Year *year);

Project *deleteProject(Year *yearNeeded, Project *project);

Person *deletePerson(Project *projectNeeded, Person *person);
