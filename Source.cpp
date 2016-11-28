#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void instructions(char* input);
void SignUp(char** username, char** password,char* UserName,char* PassWord,int rate) {
	realloc(username,sizeof(username));
	realloc(password, sizeof(password));
	*(username+rate) = UserName;
	*(password+rate) = PassWord;
}
char* getinputasSTRING() {
	int firstsize = 20;
	char* input;
	input = (char*)malloc(sizeof(char)*firstsize);
	int i = 0;
	char letter = NULL;
	while ((letter=getchar())!='\n')
	{
		input[i++] = letter;
		if (i == firstsize) {
			input =(char*) realloc(input, sizeof(char)*(firstsize += 20));
		}
	}
	input[i++] = NULL;
	return input;
	free(input);
}
void Replace_Multiple_Space_With_Single(char* input) {
	int SizeOfString = 0;
	SizeOfString = strlen(input);
	for (int j = 0; j < SizeOfString; j++)
	{
		for (int i = 0; i < SizeOfString; i++)
		{
			if (input[i] == ' ' && input[i + 1] == ' ') {
				for (int j = i; j < SizeOfString; j++)
				{
					input[j] = input[j + 1];
				}
			}
		}
	}
}
void checkinput(char* input) {
	char* instruction;
	char* username;
	char* password;
	char* projectname;
	int size = strlen(input);
	instruction = (char*)malloc(sizeof(char)*size);
	username = (char*)malloc(sizeof(char)*size);
	int i = 0;
	while(input[i]!=' ')
	{
		instruction[i] = input[i];
		i++;
	}
	instruction[i] = NULL;
	instructions(instruction);
	int j = 0;
	i++;
	while (input[i] != ' ')
	{
		username[j] = input[i];
		j++;
		i++;
	}
	username[j] = NULL;
	instructions(username);
}
void instructions(char* input) {
	printf("%s\n", input);
}
int main() {
	char** username = (char**)malloc(sizeof(char));
	char** password = (char**)malloc(sizeof(char));
	char* UserName = (char*)malloc(sizeof(char));
	char* PassWord=(char*)malloc(sizeof(char));
	char key = NULL;
	int i = 0;
	int rate = 0;
	UserName = getinputasSTRING();
	Replace_Multiple_Space_With_Single(UserName);
	checkinput(UserName);
	return 0;
}