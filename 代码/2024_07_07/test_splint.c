char func1(/*@null@*/char* str)
{
  return *str;
}

char func2(/*@null@*/char* str)
{
  if(NULL == str)
    return '\0';
  return *str;
}
