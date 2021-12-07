#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool SpecialSymbols(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}

bool assignOperator(char* ch)
{
    if (!strcmp(ch, "+=" )|| !strcmp(ch,"-=") || !strcmp(ch, "*=") ||
        !strcmp(ch,"/=") || !strcmp(ch,"%=") || !strcmp(ch,"==") ||
        !strcmp(ch,"!=") || !strcmp(ch,">") || !strcmp(ch, "<") || !strcmp(ch, ">=") || !strcmp(ch, "<=") || !strcmp(ch, "&&") || !strcmp(ch, "||") || !strcmp(ch, "!") || !strcmp(ch, "."))
        return (true);
    return (false);
}

bool Operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}
 
bool isValid(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || SpecialSymbols(str[0]) == true)
        return (false);
    return (true);
}
 
bool KeyWord(char* s)
{
    if (!strcmp(s, "if") || !strcmp(s, "else") ||
        !strcmp(s, "while") || !strcmp(s, "do") ||
        !strcmp(s, "break") ||
         !strcmp(s, "continue") || !strcmp(s, "int")
        || !strcmp(s, "double") || !strcmp(s, "float")
        || !strcmp(s, "return") || !strcmp(s, "char")
        || !strcmp(s, "case") || !strcmp(s, "char")
        || !strcmp(s, "sizeof") || !strcmp(s, "long")
        || !strcmp(s, "short") || !strcmp(s, "typedef")
        || !strcmp(s, "switch") || !strcmp(s, "unsigned")
        || !strcmp(s, "void") || !strcmp(s, "static")
        || !strcmp(s, "struct") || !strcmp(s, "goto") || !strcmp(s, "for") || !strcmp(s, "public") || !strcmp(s, "class") || !strcmp(s, "this"))
        return (true);
    return (false);
}
 
bool Integer(char* s)
{
    int i, len = strlen(s);
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (((s[i] != '0') && (s[i] != '1') && (s[i] != '2')
            && (s[i] != '3') && (s[i] != '4') && (s[i] != '5') && (s[i] != '6') && (s[i] != '7') && (s[i] != '8') && (s[i] != '9')) || ((s[i] == '-') && (i > 0)))
            return (false);
    }
    return (true);
}

bool Number(char* s)
{
    int i, length = strlen(s);
    bool decimal = false;
 
    if (length == 0)
        return (false);
    for (i = 0; i < length; i++) {
        if ((s[i] != '0' && s[i] != '1' && s[i] != '2'
            && s[i] != '3' && s[i] != '4' && s[i] != '5'
            && s[i] != '6' && s[i] != '7' && s[i] != '8'
            && s[i] != '9' && s[i] != '.') ||
            (s[i] == '-' && i > 0))
            return (false);
        if (s[i] == '.')
            decimal = true;
    }
    return (decimal);
}
 
char* sStr(char* s, int l, int r)
{
    int i;
    char* subs = (char*)malloc(
                  sizeof(char) * (r - l + 2));
 
    for (i = l; i <= r; i++)
        subs[i - l] = s[i];
    subs[r - l + 1] = '\0';
    return (subs);
}
 
void check(char* s)
{
    int l = 0, r = 0;
    int length = strlen(s);
 
    while (r <= length && l <= r) {
        if (SpecialSymbols(s[r]) == false)
            r++;
        
        if ((SpecialSymbols(s[r]) == true && l != r)
                   || (r == length && l != r)) {
            char* Strr = sStr(s, l, r - 1);
            if (KeyWord(Strr) == true)
                printf("'%s' KEYWORD\n", Strr);
 
            else if (Integer(Strr) == true)
                printf("'%s' INTEGER\n", Strr);
 
            else if (Number(Strr) == true)
                printf("'%s' REAL NUMBER\n", Strr);
            
            else if (assignOperator(Strr) == true)
                printf("'%s' ASSIGNMENT\n", Strr);
 
            else if (isValid(Strr) == true
                     && SpecialSymbols(s[r - 1]) == false)
                printf("'%s' VALID IDENTIFIER\n", Strr);
 
            else if (isValid(Strr) == false
                     && SpecialSymbols(s[r - 1]) == false)
                printf("'%s' NOT VALID IDENTIFIER\n", Strr);
            l = r;
          }
 
        else if (SpecialSymbols(s[r]) == true && l == r) {
            if (Operator(s[r]) == true)
                printf("'%c' OPERATOR\n", s[r]);
 
            r++;
            l = r;
        } 
    }
    return;
}

void error(){
  printf("Doesn't pass the syntax analyzer.");
}

char ifstmt(char *nextToken) {
 if (strstr(nextToken,"if")){
   printf("passes syntax analyzer\n");
 	check(nextToken); 
 }

 if (strstr(nextToken, "(")){
   printf("passes syntax analyzer\n");
 		check(nextToken);
 }

 if (strstr(nextToken, ")")){
   printf("passes syntax analyzer\n");
   check(nextToken);
 }

 if(strstr(nextToken, "else")){
   printf("passes syntax analyzer\n");
   check(nextToken);
 }

  if(!(!(strcmp(nextToken,"if")) || !(strcmp(nextToken, "(")) || !(strcmp(nextToken, ")")) || !(strcmp(nextToken, "else")))){
 		error();
  }
 return 0;
}

char foreachstmt(char *nextToken) {
 if (strstr(nextToken,"for")){
   printf("passes syntax analyzer\n");
 	check(nextToken); 
 }

 if (strstr(nextToken, "(")){
   printf("passes syntax analyzer\n");
 		check(nextToken);
 }

 if (strstr(nextToken, ")")){
   printf("passes syntax analyzer\n");
   check(nextToken);
 }
   
  if(!(!(strcmp(nextToken,"for")) || !(strcmp(nextToken, "(")) || !(strcmp(nextToken, ")")))){
 			ifstmt(nextToken);
 }
 return 0;
}

char forstmt(char *nextToken) {
 if (strstr(nextToken,"for")){
   printf("passes syntax analyzer\n");
 	check(nextToken); 
 }

 if (strstr(nextToken, "(")){
   printf("passes syntax analyzer\n");
 		check(nextToken);
 }

 if (strstr(nextToken, ")")){
   printf("passes syntax analyzer\n");
   check(nextToken);
 }
   
 if(!(!(strcmp(nextToken,"for")) || !(strcmp(nextToken, "(")) || !(strcmp(nextToken, ")")))){
 			foreachstmt(nextToken);
 }
 return 0;
}

char whilestmt(char *nextToken) {
 if (strstr(nextToken,"while")){
   printf("passes syntax analyzer\n");
 	check(nextToken); 
 }

 if (strstr(nextToken, "(")){
   printf("passes syntax analyzer\n");
 		check(nextToken);
 }

 if (!(strcmp(nextToken, ")"))){
   printf("passes syntax analyzer\n");
   check(nextToken);
 }
   
  
if(!(!(strcmp(nextToken,"while")) || !(strcmp(nextToken, "(")) || !(strcmp(nextToken, ")")))){
 			forstmt(nextToken);
 }
 return 0;
}

char dowhilestmt(char *nextToken) {
 if(strstr(nextToken, "do")){
   printf("passes syntax analyzer\n");
   check(nextToken);
 }
 
 if (strstr(nextToken,"while")){
   printf("passes syntax analyzer\n");
 	check(nextToken); 
 }

 if (strstr(nextToken, "(")){
   printf("passes syntax analyzer\n");
 		check(nextToken);
 }

 if (strstr(nextToken, ")")){
   printf("passes syntax analyzer\n");
   check(nextToken);
 }
   
 if(!(!(strcmp(nextToken,"do")) || !(strcmp(nextToken,"while")) || !(strcmp(nextToken, "(")) || !(strcmp(nextToken, ")")))){
 			whilestmt(nextToken);
 }
 return 0;
}

char blockstmt(char *nextToken) {
 if (strstr(nextToken,"{") || strstr(nextToken, "}")){
 	check(nextToken); 
   printf("passes syntax analyzer\n");
 }
   
 if(!(!(strcmp(nextToken, "{")) || !(strcmp(nextToken, "}")))){
 			dowhilestmt(nextToken);
 }

 return 0;
}

char assignments(char *nextToken) {

  if (strstr(nextToken, "+=") || strstr(nextToken,"-=")||strstr(nextToken, "*=")||strstr(nextToken, "/=")||strstr(nextToken, "%=")||strstr(nextToken, "==")||strstr(nextToken, "!=")||strstr(nextToken, ">") || strstr(nextToken, "<") || strstr(nextToken, ">=") || strstr(nextToken, "<=") || strstr(nextToken, "&&") || strstr(nextToken, "||")|| strstr(nextToken, "!") || strstr(nextToken, ".")){
    printf("passes syntax analyzer\n");
    check(nextToken);
  }
 else{
 			blockstmt(nextToken);
 }

 return 0;
}

char datatypestmt(char *nextToken){
  if(strstr(nextToken, "int") || strstr(nextToken, "String") || strstr(nextToken, "void") || strstr(nextToken, "double") || strstr(nextToken, "Double")){
    printf("passes syntax analyzer\n");
    check(nextToken);
  }

  else{
    assignments(nextToken);
  }
  return 0;
}

char classstmt(char *nextToken){
  if(strstr(nextToken, "public") || strstr(nextToken,"private") || strstr(nextToken, "protected") || strstr(nextToken, "class") || strstr(nextToken, "{") || strstr(nextToken, "}")){
    printf("passes syntax analyzer\n");
    check(nextToken);
  }

  else{
    datatypestmt(nextToken);
  }
  return 0;
}

char returnstmt(char *nextToken) {

  if (strstr(nextToken, "return")){
    printf("passes syntax analyzer\n");
    check(nextToken);
  }
  else{
 			classstmt(nextToken);
  }



 return 0;
}

int main()
{
     //Write what you would like in the txt file but make sure it's in a single line. This compiler parses Java Syntax.
    char * fileName = "txt.txt";
    FILE * fp = fopen(fileName, "r");
    char str[1000];
   returnstmt(fgets(str,1000 ,fp));

 
    return (0);
}
