#pragma once

enum errors { Success, IncorrectArgumentFormat, CorrectNumberOfArguments, UnableToOpen };
enum file { programName, input, unableToOpenFile };

int helpfulArgument(char * x, char * y);